"""Plan only: neutral -> oriented pre-grasp -> vertical approach -> finger contact -> place -> neutral."""
from concurrent.futures import ThreadPoolExecutor
import copy
import json
import math
from pathlib import Path
import threading
import time

from geometry_msgs.msg import Pose, PoseStamped
from moveit_msgs.msg import (AllowedCollisionEntry, AttachedCollisionObject, CollisionObject, Constraints,
                             DisplayTrajectory, JointConstraint, MoveItErrorCodes,
                             PlanningScene, PlanningSceneComponents, RobotState, RobotTrajectory)
from moveit_msgs.srv import (ApplyPlanningScene, GetCartesianPath, GetMotionPlan,
                             GetPlanningScene, GetPositionIK, GetStateValidity)
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, DurabilityPolicy
from rosidl_runtime_py.convert import message_to_ordereddict
from sensor_msgs.msg import JointState
from shape_msgs.msg import SolidPrimitive
from std_msgs.msg import String
from std_srvs.srv import Trigger
from visualization_msgs.msg import Marker, MarkerArray
from trajectory_msgs.msg import JointTrajectoryPoint
from builtin_interfaces.msg import Duration

from .pickup_geometry import grasp_targets, rotation_matrix

ARM = [f'fr3_joint{i}' for i in range(1, 8)]
FINGERS = ['fr3_finger_joint1', 'fr3_finger_joint2']
HOME = [0., -math.pi/4, 0., -3*math.pi/4, 0., math.pi/2, math.pi/4]


