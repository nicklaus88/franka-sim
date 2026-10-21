
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_Goal() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_Goal__init(msg: *mut MoveAbsolute_Goal) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Goal>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Goal>);
    fn franka_spine_msgs__action__MoveAbsolute_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Goal>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_Goal__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_Goal() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_Result() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_Result__init(msg: *mut MoveAbsolute_Result) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Result>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Result>);
    fn franka_spine_msgs__action__MoveAbsolute_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Result>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_Result {
    /// True if the target position was reached
    pub success: bool,

    /// How the motion was stopped (from spine response)
    pub stop_by: rosidl_runtime_rs::String,

    /// Error description if success is false
    pub error: rosidl_runtime_rs::String,

}



impl Default for MoveAbsolute_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_Result__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_Result where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_Result() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_Feedback__init(msg: *mut MoveAbsolute_Feedback) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Feedback>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Feedback>);
    fn franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_Feedback>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_Feedback {
    /// Current spine position
    pub current_position: f64,

}



impl Default for MoveAbsolute_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_Feedback__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_Feedback() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__init(msg: *mut MoveAbsolute_FeedbackMessage) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_FeedbackMessage>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_FeedbackMessage>);
    fn franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_FeedbackMessage>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::MoveAbsolute_Feedback,

}



impl Default for MoveAbsolute_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_FeedbackMessage() }
  }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__init(msg: *mut MoveAbsolute_SendGoal_Request) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Request>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Request>);
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::MoveAbsolute_Goal,

}



impl Default for MoveAbsolute_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_SendGoal_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__init(msg: *mut MoveAbsolute_SendGoal_Response) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Response>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Response>);
    fn franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_SendGoal_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for MoveAbsolute_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_SendGoal_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Request__init(msg: *mut MoveAbsolute_GetResult_Request) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Request>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Request>);
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for MoveAbsolute_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_GetResult_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Response__init(msg: *mut MoveAbsolute_GetResult_Response) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Response>, size: usize) -> bool;
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Response>);
    fn franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveAbsolute_GetResult_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__action__MoveAbsolute_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveAbsolute_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::MoveAbsolute_Result,

}



impl Default for MoveAbsolute_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__action__MoveAbsolute_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__action__MoveAbsolute_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveAbsolute_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveAbsolute_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveAbsolute_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/action/MoveAbsolute_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__action__MoveAbsolute_GetResult_Response() }
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


