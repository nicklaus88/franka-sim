#!/usr/bin/env python3
"""Installed launch integration: intervals, pause, stop spacing, reset, cleanup."""
import argparse
import os
os.environ.setdefault('GZ_PARTITION', 'conveyor_flow_' + str(os.getpid()))
from concurrent.futures import ProcessPoolExecutor
import multiprocessing
from pathlib import Path
import signal
import subprocess
import time
from gz.transport13 import Node
from gz.msgs10.clock_pb2 import Clock
from gz.msgs10.pose_v_pb2 import Pose_V
from gz.msgs10.double_pb2 import Double
from gz.msgs10.world_control_pb2 import WorldControl
from gz.msgs10.world_reset_pb2 import WorldReset
from franka_conveyor_sim.transport_service import request_boolean


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--motion-mode', choices=('physical', 'slider', 'force'), default='physical')
    parser.add_argument('--engine', default='gz-physics-dartsim-plugin')
    args = parser.parse_args()
    data = {'time': 0., 'poses': {}, 'seen': {}, 'removed': set()}
    def clock(msg):
        data['time'] = msg.sim.sec + msg.sim.nsec/1e9
    def poses(msg):
        current = {p.name: (p.position.x, p.position.y, p.position.z)
                   for p in msg.pose if p.name.startswith('box_')}
        data['removed'].update(set(data['poses']) - set(current))
        data['poses'] = current
        for name in current:
            data['seen'].setdefault(name, data['time'])
    node = Node()
    node.subscribe(Clock, '/world/conveyor_test/clock', clock)
    node.subscribe(Pose_V, '/world/conveyor_test/pose/info', poses)
    pub = node.advertise('/conveyor/cmd_vel', Double)
    pool = ProcessPoolExecutor(max_workers=1, mp_context=multiprocessing.get_context('spawn'))
    def wait(predicate, seconds=25):
        end = time.monotonic() + seconds
        while time.monotonic() < end:
            if predicate():
                return
            time.sleep(.05)
        raise AssertionError(str(data))
    def control(msg):
        assert all(pool.submit(request_boolean, '/world/conveyor_test/control',
                               msg.SerializeToString(), 'control').result(timeout=10))
    log = Path('/tmp') / (os.environ['GZ_PARTITION'] + '.log')
    with log.open('w') as output:
        launch = subprocess.Popen(['ros2', 'launch', 'franka_conveyor_sim', 'conveyor_test.launch.py',
                                   f'gz_args:=-s -r -v 4 --physics-engine {args.engine}',
                                   f'motion_mode:={args.motion_mode}'], stdout=output, stderr=subprocess.STDOUT,
                                  start_new_session=True)
        try:
            wait(lambda: data['time'] > 1)
            pub.publish(Double(data=.1))
            wait(lambda: len(data['seen']) >= 3)
            births = sorted(data['seen'].values())
            assert all(2.8 <= b-a <= 3.6 for a,b in zip(births,births[1:])), births
            print('PASS intervals:', births, flush=True)
            if args.motion_mode in ('slider','force'):
                if args.motion_mode == 'force':
                    settled_at = data['time']+.3
                    wait(lambda:data['time']>=settled_at)
                expected_z = .552 if args.motion_mode == 'slider' else .55
                assert all(abs(p[2]-expected_z) < .002 and abs(p[1]) < (.005 if args.motion_mode == 'force' else .001) for p in data['poses'].values())
                # The second box was created after a one-shot speed command.
                name = sorted(data['seen'], key=data['seen'].get)[1]
                x0, t0 = data['poses'][name][0], data['time']
                wait(lambda: data['time'] > t0+1)
                vx = (data['poses'][name][0]-x0)/(data['time']-t0)
                assert abs(vx-.1) < .015, vx
                print('PASS new driven box inherits speed; measured vx:', vx, flush=True)
            control(WorldControl(pause=True))
            time.sleep(.3)
            before = (data['time'], len(data['seen']))
            time.sleep(1.5)
            assert before == (data['time'], len(data['seen']))
            print('PASS paused: no time advance or spawn', flush=True)
            pub.publish(Double(data=0))
            control(WorldControl(pause=False))
            t = data['time']
            wait(lambda: data['time'] > t+7)
            count = len(data['seen'])
            t = data['time']
            wait(lambda: data['time'] > t+4)
            assert len(data['seen']) == count, 'Stopped belt spawned overlapping boxes'
            print('PASS stopped-belt spacing gate', flush=True)
            control(WorldControl(reset=WorldReset(time_only=True)))
            wait(lambda: data['time'] < 2)
            count = len(data['seen'])
            wait(lambda: data['time'] > 2)
            assert len(data['seen']) == count, 'Reset spawn burst'
            print('PASS time reset: no spawn burst', flush=True)
            pub.publish(Double(data=.2))
            wait(lambda: len(data['removed']) >= 1, seconds=25)
            print('PASS downstream removal:', sorted(data['removed']), flush=True)
            print('Log:', log, flush=True)
        finally:
            node.unsubscribe('/world/conveyor_test/clock')
            node.unsubscribe('/world/conveyor_test/pose/info')
            pool.shutdown(wait=True, cancel_futures=True)
            os.killpg(launch.pid, signal.SIGINT)
            try:
                launch.wait(timeout=12)
            except subprocess.TimeoutExpired:
                os.killpg(launch.pid, signal.SIGKILL)
                launch.wait()


if __name__ == '__main__':
    main()
