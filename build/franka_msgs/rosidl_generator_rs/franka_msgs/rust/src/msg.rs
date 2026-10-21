#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to franka_msgs__msg__CollisionIndicators
/// Indicates which dimensions have an active contact/collision flag raised

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CollisionIndicators {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_linear_collision: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_angular_collision: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_linear_contact: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_cartesian_angular_contact: geometry_msgs::msg::Vector3,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_joint_collision: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_joint_contact: [f64; 7],

}



impl Default for CollisionIndicators {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::CollisionIndicators::default())
  }
}

impl rosidl_runtime_rs::Message for CollisionIndicators {
  type RmwMsg = super::msg::rmw::CollisionIndicators;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_cartesian_linear_collision: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.is_cartesian_linear_collision)).into_owned(),
        is_cartesian_angular_collision: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.is_cartesian_angular_collision)).into_owned(),
        is_cartesian_linear_contact: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.is_cartesian_linear_contact)).into_owned(),
        is_cartesian_angular_contact: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.is_cartesian_angular_contact)).into_owned(),
        is_joint_collision: msg.is_joint_collision,
        is_joint_contact: msg.is_joint_contact,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_cartesian_linear_collision: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.is_cartesian_linear_collision)).into_owned(),
        is_cartesian_angular_collision: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.is_cartesian_angular_collision)).into_owned(),
        is_cartesian_linear_contact: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.is_cartesian_linear_contact)).into_owned(),
        is_cartesian_angular_contact: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.is_cartesian_angular_contact)).into_owned(),
        is_joint_collision: msg.is_joint_collision,
        is_joint_contact: msg.is_joint_contact,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_cartesian_linear_collision: geometry_msgs::msg::Vector3::from_rmw_message(msg.is_cartesian_linear_collision),
      is_cartesian_angular_collision: geometry_msgs::msg::Vector3::from_rmw_message(msg.is_cartesian_angular_collision),
      is_cartesian_linear_contact: geometry_msgs::msg::Vector3::from_rmw_message(msg.is_cartesian_linear_contact),
      is_cartesian_angular_contact: geometry_msgs::msg::Vector3::from_rmw_message(msg.is_cartesian_angular_contact),
      is_joint_collision: msg.is_joint_collision,
      is_joint_contact: msg.is_joint_contact,
    }
  }
}


// Corresponds to franka_msgs__msg__Elbow
/// The state of the elbow

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Elbow::default())
  }
}

impl rosidl_runtime_rs::Message for Elbow {
  type RmwMsg = super::msg::rmw::Elbow;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: msg.position,
        desired_position: msg.desired_position,
        commanded_position: msg.commanded_position,
        commanded_velocity: msg.commanded_velocity,
        commanded_acceleration: msg.commanded_acceleration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: msg.position,
        desired_position: msg.desired_position,
        commanded_position: msg.commanded_position,
        commanded_velocity: msg.commanded_velocity,
        commanded_acceleration: msg.commanded_acceleration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position: msg.position,
      desired_position: msg.desired_position,
      commanded_position: msg.commanded_position,
      commanded_velocity: msg.commanded_velocity,
      commanded_acceleration: msg.commanded_acceleration,
    }
  }
}


// Corresponds to franka_msgs__msg__Errors

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Errors::default())
  }
}

