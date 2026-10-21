
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_Goal() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_Goal__init(msg: *mut ErrorRecovery_Goal) -> bool;
    fn franka_msgs__action__ErrorRecovery_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Goal>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Goal>);
    fn franka_msgs__action__ErrorRecovery_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Goal>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ErrorRecovery_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_Goal__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_Goal() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_Result() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_Result__init(msg: *mut ErrorRecovery_Result) -> bool;
    fn franka_msgs__action__ErrorRecovery_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Result>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Result>);
    fn franka_msgs__action__ErrorRecovery_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Result>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ErrorRecovery_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_Result__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_Result where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_Result() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_Feedback__init(msg: *mut ErrorRecovery_Feedback) -> bool;
    fn franka_msgs__action__ErrorRecovery_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Feedback>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Feedback>);
    fn franka_msgs__action__ErrorRecovery_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_Feedback>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for ErrorRecovery_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_Feedback__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_Feedback() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_FeedbackMessage__init(msg: *mut ErrorRecovery_FeedbackMessage) -> bool;
    fn franka_msgs__action__ErrorRecovery_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_FeedbackMessage>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_FeedbackMessage>);
    fn franka_msgs__action__ErrorRecovery_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_FeedbackMessage>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ErrorRecovery_Feedback,

}



impl Default for ErrorRecovery_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_FeedbackMessage() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_Goal() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_Goal__init(msg: *mut Grasp_Goal) -> bool;
    fn franka_msgs__action__Grasp_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_Goal>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_Goal>);
    fn franka_msgs__action__Grasp_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_Goal>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub width: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub epsilon: super::super::msg::rmw::GraspEpsilon,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub force: f64,

}



impl Default for Grasp_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_Goal__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_Goal() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_Result() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_Result__init(msg: *mut Grasp_Result) -> bool;
    fn franka_msgs__action__Grasp_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_Result>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_Result>);
    fn franka_msgs__action__Grasp_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_Result>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for Grasp_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_Result__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_Result where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_Result() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_Feedback__init(msg: *mut Grasp_Feedback) -> bool;
    fn franka_msgs__action__Grasp_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_Feedback>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_Feedback>);
    fn franka_msgs__action__Grasp_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_Feedback>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_width: f64,

}



impl Default for Grasp_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_Feedback__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_Feedback() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_FeedbackMessage__init(msg: *mut Grasp_FeedbackMessage) -> bool;
    fn franka_msgs__action__Grasp_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_FeedbackMessage>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_FeedbackMessage>);
    fn franka_msgs__action__Grasp_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_FeedbackMessage>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Grasp_Feedback,

}



impl Default for Grasp_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_FeedbackMessage() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_Goal() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_Goal__init(msg: *mut Homing_Goal) -> bool;
    fn franka_msgs__action__Homing_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_Goal>, size: usize) -> bool;
    fn franka_msgs__action__Homing_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_Goal>);
    fn franka_msgs__action__Homing_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_Goal>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Homing_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_Goal__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_Goal() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_Result() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_Result__init(msg: *mut Homing_Result) -> bool;
    fn franka_msgs__action__Homing_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_Result>, size: usize) -> bool;
    fn franka_msgs__action__Homing_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_Result>);
    fn franka_msgs__action__Homing_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_Result>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for Homing_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_Result__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_Result where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_Result() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_Feedback__init(msg: *mut Homing_Feedback) -> bool;
    fn franka_msgs__action__Homing_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_Feedback>, size: usize) -> bool;
    fn franka_msgs__action__Homing_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_Feedback>);
    fn franka_msgs__action__Homing_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_Feedback>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_width: f64,

}



impl Default for Homing_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_Feedback__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_Feedback() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_FeedbackMessage__init(msg: *mut Homing_FeedbackMessage) -> bool;
    fn franka_msgs__action__Homing_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_FeedbackMessage>, size: usize) -> bool;
    fn franka_msgs__action__Homing_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_FeedbackMessage>);
    fn franka_msgs__action__Homing_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_FeedbackMessage>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Homing_Feedback,

}



impl Default for Homing_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_FeedbackMessage() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_Goal() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_Goal__init(msg: *mut Move_Goal) -> bool;
    fn franka_msgs__action__Move_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_Goal>, size: usize) -> bool;
    fn franka_msgs__action__Move_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_Goal>);
    fn franka_msgs__action__Move_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_Goal>) -> bool;
}

// Corresponds to franka_msgs__action__Move_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub width: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: f64,

}



impl Default for Move_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_Goal__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_Goal() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_Result() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_Result__init(msg: *mut Move_Result) -> bool;
    fn franka_msgs__action__Move_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_Result>, size: usize) -> bool;
    fn franka_msgs__action__Move_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_Result>);
    fn franka_msgs__action__Move_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_Result>) -> bool;
}

