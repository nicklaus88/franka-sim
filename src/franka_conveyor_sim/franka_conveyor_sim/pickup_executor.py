"""Execute the saved, collision-checked pickup stages with existing ros2_control."""
import copy
from concurrent.futures import ThreadPoolExecutor
import json
import math
from pathlib import Path
import threading
import time

from action_msgs.msg import GoalStatus
from builtin_interfaces.msg import Duration
from control_msgs.action import FollowJointTrajectory
from control_msgs.msg import JointTolerance
from controller_manager_msgs.srv import ListControllers
from geometry_msgs.msg import PoseStamped
from moveit_msgs.msg import (AttachedCollisionObject, CollisionObject, PlanningScene,
                             RobotState, RobotTrajectory)
from moveit_msgs.srv import ApplyPlanningScene, GetStateValidity
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile
from rosidl_runtime_py.set_message import set_message_fields
from sensor_msgs.msg import JointState
from std_msgs.msg import String
from std_srvs.srv import Trigger
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

from .pickup_planner import ARM, FINGERS

STAGES = ('neutral_to_pregrasp', 'pregrasp_to_grasp', 'close_fingers', 'lift_cube',
          'transfer_to_target', 'lower_to_release', 'release_fingers',
          'retreat_from_target', 'return_to_neutral')


def decode(cls, data):
    msg = cls()
    def restore(value):
        if isinstance(value,dict):
            return {key:(item.encode('latin1') if key == 'operation' and isinstance(item,str)
                         else restore(item)) for key,item in value.items()}
        if isinstance(value,list):
            return [restore(item) for item in value]
        return value
    # Jazzy serializes CollisionObject's byte operation as a one-character string.
    set_message_fields(msg, restore(data))
    return msg


def load_plan(path):
    plan = json.loads(Path(path).expanduser().read_text())
    if plan.get('status') != 'success' or list(plan.get('stages', {})) != list(STAGES):
        raise ValueError('Expected a successful, ordered nine-stage pickup plan')
    state = decode(RobotState, plan['trajectory_start'])
    if (len(state.joint_state.name) != len(state.joint_state.position) or
            len(set(state.joint_state.name)) != len(state.joint_state.name)):
        raise ValueError('Invalid initial robot state')
    values = dict(zip(state.joint_state.name, state.joint_state.position))
    if not all(j in values and math.isfinite(values[j]) for j in ARM+FINGERS):
        raise ValueError('Missing or nonfinite initial joint state')
    for name in STAGES:
        trajectory = decode(RobotTrajectory, plan['stages'][name]).joint_trajectory
        joints = FINGERS if name in ('close_fingers', 'release_fingers') else ARM
        if set(trajectory.joint_names) != set(joints) or len(trajectory.joint_names) != len(joints):
            raise ValueError(f'Unexpected joints in {name}')
        previous = -1.
        for point in trajectory.points:
            stamp = point.time_from_start.sec + point.time_from_start.nanosec/1e9
            if (len(point.positions) != len(joints) or
                    not all(math.isfinite(v) for v in point.positions) or
                    not math.isfinite(stamp) or stamp <= previous or stamp > 180):
                raise ValueError(f'Invalid trajectory points in {name}')
            for field in (point.velocities,point.accelerations,point.effort):
                if field and (len(field) != len(joints) or not all(math.isfinite(v) for v in field)):
                    raise ValueError(f'Invalid derivative/effort data in {name}')
            if joints == FINGERS and (any(not 0 <= v <= .04 for v in point.positions) or
                                      abs(point.positions[0]-point.positions[1]) > 1e-8):
                raise ValueError('Invalid or asymmetric finger opening')
            previous = stamp
        if not trajectory.points or previous <= 0:
            raise ValueError(f'Empty or zero-duration trajectory in {name}')
        if max(abs(values[j]-v) for j,v in zip(trajectory.joint_names, trajectory.points[0].positions)) > .01:
            raise ValueError(f'Discontinuous stage {name}')
        values.update(zip(trajectory.joint_names, trajectory.points[-1].positions))
        if name not in plan.get('stage_start_states', {}):
            raise ValueError(f'Missing collision state for {name}; regenerate the plan')
        stage = decode(RobotState,plan['stage_start_states'][name])
        start = dict(zip(stage.joint_state.name,stage.joint_state.position))
        first = dict(zip(trajectory.joint_names,trajectory.points[0].positions))
        if not all(j in start and math.isfinite(start[j]) and abs(start[j]-first[j]) <= .01 for j in joints):
            raise ValueError(f'Collision state disagrees with trajectory in {name}')
    return plan