impl rosidl_runtime_rs::Message for Errors {
  type RmwMsg = super::msg::rmw::Errors;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_position_limits_violation: msg.joint_position_limits_violation,
        cartesian_position_limits_violation: msg.cartesian_position_limits_violation,
        self_collision_avoidance_violation: msg.self_collision_avoidance_violation,
        joint_velocity_violation: msg.joint_velocity_violation,
        cartesian_velocity_violation: msg.cartesian_velocity_violation,
        force_control_safety_violation: msg.force_control_safety_violation,
        joint_reflex: msg.joint_reflex,
        cartesian_reflex: msg.cartesian_reflex,
        max_goal_pose_deviation_violation: msg.max_goal_pose_deviation_violation,
        max_path_pose_deviation_violation: msg.max_path_pose_deviation_violation,
        cartesian_velocity_profile_safety_violation: msg.cartesian_velocity_profile_safety_violation,
        joint_position_motion_generator_start_pose_invalid: msg.joint_position_motion_generator_start_pose_invalid,
        joint_motion_generator_position_limits_violation: msg.joint_motion_generator_position_limits_violation,
        joint_motion_generator_velocity_limits_violation: msg.joint_motion_generator_velocity_limits_violation,
        joint_motion_generator_velocity_discontinuity: msg.joint_motion_generator_velocity_discontinuity,
        joint_motion_generator_acceleration_discontinuity: msg.joint_motion_generator_acceleration_discontinuity,
        cartesian_position_motion_generator_start_pose_invalid: msg.cartesian_position_motion_generator_start_pose_invalid,
        cartesian_motion_generator_elbow_limit_violation: msg.cartesian_motion_generator_elbow_limit_violation,
        cartesian_motion_generator_velocity_limits_violation: msg.cartesian_motion_generator_velocity_limits_violation,
        cartesian_motion_generator_velocity_discontinuity: msg.cartesian_motion_generator_velocity_discontinuity,
        cartesian_motion_generator_acceleration_discontinuity: msg.cartesian_motion_generator_acceleration_discontinuity,
        cartesian_motion_generator_elbow_sign_inconsistent: msg.cartesian_motion_generator_elbow_sign_inconsistent,
        cartesian_motion_generator_start_elbow_invalid: msg.cartesian_motion_generator_start_elbow_invalid,
        cartesian_motion_generator_joint_position_limits_violation: msg.cartesian_motion_generator_joint_position_limits_violation,
        cartesian_motion_generator_joint_velocity_limits_violation: msg.cartesian_motion_generator_joint_velocity_limits_violation,
        cartesian_motion_generator_joint_velocity_discontinuity: msg.cartesian_motion_generator_joint_velocity_discontinuity,
        cartesian_motion_generator_joint_acceleration_discontinuity: msg.cartesian_motion_generator_joint_acceleration_discontinuity,
        cartesian_position_motion_generator_invalid_frame: msg.cartesian_position_motion_generator_invalid_frame,
        force_controller_desired_force_tolerance_violation: msg.force_controller_desired_force_tolerance_violation,
        controller_torque_discontinuity: msg.controller_torque_discontinuity,
        start_elbow_sign_inconsistent: msg.start_elbow_sign_inconsistent,
        communication_constraints_violation: msg.communication_constraints_violation,
        power_limit_violation: msg.power_limit_violation,
        joint_p2p_insufficient_torque_for_planning: msg.joint_p2p_insufficient_torque_for_planning,
        tau_j_range_violation: msg.tau_j_range_violation,
        instability_detected: msg.instability_detected,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      joint_position_limits_violation: msg.joint_position_limits_violation,
      cartesian_position_limits_violation: msg.cartesian_position_limits_violation,
      self_collision_avoidance_violation: msg.self_collision_avoidance_violation,
      joint_velocity_violation: msg.joint_velocity_violation,
      cartesian_velocity_violation: msg.cartesian_velocity_violation,
      force_control_safety_violation: msg.force_control_safety_violation,
      joint_reflex: msg.joint_reflex,
      cartesian_reflex: msg.cartesian_reflex,
      max_goal_pose_deviation_violation: msg.max_goal_pose_deviation_violation,
      max_path_pose_deviation_violation: msg.max_path_pose_deviation_violation,
      cartesian_velocity_profile_safety_violation: msg.cartesian_velocity_profile_safety_violation,
      joint_position_motion_generator_start_pose_invalid: msg.joint_position_motion_generator_start_pose_invalid,
      joint_motion_generator_position_limits_violation: msg.joint_motion_generator_position_limits_violation,
      joint_motion_generator_velocity_limits_violation: msg.joint_motion_generator_velocity_limits_violation,
      joint_motion_generator_velocity_discontinuity: msg.joint_motion_generator_velocity_discontinuity,
      joint_motion_generator_acceleration_discontinuity: msg.joint_motion_generator_acceleration_discontinuity,
      cartesian_position_motion_generator_start_pose_invalid: msg.cartesian_position_motion_generator_start_pose_invalid,
      cartesian_motion_generator_elbow_limit_violation: msg.cartesian_motion_generator_elbow_limit_violation,
      cartesian_motion_generator_velocity_limits_violation: msg.cartesian_motion_generator_velocity_limits_violation,
      cartesian_motion_generator_velocity_discontinuity: msg.cartesian_motion_generator_velocity_discontinuity,
      cartesian_motion_generator_acceleration_discontinuity: msg.cartesian_motion_generator_acceleration_discontinuity,
      cartesian_motion_generator_elbow_sign_inconsistent: msg.cartesian_motion_generator_elbow_sign_inconsistent,
      cartesian_motion_generator_start_elbow_invalid: msg.cartesian_motion_generator_start_elbow_invalid,
      cartesian_motion_generator_joint_position_limits_violation: msg.cartesian_motion_generator_joint_position_limits_violation,
      cartesian_motion_generator_joint_velocity_limits_violation: msg.cartesian_motion_generator_joint_velocity_limits_violation,
      cartesian_motion_generator_joint_velocity_discontinuity: msg.cartesian_motion_generator_joint_velocity_discontinuity,
      cartesian_motion_generator_joint_acceleration_discontinuity: msg.cartesian_motion_generator_joint_acceleration_discontinuity,
      cartesian_position_motion_generator_invalid_frame: msg.cartesian_position_motion_generator_invalid_frame,
      force_controller_desired_force_tolerance_violation: msg.force_controller_desired_force_tolerance_violation,
      controller_torque_discontinuity: msg.controller_torque_discontinuity,
      start_elbow_sign_inconsistent: msg.start_elbow_sign_inconsistent,
      communication_constraints_violation: msg.communication_constraints_violation,
      power_limit_violation: msg.power_limit_violation,
      joint_p2p_insufficient_torque_for_planning: msg.joint_p2p_insufficient_torque_for_planning,
      tau_j_range_violation: msg.tau_j_range_violation,
      instability_detected: msg.instability_detected,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      joint_position_limits_violation: msg.joint_position_limits_violation,
      cartesian_position_limits_violation: msg.cartesian_position_limits_violation,
      self_collision_avoidance_violation: msg.self_collision_avoidance_violation,
      joint_velocity_violation: msg.joint_velocity_violation,
      cartesian_velocity_violation: msg.cartesian_velocity_violation,
      force_control_safety_violation: msg.force_control_safety_violation,
      joint_reflex: msg.joint_reflex,
      cartesian_reflex: msg.cartesian_reflex,
      max_goal_pose_deviation_violation: msg.max_goal_pose_deviation_violation,
      max_path_pose_deviation_violation: msg.max_path_pose_deviation_violation,
      cartesian_velocity_profile_safety_violation: msg.cartesian_velocity_profile_safety_violation,
      joint_position_motion_generator_start_pose_invalid: msg.joint_position_motion_generator_start_pose_invalid,
      joint_motion_generator_position_limits_violation: msg.joint_motion_generator_position_limits_violation,
      joint_motion_generator_velocity_limits_violation: msg.joint_motion_generator_velocity_limits_violation,
      joint_motion_generator_velocity_discontinuity: msg.joint_motion_generator_velocity_discontinuity,
      joint_motion_generator_acceleration_discontinuity: msg.joint_motion_generator_acceleration_discontinuity,
      cartesian_position_motion_generator_start_pose_invalid: msg.cartesian_position_motion_generator_start_pose_invalid,
      cartesian_motion_generator_elbow_limit_violation: msg.cartesian_motion_generator_elbow_limit_violation,
      cartesian_motion_generator_velocity_limits_violation: msg.cartesian_motion_generator_velocity_limits_violation,
      cartesian_motion_generator_velocity_discontinuity: msg.cartesian_motion_generator_velocity_discontinuity,
      cartesian_motion_generator_acceleration_discontinuity: msg.cartesian_motion_generator_acceleration_discontinuity,
      cartesian_motion_generator_elbow_sign_inconsistent: msg.cartesian_motion_generator_elbow_sign_inconsistent,
      cartesian_motion_generator_start_elbow_invalid: msg.cartesian_motion_generator_start_elbow_invalid,
      cartesian_motion_generator_joint_position_limits_violation: msg.cartesian_motion_generator_joint_position_limits_violation,
      cartesian_motion_generator_joint_velocity_limits_violation: msg.cartesian_motion_generator_joint_velocity_limits_violation,
      cartesian_motion_generator_joint_velocity_discontinuity: msg.cartesian_motion_generator_joint_velocity_discontinuity,
      cartesian_motion_generator_joint_acceleration_discontinuity: msg.cartesian_motion_generator_joint_acceleration_discontinuity,
      cartesian_position_motion_generator_invalid_frame: msg.cartesian_position_motion_generator_invalid_frame,
      force_controller_desired_force_tolerance_violation: msg.force_controller_desired_force_tolerance_violation,
      controller_torque_discontinuity: msg.controller_torque_discontinuity,
      start_elbow_sign_inconsistent: msg.start_elbow_sign_inconsistent,
      communication_constraints_violation: msg.communication_constraints_violation,
      power_limit_violation: msg.power_limit_violation,
      joint_p2p_insufficient_torque_for_planning: msg.joint_p2p_insufficient_torque_for_planning,
      tau_j_range_violation: msg.tau_j_range_violation,
      instability_detected: msg.instability_detected,
    }
  }
}


