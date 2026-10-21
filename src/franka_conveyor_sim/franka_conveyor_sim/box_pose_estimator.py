"""Estimate upright cube pose from synchronized RGB-D and calibrated optical TF."""
from collections import deque
import json
import math
import time

import cv2
from cv_bridge import CvBridge
from geometry_msgs.msg import PoseStamped
import message_filters
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import CameraInfo, Image
from std_msgs.msg import String
from tf2_ros import Buffer, TransformListener

from .pickup_geometry import estimate_cube


class BoxPoseEstimator(Node):
    def __init__(self):
        super().__init__('box_pose_estimator')
        for key, value in dict(box_size=.06, belt_top=.45, world_frame='world',
                               stability_samples=5, maximum_age=.5).items():
            self.declare_parameter(key, value)
        if self.p('stability_samples') < 1:
            raise ValueError('stability_samples must be positive; use 1 for moving cubes')
        # Avoid OpenCV thread oversubscription delaying image feedback.
        cv2.setNumThreads(1)
        self.bridge = CvBridge()
        self.buffer = Buffer()
        self.listener = TransformListener(self.buffer, self)
        self.info = None
        self.history = deque(maxlen=self.p('stability_samples'))
        self.last_stamp = None
        self.last_warning = 0.
        self.pose_pub = self.create_publisher(PoseStamped, '/pickup/box_pose', 10)
        self.metrics_pub = self.create_publisher(String, '/pickup/detection', 10)
        self.debug_pub = self.create_publisher(Image, '/pickup/detection_image', qos_profile_sensor_data)
        self.create_subscription(CameraInfo, '/camera/color/camera_info', self.on_info, qos_profile_sensor_data)
        self.rgb = message_filters.Subscriber(self, Image, '/camera/color/image_raw', qos_profile=qos_profile_sensor_data)
        self.depth = message_filters.Subscriber(self, Image, '/camera/depth/image_rect_raw', qos_profile=qos_profile_sensor_data)
        self.sync = message_filters.ApproximateTimeSynchronizer([self.rgb,self.depth], 10, .035)
        self.sync.registerCallback(self.on_images)

    def p(self, name):
        return self.get_parameter(name).value

    def on_info(self, info):
        self.info = info

    def on_images(self, rgb, depth):
        try:
            if self.info is None:
                return
            stamp = rclpy.time.Time.from_msg(rgb.header.stamp)
            if self.last_stamp is not None and stamp.nanoseconds <= self.last_stamp:
                self.history.clear()
            self.last_stamp = stamp.nanoseconds
            age = (self.get_clock().now()-stamp).nanoseconds/1e9
            if not 0 <= age <= self.p('maximum_age'):
                raise ValueError('Stale camera image')
            if rgb.header.frame_id != depth.header.frame_id or rgb.header.frame_id != self.info.header.frame_id:
                raise ValueError('RGB/depth/intrinsics frames differ')
            if (rgb.width,rgb.height) != (self.info.width,self.info.height):
                raise ValueError('Image/intrinsics resolution differs')
            transform = self.buffer.lookup_transform(self.p('world_frame'),rgb.header.frame_id,stamp)
            t,q = transform.transform.translation,transform.transform.rotation
            image = self.bridge.imgmsg_to_cv2(rgb, desired_encoding='rgb8')
            distances = self.bridge.imgmsg_to_cv2(depth, desired_encoding='passthrough')
            if depth.encoding == '16UC1':
                distances = distances.astype(np.float32)*.001
            elif depth.encoding != '32FC1':
                raise ValueError('Unsupported depth encoding')
            result = estimate_cube(image, distances, self.info.k, ([t.x,t.y,t.z],[q.x,q.y,q.z,q.w]),
                                   self.p('box_size'),self.p('belt_top'))
            self.history.append(result)
            if len(self.history) < self.history.maxlen:
                return
            centers = np.array([r['center'] for r in self.history])
            center = np.median(centers,axis=0)
            if np.max(np.linalg.norm(centers-center,axis=1)) > .005:
                raise ValueError('Cube estimate is not stationary/stable')
            # Fourfold angle mean handles the square's 90-degree ambiguity.
            angles = np.array([r['yaw'] for r in self.history])
            yaw = math.atan2(float(np.sin(4*angles).mean()),float(np.cos(4*angles).mean()))/4
            pose = PoseStamped()
            pose.header.stamp = rgb.header.stamp
            pose.header.frame_id = self.p('world_frame')
            pose.pose.position.x,pose.pose.position.y,pose.pose.position.z = map(float,center)
            pose.pose.orientation.z,pose.pose.orientation.w = math.sin(yaw/2),math.cos(yaw/2)
            self.pose_pub.publish(pose)
            metrics = {k:v for k,v in result.items() if k != 'contour'}
            metrics['center'],metrics['yaw'],metrics['stable_samples'] = center.tolist(),yaw,len(self.history)
            self.metrics_pub.publish(String(data=json.dumps(metrics)))
            debug = image.copy()
            cv2.drawContours(debug,[result['contour']],-1,(0,255,0),2)
            overlay = self.bridge.cv2_to_imgmsg(debug,encoding='rgb8')
            overlay.header = rgb.header
            self.debug_pub.publish(overlay)
        except Exception as exc:
            self.history.clear()
            if time.monotonic()-self.last_warning > 3:
                self.get_logger().warning(str(exc))
                self.last_warning = time.monotonic()


def main(args=None):
    rclpy.init(args=args)
    node = BoxPoseEstimator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
