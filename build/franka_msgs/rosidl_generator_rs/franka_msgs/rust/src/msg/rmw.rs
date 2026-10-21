#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__CollisionIndicators() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__msg__CollisionIndicators__init(msg: *mut CollisionIndicators) -> bool;
    fn franka_msgs__msg__CollisionIndicators__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CollisionIndicators>, size: usize) -> bool;
    fn franka_msgs__msg__CollisionIndicators__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CollisionIndicators>);
    fn franka_msgs__msg__CollisionIndicators__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CollisionIndicators>, out_seq: *mut rosidl_runtime_rs::Sequence<CollisionIndicators>) -> bool;
}

// Corresponds to franka_msgs__msg__CollisionIndicators
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Indicates which dimensions have an active contact/collision flag raised

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CollisionIndicators {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_linear_collision: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_angular_collision: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_linear_contact: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_angular_contact: geometry_msgs::msg::rmw::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_joint_collision: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_joint_contact: [f64; 7],

}



impl Default for CollisionIndicators {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__msg__CollisionIndicators__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__msg__CollisionIndicators__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CollisionIndicators {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__CollisionIndicators__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__CollisionIndicators__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__CollisionIndicators__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CollisionIndicators {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CollisionIndicators where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/msg/CollisionIndicators";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__CollisionIndicators() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__Elbow() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__msg__Elbow__init(msg: *mut Elbow) -> bool;
    fn franka_msgs__msg__Elbow__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Elbow>, size: usize) -> bool;
    fn franka_msgs__msg__Elbow__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Elbow>);
    fn franka_msgs__msg__Elbow__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Elbow>, out_seq: *mut rosidl_runtime_rs::Sequence<Elbow>) -> bool;
}

// Corresponds to franka_msgs__msg__Elbow
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// The state of the elbow

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Elbow {

    // This member is not documented.
    #[allow(missing_docs)]
    pub position: [f64; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub desired_position: [f64; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub commanded_position: [f64; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub commanded_velocity: [f64; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub commanded_acceleration: [f64; 2],

}



impl Default for Elbow {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__msg__Elbow__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__msg__Elbow__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Elbow {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__Elbow__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__Elbow__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__Elbow__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Elbow {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Elbow where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/msg/Elbow";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__Elbow() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__Errors() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__msg__Errors__init(msg: *mut Errors) -> bool;
    fn franka_msgs__msg__Errors__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Errors>, size: usize) -> bool;
    fn franka_msgs__msg__Errors__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Errors>);
    fn franka_msgs__msg__Errors__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Errors>, out_seq: *mut rosidl_runtime_rs::Sequence<Errors>) -> bool;
}

// Corresponds to franka_msgs__msg__Errors
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Errors {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_position_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_position_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub self_collision_avoidance_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_velocity_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_velocity_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub force_control_safety_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_reflex: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_reflex: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_goal_pose_deviation_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_path_pose_deviation_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_velocity_profile_safety_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_position_motion_generator_start_pose_invalid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_motion_generator_position_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_motion_generator_velocity_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_motion_generator_velocity_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_motion_generator_acceleration_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_position_motion_generator_start_pose_invalid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_elbow_limit_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_velocity_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_velocity_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_acceleration_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_elbow_sign_inconsistent: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_start_elbow_invalid: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_joint_position_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_joint_velocity_limits_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_joint_velocity_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_motion_generator_joint_acceleration_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_position_motion_generator_invalid_frame: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub force_controller_desired_force_tolerance_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub controller_torque_discontinuity: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_elbow_sign_inconsistent: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub communication_constraints_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub power_limit_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_p2p_insufficient_torque_for_planning: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_j_range_violation: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub instability_detected: bool,

}



impl Default for Errors {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__msg__Errors__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__msg__Errors__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Errors {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__Errors__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__Errors__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__Errors__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Errors {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Errors where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/msg/Errors";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__Errors() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__FrankaRobotState() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__msg__FrankaRobotState__init(msg: *mut FrankaRobotState) -> bool;
    fn franka_msgs__msg__FrankaRobotState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FrankaRobotState>, size: usize) -> bool;
    fn franka_msgs__msg__FrankaRobotState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FrankaRobotState>);
    fn franka_msgs__msg__FrankaRobotState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FrankaRobotState>, out_seq: *mut rosidl_runtime_rs::Sequence<FrankaRobotState>) -> bool;
}

// Corresponds to franka_msgs__msg__FrankaRobotState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Default parts of the message

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrankaRobotState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Indicates which dimensions have an active contact/collision flag raised
    pub collision_indicators: super::super::msg::rmw::CollisionIndicators,

    /// The state of the arm in joint space
    /// The joint state consisting out of position (q), velocity (dq) and effort (tau_J)
    pub measured_joint_state: sensor_msgs::msg::rmw::JointState,

    /// The desired joint state consisting out of position (q_d), velocity (dq_d) and effort (tau_J_d)
    pub desired_joint_state: sensor_msgs::msg::rmw::JointState,

    /// The measured motor state of the joints consisting out of position (theta) and velocity (dtheta)
    pub measured_joint_motor_state: sensor_msgs::msg::rmw::JointState,

    /// The desired joint acceleration
    pub ddq_d: [f64; 7],

    /// The derivative of the measured torque signal
    pub dtau_j: [f64; 7],

    /// Filtered external torque. The JointState consists out of effort (tau_ext_hat_filtered)
    pub tau_ext_hat_filtered: sensor_msgs::msg::rmw::JointState,

    /// The state of the elbow
    pub elbow: super::super::msg::rmw::Elbow,

    /// The active wrenches acting on the stiffness frame expressed relative to
    /// stiffness frame
    pub k_f_ext_hat_k: geometry_msgs::msg::rmw::WrenchStamped,

    /// base frame
    pub o_f_ext_hat_k: geometry_msgs::msg::rmw::WrenchStamped,

    /// The different inertias of the arm
    /// The end-effector inertia
    pub inertia_ee: geometry_msgs::msg::rmw::InertiaStamped,

    /// The load inertia
    pub inertia_load: geometry_msgs::msg::rmw::InertiaStamped,

    /// The total (end-effector + load) inertia
    pub inertia_total: geometry_msgs::msg::rmw::InertiaStamped,

    /// The poses describing the transformations between different frames of the arm
    /// Measured end-effector pose in base frame
    pub o_t_ee: geometry_msgs::msg::rmw::PoseStamped,

    /// Last desired end-effector pose of motion generation in base frame
    pub o_t_ee_d: geometry_msgs::msg::rmw::PoseStamped,

    /// Last commanded end-effector pose of motion generation in base frame
    pub o_t_ee_c: geometry_msgs::msg::rmw::PoseStamped,

    /// Flange to end-effector frame
    pub f_t_ee: geometry_msgs::msg::rmw::PoseStamped,

    /// End-effector to stiffness frame
    pub ee_t_k: geometry_msgs::msg::rmw::PoseStamped,

    /// Desired end effector twist in base frame
    pub o_dp_ee_d: geometry_msgs::msg::rmw::TwistStamped,

    /// Last commanded end effector twist in base frame
    pub o_dp_ee_c: geometry_msgs::msg::rmw::TwistStamped,

    /// Last commanded end effector acceleration in base frame
    pub o_ddp_ee_c: geometry_msgs::msg::rmw::AccelStamped,

    /// Additional information
    pub time: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub control_command_success_rate: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_errors: super::super::msg::rmw::Errors,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_motion_errors: super::super::msg::rmw::Errors,

    /// Translational acceleration data from the joint-mounted accelerometers,
    /// expressed in the "<prefix>link<i>_accelerometer_<side>" frame named in each header
    /// (joints 1 through 6, mounted on links 0 through 5; no accelerometer on joint 7)
    pub accelerometer_top: [geometry_msgs::msg::rmw::Vector3Stamped; 6],


    // This member is not documented.
    #[allow(missing_docs)]
    pub accelerometer_bottom: [geometry_msgs::msg::rmw::Vector3Stamped; 6],

}

impl FrankaRobotState {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_OTHER: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_IDLE: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_MOVE: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_GUIDING: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_REFLEX: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_USER_STOPPED: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_MODE_AUTOMATIC_ERROR_RECOVERY: u8 = 6;

}


impl Default for FrankaRobotState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__msg__FrankaRobotState__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__msg__FrankaRobotState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FrankaRobotState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__FrankaRobotState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__FrankaRobotState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__FrankaRobotState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FrankaRobotState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FrankaRobotState where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/msg/FrankaRobotState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__FrankaRobotState() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__GraspEpsilon() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__msg__GraspEpsilon__init(msg: *mut GraspEpsilon) -> bool;
    fn franka_msgs__msg__GraspEpsilon__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GraspEpsilon>, size: usize) -> bool;
    fn franka_msgs__msg__GraspEpsilon__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GraspEpsilon>);
    fn franka_msgs__msg__GraspEpsilon__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GraspEpsilon>, out_seq: *mut rosidl_runtime_rs::Sequence<GraspEpsilon>) -> bool;
}