class PickupPlanner(Node):
    def __init__(self):
        super().__init__('pickup_planner')
        defaults = dict(box_size=.06, belt_top=.45, belt_y=.5, upstream_extension=1.,
                        goal_table_x=-.55, goal_table_y=.15, goal_table_top=.35,
                        pregrasp_clearance=.12, grasp_insertion=.02,
                        planning_time=5., speed_scaling=.1, auto_plan=True,
                        output_path='/tmp/franka_pickup_plan.json',
                        maximum_pose_age=1., home_joints=HOME, closure_duration=2.,
                        lift_clearance=.15, drop_height=.01)
        for key, val in defaults.items():
            self.declare_parameter(key,val)
        if not 0 < self.p('speed_scaling') <= .2:
            raise ValueError('speed_scaling must be in (0,.2]')
        self.lock = threading.Lock()
        self.pose = self.joints = None
        self.pose_seen = self.joints_seen = 0.
        self.busy = False
        self.execution_active = False
        self.auto_started = False
        self.stopping = threading.Event()
        self.pool = ThreadPoolExecutor(max_workers=1)
        self.create_subscription(PoseStamped,'/pickup/box_pose',self.on_pose,10)
        self.create_subscription(JointState,'/joint_states',self.on_joints,10)
        self.service_clients = {
            'plan': self.create_client(GetMotionPlan,'/plan_kinematic_path'),
            'ik': self.create_client(GetPositionIK,'/compute_ik'),
            'cartesian': self.create_client(GetCartesianPath,'/compute_cartesian_path'),
            'apply': self.create_client(ApplyPlanningScene,'/apply_planning_scene'),
            'scene': self.create_client(GetPlanningScene,'/get_planning_scene'),
            'valid': self.create_client(GetStateValidity,'/check_state_validity'),
        }
        qos = QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(String,'/pickup/execution_status',self.on_execution,qos)
        self.display = self.create_publisher(DisplayTrajectory,'/pickup/display_trajectory',qos)
        self.targets = self.create_publisher(MarkerArray,'/pickup/targets',qos)
        self.pregrasp_pub = self.create_publisher(PoseStamped,'/pickup/pregrasp_pose',qos)
        self.grasp_pub = self.create_publisher(PoseStamped,'/pickup/grasp_pose',qos)
        self.status = self.create_publisher(String,'/pickup/planning_status',qos)
        self.create_service(Trigger,'/pickup/plan',self.trigger)
        self.timer = self.create_timer(.25,self.maybe_start)
        self.report(dict(status='waiting',execution_enabled=False))

    def on_execution(self,msg):
        self.execution_active = json.loads(msg.data).get('status') == 'executing'

    def p(self,key):
        return self.get_parameter(key).value

    def on_pose(self,msg):
        with self.lock:
            self.pose,self.pose_seen = msg,time.monotonic()

    def on_joints(self,msg):
        with self.lock:
            self.joints,self.joints_seen = msg,time.monotonic()

    def ready(self):
        with self.lock:
            return (not self.execution_active and self.pose is not None and self.joints is not None and
                    time.monotonic()-self.pose_seen < 2 and time.monotonic()-self.joints_seen < 2 and
                    all(c.service_is_ready() for c in self.service_clients.values()))

    def maybe_start(self):
        if self.p('auto_plan') and not self.auto_started and self.ready():
            self.auto_started = True
            self.start()

    def trigger(self,request,response):
        if self.busy or self.execution_active:
            response.message = 'Planning is already in progress'
        elif not self.ready():
            response.message = 'Waiting for fresh vision, joint states and MoveIt services'
        else:
            self.start()
            response.success = True
            response.message = 'Planning queued; observe /pickup/planning_status and output JSON'
        return response

    def start(self):
        self.busy = True
        self.pool.submit(self.run)

    def report(self,data):
        if not self.context.ok():
            return
        self.status.publish(String(data=json.dumps(data)))
        self.get_logger().info(json.dumps(data))

    def call(self,key,request,timeout=15.):
        if self.stopping.is_set():
            raise RuntimeError('Planner stopping')
        future = self.service_clients[key].call_async(request)
        done = threading.Event()
        future.add_done_callback(lambda _: done.set())
        end = time.monotonic()+timeout
        while not done.wait(.1):
            if self.stopping.is_set() or time.monotonic() > end:
                future.cancel()
                raise RuntimeError(f'{key} service timed out or planner stopped')
        if future.exception():
            raise future.exception()
        return future.result()

    def state(self,joints):
        state = RobotState()
        values = dict(zip(joints.name,joints.position))
        if not all(j in values for j in ARM):
            raise ValueError('Incomplete arm joint state')
        # A planning assumption only; this node never commands the real/sim hand.
        values['fr3_finger_joint1'] = values['fr3_finger_joint2'] = .04
        state.joint_state.name = list(values)
        state.joint_state.position = list(map(float,values.values()))
        return state

    @staticmethod
    def endpoint(start,trajectory):
        result = copy.deepcopy(start)
        values = dict(zip(result.joint_state.name,result.joint_state.position))
        values.update(zip(trajectory.joint_trajectory.joint_names,trajectory.joint_trajectory.points[-1].positions))
        result.joint_state.name,result.joint_state.position = list(values),list(values.values())
        return result

    def validity(self,state):
        request = GetStateValidity.Request(robot_state=state,group_name='')
        result = self.call('valid',request)
        if not result.valid:
            pairs = [(c.contact_body_1,c.contact_body_2) for c in result.contacts]
            raise RuntimeError(f'Collision-invalid robot state: {pairs}')

    def install_scene(self,pose):
        scene = PlanningScene(is_diff=True)
        scene.robot_state.is_diff = True
        def box(name,xyz,dims,orientation=None):
            obj = CollisionObject(id=name,operation=CollisionObject.ADD)
            obj.header.frame_id = 'world'
            shape = SolidPrimitive(type=SolidPrimitive.BOX,dimensions=list(map(float,dims)))
            p = Pose()
            p.position.x,p.position.y,p.position.z = map(float,xyz)
            p.orientation.w = 1.
            if orientation is not None:
                p.orientation = orientation
            obj.primitives,obj.primitive_poses = [shape],[p]
            scene.world.collision_objects.append(obj)
        extension,top = self.p('upstream_extension'),self.p('belt_top')
        box('pickup_conveyor',(.6-extension/2,self.p('belt_y'),top-.05),(2+extension,.4,.1))
        gx,gy,gt = self.p('goal_table_x'),self.p('goal_table_y'),self.p('goal_table_top')
        box('pickup_goal_table',(gx,gy,gt-.025),(.5,.24,.05))
        for i,(x,y) in enumerate([(-.2,-.075),(-.2,.075),(.2,-.075),(.2,.075)]):
            box(f'pickup_goal_leg_{i}',(gx+x,gy+y,(gt-.05)/2),(.04,.04,gt-.05))
        box('pickup_floor',(0.,0.,-.025),(10.,10.,.05))
        size = self.p('box_size')
        p = pose.pose.position
        box('pickup_cube',(p.x,p.y,p.z),(size,size,size),pose.pose.orientation)
        # Preserve existing SRDF collision allowances and permit only base/floor
        # mounting contact. Cube, hand, belt and table collisions stay enabled.
        request = GetPlanningScene.Request()
        request.components.components = PlanningSceneComponents.ALLOWED_COLLISION_MATRIX
        matrix = self.call('scene',request).scene.allowed_collision_matrix
        for name in ('pickup_floor','fr3_link0'):
            if name not in matrix.entry_names:
                matrix.entry_names.append(name)
                for row in matrix.entry_values:
                    row.enabled.append(False)
                matrix.entry_values.append(AllowedCollisionEntry(enabled=[False]*len(matrix.entry_names)))
        a,b = matrix.entry_names.index('pickup_floor'),matrix.entry_names.index('fr3_link0')
        matrix.entry_values[a].enabled[b] = matrix.entry_values[b].enabled[a] = True
        scene.allowed_collision_matrix = matrix
        if not self.call('apply',ApplyPlanningScene.Request(scene=scene)).success:
            raise RuntimeError('Planning scene was not applied')
        return [o.id for o in scene.world.collision_objects]

    def plan_joints(self,start,goal):
        request = GetMotionPlan.Request()
        plan = request.motion_plan_request
        plan.group_name,plan.pipeline_id,plan.planner_id = 'fr3_arm','ompl','RRTConnectkConfigDefault'
        plan.start_state = start
        plan.allowed_planning_time = self.p('planning_time')
        plan.num_planning_attempts = 3
        plan.max_velocity_scaling_factor = plan.max_acceleration_scaling_factor = self.p('speed_scaling')
        plan.workspace_parameters.header.frame_id = 'world'
        plan.workspace_parameters.min_corner.x = plan.workspace_parameters.min_corner.y = -2.
        plan.workspace_parameters.min_corner.z = -.1
        plan.workspace_parameters.max_corner.x = plan.workspace_parameters.max_corner.y = 2.
        plan.workspace_parameters.max_corner.z = 2.
        constraints = Constraints()
        constraints.joint_constraints = [JointConstraint(joint_name=name,position=float(position),
            tolerance_above=.001,tolerance_below=.001,weight=1.) for name,position in zip(ARM,goal)]
        plan.goal_constraints = [constraints]
        response = self.call('plan',request,timeout=self.p('planning_time')*4+10).motion_plan_response
        if response.error_code.val != MoveItErrorCodes.SUCCESS or not response.trajectory.joint_trajectory.points:
            raise RuntimeError(f'Joint-space plan failed: {response.error_code.val}')
        return response.trajectory

    def ik(self,start,pose):
        request = GetPositionIK.Request()
        ik = request.ik_request
        ik.group_name,ik.ik_link_name = 'fr3_arm','fr3_hand_tcp'
        ik.robot_state,ik.pose_stamped,ik.avoid_collisions = start,pose,True
        ik.timeout.sec = 2
        result = self.call('ik',request)
        if result.error_code.val != MoveItErrorCodes.SUCCESS:
            raise RuntimeError(f'Pre-grasp IK failed: {result.error_code.val}')
        values = dict(zip(result.solution.joint_state.name,result.solution.joint_state.position))
        return [values[j] for j in ARM]

    def cartesian(self,start,pose):
        request = GetCartesianPath.Request()
        request.header.frame_id = 'world'
        request.start_state,request.group_name,request.link_name = start,'fr3_arm','fr3_hand_tcp'
        request.waypoints = [pose.pose]
        request.max_step,request.jump_threshold,request.revolute_jump_threshold = .005,5.,.3
        request.avoid_collisions = True
        request.max_velocity_scaling_factor = request.max_acceleration_scaling_factor = self.p('speed_scaling')
        result = self.call('cartesian',request)
        if result.error_code.val != MoveItErrorCodes.SUCCESS or result.fraction < .999:
            raise RuntimeError(f'Incomplete collision-checked approach: fraction={result.fraction}, error={result.error_code.val}')
        points = result.solution.joint_trajectory.points
        if len(points) < 2:
            raise RuntimeError('Cartesian trajectory is empty')
        for a,b in zip(points,points[1:]):
            if max(abs(x-y) for x,y in zip(a.positions,b.positions)) > .3:
                raise RuntimeError('Cartesian joint jump exceeds .3 rad')
        return result.solution,result.fraction

    def close_hand(self, start, opening=None):
        """Preview symmetric closing/opening, with collision checks and no force control."""
        duration = self.p('closure_duration')
        if not math.isfinite(duration) or duration <= 0:
            raise ValueError('closure_duration must be positive and finite')
        request = GetPlanningScene.Request()
        request.components.components = PlanningSceneComponents.ALLOWED_COLLISION_MATRIX
        original = self.call('scene', request).scene.allowed_collision_matrix
        matrix = copy.deepcopy(original)
        # Only fingertip/cube contact is allowed, only during closing checks.
        for name in ('pickup_cube', 'fr3_leftfinger', 'fr3_rightfinger'):
            if name not in matrix.entry_names:
                matrix.entry_names.append(name)
                for row in matrix.entry_values:
                    row.enabled.append(False)
                matrix.entry_values.append(AllowedCollisionEntry(enabled=[False]*len(matrix.entry_names)))
        a = matrix.entry_names.index('pickup_cube')
        for name in ('fr3_leftfinger', 'fr3_rightfinger'):
            b = matrix.entry_names.index(name)
            matrix.entry_values[a].enabled[b] = matrix.entry_values[b].enabled[a] = True
        def apply(acm):
            scene = PlanningScene(is_diff=True, allowed_collision_matrix=acm)
            scene.robot_state.is_diff = True
            if not self.call('apply', ApplyPlanningScene.Request(scene=scene)).success:
                raise RuntimeError('Could not update closing-contact allowances')
        trajectory = RobotTrajectory()
        trajectory.joint_trajectory.joint_names = FINGERS
        try:
            apply(matrix)
            for i in range(21):
                fraction = i/20
                # Smoothstep gives zero speed at either end of the preview.
                blend = fraction*fraction*(3-2*fraction)
                initial = dict(zip(start.joint_state.name, start.joint_state.position))[FINGERS[0]]
                target = self.p('box_size')/2 if opening is None else opening/2
                position = initial + (target-initial)*blend
                state = copy.deepcopy(start)
                values = dict(zip(state.joint_state.name, state.joint_state.position))
                values.update(dict.fromkeys(FINGERS, position))
                state.joint_state.name, state.joint_state.position = list(values), list(values.values())
                self.validity(state)
                ns = round(fraction*duration*1e9)
                trajectory.joint_trajectory.points.append(JointTrajectoryPoint(
                    positions=[position, position],
                    time_from_start=Duration(sec=ns//10**9, nanosec=ns%10**9)))
        finally:
            apply(original)
        return trajectory

    def cube_object(self, pose):
        obj = CollisionObject(id='pickup_cube', operation=CollisionObject.ADD)
        obj.header.frame_id = pose.header.frame_id
        obj.primitives = [SolidPrimitive(type=SolidPrimitive.BOX,
                                        dimensions=[self.p('box_size')]*3)]
        obj.primitive_poses = [copy.deepcopy(pose.pose)]
        return obj

    def world_cube(self, pose=None):
        scene = PlanningScene(is_diff=True)
        scene.robot_state.is_diff = True
        obj = self.cube_object(pose) if pose else CollisionObject(
            id='pickup_cube', operation=CollisionObject.REMOVE)
        obj.header.frame_id = 'world'
        scene.world.collision_objects = [obj]
        if not self.call('apply', ApplyPlanningScene.Request(scene=scene)).success:
            raise RuntimeError('Could not update world cube')

    def transport(self, start, box_pose, grasp_pose):
        """Carry the attached collision body, release above target, return neutral."""
        size = self.p('box_size')
        clearance, drop = self.p('lift_clearance'), self.p('drop_height')
        if not .05 <= clearance <= .3 or not .002 <= drop <= .03:
            raise ValueError('lift_clearance must be [.05,.3]; drop_height [.002,.03] m')
        q = grasp_pose.pose.orientation
        rotation = rotation_matrix([q.x,q.y,q.z,q.w])
        a,b = box_pose.pose.position,grasp_pose.pose.position
        local = rotation.T @ [a.x-b.x,a.y-b.y,a.z-b.z]
        local_pose = PoseStamped()
        local_pose.header.frame_id = 'fr3_hand_tcp'
        local_pose.pose.position.x,local_pose.pose.position.y,local_pose.pose.position.z = map(float,local)
        # The cube and top-down tool share yaw; Rx(pi) is its own inverse.
        from scipy.spatial.transform import Rotation
        bq = box_pose.pose.orientation
        relative = Rotation.from_matrix(rotation.T @ rotation_matrix([bq.x,bq.y,bq.z,bq.w])).as_quat()
        local_pose.pose.orientation.x,local_pose.pose.orientation.y,local_pose.pose.orientation.z,local_pose.pose.orientation.w = map(float,relative)
        attached = AttachedCollisionObject(link_name='fr3_hand_tcp', object=self.cube_object(local_pose),
            touch_links=['fr3_leftfinger','fr3_rightfinger'],weight=.2)
        self.world_cube()
        state = copy.deepcopy(start)
        state.attached_collision_objects = [attached]
        stages,starts,targets = [],{},{}
        def move(name, target, cartesian=True, goal_joints=None):
            nonlocal state
            starts[name] = copy.deepcopy(state)
            self.get_logger().info(f'Planning {name}')
            try:
                trajectory = (self.cartesian(state,target)[0] if cartesian else
                              self.plan_joints(state,goal_joints if goal_joints is not None else self.ik(state,target)))
            except Exception as exc:
                raise RuntimeError(f'{name}: {exc}') from exc
            state = self.endpoint(state,trajectory)
            self.validity(state)
            stages.append((name,trajectory))
            targets[name] = copy.deepcopy(target)
        lift = copy.deepcopy(grasp_pose)
        lift.pose.position.z += clearance
        move('lift_cube',lift)
        above = copy.deepcopy(lift)
        above.pose.position.x,above.pose.position.y = self.p('goal_table_x'),self.p('goal_table_y')
        above.pose.position.z = max(lift.pose.position.z,self.p('goal_table_top')+size-self.p('grasp_insertion')+clearance)
        release = copy.deepcopy(above)
        release.pose.position.z = self.p('goal_table_top')+size-self.p('grasp_insertion')+drop
        # Solve the low release pose first. A high-pose IK seeded from the
        # opposite side can choose an elbow branch that cannot descend.
        release_state = copy.deepcopy(state)
        values = dict(zip(state.joint_state.name,state.joint_state.position))
        values.update(zip(ARM,self.ik(state,release)))
        release_state.joint_state.position = [float(values[j]) for j in release_state.joint_state.name]
        ascent,_ = self.cartesian(release_state,above)
        above_state = self.endpoint(release_state,ascent)
        above_values = dict(zip(above_state.joint_state.name,above_state.joint_state.position))
        move('transfer_to_target',above,False,[above_values[j] for j in ARM])
        starts['lower_to_release'] = copy.deepcopy(state)
        # Recompute forward so MoveIt retimes descent with a zero terminal
        # velocity, as required by ros2_control's trajectory controller.
        descent,_ = self.cartesian(state,release)
        stages.append(('lower_to_release',descent))
        targets['lower_to_release'] = release
        state = self.endpoint(state,descent)
        self.validity(state)
        starts['release_fingers'] = copy.deepcopy(state)
        opening = self.close_hand(state,opening=.08)
        stages.append(('release_fingers',opening))
        state = self.endpoint(state,opening)
        state.attached_collision_objects = []
        placed = copy.deepcopy(box_pose)
        placed.pose.position.x,placed.pose.position.y = self.p('goal_table_x'),self.p('goal_table_y')
        placed.pose.position.z = self.p('goal_table_top')+size/2
        self.world_cube(placed)
        move('retreat_from_target',above)
        starts['return_to_neutral'] = copy.deepcopy(state)
        back = self.plan_joints(state,self.p('home_joints'))
        self.validity(self.endpoint(state,back))
        stages.append(('return_to_neutral',back))
        return stages,starts,targets,placed

    def target_markers(self,poses):
        markers = MarkerArray()
        for i,(name,pose,color) in enumerate(poses):
            marker = Marker()
            marker.header = pose.header
            marker.ns,marker.id,marker.type,marker.action = name,i,Marker.SPHERE,Marker.ADD
            marker.pose = pose.pose
            marker.scale.x = marker.scale.y = marker.scale.z = .025
            marker.color.r,marker.color.g,marker.color.b,marker.color.a = *color,1.
            markers.markers.append(marker)
        self.targets.publish(markers)
        self.pregrasp_pub.publish(poses[0][1])
        self.grasp_pub.publish(poses[1][1])

    def run(self):
        output = dict(status='planning',execution_enabled=False)
        self.report(output)
        try:
            with self.lock:
                pose,joints = copy.deepcopy(self.pose),copy.deepcopy(self.joints)
            if pose.header.frame_id != 'world':
                raise ValueError('Box pose must be in world frame')
            age = (self.get_clock().now()-rclpy.time.Time.from_msg(pose.header.stamp)).nanoseconds/1e9
            if not 0 <= age <= self.p('maximum_pose_age'):
                raise ValueError('Box estimate is stale')
            p,q = pose.pose.position,pose.pose.orientation
            if not all(math.isfinite(v) for v in (p.x,p.y,p.z,q.x,q.y,q.z,q.w)):
                raise ValueError('Nonfinite detection')
            base_yaw = 2*math.atan2(q.z,q.w)
            initial = self.state(joints)
            scene_ids = self.install_scene(pose)
            neutral = self.p('home_joints')
            if len(neutral) != 7 or not all(math.isfinite(v) for v in neutral):
                raise ValueError('home_joints must contain seven finite neutral positions')
            values = dict(zip(initial.joint_state.name, initial.joint_state.position))
            values.update(zip(ARM, neutral))
            initial.joint_state.position = [float(values[name]) for name in initial.joint_state.name]
            self.validity(initial)
            home_state = initial
            failures = []
            for offset in (0.,math.pi/2,math.pi,3*math.pi/2):
                try:
                    pre,grasp,quaternion = grasp_targets([p.x,p.y,p.z],base_yaw+offset,
                        self.p('box_size'),self.p('pregrasp_clearance'),self.p('grasp_insertion'))
                    def stamped(xyz):
                        result = PoseStamped()
                        result.header.frame_id = 'world'
                        result.header.stamp = pose.header.stamp
                        result.pose.position.x,result.pose.position.y,result.pose.position.z = xyz
                        result.pose.orientation.x,result.pose.orientation.y,result.pose.orientation.z,result.pose.orientation.w = quaternion
                        return result
                    pre_pose,grasp_pose = stamped(pre),stamped(grasp)
                    self.target_markers([('pregrasp',pre_pose,(0.,1.,0.)),('grasp',grasp_pose,(1.,.4,0.))])
                    pre_trajectory = self.plan_joints(home_state,self.ik(home_state,pre_pose))
                    pre_state = self.endpoint(home_state,pre_trajectory)
                    approach,fraction = self.cartesian(pre_state,grasp_pose)
                    self.validity(self.endpoint(pre_state,approach))
                    closure = self.close_hand(self.endpoint(pre_state,approach))
                    closed = self.endpoint(self.endpoint(pre_state,approach),closure)
                    extra,stage_starts,stage_targets,placed = self.transport(closed,pose,grasp_pose)
                    break
                except Exception as exc:
                    self.world_cube(pose)
                    failures.append(str(exc))
                    self.get_logger().warning(f'Yaw candidate {offset:.3f}: {exc}')
            else:
                raise RuntimeError('No feasible pick-place-return plan: '+'; '.join(failures))
            stages = [('neutral_to_pregrasp',pre_trajectory),('pregrasp_to_grasp',approach),('close_fingers',closure)]
            stages.extend(extra)
            stage_starts.update(neutral_to_pregrasp=initial, pregrasp_to_grasp=pre_state,
                                close_fingers=self.endpoint(pre_state,approach))
            self.target_markers([('pregrasp',pre_pose,(0.,1.,0.)),('grasp',grasp_pose,(1.,.4,0.)),
                                 ('release',stage_targets['lower_to_release'],(1.,1.,0.))])
            for name,trajectory in stages:
                names = trajectory.joint_trajectory.joint_names
                points = trajectory.joint_trajectory.points
                if set(names) != set(FINGERS if name in ('close_fingers','release_fingers') else ARM) or any(not math.isfinite(v) for point in points for v in point.positions):
                    raise RuntimeError(f'Invalid joint data in {name}')
                times = [point.time_from_start.sec+point.time_from_start.nanosec/1e9 for point in points]
                if any(b <= a for a,b in zip(times,times[1:])):
                    raise RuntimeError(f'Non-increasing trajectory times in {name}')
            self.display.publish(DisplayTrajectory(model_id='fr3',trajectory_start=initial,
                                                    trajectory=[t for _,t in stages]))
            output = dict(status='success',execution_enabled=False,source='OpenCV synchronized RGB-D + optical TF',
                          box_pose=message_to_ordereddict(pose),pregrasp=message_to_ordereddict(pre_pose),
                          grasp=message_to_ordereddict(grasp_pose),cartesian_fraction=fraction,
                          assumed_gripper_opening=.08,final_gripper_opening=.08,
                          terminal_condition='cube released over yellow target, open hand returned neutral',
                          drop_height=self.p('drop_height'),
                          release_model='open above target; assume upright settling for retreat; dynamics unverified',
                          placed_cube=message_to_ordereddict(placed),
                          stage_start_states={k:message_to_ordereddict(v) for k,v in stage_starts.items()},
                          stage_targets={k:message_to_ordereddict(v) for k,v in stage_targets.items()},
                          start_state_source='configured neutral, open hand',
                          gripper_commanded=False,collision_objects=scene_ids,
                          home_already_reached=max(abs(a-b) for a,b in zip(
                              [dict(zip(joints.name,joints.position))[j] for j in ARM],
                              self.p('home_joints'))) < .001,
                          trajectory_start=message_to_ordereddict(initial),
                          stages={name:message_to_ordereddict(t) for name,t in stages})
        except Exception as exc:
            output = dict(status='failed',reason=str(exc),execution_enabled=False)
        finally:
            # Planning is hypothetical: restore the sensed cube for the next run.
            try:
                if 'pose' in locals() and pose is not None:
                    self.world_cube(pose)
            except Exception as exc:
                output = dict(status='failed', reason=f'Scene restoration failed: {exc}', execution_enabled=False)
            try:
                path = Path(self.p('output_path')).expanduser()
                path.parent.mkdir(parents=True,exist_ok=True)
                temporary = path.with_suffix(path.suffix+'.tmp')
                temporary.write_text(json.dumps(output,indent=2))
                temporary.replace(path)
            except OSError as exc:
                output = dict(status='failed',reason=f'Cannot save planning result: {exc}',execution_enabled=False)
            finally:
                self.report({k:v for k,v in output.items() if k not in ('stages','trajectory_start','stage_start_states')})
                self.busy = False

    def destroy_node(self):
        self.stopping.set()
        self.timer.cancel()
        self.pool.shutdown(wait=True,cancel_futures=True)
        return super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = PickupPlanner()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
