#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to franka_msgs__srv__SetCartesianStiffness_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetCartesianStiffness_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_stiffness: [f64; 6],

}



impl Default for SetCartesianStiffness_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetCartesianStiffness_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetCartesianStiffness_Request {
  type RmwMsg = super::srv::rmw::SetCartesianStiffness_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        cartesian_stiffness: msg.cartesian_stiffness,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        cartesian_stiffness: msg.cartesian_stiffness,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      cartesian_stiffness: msg.cartesian_stiffness,
    }
  }
}


// Corresponds to franka_msgs__srv__SetCartesianStiffness_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetCartesianStiffness_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetCartesianStiffness_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetCartesianStiffness_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetCartesianStiffness_Response {
  type RmwMsg = super::srv::rmw::SetCartesianStiffness_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_msgs__srv__SetTCPFrame_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetTCPFrame_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transformation: [f64; 16],

}



impl Default for SetTCPFrame_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetTCPFrame_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetTCPFrame_Request {
  type RmwMsg = super::srv::rmw::SetTCPFrame_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transformation: msg.transformation,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transformation: msg.transformation,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      transformation: msg.transformation,
    }
  }
}


// Corresponds to franka_msgs__srv__SetTCPFrame_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetTCPFrame_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetTCPFrame_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetTCPFrame_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetTCPFrame_Response {
  type RmwMsg = super::srv::rmw::SetTCPFrame_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_msgs__srv__SetForceTorqueCollisionBehavior_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetForceTorqueCollisionBehavior_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub lower_torque_thresholds_nominal: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub upper_torque_thresholds_nominal: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub lower_force_thresholds_nominal: [f64; 6],


    // This member is not documented.
    #[allow(missing_docs)]
    pub upper_force_thresholds_nominal: [f64; 6],

}



impl Default for SetForceTorqueCollisionBehavior_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetForceTorqueCollisionBehavior_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetForceTorqueCollisionBehavior_Request {
  type RmwMsg = super::srv::rmw::SetForceTorqueCollisionBehavior_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        lower_torque_thresholds_nominal: msg.lower_torque_thresholds_nominal,
        upper_torque_thresholds_nominal: msg.upper_torque_thresholds_nominal,
        lower_force_thresholds_nominal: msg.lower_force_thresholds_nominal,
        upper_force_thresholds_nominal: msg.upper_force_thresholds_nominal,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        lower_torque_thresholds_nominal: msg.lower_torque_thresholds_nominal,
        upper_torque_thresholds_nominal: msg.upper_torque_thresholds_nominal,
        lower_force_thresholds_nominal: msg.lower_force_thresholds_nominal,
        upper_force_thresholds_nominal: msg.upper_force_thresholds_nominal,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      lower_torque_thresholds_nominal: msg.lower_torque_thresholds_nominal,
      upper_torque_thresholds_nominal: msg.upper_torque_thresholds_nominal,
      lower_force_thresholds_nominal: msg.lower_force_thresholds_nominal,
      upper_force_thresholds_nominal: msg.upper_force_thresholds_nominal,
    }
  }
}


// Corresponds to franka_msgs__srv__SetForceTorqueCollisionBehavior_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetForceTorqueCollisionBehavior_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetForceTorqueCollisionBehavior_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetForceTorqueCollisionBehavior_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetForceTorqueCollisionBehavior_Response {
  type RmwMsg = super::srv::rmw::SetForceTorqueCollisionBehavior_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_msgs__srv__SetFullCollisionBehavior_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetFullCollisionBehavior_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub lower_torque_thresholds_acceleration: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub upper_torque_thresholds_acceleration: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub lower_torque_thresholds_nominal: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub upper_torque_thresholds_nominal: [f64; 7],


    // This member is not documented.
    #[allow(missing_docs)]
    pub lower_force_thresholds_acceleration: [f64; 6],


    // This member is not documented.
    #[allow(missing_docs)]
    pub upper_force_thresholds_acceleration: [f64; 6],


    // This member is not documented.
    #[allow(missing_docs)]
    pub lower_force_thresholds_nominal: [f64; 6],


    // This member is not documented.
    #[allow(missing_docs)]
    pub upper_force_thresholds_nominal: [f64; 6],

}



