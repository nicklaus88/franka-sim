#!/usr/bin/env python3
"""Camera feedback integration test; Gazebo truth is an independent test reference only."""
import argparse
import json
import os
from pathlib import Path
import signal
import subprocess
import time
import numpy as np


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--mode',choices=['tracking','stop','watchdog','stop-approach','stop-waiting','camera-loss'],default='tracking')
    args=parser.parse_args()
    tag=f'camera_tracking_{os.getpid()}'
    os.environ.update(GZ_PARTITION=tag,ROS_DOMAIN_ID=str(80+os.getpid()%100),GZ_IP='127.0.0.1',
                      RMW_IMPLEMENTATION='rmw_cyclonedds_cpp',CYCLONEDDS_URI='file://'+str(Path.home()/'cyclonedds.xml'))
    result=Path('/tmp')/(tag+'.json')
    log=Path('/tmp')/(tag+'.log')
    from gz.transport13 import Node as GzNode
    from gz.msgs10.odometry_pb2 import Odometry
    truth=[]
    transport=GzNode()
    def on_truth(msg):
        t=msg.header.stamp.sec+msg.header.stamp.nsec*1e-9
        p=msg.pose.position
        truth.append((t,[p.x,p.y,p.z]))
    transport.subscribe(Odometry,'/model/box_pickup/ground_truth',on_truth)
    with log.open('w') as stream:
        proc=subprocess.Popen(['ros2','launch','franka_conveyor_sim','conveyor_tracking.launch.py',
            'rviz:=false','gz_args:=-s -r -v 3 --headless-rendering','result_path:='+str(result)],
            stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
        try:
            killed=False
            if args.mode!='tracking':
                import rclpy
                from sensor_msgs.msg import JointState
                from std_msgs.msg import String
                from std_srvs.srv import Trigger
                rclpy.init()
                node=rclpy.create_node('tracking_safety_test')
                state={'tracking':False,'approaching':False,'waiting_for_box':False,'velocity':None,'seen':0.}
                def status(m):
                    status=json.loads(m.data).get('status')
                    if status in ('tracking','approaching','waiting_for_box'):state[status]=True
                def joints(m):
                    state['velocity']=np.array(m.velocity[:7]);state['seen']=time.monotonic()
                node.create_subscription(String,'/conveyor_tracking/status',status,10)
                node.create_subscription(JointState,'/joint_states',joints,10)
                deadline=time.monotonic()+90
                key=({'stop-approach':'approaching','stop-waiting':'waiting_for_box'}
                     .get(args.mode,'tracking'))
                while not state[key] and time.monotonic()<deadline:
                    rclpy.spin_once(node,timeout_sec=.1)
                assert state[key],f'No tracking status; inspect {log}'
                end=time.monotonic()+.7
                while time.monotonic()<end:rclpy.spin_once(node,timeout_sec=.02)
                if args.mode=='watchdog':
                    import psutil
                    victims=[p for p in psutil.Process(proc.pid).children(recursive=True)
                             if p.name()=='conveyor_tracke' or any(x.endswith('/conveyor_tracker') for x in p.cmdline())]
                    assert len(victims)==1,victims
                    victims[0].kill()
                    end=time.monotonic()+.7
                    while time.monotonic()<end:rclpy.spin_once(node,timeout_sec=.02)
                    assert time.monotonic()-state['seen']<.2,state
                    assert np.max(abs(state['velocity']))<.005,state
                    metrics={'watchdog':'passed','joint_velocity_after_publisher_death':state['velocity'].tolist(),'log':str(log)}
                    print(json.dumps(metrics))
                    Path('src/franka_conveyor_sim/test/results/camera_tracking_watchdog_validation.json').write_text(json.dumps(metrics,indent=2))
                    killed=True
                elif args.mode=='camera-loss':
                    import psutil
                    victims=[p for p in psutil.Process(proc.pid).children(recursive=True)
                             if any(x.endswith('/box_pose_estimator') for x in p.cmdline())]
                    assert len(victims)==1,victims
                    victims[0].kill()
                else:
                    client=node.create_client(Trigger,'/conveyor_tracking/stop')
                    assert client.wait_for_service(timeout_sec=5)
                    future=client.call_async(Trigger.Request())
                    rclpy.spin_until_future_complete(node,future,timeout_sec=5)
                    assert future.result().success
                node.destroy_node();rclpy.shutdown()
            if killed:return
            deadline=time.monotonic()+150
            while not result.exists() and time.monotonic()<deadline and proc.poll() is None:
                time.sleep(.2)
            assert result.exists(),f'No result; inspect {log}'
            record=json.loads(result.read_text())
            assert record['feedback_source']=='opencv_rgbd',record
            assert record['control_law']=='position_feedback_only',record
            assert record['status']=='stopped',record
            if args.mode in ('stop-approach','stop-waiting'):
                assert record['reason']=='requested during approach',record
                assert not record['samples'],record
                print(json.dumps(record))
                return
            assert record['reason']==({'stop':'requested','camera-loss':'stale state or clock reset'}.get(args.mode,'tracking workspace boundary')),record
            samples=record['samples']
            assert len(samples)>(5 if args.mode in ('stop','camera-loss') else 30),record
            assert record['initial_box'][0]<-1.3,record
            assert record['clearance_m']==.15,record
            assert record['tracking_start_x']<=samples[0]['box'][0]<record['tracking_start_x']+.02,record
            assert record['tracking_start_x']<-.1,record
            assert samples[0]['box'][0]<record['waiting_tcp_x'],record
            errors=np.array([np.array(s['tcp'])-np.array(s['box'])-[0,0,.18] for s in samples])
            assert np.max(np.linalg.norm(errors[:,:2],axis=1))<.03,errors
            settled=[i for i,s in enumerate(samples) if s['time']-samples[0]['time']>.8]
            if settled:
                assert np.max(np.linalg.norm(errors[settled,:2],axis=1))<.035,errors
            assert abs(errors[:,2]).max()<.004,errors
            assert samples[-1]['box'][0]-samples[0]['box'][0]>(.02 if args.mode in ('stop','camera-loss') else .20)
            assert max(abs(s['box'][1]-.5) for s in samples)<.005, 'Camera cube estimate left centerline'
            assert max(s['orientation_error_rad'] for s in samples)<.02
            controllers=subprocess.check_output(['ros2','control','list_controllers'],text=True,timeout=15)
            rows=[r.split() for r in controllers.splitlines() if r.strip()]
            assert any(r[0]=='fr3_arm_controller' and r[-1]=='active' for r in rows),controllers
            assert any(r[0]=='conveyor_velocity_controller' and r[-1]=='inactive' for r in rows),controllers
            assert len(truth)>10,'No independent ground-truth reference'
            stamps=np.array([t for t,_ in truth])
            positions=np.array([p for _,p in truth])
            measured=np.array([s['box'] for s in samples])
            reference=np.column_stack([np.interp([s['measurement_stamp'] for s in samples],stamps,positions[:,i]) for i in range(3)])
            camera_error=np.linalg.norm(measured-reference,axis=1)
            assert camera_error.max()<.01,camera_error
            current_reference=np.column_stack([np.interp([s['time'] for s in samples],stamps,positions[:,i]) for i in range(3)])
            actual_error=np.array([s['tcp'] for s in samples])-current_reference-[0,0,.18]
            assert np.linalg.norm(actual_error[:,:2],axis=1).max()<.04,actual_error
            assert np.abs(current_reference[:,1]-.5).max()<.001,'Actual cube moved sideways'
            metrics=dict(feedback_source='opencv_rgbd',control_law='position_feedback_only',
                         max_camera_error_m=float(camera_error.max()),
                         max_tcp_error_vs_current_truth_m=np.abs(actual_error).max(axis=0).tolist(),
                         max_measurement_age_s=max(s['measurement_age'] for s in samples),samples=len(samples),duration=samples[-1]['time']-samples[0]['time'],
                         max_abs_error_m=abs(errors).max(axis=0).tolist(),controllers=controllers,
                         log=str(log),trace=str(result))
            import shutil
            shutil.copyfile(result,'src/franka_conveyor_sim/test/results/camera_tracking_'+args.mode+'_trace.json')
            print(json.dumps(metrics,indent=2))
            Path('src/franka_conveyor_sim/test/results/camera_tracking_'+args.mode+'_validation.json').write_text(json.dumps(metrics,indent=2))
        finally:
            os.killpg(proc.pid,signal.SIGINT)
            try:
                proc.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(proc.pid,signal.SIGKILL)
                proc.wait()

if __name__=='__main__':
    main()
