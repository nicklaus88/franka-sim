#!/usr/bin/env python3
"""Headless installed-asset contact test; isolated Gazebo partition, no robot changes."""
import argparse
from concurrent.futures import ProcessPoolExecutor
import multiprocessing
import json
import math
import os
from pathlib import Path
import subprocess
import threading
import time
import xml.etree.ElementTree as ET

from ament_index_python.packages import get_package_share_directory
os.environ.setdefault('GZ_PARTITION', 'conveyor_smoke_' + str(os.getpid()))
from franka_conveyor_sim.transport_service import request_boolean
from gz.transport13 import Node
from gz.msgs10.clock_pb2 import Clock
from gz.msgs10.double_pb2 import Double
from gz.msgs10.entity_factory_pb2 import EntityFactory
from gz.msgs10.entity_pb2 import Entity
from gz.msgs10.pose_v_pb2 import Pose_V


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--engine', default='gz-physics-dartsim-plugin')
    parser.add_argument('--motion-mode', choices=('physical', 'slider', 'force'), default='physical')
    parser.add_argument('--belt-yaw', type=float, default=0.0)
    args = parser.parse_args()
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    log = Path('/tmp') / (os.environ['GZ_PARTITION'] + '.log')
    data = {'time': 0.0, 'pose': None, 'force':None, 'velocity':None, 'peak_force':0.0}
    lock = threading.Lock()
    pool = ProcessPoolExecutor(max_workers=1, mp_context=multiprocessing.get_context('spawn'))
    node = Node()
    def clock(msg):
        with lock:
            data['time'] = msg.sim.sec + msg.sim.nsec/1e9
    def poses(msg):
        for pose in msg.pose:
            if pose.name == 'box_test':
                with lock:
                    data['pose'] = [pose.position.x, pose.position.y, pose.position.z]
    node.subscribe(Clock, '/world/conveyor_test/clock', clock)
    node.subscribe(Pose_V, '/world/conveyor_test/pose/info', poses)
    def force(msg):
        data['force']=msg.data
        data['peak_force']=max(data['peak_force'],abs(msg.data))
    node.subscribe(Double,'/model/box_test/conveyor_force',force)
    node.subscribe(Double,'/model/box_test/conveyor_velocity',lambda m:data.update(velocity=m.data))
    pub = node.advertise('/conveyor/cmd_vel', Double)
    def wait_for(predicate, timeout=15):
        end = time.monotonic() + timeout
        while time.monotonic() < end:
            if predicate():
                return
            time.sleep(.02)
        raise RuntimeError('Timed out: ' + str(data))
    def request(service, msg):
        started = time.monotonic()
        ok, response = pool.submit(request_boolean, '/world/conveyor_test/' + service,
                                   msg.SerializeToString(), service == 'create').result(timeout=10)
        print(f'{service}: ok={ok!r}, response={response!r}, elapsed={time.monotonic()-started:.3f}s', flush=True)
        assert ok and response, service
    with log.open('w') as output:
        server = subprocess.Popen(['gz', 'sim', '-s', '-r', '-v', '4', '--physics-engine', args.engine, str(share/'worlds/conveyor_test.sdf')], stdout=output, stderr=subprocess.STDOUT)
        try:
            wait_for(lambda: data['time'] > .1)
            belt = EntityFactory(sdf_filename=str(share/'models'/{'slider':'conveyor_stationary','force':'conveyor_force','physical':'conveyor'}[args.motion_mode]/'model.sdf'), name='conveyor')
            belt.pose.position.x = .6
            belt.pose.position.z = .45
            belt.pose.orientation.z = math.sin(args.belt_yaw/2)
            belt.pose.orientation.w = math.cos(args.belt_yaw/2)
            request('create', belt)
            box = EntityFactory(sdf_filename=str(share/'models'/{'slider':'box_slider','force':'box_force','physical':'box'}[args.motion_mode]/'model.sdf'), name='box_test')
            if args.motion_mode == 'force':
                model = ET.parse(share/'models/box_force/model.sdf')
                model.find('.//plugin/belt_yaw').text = str(args.belt_yaw)
                box.sdf_filename = ''
                box.sdf = ET.tostring(model.getroot(),encoding='unicode')
            box.pose.position.x = .6 - .85*math.cos(args.belt_yaw)
            box.pose.position.y = -.85*math.sin(args.belt_yaw)
            box.pose.position.z = .552 if args.motion_mode == 'slider' else .57
            box.pose.orientation.z = math.sin(args.belt_yaw/2)
            box.pose.orientation.w = math.cos(args.belt_yaw/2)
            request('create', box)
            wait_for(lambda: data['pose'] is not None)
            results = []
            for speed in (.1, .2, 0., -.1):
                pub.publish(Double(data=speed))
                t = data['time']
                wait_for(lambda: data['time'] >= t + .5)
                with lock:
                    start = (data['time'], list(data['pose']))
                wait_for(lambda: data['time'] >= start[0] + 1.5)
                with lock:
                    end = (data['time'], list(data['pose']))
                dx, dy = end[1][0]-start[1][0], end[1][1]-start[1][1]
                velocity = (dx*math.cos(args.belt_yaw)+dy*math.sin(args.belt_yaw))/(end[0]-start[0])
                assert abs(-dx*math.sin(args.belt_yaw)+dy*math.cos(args.belt_yaw)) < .005
                if args.motion_mode == 'slider':
                    assert abs(end[1][2]-.552) < .001
                results.append(dict(command=speed, start=start, end=end, measured_local_vx=velocity, force_N=data['force'],plugin_velocity=data['velocity'],peak_force_N=data['peak_force']))
            request('remove', Entity(name='box_test', type=Entity.MODEL))
            print(json.dumps(dict(engine=args.engine, motion_mode=args.motion_mode, belt_yaw=args.belt_yaw, log=str(log), results=results), indent=2))
            assert all(abs(r['measured_local_vx']-r['command']) < .035 for r in results), 'Commanded box motion failed'
            assert all(abs(r['end'][1][2]-.55) < .02 for r in results), 'Box did not settle on belt'
            if args.motion_mode == 'force':
                output.flush()
                assert '[ConveyorForce] Free-body force controller' in log.read_text()
                assert 'Failed to load system plugin' not in log.read_text()
                result = dict(engine=args.engine,motion_mode=args.motion_mode,belt_yaw=args.belt_yaw,results=results,log=str(log))
                log.with_suffix('.json').write_text(json.dumps(result,indent=2))
        finally:
            node.unsubscribe('/model/box_test/conveyor_force')
            node.unsubscribe('/model/box_test/conveyor_velocity')
            node.unsubscribe('/world/conveyor_test/clock')
            node.unsubscribe('/world/conveyor_test/pose/info')
            pool.shutdown(wait=True, cancel_futures=True)
            server.terminate()
            try:
                server.wait(timeout=8)
            except subprocess.TimeoutExpired:
                server.kill()
                server.wait()


if __name__ == '__main__':
    main()
