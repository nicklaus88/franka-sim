"""MoveIt approach followed by reactive OpenCV pose-based velocity tracking."""
import copy
import json
import time
import numpy as np
import pinocchio as pin
import rclpy
from rclpy.action import ActionClient
from control_msgs.action import FollowJointTrajectory
from controller_manager_msgs.srv import SwitchController
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray, String
from std_srvs.srv import Trigger
from moveit_msgs.msg import RobotState
from moveit_msgs.srv import GetPositionIK
from moveit_msgs.msg import MoveItErrorCodes
from gz.transport13 import Node as GzNode
from gz.msgs10.double_pb2 import Double
from .pickup_planner import PickupPlanner, ARM


def resolved_velocity(jacobian, velocity, damping=.02):
    """Damped least squares, world-aligned TCP translation; returns seven rates."""
    return jacobian.T @ np.linalg.solve(jacobian @ jacobian.T + damping**2*np.eye(3), velocity)


def tracking_rates(full_jacobian, rotation, velocity):
    """Translation task with a projected secondary downwards orientation task."""
    jac=full_jacobian[:3]
    rates=resolved_velocity(jac,velocity)
    null=np.eye(7)-np.linalg.pinv(jac)@jac
    angular=full_jacobian[3:]
    rotation_error=pin.log3(np.diag([1.,-1.,-1.])@rotation.T)
    rates+=null@resolved_velocity(angular@null,4.*rotation_error-angular@rates)
    return rates,rotation_error