// Corresponds to franka_msgs__action__Move_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for Move_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_Result__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_Result where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_Result() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_Feedback__init(msg: *mut Move_Feedback) -> bool;
    fn franka_msgs__action__Move_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_Feedback>, size: usize) -> bool;
    fn franka_msgs__action__Move_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_Feedback>);
    fn franka_msgs__action__Move_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_Feedback>) -> bool;
}

// Corresponds to franka_msgs__action__Move_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_width: f64,

}



impl Default for Move_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_Feedback__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_Feedback() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_FeedbackMessage__init(msg: *mut Move_FeedbackMessage) -> bool;
    fn franka_msgs__action__Move_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_FeedbackMessage>, size: usize) -> bool;
    fn franka_msgs__action__Move_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_FeedbackMessage>);
    fn franka_msgs__action__Move_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_FeedbackMessage>) -> bool;
}

// Corresponds to franka_msgs__action__Move_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Move_Feedback,

}



impl Default for Move_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_FeedbackMessage() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_Goal() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_Goal__init(msg: *mut PTPMotion_Goal) -> bool;
    fn franka_msgs__action__PTPMotion_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Goal>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Goal>);
    fn franka_msgs__action__PTPMotion_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Goal>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_joint_configuration: rosidl_runtime_rs::Sequence<f64>,

    /// The maximum allowed joint velocities for the motion.
    /// [rad/s]
    pub maximum_joint_velocities: rosidl_runtime_rs::Sequence<f64>,

    /// The acceptable goal tolerance for the motion. The 'target reached condition is met when
    /// - the absolute difference between the current and goal joint positions is within this goal_tolerance
    /// - the joint velocities are below a small threshold
    /// [rad]
    pub goal_tolerance: f64,

}



impl Default for PTPMotion_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_Goal__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_Goal() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_Result() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_Result__init(msg: *mut PTPMotion_Result) -> bool;
    fn franka_msgs__action__PTPMotion_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Result>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Result>);
    fn franka_msgs__action__PTPMotion_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Result>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_status: super::super::msg::rmw::TargetStatus,

    /// In case of failure, an error message describing the issue
    pub error_message: rosidl_runtime_rs::String,

}



impl Default for PTPMotion_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_Result__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_Result where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_Result() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_Feedback__init(msg: *mut PTPMotion_Feedback) -> bool;
    fn franka_msgs__action__PTPMotion_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Feedback>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Feedback>);
    fn franka_msgs__action__PTPMotion_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_Feedback>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_status: super::super::msg::rmw::TargetStatus,

}



impl Default for PTPMotion_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_Feedback__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_Feedback() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_FeedbackMessage__init(msg: *mut PTPMotion_FeedbackMessage) -> bool;
    fn franka_msgs__action__PTPMotion_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_FeedbackMessage>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_FeedbackMessage>);
    fn franka_msgs__action__PTPMotion_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_FeedbackMessage>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::PTPMotion_Feedback,

}



impl Default for PTPMotion_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_FeedbackMessage() }
  }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_SendGoal_Request__init(msg: *mut ErrorRecovery_SendGoal_Request) -> bool;
    fn franka_msgs__action__ErrorRecovery_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Request>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Request>);
    fn franka_msgs__action__ErrorRecovery_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Request>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ErrorRecovery_Goal,

}



impl Default for ErrorRecovery_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_SendGoal_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_SendGoal_Response__init(msg: *mut ErrorRecovery_SendGoal_Response) -> bool;
    fn franka_msgs__action__ErrorRecovery_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Response>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Response>);
    fn franka_msgs__action__ErrorRecovery_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_SendGoal_Response>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ErrorRecovery_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_SendGoal_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_GetResult_Request__init(msg: *mut ErrorRecovery_GetResult_Request) -> bool;
    fn franka_msgs__action__ErrorRecovery_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Request>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Request>);
    fn franka_msgs__action__ErrorRecovery_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Request>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ErrorRecovery_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_GetResult_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__ErrorRecovery_GetResult_Response__init(msg: *mut ErrorRecovery_GetResult_Response) -> bool;
    fn franka_msgs__action__ErrorRecovery_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Response>, size: usize) -> bool;
    fn franka_msgs__action__ErrorRecovery_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Response>);
    fn franka_msgs__action__ErrorRecovery_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ErrorRecovery_GetResult_Response>) -> bool;
}

// Corresponds to franka_msgs__action__ErrorRecovery_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorRecovery_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ErrorRecovery_Result,

}