impl Default for SetFullCollisionBehavior_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetFullCollisionBehavior_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetFullCollisionBehavior_Request {
  type RmwMsg = super::srv::rmw::SetFullCollisionBehavior_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        lower_torque_thresholds_acceleration: msg.lower_torque_thresholds_acceleration,
        upper_torque_thresholds_acceleration: msg.upper_torque_thresholds_acceleration,
        lower_torque_thresholds_nominal: msg.lower_torque_thresholds_nominal,
        upper_torque_thresholds_nominal: msg.upper_torque_thresholds_nominal,
        lower_force_thresholds_acceleration: msg.lower_force_thresholds_acceleration,
        upper_force_thresholds_acceleration: msg.upper_force_thresholds_acceleration,
        lower_force_thresholds_nominal: msg.lower_force_thresholds_nominal,
        upper_force_thresholds_nominal: msg.upper_force_thresholds_nominal,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        lower_torque_thresholds_acceleration: msg.lower_torque_thresholds_acceleration,
        upper_torque_thresholds_acceleration: msg.upper_torque_thresholds_acceleration,
        lower_torque_thresholds_nominal: msg.lower_torque_thresholds_nominal,
        upper_torque_thresholds_nominal: msg.upper_torque_thresholds_nominal,
        lower_force_thresholds_acceleration: msg.lower_force_thresholds_acceleration,
        upper_force_thresholds_acceleration: msg.upper_force_thresholds_acceleration,
        lower_force_thresholds_nominal: msg.lower_force_thresholds_nominal,
        upper_force_thresholds_nominal: msg.upper_force_thresholds_nominal,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      lower_torque_thresholds_acceleration: msg.lower_torque_thresholds_acceleration,
      upper_torque_thresholds_acceleration: msg.upper_torque_thresholds_acceleration,
      lower_torque_thresholds_nominal: msg.lower_torque_thresholds_nominal,
      upper_torque_thresholds_nominal: msg.upper_torque_thresholds_nominal,
      lower_force_thresholds_acceleration: msg.lower_force_thresholds_acceleration,
      upper_force_thresholds_acceleration: msg.upper_force_thresholds_acceleration,
      lower_force_thresholds_nominal: msg.lower_force_thresholds_nominal,
      upper_force_thresholds_nominal: msg.upper_force_thresholds_nominal,
    }
  }
}


// Corresponds to franka_msgs__srv__SetFullCollisionBehavior_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetFullCollisionBehavior_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetFullCollisionBehavior_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetFullCollisionBehavior_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetFullCollisionBehavior_Response {
  type RmwMsg = super::srv::rmw::SetFullCollisionBehavior_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_msgs__srv__SetJointStiffness_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetJointStiffness_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_stiffness: [f64; 7],

}



impl Default for SetJointStiffness_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetJointStiffness_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetJointStiffness_Request {
  type RmwMsg = super::srv::rmw::SetJointStiffness_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_stiffness: msg.joint_stiffness,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        joint_stiffness: msg.joint_stiffness,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      joint_stiffness: msg.joint_stiffness,
    }
  }
}


// Corresponds to franka_msgs__srv__SetJointStiffness_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetJointStiffness_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetJointStiffness_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetJointStiffness_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetJointStiffness_Response {
  type RmwMsg = super::srv::rmw::SetJointStiffness_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_msgs__srv__SetStiffnessFrame_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetStiffnessFrame_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transformation: [f64; 16],

}



