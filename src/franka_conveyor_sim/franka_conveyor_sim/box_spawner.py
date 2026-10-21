"""Simulation-time box flow using persistent Gazebo Transport 13 services."""
from concurrent.futures import ProcessPoolExecutor
import multiprocessing
import math
from pathlib import Path
import random
import threading
import time
import uuid
import xml.etree.ElementTree as ET

from ament_index_python.packages import get_package_share_directory
import rclpy
from rclpy.node import Node
from gz.transport13 import Node as GzNode
from .transport_service import request_boolean
from .force_model import configure_force_plugin
from gz.msgs10.entity_factory_pb2 import EntityFactory
from gz.msgs10.entity_pb2 import Entity
from gz.msgs10.pose_v_pb2 import Pose_V
from gz.msgs10.double_pb2 import Double


def world_point(x, y, bx, by, yaw):
    return bx + math.cos(yaw)*x - math.sin(yaw)*y, by + math.sin(yaw)*x + math.cos(yaw)*y


def local_point(x, y, bx, by, yaw):
    return math.cos(yaw)*(x-bx) + math.sin(yaw)*(y-by), -math.sin(yaw)*(x-bx) + math.cos(yaw)*(y-by)


class BoxSpawner(Node):
    def __init__(self):
        super().__init__('box_spawner')
        defaults = dict(world='', motion_mode='physical', hover_gap=0.002, enabled=True, interval=3.0, belt_x=0.6,
                        belt_y=0.5, belt_z=0.45, belt_yaw=0.0, belt_speed=.1,
                        force_velocity_gain=10., force_integral_gain=2., force_max_acceleration=1.,
                        spawn_local_x=-0.85, lateral_range=0.0, seed=42,
                        minimum_spacing=0.16, cleanup=True, cleanup_local_x=1.15,
                        max_boxes=30, pose_timeout=0.5)
        for key, value in defaults.items():
            self.declare_parameter(key, value)
        if not self.p('world') or self.p('interval') <= 0 or self.p('minimum_spacing') < 0.15:
            raise ValueError('world, positive interval, and spacing >= 0.15 are required')
        if abs(self.p('spawn_local_x')) > 0.9 or not 0 <= self.p('lateral_range') <= 0.14:
            raise ValueError('spawn position must fit the default 2.0 x 0.4 m belt')
        if not self.get_parameter('use_sim_time').value:
            raise ValueError('use_sim_time must be true; bridge /clock first')
        self.motion_mode = self.p('motion_mode')
        if self.motion_mode not in ('physical', 'slider', 'force') or not 0.001 <= self.p('hover_gap') <= 0.02:
            raise ValueError('motion_mode must be physical, slider or force; hover_gap in [0.001, 0.02]')
        self.gz = GzNode()
        self.lock = threading.Lock()
        self.poses = {}
        self.speed = self.p('belt_speed') if self.motion_mode == 'force' else 0.0
        if not all(math.isfinite(self.p(key)) for key in ('belt_speed','force_velocity_gain','force_integral_gain','force_max_acceleration')):
            raise ValueError('Force settings must be finite')
        if self.p('force_velocity_gain') <= 0 or self.p('force_integral_gain') < 0 or self.p('force_max_acceleration') <= 0:
            raise ValueError('Invalid force gains/limit')
        if self.motion_mode == 'slider':
            self.get_logger().warning('SLIDER DEBUG MODE: world-constrained boxes, not friction transport or graspable free bodies')
            self.gz.subscribe(Double, '/conveyor/cmd_vel', self.on_speed)
        if self.motion_mode == 'force':
            self.get_logger().warning('FORCE MODE: external-force approximation on free boxes with a low-friction belt, not a moving belt surface')
            self.gz.subscribe(Double, '/conveyor/cmd_vel', self.on_speed)
        self.pose_seen = 0.0
        self.gz.subscribe(Pose_V, f"/world/{self.p('world')}/pose/info", self.on_poses)
        self.pool = ProcessPoolExecutor(max_workers=1, mp_context=multiprocessing.get_context('spawn'))
        self.future = None
        self.operation = None
        self.owned = set()
        self.prefix = 'box_' + uuid.uuid4().hex[:8] + '_'
        self.index = 0
        self.candidate = None
        self.rng = random.Random(self.p('seed'))
        self.last = 0.0
        self.next_spawn = None
        self.retry_at = 0.0
        self.failures = 0
        self.sdf = Path(get_package_share_directory('franka_conveyor_sim'), 'models', {'slider':'box_slider','force':'box_force','physical':'box'}[self.motion_mode], 'model.sdf').read_text()
        self.timer = self.create_timer(0.1, self.tick)

    def p(self, key):
        return self.get_parameter(key).value

    def on_speed(self, msg):
        if math.isfinite(msg.data):
            with self.lock:
                self.speed = msg.data

    def on_poses(self, msg):
        with self.lock:
            self.poses = {p.name: (p.position.x, p.position.y, p.position.z)
                          for p in msg.pose if p.name.startswith('box_')}
            self.pose_seen = time.monotonic()

    def submit(self, kind, name, request):
        self.operation = kind, name
        service = 'create' if kind == 'create' else 'remove'
        self.future = self.pool.submit(request_boolean,
            f"/world/{self.p('world')}/{service}", request.SerializeToString(), kind == 'create')

    def tick(self):
        now = self.get_clock().now().nanoseconds / 1e9
        with self.lock:
            poses = dict(self.poses)
            fresh = time.monotonic() - self.pose_seen < self.p('pose_timeout')
        if now < self.last:
            # Preserve ownership: a time-only reset may leave models in the world.
            self.next_spawn = now + self.p('interval')
            self.retry_at = now
            self.get_logger().info('Simulation reset; restarting interval without a spawn burst')
        self.last = now
        if self.future is not None:
            if not self.future.done():
                return
            kind, name = self.operation
            try:
                ok, reply = self.future.result()
                success = ok and reply
            except Exception as exc:
                self.get_logger().warning(str(exc))
                success = False
            self.future = None
            # A timed-out create can still have succeeded. Adopt the observed name.
            if kind == 'create' and name in poses:
                success = True
            if success:
                self.failures = 0
                if kind == 'create':
                    self.owned.add(name)
                    self.candidate = None
                    self.next_spawn = now + self.p('interval')
                else:
                    self.owned.discard(name)
                self.get_logger().info(f'{kind} {name} at sim t={now:.3f}')
            else:
                self.failures += 1
                self.retry_at = now + min(8.0, 0.5 * 2**min(self.failures, 4))
                self.get_logger().warning(f'{kind} {name} failed; retry after sim t={self.retry_at:.3f}')
        if now <= 0 or now < self.retry_at or not fresh:
            return
        if self.p('cleanup'):
            for name in sorted(self.owned):
                if name not in poses:
                    continue
                x, y, z = poses[name]
                lx, ly = local_point(x, y, self.p('belt_x'), self.p('belt_y'), self.p('belt_yaw'))
                # Conservative downstream corridor; lifted or laterally moved boxes remain.
                downstream = lx > self.p('cleanup_local_x')
                # Free boxes can fall and stop on the floor before the old
                # slider cleanup limit. Remove them only past the belt end and
                # below its bottom; elevated/grasped boxes are retained.
                fallen_downstream = (self.motion_mode == 'force' and lx > 1.0 and
                                     z < self.p('belt_z')-.05)
                if (downstream or fallen_downstream) and abs(ly) < 0.3 and z < self.p('belt_z') + 0.18:
                    self.submit('remove', name, Entity(name=name, type=Entity.MODEL))
                    return
        if self.next_spawn is None:
            self.next_spawn = now + self.p('interval')
        if not self.p('enabled') or now < self.next_spawn or len(self.owned) >= self.p('max_boxes'):
            return
        if self.candidate is None:
            self.index += 1
            lateral = self.rng.uniform(-self.p('lateral_range'), self.p('lateral_range'))
            x, y = world_point(self.p('spawn_local_x'), lateral, self.p('belt_x'), self.p('belt_y'), self.p('belt_yaw'))
            self.candidate = (self.prefix + f'{self.index:04d}', x, y)
        name, x, y = self.candidate
        if name in poses:
            self.owned.add(name)
            self.candidate = None
            self.next_spawn = now + self.p('interval')
            return
        if any(math.hypot(px-x, py-y) < self.p('minimum_spacing') for px, py, pz in poses.values()):
            return
        sdf = self.sdf
        if self.motion_mode == 'slider':
            model = ET.fromstring(sdf)
            with self.lock:
                speed = self.speed
            model.find('model/plugin/initial_velocity').text = str(speed)
            sdf = ET.tostring(model, encoding='unicode')
        if self.motion_mode == 'force':
            model = ET.fromstring(sdf)
            with self.lock:
                speed = self.speed
            configure_force_plugin(model,belt_x=self.p('belt_x'),belt_y=self.p('belt_y'),
                belt_top=self.p('belt_z')+.05,belt_yaw=self.p('belt_yaw'),initial_speed=speed,
                velocity_gain=self.p('force_velocity_gain'),integral_gain=self.p('force_integral_gain'),
                max_acceleration=self.p('force_max_acceleration'))
            sdf = ET.tostring(model,encoding='unicode')
        request = EntityFactory(sdf=sdf, name=name, allow_renaming=False)
        request.pose.position.x, request.pose.position.y = x, y
        request.pose.position.z = self.p('belt_z') + (0.10 + self.p('hover_gap') if self.motion_mode == 'slider' else 0.12)
        request.pose.orientation.z = math.sin(self.p('belt_yaw')/2)
        request.pose.orientation.w = math.cos(self.p('belt_yaw')/2)
        self.submit('create', name, request)

    def destroy_node(self):
        self.timer.cancel()
        self.gz.unsubscribe(f"/world/{self.p('world')}/pose/info")
        if self.motion_mode in ('slider','force'):
            self.gz.unsubscribe('/conveyor/cmd_vel')
        self.pool.shutdown(wait=True, cancel_futures=True)
        return super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = BoxSpawner()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
