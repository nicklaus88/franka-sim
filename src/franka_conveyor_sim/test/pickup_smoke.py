#!/usr/bin/env python3
"""Launch pickup scene headlessly; validate actual RGB-D data and free cube."""
import json
import math
import os
from pathlib import Path
import signal
import struct
import subprocess
import time


def main():
    os.environ['GZ_PARTITION'] = 'pickup_smoke_' + str(os.getpid())
    os.environ['ROS_DOMAIN_ID'] = '75'
    os.environ['GZ_IP'] = '127.0.0.1'
    os.environ['RMW_IMPLEMENTATION'] = 'rmw_cyclonedds_cpp'
    os.environ['CYCLONEDDS_URI'] = 'file://' + str(Path.home()/'cyclonedds.xml')
    import numpy as np
    from PIL import Image as PillowImage
    import rclpy
    from rclpy.qos import qos_profile_sensor_data
    from sensor_msgs.msg import Image, CameraInfo, PointCloud2
    from tf2_ros import Buffer, TransformListener
    from gz.transport13 import Node as GzNode
    from gz.msgs10.pose_v_pb2 import Pose_V
    from gz.msgs10.clock_pb2 import Clock

    prefix = Path('/tmp')/os.environ['GZ_PARTITION']
    state = {'poses': {}, 'time': 0.}
    def poses(msg):
        state['poses'] = {p.name: [p.position.x, p.position.y, p.position.z]
                          for p in msg.pose if p.name in ('box_pickup', 'conveyor', 'd435')}
    def clock(msg):
        state['time'] = msg.sim.sec + msg.sim.nsec/1e9
    gz = GzNode()
    gz.subscribe(Pose_V, '/world/franka_pickup/pose/info', poses)
    gz.subscribe(Clock, '/world/franka_pickup/clock', clock)
    rclpy.init()
    node = rclpy.create_node('pickup_smoke', parameter_overrides=[rclpy.parameter.Parameter('use_sim_time', value=True)])
    buffer = Buffer()
    listener = TransformListener(buffer, node)
    messages = {}
    counts = {}
    def received(key, msg):
        messages[key] = msg
        counts[key] = counts.get(key, 0)+1
    for key, topic, kind in [('rgb', '/camera/color/image_raw', Image),
                             ('depth', '/camera/depth/image_rect_raw', Image),
                             ('info', '/camera/color/camera_info', CameraInfo),
                             ('depth_info', '/camera/depth/camera_info', CameraInfo),
                             ('points', '/camera/depth/points', PointCloud2)]:
        node.create_subscription(kind, topic, lambda msg, key=key: received(key, msg), qos_profile_sensor_data)
    def wait(predicate, timeout=50):
        end = time.monotonic()+timeout
        while time.monotonic() < end:
            rclpy.spin_once(node, timeout_sec=.05)
            if predicate():
                return
        raise AssertionError((state, counts))
    def cli(cmd):
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=15)
        assert result.returncode == 0, result.stderr
        return result.stdout
    with prefix.with_suffix('.log').open('w') as log:
        launch = subprocess.Popen(['ros2', 'launch', 'franka_conveyor_sim', 'franka_pickup_sim.launch.py',
                                   'rviz:=false', 'gz_args:=-s -r -v 4 --headless-rendering'],
                                  stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
        try:
            wait(lambda: all(counts.get(k, 0) >= 3 for k in ('rgb', 'depth', 'info', 'depth_info', 'points'))
                         and 'box_pickup' in state['poses'] and state['time'] > 4)
            assert abs(state['poses']['box_pickup'][2]-.48) < .005, state
            assert abs(state['poses']['conveyor'][0]-.1) < .001, state
            rgb, depth, info, cloud = (messages[k] for k in ('rgb', 'depth', 'info', 'points'))
            assert (rgb.width, rgb.height) == (848,480)
            assert rgb.encoding == 'rgb8', rgb.encoding
            assert depth.encoding == '32FC1', depth.encoding
            assert all(messages[k].header.frame_id == ('camera_link' if k == 'points' else 'camera_optical_frame') for k in messages), {
                k: v.header.frame_id for k,v in messages.items()}
            image = np.frombuffer(rgb.data, dtype=np.uint8).reshape(rgb.height, rgb.step)[:, :rgb.width*3].reshape(rgb.height,rgb.width,3)
            pixels = np.frombuffer(depth.data, dtype=np.dtype('>f4' if depth.is_bigendian else '<f4')).reshape(depth.height,depth.step//4)[:,:depth.width]
            # A red cube must be in view, with actual finite depth around its top.
            red = (image[:,:,0] > 70) & (image[:,:,0] > image[:,:,1].astype(float)*1.5) & (image[:,:,0] > image[:,:,2].astype(float)*1.5)
            assert int(red.sum()) > 80, int(red.sum())
            valid = pixels[red & np.isfinite(pixels)]
            assert valid.size > 80 and .9 < float(np.median(valid)) < 1.3
            frame = buffer.lookup_transform('world', 'camera_optical_frame', rclpy.time.Time())
            assert abs(frame.transform.translation.z-1.6) < .001
            assert info.k[0] > 400 and info.k[4] > 400, info.k
            # Harmonic cloud uses camera-link +X forward; images use optical +Z.
            fields = {f.name: f.offset for f in cloud.fields}
            offset = (cloud.height//2)*cloud.row_step+(cloud.width//2)*cloud.point_step
            point = [struct.unpack_from(('>' if cloud.is_bigendian else '<')+'f', cloud.data, offset+fields[k])[0]
                     for k in ('x','y','z')]
            assert .9 < point[0] < 1.3 and abs(point[1]) < .03 and abs(point[2]) < .03, point
            camera_frame = buffer.lookup_transform('world', 'camera_link', rclpy.time.Time())
            q = camera_frame.transform.rotation
            # Rotate the center sample into world and verify it lands on the cube top.
            v, u = np.array(point), np.array([q.x,q.y,q.z])
            rotated = v+2*np.cross(u, np.cross(u,v)+q.w*v)
            tr = camera_frame.transform.translation
            world_point = rotated+np.array([tr.x,tr.y,tr.z])
            assert np.linalg.norm(world_point-np.array([.15,.5,.51])) < .03, world_point
            PillowImage.fromarray(image).save(prefix.with_suffix('.png'))
            controllers = cli(['ros2','control','list_controllers'])
            assert controllers.count('active') == 2, controllers
            # Move the unconstrained box up through UserCommands; gravity must bring
            # it back to the surface. This is not a gripper pickup test.
            out = cli(['gz','service','-s','/world/franka_pickup/set_pose','--reqtype','gz.msgs.Pose',
                       '--reptype','gz.msgs.Boolean','--timeout','3000','--req',
                       'name: "box_pickup", position: {x: 0.15, y: 0.5, z: 0.65}, orientation: {w: 1}'])
            assert 'true' in out, out
            wait(lambda: state['poses']['box_pickup'][2] > .60, timeout=5)
            t = state['time']
            wait(lambda: state['time'] > t+1 and abs(state['poses']['box_pickup'][2]-.48) < .005, timeout=10)
            result = dict(log=str(prefix.with_suffix('.log')), image=str(prefix.with_suffix('.png')),
                          rgb_encoding=rgb.encoding, depth_encoding=depth.encoding,
                          resolution=[rgb.width,rgb.height], frame=rgb.header.frame_id,
                          messages=counts, red_pixels=int(red.sum()), cube_depth_median=float(np.median(valid)),
                          center_cloud_point=point, center_cloud_world=world_point.tolist(), cloud_frame=cloud.header.frame_id, box_settled=state['poses']['box_pickup'],
                          controllers=controllers, free_fall_retest='passed')
            prefix.with_suffix('.json').write_text(json.dumps(result, indent=2))
            print(json.dumps(result, indent=2), flush=True)
        finally:
            gz.unsubscribe('/world/franka_pickup/pose/info')
            gz.unsubscribe('/world/franka_pickup/clock')
            node.destroy_node()
            rclpy.shutdown()
            launch.send_signal(signal.SIGINT)
            try:
                launch.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(launch.pid, signal.SIGKILL)
                launch.wait()
            # gz's Ruby launcher may exit before its rendering-server child.
            # This isolated process group belongs only to this smoke test.
            try:
                os.killpg(launch.pid, signal.SIGTERM)
                time.sleep(.5)
                os.killpg(launch.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass


if __name__ == '__main__':
    main()