impl Default for SetStiffnessFrame_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetStiffnessFrame_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetStiffnessFrame_Request {
  type RmwMsg = super::srv::rmw::SetStiffnessFrame_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transformation: msg.transformation,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        transformation: msg.transformation,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      transformation: msg.transformation,
    }
  }
}


// Corresponds to franka_msgs__srv__SetStiffnessFrame_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetStiffnessFrame_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetStiffnessFrame_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetStiffnessFrame_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetStiffnessFrame_Response {
  type RmwMsg = super::srv::rmw::SetStiffnessFrame_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_msgs__srv__SetLoad_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetLoad_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mass: f64,

    /// Position of the center of mass
    pub center_of_mass: [f64; 3],

    /// Inertia of the object - the provided 3x3 matrix is in column major form.
    pub load_inertia: [f64; 9],

}



impl Default for SetLoad_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetLoad_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetLoad_Request {
  type RmwMsg = super::srv::rmw::SetLoad_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mass: msg.mass,
        center_of_mass: msg.center_of_mass,
        load_inertia: msg.load_inertia,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mass: msg.mass,
        center_of_mass: msg.center_of_mass,
        load_inertia: msg.load_inertia,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mass: msg.mass,
      center_of_mass: msg.center_of_mass,
      load_inertia: msg.load_inertia,
    }
  }
}


// Corresponds to franka_msgs__srv__SetLoad_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetLoad_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for SetLoad_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetLoad_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetLoad_Response {
  type RmwMsg = super::srv::rmw::SetLoad_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      error: msg.error.to_string(),
    }
  }
}






#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetCartesianStiffness() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetCartesianStiffness
#[allow(missing_docs, non_camel_case_types)]
pub struct SetCartesianStiffness;

impl rosidl_runtime_rs::Service for SetCartesianStiffness {
    type Request = SetCartesianStiffness_Request;
    type Response = SetCartesianStiffness_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetCartesianStiffness() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetTCPFrame() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetTCPFrame
#[allow(missing_docs, non_camel_case_types)]
pub struct SetTCPFrame;

impl rosidl_runtime_rs::Service for SetTCPFrame {
    type Request = SetTCPFrame_Request;
    type Response = SetTCPFrame_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetTCPFrame() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetForceTorqueCollisionBehavior() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetForceTorqueCollisionBehavior
#[allow(missing_docs, non_camel_case_types)]
pub struct SetForceTorqueCollisionBehavior;

impl rosidl_runtime_rs::Service for SetForceTorqueCollisionBehavior {
    type Request = SetForceTorqueCollisionBehavior_Request;
    type Response = SetForceTorqueCollisionBehavior_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetForceTorqueCollisionBehavior() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetFullCollisionBehavior() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetFullCollisionBehavior
#[allow(missing_docs, non_camel_case_types)]
pub struct SetFullCollisionBehavior;

impl rosidl_runtime_rs::Service for SetFullCollisionBehavior {
    type Request = SetFullCollisionBehavior_Request;
    type Response = SetFullCollisionBehavior_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetFullCollisionBehavior() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetJointStiffness() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetJointStiffness
#[allow(missing_docs, non_camel_case_types)]
pub struct SetJointStiffness;

impl rosidl_runtime_rs::Service for SetJointStiffness {
    type Request = SetJointStiffness_Request;
    type Response = SetJointStiffness_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetJointStiffness() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetStiffnessFrame() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetStiffnessFrame
#[allow(missing_docs, non_camel_case_types)]
pub struct SetStiffnessFrame;

impl rosidl_runtime_rs::Service for SetStiffnessFrame {
    type Request = SetStiffnessFrame_Request;
    type Response = SetStiffnessFrame_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetStiffnessFrame() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetLoad() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__srv__SetLoad
#[allow(missing_docs, non_camel_case_types)]
pub struct SetLoad;

impl rosidl_runtime_rs::Service for SetLoad {
    type Request = SetLoad_Request;
    type Response = SetLoad_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__srv__SetLoad() }
    }
}


