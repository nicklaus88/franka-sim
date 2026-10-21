#!/usr/bin/env python3
"""Headless same-world slider/force trial with unchanged Franka controllers."""

def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--combined-launch', action='store_true')
    parser.add_argument('--motion-mode',choices=('slider','force'),default='slider')
    args = parser.parse_args()
    import os
    os.environ.update(GZ_PARTITION='franka_slider_trial', ROS_DOMAIN_ID='74', GZ_IP='127.0.0.1', RMW_IMPLEMENTATION='rmw_cyclonedds_cpp', CYCLONEDDS_URI='file:///home/nick/cyclonedds.xml')
    import re, signal, subprocess, time
    from gz.transport13 import Node
    from gz.msgs10.pose_v_pb2 import Pose_V
    from gz.msgs10.clock_pb2 import Clock
    from gz.msgs10.double_pb2 import Double
    processes=[]
    data={'time':0.,'poses':{}}
    node=Node()
    def clock(msg):data['time']=msg.sim.sec+msg.sim.nsec/1e9
    def poses(msg):data['poses']={p.name:(p.position.x,p.position.y,p.position.z) for p in msg.pose if p.name.startswith('box_')}
    def wait(predicate,timeout=25):
     end=time.monotonic()+timeout
     while time.monotonic()<end:
      if predicate():return
      time.sleep(.05)
     raise AssertionError(data)
    def run(cmd):
     r=subprocess.run(cmd,capture_output=True,text=True,timeout=15)
     assert r.returncode==0,(cmd,r.stderr)
     return r.stdout
    log_path = f'/tmp/franka_{args.motion_mode}_{"wrapper" if args.combined_launch else "injection"}_trial.log'
    with open(log_path, 'w') as log:
     try:
      robot_cmd = (['ros2', 'launch', 'franka_conveyor_sim', 'franka_conveyor_sim.launch.py',
                    'rviz:=false', f'motion_mode:={args.motion_mode}', 'gz_args:=-s -r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf']
                   if args.combined_launch else
                   ['ros2','launch','franka_gazebo_bringup','gazebo_franka_arm_example_controller.launch.py','load_gripper:=true','controller:=fr3_arm_controller','rviz:=false','gz_args:=-s -r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf'])
      processes.append(subprocess.Popen(robot_cmd, stdout=log, stderr=subprocess.STDOUT, start_new_session=True))
      time.sleep(10)
      worlds=re.findall(r'^/world/([^/]+)/create$',run(['gz','service','-l']),re.M)
      assert len(worlds)==1,worlds
      world=worlds[0]
      node.subscribe(Clock,f'/world/{world}/clock',clock)
      node.subscribe(Pose_V,f'/world/{world}/pose/info',poses)
      baseline=run(['ros2','control','list_controllers']);print('Baseline:',baseline,flush=True)
      assert baseline.count('active')==2,baseline
      if not args.combined_launch:
        processes.append(subprocess.Popen(['ros2','launch','franka_conveyor_sim','add_conveyor.launch.py',f'world:={world}',f'motion_mode:={args.motion_mode}'],stdout=log,stderr=subprocess.STDOUT,start_new_session=True))
      wait(lambda:len(data['poses'])>=1)
      pub=node.advertise('/conveyor/cmd_vel',Double)
      time.sleep(.3);pub.publish(Double(data=.1))
      wait(lambda:len(data['poses'])>=2)
      name=sorted(data['poses'])[0]
      start=data['poses'][name];t=data['time']
      wait(lambda:data['time']>t+2)
      end=data['poses'][name];vx=(end[0]-start[0])/(data['time']-t)
      assert abs(vx-.1)<.015,(start,end,vx)
      assert abs(end[1]-.5)<.001 and abs(end[2]-(.552 if args.motion_mode=='slider' else .55))<.002,end
      after=run(['ros2','control','list_controllers']);assert after.count('active')==2,after
      joints=run(['ros2','topic','echo','/joint_states','--once']);assert 'fr3_joint7' in joints
      print(f'PASS same-world {args.motion_mode} motion:',world,'vx=',vx,'pose=',end,flush=True)
      print('PASS arm controller + broadcaster active; joint states present',flush=True)
     finally:
      if 'world' in locals():
       node.unsubscribe(f'/world/{world}/clock');node.unsubscribe(f'/world/{world}/pose/info')
      for p in reversed(processes):
       os.killpg(p.pid,signal.SIGINT)
       try:p.wait(timeout=12)
       except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()


if __name__ == '__main__':
    main()
