#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetCartesianStiffness_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetCartesianStiffness_Request__init(msg: *mut SetCartesianStiffness_Request) -> bool;
    fn franka_msgs__srv__SetCartesianStiffness_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetCartesianStiffness_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetCartesianStiffness_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetCartesianStiffness_Request>);
    fn franka_msgs__srv__SetCartesianStiffness_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetCartesianStiffness_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetCartesianStiffness_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetCartesianStiffness_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetCartesianStiffness_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub cartesian_stiffness: [f64; 6],

}



impl Default for SetCartesianStiffness_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetCartesianStiffness_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetCartesianStiffness_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetCartesianStiffness_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetCartesianStiffness_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetCartesianStiffness_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetCartesianStiffness_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetCartesianStiffness_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetCartesianStiffness_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetCartesianStiffness_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetCartesianStiffness_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetCartesianStiffness_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetCartesianStiffness_Response__init(msg: *mut SetCartesianStiffness_Response) -> bool;
    fn franka_msgs__srv__SetCartesianStiffness_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetCartesianStiffness_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetCartesianStiffness_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetCartesianStiffness_Response>);
    fn franka_msgs__srv__SetCartesianStiffness_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetCartesianStiffness_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetCartesianStiffness_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetCartesianStiffness_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetCartesianStiffness_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetCartesianStiffness_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetCartesianStiffness_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetCartesianStiffness_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetCartesianStiffness_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetCartesianStiffness_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetCartesianStiffness_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetCartesianStiffness_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetCartesianStiffness_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetCartesianStiffness_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetCartesianStiffness_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetCartesianStiffness_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetTCPFrame_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetTCPFrame_Request__init(msg: *mut SetTCPFrame_Request) -> bool;
    fn franka_msgs__srv__SetTCPFrame_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetTCPFrame_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetTCPFrame_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetTCPFrame_Request>);
    fn franka_msgs__srv__SetTCPFrame_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetTCPFrame_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetTCPFrame_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetTCPFrame_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetTCPFrame_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transformation: [f64; 16],

}



impl Default for SetTCPFrame_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetTCPFrame_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetTCPFrame_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetTCPFrame_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetTCPFrame_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetTCPFrame_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetTCPFrame_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetTCPFrame_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetTCPFrame_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetTCPFrame_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetTCPFrame_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetTCPFrame_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetTCPFrame_Response__init(msg: *mut SetTCPFrame_Response) -> bool;
    fn franka_msgs__srv__SetTCPFrame_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetTCPFrame_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetTCPFrame_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetTCPFrame_Response>);
    fn franka_msgs__srv__SetTCPFrame_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetTCPFrame_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetTCPFrame_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetTCPFrame_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetTCPFrame_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetTCPFrame_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetTCPFrame_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetTCPFrame_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetTCPFrame_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetTCPFrame_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetTCPFrame_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetTCPFrame_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetTCPFrame_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetTCPFrame_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetTCPFrame_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetTCPFrame_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetForceTorqueCollisionBehavior_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__init(msg: *mut SetForceTorqueCollisionBehavior_Request) -> bool;
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Request>);
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetForceTorqueCollisionBehavior_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetForceTorqueCollisionBehavior_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetForceTorqueCollisionBehavior_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetForceTorqueCollisionBehavior_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetForceTorqueCollisionBehavior_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetForceTorqueCollisionBehavior_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetForceTorqueCollisionBehavior_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__init(msg: *mut SetForceTorqueCollisionBehavior_Response) -> bool;
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Response>);
    fn franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetForceTorqueCollisionBehavior_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetForceTorqueCollisionBehavior_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetForceTorqueCollisionBehavior_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetForceTorqueCollisionBehavior_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetForceTorqueCollisionBehavior_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetForceTorqueCollisionBehavior_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetForceTorqueCollisionBehavior_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetForceTorqueCollisionBehavior_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetForceTorqueCollisionBehavior_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetFullCollisionBehavior_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetFullCollisionBehavior_Request__init(msg: *mut SetFullCollisionBehavior_Request) -> bool;
    fn franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Request>);
    fn franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetFullCollisionBehavior_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetFullCollisionBehavior_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetFullCollisionBehavior_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetFullCollisionBehavior_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetFullCollisionBehavior_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetFullCollisionBehavior_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetFullCollisionBehavior_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetFullCollisionBehavior_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetFullCollisionBehavior_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetFullCollisionBehavior_Response__init(msg: *mut SetFullCollisionBehavior_Response) -> bool;
    fn franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Response>);
    fn franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetFullCollisionBehavior_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetFullCollisionBehavior_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetFullCollisionBehavior_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetFullCollisionBehavior_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetFullCollisionBehavior_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetFullCollisionBehavior_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetFullCollisionBehavior_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetFullCollisionBehavior_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetFullCollisionBehavior_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetFullCollisionBehavior_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetFullCollisionBehavior_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetJointStiffness_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetJointStiffness_Request__init(msg: *mut SetJointStiffness_Request) -> bool;
    fn franka_msgs__srv__SetJointStiffness_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetJointStiffness_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetJointStiffness_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetJointStiffness_Request>);
    fn franka_msgs__srv__SetJointStiffness_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetJointStiffness_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetJointStiffness_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetJointStiffness_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetJointStiffness_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_stiffness: [f64; 7],

}