// Corresponds to franka_msgs__msg__FrankaRobotState
/// Default parts of the message

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FrankaRobotState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Indicates which dimensions have an active contact/collision flag raised
    pub collision_indicators: super::msg::CollisionIndicators,

    /// The state of the arm in joint space
    /// The joint state consisting out of position (q), velocity (dq) and effort (tau_J)
    pub measured_joint_state: sensor_msgs::msg::JointState,

    /// The desired joint state consisting out of position (q_d), velocity (dq_d) and effort (tau_J_d)
    pub desired_joint_state: sensor_msgs::msg::JointState,

    /// The measured motor state of the joints consisting out of position (theta) and velocity (dtheta)
    pub measured_joint_motor_state: sensor_msgs::msg::JointState,

    /// The desired joint acceleration
    pub ddq_d: [f64; 7],

    /// The derivative of the measured torque signal
    pub dtau_j: [f64; 7],

    /// Filtered external torque. The JointState consists out of effort (tau_ext_hat_filtered)
    pub tau_ext_hat_filtered: sensor_msgs::msg::JointState,

    /// The state of the elbow
    pub elbow: super::msg::Elbow,

    /// The active wrenches acting on the stiffness frame expressed relative to
    /// stiffness frame
    pub k_f_ext_hat_k: geometry_msgs::msg::WrenchStamped,

    /// base frame
    pub o_f_ext_hat_k: geometry_msgs::msg::WrenchStamped,

    /// The different inertias of the arm
    /// The end-effector inertia
    pub inertia_ee: geometry_msgs::msg::InertiaStamped,

    /// The load inertia
    pub inertia_load: geometry_msgs::msg::InertiaStamped,

    /// The total (end-effector + load) inertia
    pub inertia_total: geometry_msgs::msg::InertiaStamped,

    /// The poses describing the transformations between different frames of the arm
    /// Measured end-effector pose in base frame
    pub o_t_ee: geometry_msgs::msg::PoseStamped,

    /// Last desired end-effector pose of motion generation in base frame
    pub o_t_ee_d: geometry_msgs::msg::PoseStamped,

    /// Last commanded end-effector pose of motion generation in base frame
    pub o_t_ee_c: geometry_msgs::msg::PoseStamped,

    /// Flange to end-effector frame
    pub f_t_ee: geometry_msgs::msg::PoseStamped,

    /// End-effector to stiffness frame
    pub ee_t_k: geometry_msgs::msg::PoseStamped,

    /// Desired end effector twist in base frame
    pub o_dp_ee_d: geometry_msgs::msg::TwistStamped,

    /// Last commanded end effector twist in base frame
    pub o_dp_ee_c: geometry_msgs::msg::TwistStamped,

    /// Last commanded end effector acceleration in base frame
    pub o_ddp_ee_c: geometry_msgs::msg::AccelStamped,

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
    pub current_errors: super::msg::Errors,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_motion_errors: super::msg::Errors,

    /// Translational acceleration data from the joint-mounted accelerometers,
    /// expressed in the "<prefix>link<i>_accelerometer_<side>" frame named in each header
    /// (joints 1 through 6, mounted on links 0 through 5; no accelerometer on joint 7)
    pub accelerometer_top: [geometry_msgs::msg::Vector3Stamped; 6],


    // This member is not documented.
    #[allow(missing_docs)]
    pub accelerometer_bottom: [geometry_msgs::msg::Vector3Stamped; 6],

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FrankaRobotState::default())
  }
}

