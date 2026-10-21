
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to franka_spine_msgs__action__MoveAbsolute_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_Goal {
    /// Target position
    pub position: f64,

    /// Motion velocity, must be > 0
    pub velocity: f64,

    /// Motion acceleration, must be > 0
    pub acceleration: f64,

    /// Motion deceleration, must be > 0
    pub deceleration: f64,

}



impl Default for MoveAbsolute_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_Goal {
  type RmwMsg = super::action::rmw::MoveAbsolute_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: msg.position,
        velocity: msg.velocity,
        acceleration: msg.acceleration,
        deceleration: msg.deceleration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      position: msg.position,
      velocity: msg.velocity,
      acceleration: msg.acceleration,
      deceleration: msg.deceleration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position: msg.position,
      velocity: msg.velocity,
      acceleration: msg.acceleration,
      deceleration: msg.deceleration,
    }
  }
}


// Corresponds to franka_spine_msgs__action__MoveAbsolute_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_Result {
    /// True if the target position was reached
    pub success: bool,

    /// How the motion was stopped (from spine response)
    pub stop_by: std::string::String,

    /// Error description if success is false
    pub error: std::string::String,

}



impl Default for MoveAbsolute_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_Result::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_Result {
  type RmwMsg = super::action::rmw::MoveAbsolute_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        stop_by: msg.stop_by.as_str().into(),
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        stop_by: msg.stop_by.as_str().into(),
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      stop_by: msg.stop_by.to_string(),
      error: msg.error.to_string(),
    }
  }
}


// Corresponds to franka_spine_msgs__action__MoveAbsolute_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_Feedback {
    /// Current spine position
    pub current_position: f64,

}



impl Default for MoveAbsolute_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_Feedback {
  type RmwMsg = super::action::rmw::MoveAbsolute_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_position: msg.current_position,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      current_position: msg.current_position,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      current_position: msg.current_position,
    }
  }
}


// Corresponds to franka_spine_msgs__action__MoveAbsolute_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::MoveAbsolute_Feedback,

}



impl Default for MoveAbsolute_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_FeedbackMessage {
  type RmwMsg = super::action::rmw::MoveAbsolute_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::MoveAbsolute_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::MoveAbsolute_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::MoveAbsolute_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to franka_spine_msgs__action__MoveAbsolute_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::MoveAbsolute_Goal,

}



impl Default for MoveAbsolute_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_SendGoal_Request {
  type RmwMsg = super::action::rmw::MoveAbsolute_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::MoveAbsolute_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::MoveAbsolute_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::MoveAbsolute_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to franka_spine_msgs__action__MoveAbsolute_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for MoveAbsolute_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_SendGoal_Response {
  type RmwMsg = super::action::rmw::MoveAbsolute_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to franka_spine_msgs__action__MoveAbsolute_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for MoveAbsolute_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_GetResult_Request {
  type RmwMsg = super::action::rmw::MoveAbsolute_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to franka_spine_msgs__action__MoveAbsolute_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::MoveAbsolute_Result,

}



impl Default for MoveAbsolute_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::MoveAbsolute_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_GetResult_Response {
  type RmwMsg = super::action::rmw::MoveAbsolute_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::MoveAbsolute_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::MoveAbsolute_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::MoveAbsolute_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__action__MoveAbsolute_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveAbsolute_SendGoal;

impl rosidl_runtime_rs::Service for MoveAbsolute_SendGoal {
    type Request = MoveAbsolute_SendGoal_Request;
    type Response = MoveAbsolute_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__action__MoveAbsolute_SendGoal() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__action__MoveAbsolute_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveAbsolute_GetResult;

impl rosidl_runtime_rs::Service for MoveAbsolute_GetResult {
    type Request = MoveAbsolute_GetResult_Request;
    type Response = MoveAbsolute_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__action__MoveAbsolute_GetResult() }
    }
}






#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__franka_spine_msgs__action__MoveAbsolute() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveAbsolute;

impl rosidl_runtime_rs::Action for MoveAbsolute {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = MoveAbsolute_Goal;

  /// The result message defined in the action definition.
  type Result = MoveAbsolute_Result;

  /// The feedback message defined in the action definition.
  type Feedback = MoveAbsolute_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::MoveAbsolute_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::MoveAbsolute_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::MoveAbsolute_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__franka_spine_msgs__action__MoveAbsolute() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::MoveAbsolute_Goal,
  ) -> super::action::rmw::MoveAbsolute_SendGoal_Request {
   super::action::rmw::MoveAbsolute_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::MoveAbsolute_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveAbsolute_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::MoveAbsolute_SendGoal_Response {
   super::action::rmw::MoveAbsolute_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::MoveAbsolute_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::MoveAbsolute_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::MoveAbsolute_Feedback,
  ) -> super::action::rmw::MoveAbsolute_FeedbackMessage {
    let mut message = super::action::rmw::MoveAbsolute_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::MoveAbsolute_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::MoveAbsolute_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::MoveAbsolute_GetResult_Request {
   super::action::rmw::MoveAbsolute_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::MoveAbsolute_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::MoveAbsolute_Result,
  ) -> super::action::rmw::MoveAbsolute_GetResult_Response {
   super::action::rmw::MoveAbsolute_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::MoveAbsolute_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::MoveAbsolute_Result,
  ) {
    (response.status, response.result)
  }
}