impl Default for ErrorRecovery_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__ErrorRecovery_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__ErrorRecovery_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ErrorRecovery_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__ErrorRecovery_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ErrorRecovery_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ErrorRecovery_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/ErrorRecovery_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__ErrorRecovery_GetResult_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_SendGoal_Request__init(msg: *mut Grasp_SendGoal_Request) -> bool;
    fn franka_msgs__action__Grasp_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_SendGoal_Request>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_SendGoal_Request>);
    fn franka_msgs__action__Grasp_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_SendGoal_Request>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Grasp_Goal,

}



impl Default for Grasp_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_SendGoal_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_SendGoal_Response__init(msg: *mut Grasp_SendGoal_Response) -> bool;
    fn franka_msgs__action__Grasp_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_SendGoal_Response>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_SendGoal_Response>);
    fn franka_msgs__action__Grasp_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_SendGoal_Response>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Grasp_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_SendGoal_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_GetResult_Request__init(msg: *mut Grasp_GetResult_Request) -> bool;
    fn franka_msgs__action__Grasp_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_GetResult_Request>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_GetResult_Request>);
    fn franka_msgs__action__Grasp_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_GetResult_Request>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Grasp_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_GetResult_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Grasp_GetResult_Response__init(msg: *mut Grasp_GetResult_Response) -> bool;
    fn franka_msgs__action__Grasp_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Grasp_GetResult_Response>, size: usize) -> bool;
    fn franka_msgs__action__Grasp_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Grasp_GetResult_Response>);
    fn franka_msgs__action__Grasp_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Grasp_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Grasp_GetResult_Response>) -> bool;
}

// Corresponds to franka_msgs__action__Grasp_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Grasp_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Grasp_Result,

}



impl Default for Grasp_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Grasp_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Grasp_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Grasp_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Grasp_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Grasp_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Grasp_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Grasp_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Grasp_GetResult_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_SendGoal_Request__init(msg: *mut Homing_SendGoal_Request) -> bool;
    fn franka_msgs__action__Homing_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_SendGoal_Request>, size: usize) -> bool;
    fn franka_msgs__action__Homing_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_SendGoal_Request>);
    fn franka_msgs__action__Homing_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_SendGoal_Request>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Homing_Goal,

}



impl Default for Homing_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_SendGoal_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_SendGoal_Response__init(msg: *mut Homing_SendGoal_Response) -> bool;
    fn franka_msgs__action__Homing_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_SendGoal_Response>, size: usize) -> bool;
    fn franka_msgs__action__Homing_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_SendGoal_Response>);
    fn franka_msgs__action__Homing_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_SendGoal_Response>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Homing_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_SendGoal_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_GetResult_Request__init(msg: *mut Homing_GetResult_Request) -> bool;
    fn franka_msgs__action__Homing_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_GetResult_Request>, size: usize) -> bool;
    fn franka_msgs__action__Homing_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_GetResult_Request>);
    fn franka_msgs__action__Homing_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_GetResult_Request>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Homing_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_GetResult_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Homing_GetResult_Response__init(msg: *mut Homing_GetResult_Response) -> bool;
    fn franka_msgs__action__Homing_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Homing_GetResult_Response>, size: usize) -> bool;
    fn franka_msgs__action__Homing_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Homing_GetResult_Response>);
    fn franka_msgs__action__Homing_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Homing_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Homing_GetResult_Response>) -> bool;
}

// Corresponds to franka_msgs__action__Homing_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Homing_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Homing_Result,

}



impl Default for Homing_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Homing_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Homing_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Homing_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Homing_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Homing_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Homing_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Homing_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Homing_GetResult_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_SendGoal_Request__init(msg: *mut Move_SendGoal_Request) -> bool;
    fn franka_msgs__action__Move_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_SendGoal_Request>, size: usize) -> bool;
    fn franka_msgs__action__Move_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_SendGoal_Request>);
    fn franka_msgs__action__Move_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_SendGoal_Request>) -> bool;
}

// Corresponds to franka_msgs__action__Move_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Move_Goal,

}



impl Default for Move_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_SendGoal_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_SendGoal_Response__init(msg: *mut Move_SendGoal_Response) -> bool;
    fn franka_msgs__action__Move_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_SendGoal_Response>, size: usize) -> bool;
    fn franka_msgs__action__Move_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_SendGoal_Response>);
    fn franka_msgs__action__Move_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_SendGoal_Response>) -> bool;
}

// Corresponds to franka_msgs__action__Move_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Move_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_SendGoal_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_GetResult_Request__init(msg: *mut Move_GetResult_Request) -> bool;
    fn franka_msgs__action__Move_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_GetResult_Request>, size: usize) -> bool;
    fn franka_msgs__action__Move_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_GetResult_Request>);
    fn franka_msgs__action__Move_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_GetResult_Request>) -> bool;
}