class ConveyorTracker(PickupPlanner):
    def __init__(self):
        super().__init__()
        self.timer.cancel()
        for key,value in dict(robot_description='',clearance=.15,position_gain=5.,
                              maximum_measurement_age=.25,belt_speed=.1,tracking_end_x=.24,
                              tracking_min_x=-1.4,tracking_start_x=0.,workspace_step=.025,
                              entry_lead=.02,result_path='/tmp/conveyor_tracking.json').items():
            self.declare_parameter(key,value)
        for key in ('clearance','position_gain','maximum_measurement_age','belt_speed','tracking_end_x','tracking_min_x','tracking_start_x','workspace_step','entry_lead'):
            if not np.isfinite(self.p(key)):
                raise ValueError(f'{key} must be finite')
        if self.p('clearance')<.15 or self.p('position_gain')<=0 or not 0<self.p('maximum_measurement_age')<=.5:
            raise ValueError('Require clearance >= .15, positive gain, measurement age in (0,.5]')
        if not 0<self.p('belt_speed')<=.2 or self.p('tracking_min_x')>=self.p('tracking_end_x'):
            raise ValueError('Require belt speed in (0,.2] and ordered workspace bounds')
        if not self.p('tracking_min_x')<self.p('tracking_start_x')<self.p('tracking_end_x'):
            raise ValueError('tracking_start_x must be inside the tracking workspace')
        if not .005<=self.p('workspace_step')<=.1 or not .005<=self.p('entry_lead')<=.03:
            raise ValueError('workspace_step must be [.005,.1], entry_lead [.005,.03] m')
        self.entry_x=None
        self.model=pin.buildModelFromXML(self.p('robot_description'))
        self.data=self.model.createData()
        self.tcp=self.model.getFrameId('fr3_hand_tcp')
        self.indices=[self.model.joints[self.model.getJointId(j)].idx_v for j in ARM]
        self.measurement=None
        self.tracking=False
        self.switched=False
        self.stop_requested=False
        self.samples=[]
        self.action=ActionClient(self,FollowJointTrajectory,'/fr3_arm_controller/follow_joint_trajectory')
        self.service_clients['switch']=self.create_client(SwitchController,'/controller_manager/switch_controller')
        self.command=self.create_publisher(Float64MultiArray,'/conveyor_velocity_controller/commands',1)
        self.measurement_pub=self.create_publisher(Odometry,'/conveyor_tracking/camera_measurement',10)
        self.tracking_status=self.create_publisher(String,'/conveyor_tracking/status',10)
        self.create_service(Trigger,'/conveyor_tracking/stop',self.stop_tracking)
        self.gz=GzNode()
        self.belt=self.gz.advertise('/conveyor/cmd_vel',Double)
        self.control_timer=self.create_timer(.01,self.control)
        self.timer=self.create_timer(.25,self.begin)

    def report(self,data):
        if not self.context.ok():
            return
        self.get_logger().info(json.dumps(data))
        if hasattr(self,'tracking_status'):
            self.tracking_status.publish(String(data=json.dumps(data)))

    def on_pose(self,msg):
        """Only camera measurements drive approach, entry gate and tracking."""
        if msg.header.frame_id != 'world':
            return
        p,q=msg.pose.position,msg.pose.orientation
        position=np.array([p.x,p.y,p.z])
        quaternion=np.array([q.x,q.y,q.z,q.w])
        if not np.all(np.isfinite(position)) or not np.all(np.isfinite(quaternion)) or abs(np.linalg.norm(quaternion)-1.)>.01:
            return
        with self.lock:
            self.pose,self.pose_seen=msg,time.monotonic()
            self.measurement=(msg.header.stamp.sec+msg.header.stamp.nanosec*1e-9,
                              position,np.zeros(3),self.pose_seen,quaternion)

    def stop_tracking(self,request,response):
        self.stop_requested=True
        response.success=True
        response.message='Stopping belt and tracking; restoring position controller'
        return response

    def begin(self):
        with self.lock:
            measurement=self.measurement
        age=self.get_clock().now().nanoseconds*1e-9-measurement[0] if measurement else float('inf')
        if not self.auto_started and measurement and 0<=age<=self.p('maximum_measurement_age') and time.monotonic()-measurement[3]<.5 and self.ready():
            self.auto_started=True
            self.pool.submit(self.run)

    def ready(self):
        return (self.joints is not None and time.monotonic()-self.joints_seen<1 and
                all(c.service_is_ready() for c in self.service_clients.values()) and
                self.action.server_is_ready())

    def trigger(self,request,response):
        response.success=False
        response.message='Tracking starts once automatically; use /conveyor_tracking/stop to stop'
        return response

    def state(self,joints):
        state=RobotState()
        state.joint_state=copy.deepcopy(joints)
        return state

    def wait_future(self,future,timeout=120):
        deadline=time.monotonic()+timeout
        while not future.done():
            if time.monotonic()>deadline or self.stopping.is_set() or self.stop_requested:
                raise RuntimeError('Action timeout or shutdown')
            time.sleep(.01)
        return future.result()

    def switch(self,tracking):
        request=SwitchController.Request(strictness=SwitchController.Request.STRICT,activate_asap=True)
        request.timeout.sec=5
        request.activate_controllers=['conveyor_velocity_controller' if tracking else 'fr3_arm_controller']
        request.deactivate_controllers=['fr3_arm_controller' if tracking else 'conveyor_velocity_controller']
        response=self.call('switch',request)
        if not response.ok:
            raise RuntimeError('Controller handoff failed: '+response.message)
        self.switched=tracking

    def workspace_entry(self,start,target,box_x):
        """Search upstream first, using collision-aware IK and joint/rate margins.

        This samples the current belt corridor, not the robot's entire workspace.
        The TCP waits slightly downstream so entry does not depend on reaching it.
        """
        first=max(box_x,self.p('tracking_min_x')+self.p('workspace_step'))
        last=self.p('tracking_start_x')
        xs=list(np.arange(first,last,self.p('workspace_step')))+[last]
        self.report({'status':'searching_workspace','from_x':first,'to_x':last})
        for x in xs:
            if self.stop_requested or self.stopping.is_set():
                raise RuntimeError('Workspace search cancelled')
            candidate=copy.deepcopy(target)
            candidate.pose.position.x=float(x)
            seeds=start
            goals=[]
            for offset in (0.,self.p('entry_lead'),.06):
                candidate.pose.position.x=float(x+offset)
                request=GetPositionIK.Request()
                request.ik_request.group_name='fr3_arm'
                request.ik_request.ik_link_name='fr3_hand_tcp'
                request.ik_request.robot_state=seeds
                request.ik_request.pose_stamped=candidate
                request.ik_request.avoid_collisions=True
                request.ik_request.timeout.nanosec=100000000
                response=self.call('ik',request)
                if response.error_code.val!=MoveItErrorCodes.SUCCESS:
                    break
                seeds=response.solution
                values=dict(zip(seeds.joint_state.name,seeds.joint_state.position))
                goal=[values[j] for j in ARM]
                position,jac,q=self.kinematics(seeds.joint_state)
                indices=np.array(self.indices)
                if (np.any(q[indices]<self.model.lowerPositionLimit[indices]+.12) or
                    np.any(q[indices]>self.model.upperPositionLimit[indices]-.12)):
                    break
                rates,_=tracking_rates(jac,self.data.oMf[self.tcp].rotation,
                                       np.array([self.p('belt_speed'),0.,0.]))
                if np.max(np.abs(rates))>1. or np.linalg.norm(jac[:3]@rates-[self.p('belt_speed'),0.,0.])>.01:
                    break
                goals.append(goal)
            if len(goals)==3:
                target.pose.position.x=float(x+self.p('entry_lead'))
                trajectory=self.plan_joints(start,goals[1])
                self.entry_x=float(x)
                self.report({'status':'workspace_entry_selected','entry_x':self.entry_x,
                             'waiting_tcp_x':target.pose.position.x,'resolution_m':self.p('workspace_step')})
                return trajectory
        raise RuntimeError('No collision-free workspace entry with joint/rate margins found')

    def run(self):
        result={'status':'failed'}
        handle=None
        try:
            self.belt.publish(Double(data=0.))
            time.sleep(.3)
            with self.lock:
                measurement=self.measurement
                joints=copy.deepcopy(self.joints)
            age=self.get_clock().now().nanoseconds*1e-9-measurement[0] if measurement else float('inf')
            if not 0<=age<=self.p('maximum_measurement_age') or time.monotonic()-measurement[3]>.5:
                raise RuntimeError('Stale camera pose before approach')
            initial_box=measurement[1].tolist()
            pose=PoseStamped()
            pose.header.frame_id='world'
            pose.pose.position.x,pose.pose.position.y,pose.pose.position.z=map(float,measurement[1])
            pose.pose.orientation.x,pose.pose.orientation.y,pose.pose.orientation.z,pose.pose.orientation.w=map(float,measurement[4])
            if abs(pose.pose.position.y-self.p('belt_y'))>.005:
                raise RuntimeError('Initial cube must be on conveyor centerline')
            if pose.pose.position.x>self.p('tracking_start_x'):
                raise RuntimeError('Initial cube must be upstream of tracking_start_x')
            self.install_scene(pose)
            target=copy.deepcopy(pose)
            target.pose.position.x=self.p('tracking_start_x')
            target.pose.position.y=self.p('belt_y')
            target.pose.position.z+=self.p('box_size')/2+self.p('clearance')
            target.pose.orientation.x=1.
            target.pose.orientation.y=target.pose.orientation.z=target.pose.orientation.w=0.
            start=self.state(joints)
            trajectory=self.workspace_entry(start,target,pose.pose.position.x)
            self.report({'status':'approaching','target':[target.pose.position.x,target.pose.position.y,target.pose.position.z]})
            handle=self.wait_future(self.action.send_goal_async(FollowJointTrajectory.Goal(trajectory=trajectory.joint_trajectory)))
            if not handle.accepted:
                raise RuntimeError('Initial MoveIt trajectory rejected')
            response=self.wait_future(handle.get_result_async())
            if response.result.error_code!=0:
                raise RuntimeError('Initial approach failed: '+response.result.error_string)
            if self.stop_requested:
                raise RuntimeError('Approach cancelled')
            self.report({'status':'waiting_for_box','entry_x':self.entry_x})
            self.belt.publish(Double(data=float(self.p('belt_speed'))))
            # Hold the collision-checked entry pose with the position controller
            # while the box travels from the upstream end. Pauses do not advance
            # this gate: it depends on measured simulation state, not wall time.
            while not self.stopping.is_set() and not self.stop_requested:
                with self.lock:
                    current=self.measurement
                now=self.get_clock().now().nanoseconds*1e-9
                if current is None or now-current[0]>self.p('maximum_measurement_age') or time.monotonic()-current[3]>.5 or now-current[0]<-.02:
                    raise RuntimeError('Stale box state or clock reset while waiting')
                if abs(current[1][1]-self.p('belt_y'))>.02:
                    raise RuntimeError('Cube left the belt centerline while waiting')
                if current[1][0]>=self.entry_x:
                    if current[1][0]-self.entry_x>.02:
                        raise RuntimeError('Cube passed the entry pose before handoff')
                    break
                time.sleep(.01)
            if self.stop_requested or self.stopping.is_set():
                raise RuntimeError('Tracking cancelled while waiting for box')
            self.switch(True)
            self.tracking=True
            self.report({'status':'tracking','clearance_m':self.p('clearance')})
            self.belt.publish(Double(data=float(self.p('belt_speed'))))
            while self.tracking and not self.stopping.is_set():
                time.sleep(.02)
            result={'status':'stopped','reason':getattr(self,'stop_reason','requested')}
        except Exception as exc:
            result=({'status':'stopped','reason':'requested during approach'} if self.stop_requested else
                    {'status':'failed','error':str(exc)})
            if handle is not None:
                handle.cancel_goal_async()
        finally:
            self.tracking=False
            self.belt.publish(Double(data=0.))
            if self.context.ok():
                self.command.publish(Float64MultiArray(data=[0.]*7))
            if self.switched and self.context.ok():
                try:
                    self.switch(False)
                except Exception as exc:
                    result={'status':'failed','error':'Position controller restoration: '+str(exc)}
            result['feedback_source']='opencv_rgbd'
            result['control_law']='position_feedback_only'
            result['samples']=self.samples
            result['tracking_start_x']=self.entry_x
            result['waiting_tcp_x']=target.pose.position.x if 'target' in locals() else None
            result['clearance_m']=self.p('clearance')
            if 'initial_box' in locals():
                result['initial_box']=initial_box
            from pathlib import Path
            path=Path(self.p('result_path'))
            path.parent.mkdir(parents=True,exist_ok=True)
            temporary=path.with_suffix('.tmp')
            temporary.write_text(json.dumps(result,indent=2))
            temporary.replace(path)
            self.report({k:v for k,v in result.items() if k!='samples'})

    def kinematics(self,joints):
        values=dict(zip(joints.name,joints.position))
        q=pin.neutral(self.model)
        for name,value in values.items():
            jid=self.model.getJointId(name)
            if jid<self.model.njoints:
                q[self.model.joints[jid].idx_q]=value
        pin.forwardKinematics(self.model,self.data,q)
        pin.updateFramePlacements(self.model,self.data)
        jac=pin.computeFrameJacobian(self.model,self.data,q,self.tcp,pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)
        return self.data.oMf[self.tcp].translation.copy(),jac[:,self.indices].copy(),q

    def control(self):
        if not self.tracking:
            return
        with self.lock:
            measurement=self.measurement
            joints=copy.deepcopy(self.joints)
            joint_age=time.monotonic()-self.joints_seen
        now=self.get_clock().now().nanoseconds*1e-9
        age=now-measurement[0] if measurement else 999.
        reason=None
        if self.stop_requested:
            reason='requested'
        elif measurement is None or age<-.02 or age>self.p('maximum_measurement_age') or time.monotonic()-measurement[3]>.5 or joint_age>.3:
            reason='stale state or clock reset'
        elif abs(measurement[1][1]-self.p('belt_y'))>.02 or abs(measurement[1][2]-self.p('belt_top')-self.p('box_size')/2)>.005:
            reason='cube left the validated belt corridor'
        elif not self.p('tracking_min_x')<measurement[1][0]<self.p('tracking_end_x'):
            reason='tracking workspace boundary'
        if reason:
            self.stop_reason=reason
            self.tracking=False
            self.command.publish(Float64MultiArray(data=[0.]*7))
            return
        try:
            position,full_jac,q=self.kinematics(joints)
            # Reactive position servo: use the last image pose unchanged.
            # No prediction, latency extrapolation, velocity or force feedforward.
            target=measurement[1].copy()
            cube_rotation=pin.Quaternion(measurement[4]).matrix()
            target[2]+=self.p('box_size')/2*np.abs(cube_rotation[2]).sum()+self.p('clearance')
            error=target-position
            velocity=self.p('position_gain')*error
            speed=np.linalg.norm(velocity)
            velocity*=min(1.,.25/max(speed,1e-9))
            rates,rotation_error=tracking_rates(full_jac,self.data.oMf[self.tcp].rotation,velocity)
            rates*=min(1.,1.5/max(np.max(np.abs(rates)),1e-9))
            for index,rate in zip(self.indices,rates):
                if q[index]<self.model.lowerPositionLimit[index]+.08 and rate<0 or q[index]>self.model.upperPositionLimit[index]-.08 and rate>0:
                    raise RuntimeError('Joint limit margin reached')
            if not np.all(np.isfinite(rates)) or np.linalg.norm(error)>.05:
                raise RuntimeError('Tracking error or invalid joint command')
            self.command.publish(Float64MultiArray(data=rates.tolist()))
            msg=Odometry()
            msg.header.frame_id='world'
            msg.child_frame_id='box_pickup/base_link'
            msg.header.stamp.sec=int(measurement[0])
            msg.header.stamp.nanosec=int((measurement[0]%1)*1e9)
            msg.pose.pose.position.x,msg.pose.pose.position.y,msg.pose.pose.position.z=map(float,measurement[1])
            msg.pose.pose.orientation.x,msg.pose.pose.orientation.y,msg.pose.pose.orientation.z,msg.pose.pose.orientation.w=map(float,measurement[4])
            # Pose-only measurement; no estimated velocity is provided.
            msg.pose.covariance[0]=msg.pose.covariance[7]=msg.pose.covariance[14]=.005**2
            self.measurement_pub.publish(msg)
            if not self.samples or now-self.samples[-1]['time']>=.05:
                self.samples.append(dict(time=now,box=measurement[1].tolist(),tcp=position.tolist(),measurement_stamp=measurement[0],measurement_age=age,feedback_source='opencv_rgbd',
                                         joint_velocity=rates.tolist(),orientation_error_rad=float(np.linalg.norm(rotation_error))))
        except Exception as exc:
            self.stop_reason=str(exc)
            self.tracking=False
            self.command.publish(Float64MultiArray(data=[0.]*7))


def main():
    rclpy.init()
    node=ConveyorTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.stopping.set()
        node.tracking=False
        node.belt.publish(Double(data=0.))
        if node.context.ok():
            node.command.publish(Float64MultiArray(data=[0.]*7))
        node.pool.shutdown(wait=True)
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