// Corresponds to franka_msgs__msg__GraspEpsilon
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Maximum tolerated deviation when the actual grasped width
/// is smaller than the commanded grasp width. Unit:

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GraspEpsilon {

    // This member is not documented.
    #[allow(missing_docs)]
    pub inner: f64,

    /// Maximum tolerated deviation when the actual grasped width
    /// is larger than the commanded grasp width. Unit:
    pub outer: f64,

}



impl Default for GraspEpsilon {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__msg__GraspEpsilon__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__msg__GraspEpsilon__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GraspEpsilon {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__GraspEpsilon__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__GraspEpsilon__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__GraspEpsilon__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GraspEpsilon {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GraspEpsilon where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/msg/GraspEpsilon";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__GraspEpsilon() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__TargetStatus() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__msg__TargetStatus__init(msg: *mut TargetStatus) -> bool;
    fn franka_msgs__msg__TargetStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TargetStatus>, size: usize) -> bool;
    fn franka_msgs__msg__TargetStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TargetStatus>);
    fn franka_msgs__msg__TargetStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TargetStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<TargetStatus>) -> bool;
}

// Corresponds to franka_msgs__msg__TargetStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// The status of a motion action
/// IDLE: The robot is idle, no motion is being executed

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TargetStatus {
    /// The current status of the motion (one of the above states)
    pub status: u8,

}

impl TargetStatus {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const IDLE: u8 = 0;

    /// EXECUTING: The robot is currently executing the motion
    pub const EXECUTING: u8 = 1;

    /// TARGET_REACHED: The robot has reached the target position given two conditions:
    /// - the absolute difference between the current and goal joint positions is within the goal_tolerance
    /// - the joint velocities are below a small threshold
    pub const TARGET_REACHED: u8 = 2;

    /// ABORTED: The motion was aborted due to an error or external intervention
    pub const ABORTED: u8 = 3;

}


impl Default for TargetStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__msg__TargetStatus__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__msg__TargetStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TargetStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__TargetStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__TargetStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__msg__TargetStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TargetStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TargetStatus where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/msg/TargetStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__msg__TargetStatus() }
  }
}


