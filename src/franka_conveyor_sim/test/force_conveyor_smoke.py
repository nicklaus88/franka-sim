#!/usr/bin/env python3
"""Real force/motion, airborne cutoff and pause tests; optional existing Franka scene."""
import argparse
from concurrent.futures import ProcessPoolExecutor
import json
import math
import multiprocessing
import os
from pathlib import Path
import signal
import subprocess
import threading
import time


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--pickup-scene',action='store_true')
    args=parser.parse_args()
    partition='conveyor_force_'+str(os.getpid())
    os.environ.update(GZ_PARTITION=partition,ROS_DOMAIN_ID=str(80+os.getpid()%100),GZ_IP='127.0.0.1',
                      RMW_IMPLEMENTATION='rmw_cyclonedds_cpp',CYCLONEDDS_URI='file://'+str(Path.home()/'cyclonedds.xml'))
    from ament_index_python.packages import get_package_share_directory
    from franka_conveyor_sim.force_model import configure_force_plugin
    from franka_conveyor_sim.transport_service import request_boolean
    from gz.transport13 import Node
    from gz.msgs10.clock_pb2 import Clock
    from gz.msgs10.double_pb2 import Double
    from gz.msgs10.entity_factory_pb2 import EntityFactory
    from gz.msgs10.pose_v_pb2 import Pose_V
    from gz.msgs10.world_control_pb2 import WorldControl
    import xml.etree.ElementTree as ET
    world='franka_pickup' if args.pickup_scene else 'conveyor_test'
    box='box_pickup' if args.pickup_scene else 'box_force_test'
    top=.45 if args.pickup_scene else .5
    center_y=.5 if args.pickup_scene else 0.
    prefix=Path('/tmp')/partition
    state=dict(time=0.,pose=None,force=0.,velocity=0.,peak_force=0.,trace=[])
    lock=threading.Lock()
    node=Node()
    def clock(m):
        with lock:state['time']=m.sim.sec+m.sim.nsec/1e9
    def poses(m):
        for p in m.pose:
            if p.name==box:
                with lock:
                    state['pose']=[p.position.x,p.position.y,p.position.z]
    def force(m):
        with lock:
            state['force']=m.data
            state['peak_force']=max(state['peak_force'],abs(m.data))
    def velocity(m):
        with lock:
            state['velocity']=m.data
            state['trace'].append([state['time'],m.data,state['force']])
            state['trace']=state['trace'][-200:]
    topics=[f'/world/{world}/clock',f'/world/{world}/pose/info',f'/model/{box}/conveyor_force',f'/model/{box}/conveyor_velocity']
    for typ,topic,cb in [(Clock,topics[0],clock),(Pose_V,topics[1],poses),(Double,topics[2],force),(Double,topics[3],velocity)]:
        node.subscribe(typ,topic,cb)
    pub=node.advertise('/conveyor/cmd_vel',Double)
    pool=ProcessPoolExecutor(max_workers=1,mp_context=multiprocessing.get_context('spawn'))
    def snapshot():
        with lock:return {k:list(v) if isinstance(v,list) else v for k,v in state.items()}
    def wait(predicate,timeout=35):
        end=time.monotonic()+timeout
        while time.monotonic()<end:
            if predicate(snapshot()):return
            time.sleep(.01)
        raise AssertionError(snapshot())
    def sim_wait(duration):
        t=snapshot()['time'];wait(lambda s:s['time']>=t+duration)
    def request(kind,msg):
        assert all(pool.submit(request_boolean,f'/world/{world}/{kind}',msg.SerializeToString(),
                               'control' if kind=='control' else True).result(timeout=10))
    def cli(command):
        r=subprocess.run(command,text=True,capture_output=True,timeout=20)
        assert r.returncode==0,(command,r.stdout,r.stderr)
        return r.stdout
    launch_args=['ros2','launch','franka_conveyor_sim',
                 'franka_pickup_sim.launch.py' if args.pickup_scene else 'conveyor_test.launch.py',
                 'motion_mode:=force','belt_speed:=0.1']
    if args.pickup_scene:
        launch_args+=['rviz:=false','gz_args:=-s -r -v 3 --headless-rendering']
    else:
        launch_args+=['spawn_boxes:=false','gz_args:=-s -r -v 4 --physics-engine gz-physics-bullet-featherstone-plugin']
    results={}
    with prefix.with_suffix('.log').open('w') as output:
        launch=subprocess.Popen(launch_args,stdout=output,stderr=subprocess.STDOUT,start_new_session=True)
        try:
            wait(lambda s:s['time']>.2)
            if not args.pickup_scene:
                share=Path(get_package_share_directory('franka_conveyor_sim'))
                root=ET.parse(share/'models/box_force/model.sdf').getroot()
                configure_force_plugin(root,belt_x=.6,belt_y=0.,belt_top=.5,belt_yaw=0.,initial_speed=0.)
                msg=EntityFactory(name=box,sdf=ET.tostring(root,encoding='unicode'))
                msg.pose.position.x=-.25;msg.pose.position.z=.57
                request('create',msg)
            wait(lambda s:s['pose'] is not None and abs(s['pose'][2]-(top+(.03 if args.pickup_scene else .05)))<.003)
            if args.pickup_scene:
                baseline=cli(['ros2','control','list_controllers'])
                assert all(any(n in line and 'active' in line for line in baseline.splitlines())
                           for n in ('fr3_arm_controller','joint_state_broadcaster')),baseline
                results['controllers_before']=baseline
            pub.publish(Double(data=0.));sim_wait(1.5)
            before=snapshot();pub.publish(Double(data=.1))
            sim_wait(.05);early=snapshot()
            assert abs(early['velocity'])<.085,('Velocity jumped instead of accelerating',before,early)
            sim_wait(.2);later=snapshot()
            assert later['velocity']>early['velocity']+.01,(early,later)
            results['acceleration_samples']=[early['velocity'],later['velocity']]
            results['speed_response']=[]
            for speed in (.1,.2,0.,-.1):
                pub.publish(Double(data=speed));sim_wait(1.0)
                a=snapshot();sim_wait(1.0);b=snapshot()
                vx=(b['pose'][0]-a['pose'][0])/(b['time']-a['time'])
                assert abs(vx-speed)<.006,(speed,vx)
                assert abs(b['pose'][1]-center_y)<.006,b
                results['speed_response'].append(dict(command=speed,measured_vx=vx,force_N=b['force']))
                print('PASS force response:',results['speed_response'][-1],flush=True)
            assert 0.001<snapshot()['peak_force']<=.200001,snapshot()
            results['peak_force_N']=snapshot()['peak_force']
            # Pausing freezes both physics and the applied-force control loop.
            request('control',WorldControl(pause=True));time.sleep(.2)
            paused=snapshot();time.sleep(.5);still=snapshot()
            assert paused['time']==still['time'] and paused['pose']==still['pose'],(paused,still)
            pub.publish(Double(data=.2))
            request('control',WorldControl(pause=False));sim_wait(.3)
            results['pause']='PASS'
            pub.publish(Double(data=0.));sim_wait(1.5)
            old=snapshot();x,y=old['pose'][:2]
            # Test fixture only: lift the free body; the runtime plugin never sets poses.
            reply=cli(['gz','service','-s',f'/world/{world}/set_pose','--reqtype','gz.msgs.Pose',
                       '--reptype','gz.msgs.Boolean','--timeout','3000','--req',
                       f'name: "{box}" position {{ x: {x} y: {y} z: {top+.45} }} orientation {{ w: 1 }}'])
            assert 'true' in reply,reply
            wait(lambda s:s['pose'][2]>top+.30)
            pub.publish(Double(data=.2));sim_wait(.08);air_a=snapshot()
            sim_wait(.08);air_b=snapshot()
            assert air_a['pose'][2]>top+.18 and air_b['pose'][2]>top+.12,(air_a,air_b)
            assert abs(air_a['force'])<1e-12 and abs(air_b['force'])<1e-12,(air_a,air_b)
            assert air_b['pose'][2]<air_a['pose'][2]-.015,(air_a,air_b)
            assert abs(air_b['velocity']-air_a['velocity'])<.005,(air_a,air_b)
            results['airborne_cutoff_and_free_fall']='PASS'
            # Move outside the footprint and verify it stays unpowered on the floor.
            reply=cli(['gz','service','-s',f'/world/{world}/set_pose','--reqtype','gz.msgs.Pose',
                       '--reptype','gz.msgs.Boolean','--timeout','3000','--req',
                       f'name: "{box}" position {{ x: {x} y: {center_y+.8} z: {top+.45} }} orientation {{ w: 1 }}'])
            assert 'true' in reply
            sim_wait(.6);assert abs(snapshot()['force'])<1e-12,snapshot()
            results['off_belt_cutoff']='PASS'
            if args.pickup_scene:
                after=cli(['ros2','control','list_controllers'])
                assert all(any(n in line and 'active' in line for line in after.splitlines())
                           for n in ('fr3_arm_controller','joint_state_broadcaster')),after
                results['controllers_after']=after
                assert 'fr3_joint7' in cli(['ros2','topic','echo','/joint_states','--once'])
            output.flush()
            log=prefix.with_suffix('.log').read_text()
            assert '[ConveyorForce] Free-body force controller' in log
            assert 'Failed to load system plugin' not in log
            results.update(pickup_scene=args.pickup_scene,log=str(prefix.with_suffix('.log')))
            prefix.with_suffix('.json').write_text(json.dumps(results,indent=2))
            print('PASS force limits, finite acceleration, pause, free fall and force cutoff:',results,flush=True)
        finally:
            for topic in topics:node.unsubscribe(topic)
            pool.shutdown(wait=True,cancel_futures=True)
            os.killpg(launch.pid,signal.SIGINT)
            try:launch.wait(timeout=12)
            except subprocess.TimeoutExpired:
                os.killpg(launch.pid,signal.SIGKILL);launch.wait()
            try:os.killpg(launch.pid,signal.SIGKILL)
            except ProcessLookupError:pass
            print('Log:',prefix.with_suffix('.log'),flush=True)


if __name__=='__main__':main()
