#!/usr/bin/env python3
"""Live RGB-D -> MoveIt trajectories, validating against Gazebo truth only in test."""
from collections import deque
import json
import os
from pathlib import Path
import signal
import subprocess
import time


def main():
    os.environ.update(GZ_PARTITION='pickup_planning_'+str(os.getpid()),ROS_DOMAIN_ID=str(80+os.getpid()%100),
                      GZ_IP='127.0.0.1',RMW_IMPLEMENTATION='rmw_cyclonedds_cpp',
                      CYCLONEDDS_URI='file://'+str(Path.home()/'cyclonedds.xml'))
    import numpy as np
    import rclpy
    from geometry_msgs.msg import PoseStamped
    from moveit_msgs.msg import RobotState,MoveItErrorCodes
    from moveit_msgs.srv import GetPositionFK
    from std_srvs.srv import Trigger
    from franka_conveyor_sim.pickup_geometry import rotation_matrix
    from sensor_msgs.msg import JointState,Image
    from rclpy.qos import qos_profile_sensor_data
    from cv_bridge import CvBridge
    import cv2
    from gz.transport13 import Node as GzNode
    from gz.msgs10.pose_v_pb2 import Pose_V
    prefix = Path('/tmp')/os.environ['GZ_PARTITION']
    output = prefix.with_suffix('.json')
    truth,vision,joints,images = {},deque(maxlen=10),deque(maxlen=2000),deque(maxlen=1)
    def poses(msg):
        for pose in msg.pose:
            if pose.name == 'box_pickup':
                truth['center'] = [pose.position.x,pose.position.y,pose.position.z]
    gz = GzNode()
    gz.subscribe(Pose_V,'/world/franka_pickup/pose/info',poses)
    rclpy.init()
    node = rclpy.create_node('pickup_planning_smoke')
    node.create_subscription(PoseStamped,'/pickup/box_pose',lambda msg:vision.append(msg),10)
    node.create_subscription(JointState,'/joint_states',lambda msg:joints.append(msg),10)
    node.create_subscription(Image,'/pickup/detection_image',lambda msg:images.append(msg),qos_profile_sensor_data)
    with prefix.with_suffix('.log').open('w') as log:
        launch = subprocess.Popen(['ros2','launch','franka_conveyor_sim','pickup_planning.launch.py',
                                   'rviz:=false','gz_args:=-s -r -v 3 --headless-rendering',
                                   f'output_path:={output}'],stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
        try:
            deadline = time.monotonic()+120
            while time.monotonic() < deadline and not output.exists():
                rclpy.spin_once(node,timeout_sec=.05)
            assert output.exists(),f'No planning result; inspect {prefix.with_suffix(".log")}'
            result = json.loads(output.read_text())
            print(json.dumps({k:v for k,v in result.items() if k not in ('stages','trajectory_start','stage_start_states')},indent=2),flush=True)
            assert result['status'] == 'success',result
            assert result['execution_enabled'] is False and result['gripper_commanded'] is False
            assert result['cartesian_fraction'] >= .999
            assert set(result['stages']) == {'neutral_to_pregrasp','pregrasp_to_grasp','close_fingers','lift_cube','transfer_to_target','lower_to_release','release_fingers','retreat_from_target','return_to_neutral'}
            p = result['box_pose']['pose']['position']
            estimated = np.array([p['x'],p['y'],p['z']])
            assert 'center' in truth
            error = float(np.linalg.norm(estimated-np.array(truth['center'])))
            assert error < .008,(estimated,truth,error)
            assert len(joints) > 2
            def arm(msg):
                values = dict(zip(msg.name,msg.position))
                return np.array([values[f'fr3_joint{i}'] for i in range(1,8)])
            assert np.max(np.abs(arm(joints[-1])-arm(joints[0]))) < .002,'Planning moved the arm'
            names = result['trajectory_start']['joint_state']['name']
            values = dict(zip(names,result['trajectory_start']['joint_state']['position']))
            from franka_conveyor_sim.pickup_planner import ARM, HOME
            assert np.allclose([values[j] for j in ARM], HOME)
            assert all(abs(values[f'fr3_finger_joint{i}']-.04) < 1e-8 for i in (1,2))
            fk = node.create_client(GetPositionFK,'/compute_fk')
            fk_errors = {}
            for name,stage in result['stages'].items():
                trajectory = stage['joint_trajectory']
                ts = trajectory['points']
                assert ts
                assert max(abs(values[j]-q) for j,q in zip(trajectory['joint_names'],ts[0]['positions'])) < .01,name
                values.update(zip(trajectory['joint_names'],ts[-1]['positions']))
                if name not in ('close_fingers','release_fingers','return_to_neutral'):
                    request = GetPositionFK.Request()
                    request.header.frame_id = 'world'
                    request.fk_link_names = ['fr3_hand_tcp']
                    request.robot_state = RobotState(joint_state=JointState(name=list(values),position=list(values.values())))
                    future = fk.call_async(request)
                    rclpy.spin_until_future_complete(node,future,timeout_sec=5)
                    assert future.done() and future.result().error_code.val == MoveItErrorCodes.SUCCESS
                    actual = future.result().pose_stamped[0].pose
                    target_pose = result['pregrasp' if name == 'neutral_to_pregrasp' else 'grasp'] if name in ('neutral_to_pregrasp','pregrasp_to_grasp') else result['stage_targets'][name]
                    target = target_pose['pose']['position']
                    fk_errors[name] = float(np.linalg.norm(np.array([actual.position.x,actual.position.y,actual.position.z])-
                                                           np.array([target['x'],target['y'],target['z']])))
                    assert fk_errors[name] < .003,fk_errors
                    q = actual.orientation
                    desired = target_pose['pose']['orientation']
                    assert abs(np.dot([q.x,q.y,q.z,q.w],[desired[k] for k in ('x','y','z','w')])) > .9999
                    assert np.linalg.norm(rotation_matrix([q.x,q.y,q.z,q.w])@[0,0,1]-[0,0,-1]) < .02
            assert np.allclose([values[j] for j in ARM], HOME, atol=.002)
            for stage in ('lift_cube','transfer_to_target','lower_to_release'):
                assert result['stage_start_states'][stage]['attached_collision_objects'][0]['object']['id'] == 'pickup_cube'
            assert result['placed_cube']['pose']['position'] == {'x':-.55,'y':.15,'z':.38}
            assert abs(values['fr3_finger_joint1']*2-result['final_gripper_opening']) < 1e-8
            assert abs(values['fr3_finger_joint2']-values['fr3_finger_joint1']) < 1e-8
            assert not result['stage_start_states']['return_to_neutral']['attached_collision_objects']
            print('PASS actual TCP endpoint FK errors:',fk_errors,flush=True)
            if images:
                cv2.imwrite(str(prefix.with_suffix('.png')),CvBridge().imgmsg_to_cv2(images[-1],desired_encoding='bgr8'))
            # Exercise the public replan service after a newer camera estimate.
            old_stamp = result['box_pose']['header']['stamp']
            until = time.monotonic()+1.
            while time.monotonic() < until:
                rclpy.spin_once(node,timeout_sec=.05)
            trigger = node.create_client(Trigger,'/pickup/plan')
            future = trigger.call_async(Trigger.Request())
            rclpy.spin_until_future_complete(node,future,timeout_sec=5)
            assert future.done() and future.result().success
            until = time.monotonic()+90
            refreshed = None
            while time.monotonic() < until:
                rclpy.spin_once(node,timeout_sec=.05)
                refreshed = json.loads(output.read_text())
                if refreshed.get('status') == 'success' and refreshed['box_pose']['header']['stamp'] != old_stamp:
                    break
            else:
                raise AssertionError(('Replanning did not produce a fresh successful result',refreshed))
            assert refreshed['cartesian_fraction'] >= .999
            print('PASS Trigger service replans from fresh camera pose',flush=True)
            print(f'PASS vision error={error:.6f} m, chained stages, full Cartesian approach, no arm execution; log={prefix.with_suffix(".log")}',flush=True)
        finally:
            gz.unsubscribe('/world/franka_pickup/pose/info')
            node.destroy_node()
            rclpy.try_shutdown()
            launch.send_signal(signal.SIGINT)
            try:
                launch.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(launch.pid,signal.SIGKILL)
                launch.wait()
            try:
                os.killpg(launch.pid,signal.SIGTERM)
                time.sleep(.5)
                os.killpg(launch.pid,signal.SIGKILL)
            except ProcessLookupError:
                pass


if __name__ == '__main__':
    main()