impl Default for SetJointStiffness_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetJointStiffness_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetJointStiffness_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetJointStiffness_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetJointStiffness_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetJointStiffness_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetJointStiffness_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetJointStiffness_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetJointStiffness_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetJointStiffness_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetJointStiffness_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetJointStiffness_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetJointStiffness_Response__init(msg: *mut SetJointStiffness_Response) -> bool;
    fn franka_msgs__srv__SetJointStiffness_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetJointStiffness_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetJointStiffness_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetJointStiffness_Response>);
    fn franka_msgs__srv__SetJointStiffness_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetJointStiffness_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetJointStiffness_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetJointStiffness_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetJointStiffness_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetJointStiffness_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetJointStiffness_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetJointStiffness_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetJointStiffness_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetJointStiffness_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetJointStiffness_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetJointStiffness_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetJointStiffness_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetJointStiffness_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetJointStiffness_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetJointStiffness_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetStiffnessFrame_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetStiffnessFrame_Request__init(msg: *mut SetStiffnessFrame_Request) -> bool;
    fn franka_msgs__srv__SetStiffnessFrame_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetStiffnessFrame_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetStiffnessFrame_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetStiffnessFrame_Request>);
    fn franka_msgs__srv__SetStiffnessFrame_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetStiffnessFrame_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetStiffnessFrame_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetStiffnessFrame_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetStiffnessFrame_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub transformation: [f64; 16],

}



impl Default for SetStiffnessFrame_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetStiffnessFrame_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetStiffnessFrame_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetStiffnessFrame_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetStiffnessFrame_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetStiffnessFrame_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetStiffnessFrame_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetStiffnessFrame_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetStiffnessFrame_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetStiffnessFrame_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetStiffnessFrame_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetStiffnessFrame_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetStiffnessFrame_Response__init(msg: *mut SetStiffnessFrame_Response) -> bool;
    fn franka_msgs__srv__SetStiffnessFrame_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetStiffnessFrame_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetStiffnessFrame_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetStiffnessFrame_Response>);
    fn franka_msgs__srv__SetStiffnessFrame_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetStiffnessFrame_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetStiffnessFrame_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetStiffnessFrame_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetStiffnessFrame_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetStiffnessFrame_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetStiffnessFrame_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetStiffnessFrame_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetStiffnessFrame_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetStiffnessFrame_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetStiffnessFrame_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetStiffnessFrame_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetStiffnessFrame_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetStiffnessFrame_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetStiffnessFrame_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetStiffnessFrame_Response() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetLoad_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetLoad_Request__init(msg: *mut SetLoad_Request) -> bool;
    fn franka_msgs__srv__SetLoad_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetLoad_Request>, size: usize) -> bool;
    fn franka_msgs__srv__SetLoad_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetLoad_Request>);
    fn franka_msgs__srv__SetLoad_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetLoad_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetLoad_Request>) -> bool;
}

// Corresponds to franka_msgs__srv__SetLoad_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetLoad_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetLoad_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetLoad_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetLoad_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetLoad_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetLoad_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetLoad_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetLoad_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetLoad_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetLoad_Request() }
  }
}


#[link(name = "franka_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetLoad_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_msgs__srv__SetLoad_Response__init(msg: *mut SetLoad_Response) -> bool;
    fn franka_msgs__srv__SetLoad_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetLoad_Response>, size: usize) -> bool;
    fn franka_msgs__srv__SetLoad_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetLoad_Response>);
    fn franka_msgs__srv__SetLoad_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetLoad_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetLoad_Response>) -> bool;
}

// Corresponds to franka_msgs__srv__SetLoad_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetLoad_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for SetLoad_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_msgs__srv__SetLoad_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_msgs__srv__SetLoad_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetLoad_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetLoad_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetLoad_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_msgs__srv__SetLoad_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetLoad_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetLoad_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_msgs/srv/SetLoad_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_msgs__srv__SetLoad_Response() }
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


