#!/usr/bin/env python3
"""Execute the pickup with ros2_control; use Gazebo truth only to assess physics."""
import argparse
import json
import math
import os
from pathlib import Path
import signal
import subprocess
import time


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--cancel',action='store_true')
    parser.add_argument('--attach-executor',action='store_true')
    args = parser.parse_args()
    partition = 'pickup_execution_'+str(os.getpid())
    os.environ.update(GZ_PARTITION=partition, ROS_DOMAIN_ID=str(80+os.getpid()%100),
                      GZ_IP='127.0.0.1', RMW_IMPLEMENTATION='rmw_cyclonedds_cpp',
                      CYCLONEDDS_URI='file://'+str(Path.home()/'cyclonedds.xml'))
    import rclpy
    from rclpy.qos import DurabilityPolicy, QoSProfile
    from sensor_msgs.msg import JointState
    from std_msgs.msg import String
    from std_srvs.srv import Trigger
    from gz.transport13 import Node as GzNode
    from gz.msgs10.pose_v_pb2 import Pose_V
    from franka_conveyor_sim.pickup_planner import ARM, HOME
    prefix = Path('/tmp')/partition
    plan_path,result_path = str(prefix)+'.plan.json',str(prefix)+'.execution.json'
    gz = GzNode()
    data = dict(cube=None,peak_z=0.,stages={},joints=None)
    def poses(msg):
        for pose in msg.pose:
            if pose.name == 'box_pickup':
                data['cube'] = [pose.position.x,pose.position.y,pose.position.z]
                data['peak_z'] = max(data['peak_z'],pose.position.z)
    gz.subscribe(Pose_V,'/world/franka_pickup/pose/info',poses)
    rclpy.init()
    node = rclpy.create_node('pickup_execution_test')
    def status(msg):
        state = json.loads(msg.data)
        if state.get('stage') not in data['stages']:
            data['stages'][state.get('stage')] = data['cube']
            print('Execution:',state,'cube=',data['cube'],flush=True)
    def joints(msg):
        data['joints'] = dict(zip(msg.name,msg.position))
    qos = QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
    node.create_subscription(String,'/pickup/execution_status',status,qos)
    node.create_subscription(JointState,'/joint_states',joints,10)
    cancel_client = node.create_client(Trigger,'/pickup/cancel')
    plan_client = node.create_client(Trigger,'/pickup/plan')
    cancelled = False
    with prefix.with_suffix('.log').open('w') as log:
        launch = subprocess.Popen(['ros2','launch','franka_conveyor_sim','pickup_planning.launch.py',
            'rviz:=false',f'execution:={str(not args.attach_executor).lower()}','auto_execute:=true',
            'gz_args:=-s -r -v 3 --headless-rendering',f'output_path:={plan_path}',
            f'execution_result_path:={result_path}'],stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
        attached = None
        if args.attach_executor:
            attached = subprocess.Popen(['ros2','launch','franka_conveyor_sim','pickup_execution.launch.py',
                'auto_execute:=true',f'plan_path:={plan_path}',f'result_path:={result_path}'],
                stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
        try:
            deadline = time.monotonic()+600
            while time.monotonic() < deadline and not Path(result_path).exists():
                rclpy.spin_once(node,timeout_sec=.1)
                assert launch.poll() is None, f'Launch exited; inspect {prefix.with_suffix(".log")}'
                if (args.cancel and not cancelled and data['joints'] is not None and
                        'neutral_to_pregrasp' in data['stages'] and
                        max(abs(data['joints'][j]-v) for j,v in zip(ARM,HOME)) > .05):
                    replan = plan_client.call_async(Trigger.Request())
                    rclpy.spin_until_future_complete(node,replan,timeout_sec=5)
                    assert replan.done() and not replan.result().success,'Planner allowed replan during execution'
                    future = cancel_client.call_async(Trigger.Request())
                    rclpy.spin_until_future_complete(node,future,timeout_sec=5)
                    assert future.done() and future.result().success
                    cancelled = True
                if Path(plan_path).exists() and json.loads(Path(plan_path).read_text()).get('status') == 'failed':
                    raise AssertionError(Path(plan_path).read_text())
            assert Path(result_path).exists(),f'No execution report; inspect {prefix.with_suffix(".log")}'
            result = json.loads(Path(result_path).read_text())
            print('Result:',result,flush=True)
            if args.cancel:
                assert cancelled and result['status'] == 'cancelled',result
                assert not result['completed'],result
                end = time.monotonic()+3
                while time.monotonic() < end:
                    rclpy.spin_once(node,timeout_sec=.05)
                before = dict(data['joints'])
                end = time.monotonic()+2
                while time.monotonic() < end:
                    rclpy.spin_once(node,timeout_sec=.05)
                assert max(abs(before[j]-data['joints'][j]) for j in ARM) < .003,'Arm kept moving after cancellation'
                execute = node.create_client(Trigger,'/pickup/execute')
                future = execute.call_async(Trigger.Request())
                rclpy.spin_until_future_complete(node,future,timeout_sec=5)
                assert future.done() and future.result().success
                deadline = time.monotonic()+10
                while time.monotonic() < deadline:
                    rclpy.spin_once(node,timeout_sec=.05)
                    retry = json.loads(Path(result_path).read_text())
                    if retry['status'] == 'failed':
                        assert 'neutral' in retry['reason'],retry
                        break
                else:
                    raise AssertionError('Executor did not reject non-neutral restart')
                prefix.with_suffix('.validation.json').write_text(json.dumps({'cancel':result,'retry':retry,'stopped':True},indent=2))
                print('PASS cancellation, replan interlock, stopped arm and non-neutral restart rejection',flush=True)
                return
            assert result['status'] == 'success',result
            end = time.monotonic()+3
            while time.monotonic()<end:
                rclpy.spin_once(node,timeout_sec=.05)
            assert data['cube'] is not None
            assert math.dist(data['cube'][:2],[-.55,.15]) < .04,data
            assert abs(data['cube'][2]-.38) < .015,data
            assert data['peak_z'] > .56,data
            assert max(abs(data['joints'][j]-v) for j,v in zip(ARM,HOME)) < .02,data
            controllers = subprocess.run(['ros2','control','list_controllers'],capture_output=True,text=True,timeout=15)
            assert controllers.returncode == 0 and 'pickup_hand_controller' in controllers.stdout,controllers
            data['result'] = result
            prefix.with_suffix('.validation.json').write_text(json.dumps(data,indent=2))
            print('PASS physical pick/place/return:',data,flush=True)
        finally:
            gz.unsubscribe('/world/franka_pickup/pose/info')
            node.destroy_node()
            rclpy.try_shutdown()
            if attached is not None:
                os.killpg(attached.pid,signal.SIGINT)
                try:
                    attached.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    os.killpg(attached.pid,signal.SIGKILL)
                    attached.wait()
            os.killpg(launch.pid,signal.SIGINT)
            try:
                launch.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(launch.pid,signal.SIGKILL)
                launch.wait()
            try:
                os.killpg(launch.pid,signal.SIGKILL)
            except ProcessLookupError:
                pass
            print('Log:',prefix.with_suffix('.log'),flush=True)


if __name__ == '__main__':
    main()