impl rosidl_runtime_rs::Message for FrankaRobotState {
  type RmwMsg = super::msg::rmw::FrankaRobotState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        collision_indicators: super::msg::CollisionIndicators::into_rmw_message(std::borrow::Cow::Owned(msg.collision_indicators)).into_owned(),
        measured_joint_state: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(msg.measured_joint_state)).into_owned(),
        desired_joint_state: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(msg.desired_joint_state)).into_owned(),
        measured_joint_motor_state: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(msg.measured_joint_motor_state)).into_owned(),
        ddq_d: msg.ddq_d,
        dtau_j: msg.dtau_j,
        tau_ext_hat_filtered: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(msg.tau_ext_hat_filtered)).into_owned(),
        elbow: super::msg::Elbow::into_rmw_message(std::borrow::Cow::Owned(msg.elbow)).into_owned(),
        k_f_ext_hat_k: geometry_msgs::msg::WrenchStamped::into_rmw_message(std::borrow::Cow::Owned(msg.k_f_ext_hat_k)).into_owned(),
        o_f_ext_hat_k: geometry_msgs::msg::WrenchStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_f_ext_hat_k)).into_owned(),
        inertia_ee: geometry_msgs::msg::InertiaStamped::into_rmw_message(std::borrow::Cow::Owned(msg.inertia_ee)).into_owned(),
        inertia_load: geometry_msgs::msg::InertiaStamped::into_rmw_message(std::borrow::Cow::Owned(msg.inertia_load)).into_owned(),
        inertia_total: geometry_msgs::msg::InertiaStamped::into_rmw_message(std::borrow::Cow::Owned(msg.inertia_total)).into_owned(),
        o_t_ee: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_t_ee)).into_owned(),
        o_t_ee_d: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_t_ee_d)).into_owned(),
        o_t_ee_c: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_t_ee_c)).into_owned(),
        f_t_ee: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.f_t_ee)).into_owned(),
        ee_t_k: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.ee_t_k)).into_owned(),
        o_dp_ee_d: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_dp_ee_d)).into_owned(),
        o_dp_ee_c: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_dp_ee_c)).into_owned(),
        o_ddp_ee_c: geometry_msgs::msg::AccelStamped::into_rmw_message(std::borrow::Cow::Owned(msg.o_ddp_ee_c)).into_owned(),
        time: msg.time,
        control_command_success_rate: msg.control_command_success_rate,
        robot_mode: msg.robot_mode,
        current_errors: super::msg::Errors::into_rmw_message(std::borrow::Cow::Owned(msg.current_errors)).into_owned(),
        last_motion_errors: super::msg::Errors::into_rmw_message(std::borrow::Cow::Owned(msg.last_motion_errors)).into_owned(),
        accelerometer_top: msg.accelerometer_top
          .map(|elem| geometry_msgs::msg::Vector3Stamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        accelerometer_bottom: msg.accelerometer_bottom
          .map(|elem| geometry_msgs::msg::Vector3Stamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        collision_indicators: super::msg::CollisionIndicators::into_rmw_message(std::borrow::Cow::Borrowed(&msg.collision_indicators)).into_owned(),
        measured_joint_state: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.measured_joint_state)).into_owned(),
        desired_joint_state: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.desired_joint_state)).into_owned(),
        measured_joint_motor_state: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.measured_joint_motor_state)).into_owned(),
        ddq_d: msg.ddq_d,
        dtau_j: msg.dtau_j,
        tau_ext_hat_filtered: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.tau_ext_hat_filtered)).into_owned(),
        elbow: super::msg::Elbow::into_rmw_message(std::borrow::Cow::Borrowed(&msg.elbow)).into_owned(),
        k_f_ext_hat_k: geometry_msgs::msg::WrenchStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.k_f_ext_hat_k)).into_owned(),
        o_f_ext_hat_k: geometry_msgs::msg::WrenchStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_f_ext_hat_k)).into_owned(),
        inertia_ee: geometry_msgs::msg::InertiaStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.inertia_ee)).into_owned(),
        inertia_load: geometry_msgs::msg::InertiaStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.inertia_load)).into_owned(),
        inertia_total: geometry_msgs::msg::InertiaStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.inertia_total)).into_owned(),
        o_t_ee: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_t_ee)).into_owned(),
        o_t_ee_d: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_t_ee_d)).into_owned(),
        o_t_ee_c: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_t_ee_c)).into_owned(),
        f_t_ee: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.f_t_ee)).into_owned(),
        ee_t_k: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.ee_t_k)).into_owned(),
        o_dp_ee_d: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_dp_ee_d)).into_owned(),
        o_dp_ee_c: geometry_msgs::msg::TwistStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_dp_ee_c)).into_owned(),
        o_ddp_ee_c: geometry_msgs::msg::AccelStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.o_ddp_ee_c)).into_owned(),
      time: msg.time,
      control_command_success_rate: msg.control_command_success_rate,
      robot_mode: msg.robot_mode,
        current_errors: super::msg::Errors::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_errors)).into_owned(),
        last_motion_errors: super::msg::Errors::into_rmw_message(std::borrow::Cow::Borrowed(&msg.last_motion_errors)).into_owned(),
        accelerometer_top: msg.accelerometer_top
          .iter()
          .map(|elem| geometry_msgs::msg::Vector3Stamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        accelerometer_bottom: msg.accelerometer_bottom
          .iter()
          .map(|elem| geometry_msgs::msg::Vector3Stamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      collision_indicators: super::msg::CollisionIndicators::from_rmw_message(msg.collision_indicators),
      measured_joint_state: sensor_msgs::msg::JointState::from_rmw_message(msg.measured_joint_state),
      desired_joint_state: sensor_msgs::msg::JointState::from_rmw_message(msg.desired_joint_state),
      measured_joint_motor_state: sensor_msgs::msg::JointState::from_rmw_message(msg.measured_joint_motor_state),
      ddq_d: msg.ddq_d,
      dtau_j: msg.dtau_j,
      tau_ext_hat_filtered: sensor_msgs::msg::JointState::from_rmw_message(msg.tau_ext_hat_filtered),
      elbow: super::msg::Elbow::from_rmw_message(msg.elbow),
      k_f_ext_hat_k: geometry_msgs::msg::WrenchStamped::from_rmw_message(msg.k_f_ext_hat_k),
      o_f_ext_hat_k: geometry_msgs::msg::WrenchStamped::from_rmw_message(msg.o_f_ext_hat_k),
      inertia_ee: geometry_msgs::msg::InertiaStamped::from_rmw_message(msg.inertia_ee),
      inertia_load: geometry_msgs::msg::InertiaStamped::from_rmw_message(msg.inertia_load),
      inertia_total: geometry_msgs::msg::InertiaStamped::from_rmw_message(msg.inertia_total),
      o_t_ee: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.o_t_ee),
      o_t_ee_d: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.o_t_ee_d),
      o_t_ee_c: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.o_t_ee_c),
      f_t_ee: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.f_t_ee),
      ee_t_k: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.ee_t_k),
      o_dp_ee_d: geometry_msgs::msg::TwistStamped::from_rmw_message(msg.o_dp_ee_d),
      o_dp_ee_c: geometry_msgs::msg::TwistStamped::from_rmw_message(msg.o_dp_ee_c),
      o_ddp_ee_c: geometry_msgs::msg::AccelStamped::from_rmw_message(msg.o_ddp_ee_c),
      time: msg.time,
      control_command_success_rate: msg.control_command_success_rate,
      robot_mode: msg.robot_mode,
      current_errors: super::msg::Errors::from_rmw_message(msg.current_errors),
      last_motion_errors: super::msg::Errors::from_rmw_message(msg.last_motion_errors),
      accelerometer_top: msg.accelerometer_top
        .map(geometry_msgs::msg::Vector3Stamped::from_rmw_message),
      accelerometer_bottom: msg.accelerometer_bottom
        .map(geometry_msgs::msg::Vector3Stamped::from_rmw_message),
    }
  }
}


// Corresponds to franka_msgs__msg__GraspEpsilon
/// Maximum tolerated deviation when the actual grasped width
/// is smaller than the commanded grasp width. Unit:

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GraspEpsilon::default())
  }
}

impl rosidl_runtime_rs::Message for GraspEpsilon {
  type RmwMsg = super::msg::rmw::GraspEpsilon;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        inner: msg.inner,
        outer: msg.outer,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      inner: msg.inner,
      outer: msg.outer,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      inner: msg.inner,
      outer: msg.outer,
    }
  }
}


// Corresponds to franka_msgs__msg__TargetStatus
/// The status of a motion action
/// IDLE: The robot is idle, no motion is being executed

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TargetStatus::default())
  }
}

impl rosidl_runtime_rs::Message for TargetStatus {
  type RmwMsg = super::msg::rmw::TargetStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
    }
  }
}