// Corresponds to franka_msgs__action__Move_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Move_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_GetResult_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__Move_GetResult_Response__init(msg: *mut Move_GetResult_Response) -> bool;
    fn franka_msgs__action__Move_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Move_GetResult_Response>, size: usize) -> bool;
    fn franka_msgs__action__Move_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Move_GetResult_Response>);
    fn franka_msgs__action__Move_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Move_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Move_GetResult_Response>) -> bool;
}

// Corresponds to franka_msgs__action__Move_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Move_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Move_Result,

}



impl Default for Move_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__Move_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__Move_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Move_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__Move_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Move_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Move_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/Move_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__Move_GetResult_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_SendGoal_Request__init(msg: *mut PTPMotion_SendGoal_Request) -> bool;
    fn franka_msgs__action__PTPMotion_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Request>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Request>);
    fn franka_msgs__action__PTPMotion_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Request>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::PTPMotion_Goal,

}



impl Default for PTPMotion_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_SendGoal_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_SendGoal_Response__init(msg: *mut PTPMotion_SendGoal_Response) -> bool;
    fn franka_msgs__action__PTPMotion_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Response>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Response>);
    fn franka_msgs__action__PTPMotion_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_SendGoal_Response>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for PTPMotion_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_SendGoal_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_GetResult_Request__init(msg: *mut PTPMotion_GetResult_Request) -> bool;
    fn franka_msgs__action__PTPMotion_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Request>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Request>);
    fn franka_msgs__action__PTPMotion_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Request>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for PTPMotion_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_GetResult_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__action__PTPMotion_GetResult_Response__init(msg: *mut PTPMotion_GetResult_Response) -> bool;
    fn franka_msgs__action__PTPMotion_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Response>, size: usize) -> bool;
    fn franka_msgs__action__PTPMotion_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Response>);
    fn franka_msgs__action__PTPMotion_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PTPMotion_GetResult_Response>) -> bool;
}

// Corresponds to franka_msgs__action__PTPMotion_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PTPMotion_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::PTPMotion_Result,

}



impl Default for PTPMotion_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__action__PTPMotion_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__action__PTPMotion_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PTPMotion_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__action__PTPMotion_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PTPMotion_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PTPMotion_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/action/PTPMotion_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__action__PTPMotion_GetResult_Response() }
  }
}






#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__ErrorRecovery_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__ErrorRecovery_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ErrorRecovery_SendGoal;

impl rosidl_runtime_rs::Service for ErrorRecovery_SendGoal {
    type Request = ErrorRecovery_SendGoal_Request;
    type Response = ErrorRecovery_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__ErrorRecovery_SendGoal() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__ErrorRecovery_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__ErrorRecovery_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ErrorRecovery_GetResult;

impl rosidl_runtime_rs::Service for ErrorRecovery_GetResult {
    type Request = ErrorRecovery_GetResult_Request;
    type Response = ErrorRecovery_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__ErrorRecovery_GetResult() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Grasp_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__Grasp_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Grasp_SendGoal;

impl rosidl_runtime_rs::Service for Grasp_SendGoal {
    type Request = Grasp_SendGoal_Request;
    type Response = Grasp_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Grasp_SendGoal() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Grasp_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__Grasp_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Grasp_GetResult;

impl rosidl_runtime_rs::Service for Grasp_GetResult {
    type Request = Grasp_GetResult_Request;
    type Response = Grasp_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Grasp_GetResult() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Homing_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__Homing_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Homing_SendGoal;

impl rosidl_runtime_rs::Service for Homing_SendGoal {
    type Request = Homing_SendGoal_Request;
    type Response = Homing_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Homing_SendGoal() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Homing_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__Homing_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Homing_GetResult;

impl rosidl_runtime_rs::Service for Homing_GetResult {
    type Request = Homing_GetResult_Request;
    type Response = Homing_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Homing_GetResult() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Move_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__Move_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Move_SendGoal;

impl rosidl_runtime_rs::Service for Move_SendGoal {
    type Request = Move_SendGoal_Request;
    type Response = Move_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Move_SendGoal() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Move_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__Move_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Move_GetResult;

impl rosidl_runtime_rs::Service for Move_GetResult {
    type Request = Move_GetResult_Request;
    type Response = Move_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__Move_GetResult() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__PTPMotion_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__PTPMotion_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct PTPMotion_SendGoal;

impl rosidl_runtime_rs::Service for PTPMotion_SendGoal {
    type Request = PTPMotion_SendGoal_Request;
    type Response = PTPMotion_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__PTPMotion_SendGoal() }
    }
}




#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__PTPMotion_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to franka_msgs__action__PTPMotion_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct PTPMotion_GetResult;

impl rosidl_runtime_rs::Service for PTPMotion_GetResult {
    type Request = PTPMotion_GetResult_Request;
    type Response = PTPMotion_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_msgs__action__PTPMotion_GetResult() }
    }
}


