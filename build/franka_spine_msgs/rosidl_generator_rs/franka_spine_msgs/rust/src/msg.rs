#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to franka_spine_msgs__msg__UserLimits
/// User-defined soft motion limits for the spine.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UserLimits {
    /// Lower motion limit
    pub lower_limit: f64,

    /// Upper motion limit
    pub upper_limit: f64,

}



impl Default for UserLimits {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UserLimits::default())
  }
}

impl rosidl_runtime_rs::Message for UserLimits {
  type RmwMsg = super::msg::rmw::UserLimits;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        lower_limit: msg.lower_limit,
        upper_limit: msg.upper_limit,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      lower_limit: msg.lower_limit,
      upper_limit: msg.upper_limit,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      lower_limit: msg.lower_limit,
      upper_limit: msg.upper_limit,
    }
  }
}


// Corresponds to franka_spine_msgs__msg__SpineParameters
/// Aggregated spine parameters returned by the GetParameters service.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpineParameters {
    /// User-defined motion limits
    pub user_limits: super::msg::UserLimits,

}



impl Default for SpineParameters {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SpineParameters::default())
  }
}

impl rosidl_runtime_rs::Message for SpineParameters {
  type RmwMsg = super::msg::rmw::SpineParameters;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        user_limits: super::msg::UserLimits::into_rmw_message(std::borrow::Cow::Owned(msg.user_limits)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        user_limits: super::msg::UserLimits::into_rmw_message(std::borrow::Cow::Borrowed(&msg.user_limits)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      user_limits: super::msg::UserLimits::from_rmw_message(msg.user_limits),
    }
  }
}


// Corresponds to franka_spine_msgs__msg__SpinePosition
/// Periodic spine position sample published on ~/position.
/// Subscribe to this instead of polling the GetPosition service in a loop.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpinePosition {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Last known position
    pub position: f64,

    /// False when the sample is stale because the REST read failed
    pub valid: bool,

}



impl Default for SpinePosition {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SpinePosition::default())
  }
}

impl rosidl_runtime_rs::Message for SpinePosition {
  type RmwMsg = super::msg::rmw::SpinePosition;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        position: msg.position,
        valid: msg.valid,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      position: msg.position,
      valid: msg.valid,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      position: msg.position,
      valid: msg.valid,
    }
  }
}


// Corresponds to franka_spine_msgs__msg__SpineState
/// Periodic spine state sample published on ~/state.
/// Subscribe to this instead of polling the GetSpineState service in a loop.
/// Possible states: NotReadyToSwitchOn, SwitchedOff, ReadyToSwitchOn,
///   MotorOff, SwitchedOn, QuickStopActive, FaultReactionActive, Fault, Unknown.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpineState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// Current spine state
    pub state: std::string::String,

    /// Error code (empty when no error)
    pub error_code: std::string::String,

    /// Human-readable error description
    pub error_description: std::string::String,

    /// False when the sample is stale because the REST read failed
    pub valid: bool,

}



impl Default for SpineState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SpineState::default())
  }
}

impl rosidl_runtime_rs::Message for SpineState {
  type RmwMsg = super::msg::rmw::SpineState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        state: msg.state.as_str().into(),
        error_code: msg.error_code.as_str().into(),
        error_description: msg.error_description.as_str().into(),
        valid: msg.valid,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        state: msg.state.as_str().into(),
        error_code: msg.error_code.as_str().into(),
        error_description: msg.error_description.as_str().into(),
      valid: msg.valid,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      state: msg.state.to_string(),
      error_code: msg.error_code.to_string(),
      error_description: msg.error_description.to_string(),
      valid: msg.valid,
    }
  }
}