class PickupExecutor(Node):
    def __init__(self):
        super().__init__('pickup_executor')
        for key, value in dict(plan_path='/tmp/franka_pickup_plan.json', auto_execute=False,
                               arm_controller='fr3_arm_controller', hand_controller='pickup_hand_controller',
                               controller_manager='/controller_manager', start_tolerance=.02,
                               pose_tolerance=.005, grasp_compression=.001,
                               maximum_plan_age=120., wall_timeout=300.,
                               result_path='/tmp/franka_pickup_execution.json').items():
            self.declare_parameter(key,value)
        if not self.get_parameter('use_sim_time').value:
            raise ValueError('Pickup executor requires use_sim_time:=true (simulation only)')
        if not 0 <= self.p('grasp_compression') <= .002:
            raise ValueError('grasp_compression must be in [0,.002] m per finger')
        self.lock = threading.Lock()
        self.joints = self.pose = None
        self.joint_seen = self.pose_seen = 0.
        self.busy = self.auto_started = False
        self.planning_status = None
        self.cancelled = threading.Event()
        self.stopping = threading.Event()
        self.active_goal = None
        self.scene_attached = False
        self.pool = ThreadPoolExecutor(max_workers=1)
        self.create_subscription(JointState,'/joint_states',self.on_joints,10)
        self.create_subscription(PoseStamped,'/pickup/box_pose',self.on_pose,10)
        self.actions = {key:ActionClient(self,FollowJointTrajectory,
                        '/'+self.p(key+'_controller').strip('/')+'/follow_joint_trajectory')
                        for key in ('arm','hand')}
        self.service_clients = dict(controllers=self.create_client(ListControllers,
                            self.p('controller_manager').rstrip('/')+'/list_controllers'),
                            apply=self.create_client(ApplyPlanningScene,'/apply_planning_scene'),
                            valid=self.create_client(GetStateValidity,'/check_state_validity'))
        qos = QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(String,'/pickup/planning_status',self.on_plan_status,qos)
        self.status = self.create_publisher(String,'/pickup/execution_status',qos)
        self.create_service(Trigger,'/pickup/execute',self.trigger)
        self.create_service(Trigger,'/pickup/cancel',self.cancel)
        self.timer = self.create_timer(.25,self.maybe_start)
        self.report(status='idle',execution_enabled=True)

    def p(self,name):
        return self.get_parameter(name).value

    def report(self,**data):
        self.last_status = data
        if self.context.ok():
            self.status.publish(String(data=json.dumps(data)))
            self.get_logger().info(json.dumps(data))

    def on_joints(self,msg):
        with self.lock:
            self.joints,self.joint_seen = msg,time.monotonic()

    def on_pose(self,msg):
        with self.lock:
            self.pose,self.pose_seen = msg,time.monotonic()

    def on_plan_status(self,msg):
        self.planning_status = json.loads(msg.data).get('status')

    def ready(self):
        return (self.planning_status == 'success' and all(a.server_is_ready() for a in self.actions.values()) and
                all(c.service_is_ready() for c in self.service_clients.values()) and
                self.joints is not None and self.pose is not None)

    def maybe_start(self):
        if self.p('auto_execute') and not self.auto_started and not self.busy and self.ready():
            try:
                load_plan(self.p('plan_path'))
            except (OSError,ValueError,KeyError,TypeError):
                return
            self.auto_started = True
            self.start()

    def start(self):
        self.busy = True
        self.cancelled.clear()
        self.report(status='executing',stage='preflight')
        self.pool.submit(self.run)

    def trigger(self,request,response):
        if self.busy:
            response.message = 'Execution already in progress'
        elif not self.ready():
            response.message = 'Waiting for controller actions, MoveIt, camera and joint states'
        else:
            self.start()
            response.success = True
            response.message = 'Execution queued; observe /pickup/execution_status'
        return response

    def cancel(self,request,response):
        self.cancelled.set()
        if self.active_goal is not None:
            self.active_goal.cancel_goal_async()
        response.success = True
        response.message = 'Cancellation requested; no later stages will be sent'
        return response

    def guard(self):
        if not self.context.ok() or self.stopping.is_set() or self.cancelled.is_set():
            raise RuntimeError('Execution cancelled')
        now = self.get_clock().now().nanoseconds
        if hasattr(self,'last_sim') and now < self.last_sim:
            raise RuntimeError('Simulation clock reset during execution')
        self.last_sim = now

    def wait(self,future,timeout=15.):
        deadline = time.monotonic()+timeout
        while not future.done():
            self.guard()
            if time.monotonic() > deadline:
                raise RuntimeError('Action/service timed out')
            self.stopping.wait(.02)
        self.guard()
        return future.result()

    def call(self,key,request):
        return self.wait(self.service_clients[key].call_async(request))

    def measured(self):
        with self.lock:
            msg,seen = copy.deepcopy(self.joints),self.joint_seen
        if msg is None or time.monotonic()-seen > 2:
            raise RuntimeError('Joint states are stale')
        values = dict(zip(msg.name,msg.position))
        # ros2_control exports only the driven finger; the URDF's 1:1 mimic
        # joint is derived by robot_state_publisher and may be absent here.
        if FINGERS[0] in values:
            values.setdefault(FINGERS[1],values[FINGERS[0]])
        return values

    def check_start(self,state):
        expected = dict(zip(state.joint_state.name,state.joint_state.position))
        measured = self.measured()
        for name in ARM+FINGERS:
            tolerance = .003 if name in FINGERS else self.p('start_tolerance')
            if name not in measured or not math.isfinite(measured[name]) or abs(measured[name]-expected[name]) > tolerance:
                raise RuntimeError(f'{name} differs from planned start; replan from the measured state')

    def send(self,trajectory,hand=False):
        self.guard()
        action = self.actions['hand' if hand else 'arm']
        goal = FollowJointTrajectory.Goal(trajectory=trajectory,goal_time_tolerance=Duration(sec=2))
        tolerance = .002 if hand else .02
        goal.goal_tolerance = [JointTolerance(name=j,position=tolerance) for j in trajectory.joint_names]
        goal.path_tolerance = [JointTolerance(name=j,position=.01 if hand else .1) for j in trajectory.joint_names]
        pending = action.send_goal_async(goal)
        try:
            handle = self.wait(pending)
        except Exception:
            def cancel_late(future):
                if not future.cancelled() and future.exception() is None and future.result().accepted and self.context.ok():
                    future.result().cancel_goal_async()
            pending.add_done_callback(cancel_late)
            raise
        if not handle.accepted:
            raise RuntimeError('Controller rejected trajectory')
        self.active_goal = handle
        result = self.wait(handle.get_result_async(),self.p('wall_timeout'))
        if result.status != GoalStatus.STATUS_SUCCEEDED or result.result.error_code != 0:
            raise RuntimeError(f'Controller failed: status={result.status}, {result.result.error_string}')
        self.active_goal = None

    def scene(self,state,world=None):
        scene = PlanningScene(is_diff=True)
        scene.robot_state.is_diff = True
        if state.attached_collision_objects:
            # MoveIt automatically removes the matching world body on attach.
            scene.robot_state.attached_collision_objects = copy.deepcopy(state.attached_collision_objects)
        elif self.scene_attached:
            scene.robot_state.attached_collision_objects = [AttachedCollisionObject(
                link_name='fr3_hand_tcp',object=CollisionObject(id='pickup_cube',operation=CollisionObject.REMOVE))]
        if world is not None:
            scene.world.collision_objects = [world]
        if not self.call('apply',ApplyPlanningScene.Request(scene=scene)).success:
            raise RuntimeError('Execution planning scene update failed')
        self.scene_attached = bool(state.attached_collision_objects)

    def validate_path(self,state,trajectory):
        state = copy.deepcopy(state)
        values = dict(zip(state.joint_state.name,state.joint_state.position))
        for point in trajectory.points:
            self.guard()
            values.update(zip(trajectory.joint_names,point.positions))
            state.joint_state.name,state.joint_state.position = list(values),list(values.values())
            # During close only, nominal finger/cube contact is handled by the
            # planner. All arm stages are rechecked against the live scene.
            result = self.call('valid',GetStateValidity.Request(robot_state=state,group_name=''))
            if not result.valid:
                contacts = [(c.contact_body_1,c.contact_body_2) for c in result.contacts]
                raise RuntimeError(f'Live scene invalidates trajectory: {contacts}')

    def run(self):
        completed = []
        self.last_sim = self.get_clock().now().nanoseconds
        try:
            plan = load_plan(self.p('plan_path'))
            controllers = {c.name:c.state for c in self.call('controllers',ListControllers.Request()).controller}
            if any(controllers.get(self.p(key+'_controller')) != 'active' for key in ('arm','hand')):
                raise RuntimeError('Arm and hand trajectory controllers must both be active')
            initial = decode(RobotState,plan['trajectory_start'])
            measured = self.measured()
            expected = dict(zip(initial.joint_state.name,initial.joint_state.position))
            if any(not math.isfinite(measured.get(j,float('inf'))) or
                   abs(measured.get(j,float('inf'))-expected[j]) > self.p('start_tolerance') for j in ARM):
                raise RuntimeError('Arm is not at planned neutral start; return/replan before execution')
            with self.lock:
                observed,seen = copy.deepcopy(self.pose),self.pose_seen
            source = decode(PoseStamped,plan['box_pose'])
            age = (self.get_clock().now()-rclpy.time.Time.from_msg(source.header.stamp)).nanoseconds/1e9
            if not 0 <= age <= self.p('maximum_plan_age'):
                raise RuntimeError('Plan is stale or simulation has reset; replan')
            observed_age = (self.get_clock().now()-rclpy.time.Time.from_msg(observed.header.stamp)).nanoseconds/1e9
            if (time.monotonic()-seen > 2 or observed.header.frame_id != 'world' or
                    not 0 <= observed_age <= 2):
                raise RuntimeError('No fresh world-frame cube estimate')
            a,b = observed.pose.position,source.pose.position
            qa,qb = observed.pose.orientation,source.pose.orientation
            yaw_error = (2*math.atan2(qa.z,qa.w)-2*math.atan2(qb.z,qb.w)+math.pi/4) % (math.pi/2)-math.pi/4
            if (not all(math.isfinite(v) for v in (a.x,a.y,a.z,b.x,b.y,b.z,yaw_error)) or
                    abs(yaw_error) > .05 or math.dist((a.x,a.y,a.z),(b.x,b.y,b.z)) > self.p('pose_tolerance')):
                raise RuntimeError('Cube moved since planning; replan')
            # Initialize the hand without moving the arm; the mimic finger is
            # controlled by Gazebo, never by a second competing controller.
            opening = JointTrajectory(joint_names=[FINGERS[0]],points=[
                JointTrajectoryPoint(positions=[float(measured[FINGERS[0]])],time_from_start=Duration()),
                JointTrajectoryPoint(positions=[.04],time_from_start=Duration(sec=2))])
            self.send(opening,hand=True)
            for name in STAGES:
                self.report(status='executing',stage=name,completed=completed)
                state = decode(RobotState,plan['stage_start_states'][name])
                self.check_start(state)
                trajectory = decode(RobotTrajectory,plan['stages'][name]).joint_trajectory
                trajectory.header.stamp.sec = trajectory.header.stamp.nanosec = 0
                if name in ('close_fingers','release_fingers'):
                    trajectory.joint_names = [FINGERS[0]]
                    for point in trajectory.points:
                        point.positions = [point.positions[0]]
                        point.velocities = point.accelerations = point.effort = []
                        if name == 'close_fingers':
                            fraction = (point.time_from_start.sec+point.time_from_start.nanosec/1e9)/(
                                trajectory.points[-1].time_from_start.sec+trajectory.points[-1].time_from_start.nanosec/1e9)
                            point.positions[0] -= self.p('grasp_compression')*fraction
                    self.send(trajectory,hand=True)
                else:
                    world = None
                    if name == 'retreat_from_target':
                        placed = decode(PoseStamped,plan['placed_cube'])
                        carried = decode(RobotState,plan['stage_start_states']['lift_cube']).attached_collision_objects[0].object
                        world = CollisionObject(id='pickup_cube',header=placed.header,
                            primitives=carried.primitives,primitive_poses=[placed.pose],operation=CollisionObject.ADD)
                    self.scene(state,world)
                    self.validate_path(state,trajectory)
                    self.send(trajectory)
                completed.append(name)
            self.check_start(initial)
            self.report(status='success',completed=completed,physical_cube_placement_verified=False)
        except Exception as exc:
            if self.active_goal is not None and self.context.ok():
                future = self.active_goal.cancel_goal_async()
                # Cancellation is asynchronous; report outcome rather than opening a held cube.
                deadline = time.monotonic()+3
                while not future.done() and time.monotonic() < deadline and not self.stopping.is_set():
                    self.stopping.wait(.02)
                self.active_goal = None
            self.report(status='cancelled' if self.cancelled.is_set() else 'failed',reason=str(exc),completed=completed)
        finally:
            try:
                path = Path(self.p('result_path')).expanduser()
                path.parent.mkdir(parents=True,exist_ok=True)
                temporary = path.with_suffix(path.suffix+'.tmp')
                temporary.write_text(json.dumps(self.last_status,indent=2))
                temporary.replace(path)
            except OSError as exc:
                self.get_logger().error(f'Cannot save execution report: {exc}')
            self.busy = False

    def destroy_node(self):
        self.cancelled.set()
        self.stopping.set()
        if self.active_goal is not None and self.context.ok():
            self.active_goal.cancel_goal_async()
        self.pool.shutdown(wait=True,cancel_futures=True)
        return super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = PickupExecutor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()
