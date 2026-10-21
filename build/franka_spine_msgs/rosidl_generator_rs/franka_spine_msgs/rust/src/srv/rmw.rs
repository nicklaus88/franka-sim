#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetSpineState_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__GetSpineState_Request__init(msg: *mut GetSpineState_Request) -> bool;
    fn franka_spine_msgs__srv__GetSpineState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSpineState_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__GetSpineState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSpineState_Request>);
    fn franka_spine_msgs__srv__GetSpineState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSpineState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSpineState_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__GetSpineState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSpineState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetSpineState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__GetSpineState_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__GetSpineState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSpineState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetSpineState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetSpineState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetSpineState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSpineState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSpineState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/GetSpineState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetSpineState_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetSpineState_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__GetSpineState_Response__init(msg: *mut GetSpineState_Response) -> bool;
    fn franka_spine_msgs__srv__GetSpineState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSpineState_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__GetSpineState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSpineState_Response>);
    fn franka_spine_msgs__srv__GetSpineState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSpineState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSpineState_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__GetSpineState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSpineState_Response {
    /// Current spine state
    pub state: rosidl_runtime_rs::String,

    /// Error code (empty when no error)
    pub error_code: rosidl_runtime_rs::String,

    /// Human-readable error description
    pub error_description: rosidl_runtime_rs::String,

    /// True if the REST call succeeded
    pub success: bool,

}



impl Default for GetSpineState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__GetSpineState_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__GetSpineState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSpineState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetSpineState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetSpineState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetSpineState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSpineState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSpineState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/GetSpineState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetSpineState_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetPosition_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__GetPosition_Request__init(msg: *mut GetPosition_Request) -> bool;
    fn franka_spine_msgs__srv__GetPosition_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPosition_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__GetPosition_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPosition_Request>);
    fn franka_spine_msgs__srv__GetPosition_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPosition_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPosition_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__GetPosition_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPosition_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetPosition_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__GetPosition_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__GetPosition_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPosition_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetPosition_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetPosition_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetPosition_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPosition_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPosition_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/GetPosition_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetPosition_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetPosition_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__GetPosition_Response__init(msg: *mut GetPosition_Response) -> bool;
    fn franka_spine_msgs__srv__GetPosition_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPosition_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__GetPosition_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPosition_Response>);
    fn franka_spine_msgs__srv__GetPosition_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPosition_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPosition_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__GetPosition_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPosition_Response {
    /// Current position
    pub position: f64,

    /// True if the REST call succeeded
    pub success: bool,

}



impl Default for GetPosition_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__GetPosition_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__GetPosition_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPosition_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetPosition_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetPosition_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetPosition_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPosition_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPosition_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/GetPosition_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetPosition_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__FaultReset_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__FaultReset_Request__init(msg: *mut FaultReset_Request) -> bool;
    fn franka_spine_msgs__srv__FaultReset_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FaultReset_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__FaultReset_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FaultReset_Request>);
    fn franka_spine_msgs__srv__FaultReset_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FaultReset_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<FaultReset_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__FaultReset_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FaultReset_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for FaultReset_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__FaultReset_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__FaultReset_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FaultReset_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__FaultReset_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__FaultReset_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__FaultReset_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FaultReset_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FaultReset_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/FaultReset_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__FaultReset_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__FaultReset_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__FaultReset_Response__init(msg: *mut FaultReset_Response) -> bool;
    fn franka_spine_msgs__srv__FaultReset_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FaultReset_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__FaultReset_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FaultReset_Response>);
    fn franka_spine_msgs__srv__FaultReset_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FaultReset_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<FaultReset_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__FaultReset_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FaultReset_Response {
    /// Spine state after the reset
    pub state: rosidl_runtime_rs::String,

    /// True if the fault was cleared
    pub success: bool,

    /// Human-readable status or error description
    pub message: rosidl_runtime_rs::String,

}



impl Default for FaultReset_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__FaultReset_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__FaultReset_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FaultReset_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__FaultReset_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__FaultReset_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__FaultReset_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FaultReset_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FaultReset_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/FaultReset_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__FaultReset_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOn_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__SwitchOn_Request__init(msg: *mut SwitchOn_Request) -> bool;
    fn franka_spine_msgs__srv__SwitchOn_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SwitchOn_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__SwitchOn_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SwitchOn_Request>);
    fn franka_spine_msgs__srv__SwitchOn_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SwitchOn_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SwitchOn_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__SwitchOn_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SwitchOn_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SwitchOn_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__SwitchOn_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__SwitchOn_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SwitchOn_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOn_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOn_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOn_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SwitchOn_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SwitchOn_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/SwitchOn_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOn_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOn_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__SwitchOn_Response__init(msg: *mut SwitchOn_Response) -> bool;
    fn franka_spine_msgs__srv__SwitchOn_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SwitchOn_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__SwitchOn_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SwitchOn_Response>);
    fn franka_spine_msgs__srv__SwitchOn_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SwitchOn_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SwitchOn_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__SwitchOn_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SwitchOn_Response {
    /// Spine state after switching on
    pub state: rosidl_runtime_rs::String,

    /// True if the transition succeeded
    pub success: bool,

    /// Human-readable status or error description
    pub message: rosidl_runtime_rs::String,

}



impl Default for SwitchOn_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__SwitchOn_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__SwitchOn_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SwitchOn_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOn_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOn_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOn_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SwitchOn_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SwitchOn_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/SwitchOn_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOn_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOff_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__SwitchOff_Request__init(msg: *mut SwitchOff_Request) -> bool;
    fn franka_spine_msgs__srv__SwitchOff_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SwitchOff_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__SwitchOff_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SwitchOff_Request>);
    fn franka_spine_msgs__srv__SwitchOff_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SwitchOff_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SwitchOff_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__SwitchOff_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SwitchOff_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SwitchOff_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__SwitchOff_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__SwitchOff_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SwitchOff_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOff_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOff_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOff_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SwitchOff_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SwitchOff_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/SwitchOff_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOff_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOff_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__SwitchOff_Response__init(msg: *mut SwitchOff_Response) -> bool;
    fn franka_spine_msgs__srv__SwitchOff_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SwitchOff_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__SwitchOff_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SwitchOff_Response>);
    fn franka_spine_msgs__srv__SwitchOff_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SwitchOff_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SwitchOff_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__SwitchOff_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SwitchOff_Response {
    /// Spine state after switching off
    pub state: rosidl_runtime_rs::String,

    /// True if the transition succeeded
    pub success: bool,

    /// Human-readable status or error description
    pub message: rosidl_runtime_rs::String,

}



impl Default for SwitchOff_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__SwitchOff_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__SwitchOff_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SwitchOff_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOff_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOff_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__SwitchOff_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SwitchOff_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SwitchOff_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/SwitchOff_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__SwitchOff_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__Halt_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__Halt_Request__init(msg: *mut Halt_Request) -> bool;
    fn franka_spine_msgs__srv__Halt_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Halt_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__Halt_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Halt_Request>);
    fn franka_spine_msgs__srv__Halt_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Halt_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Halt_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__Halt_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Halt_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Halt_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__Halt_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__Halt_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Halt_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__Halt_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__Halt_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__Halt_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Halt_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Halt_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/Halt_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__Halt_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__Halt_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__Halt_Response__init(msg: *mut Halt_Response) -> bool;
    fn franka_spine_msgs__srv__Halt_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Halt_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__Halt_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Halt_Response>);
    fn franka_spine_msgs__srv__Halt_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Halt_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Halt_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__Halt_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Halt_Response {
    /// Spine state after the halt
    pub state: rosidl_runtime_rs::String,

    /// True if the halt was executed
    pub success: bool,

    /// Human-readable status or error description
    pub message: rosidl_runtime_rs::String,

}



impl Default for Halt_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__Halt_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__Halt_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Halt_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__Halt_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__Halt_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__Halt_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Halt_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Halt_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/Halt_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__Halt_Response() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetParameters_Request() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__GetParameters_Request__init(msg: *mut GetParameters_Request) -> bool;
    fn franka_spine_msgs__srv__GetParameters_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Request>, size: usize) -> bool;
    fn franka_spine_msgs__srv__GetParameters_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Request>);
    fn franka_spine_msgs__srv__GetParameters_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetParameters_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Request>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__GetParameters_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetParameters_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetParameters_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__GetParameters_Request__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__GetParameters_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetParameters_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetParameters_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetParameters_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetParameters_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetParameters_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetParameters_Request where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/GetParameters_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetParameters_Request() }
  }
}


#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetParameters_Response() -> *const std::ffi::c_void;
}

#[link(name = "franka_spine_msgs__rosidl_generator_c")]
extern "C" {
    fn franka_spine_msgs__srv__GetParameters_Response__init(msg: *mut GetParameters_Response) -> bool;
    fn franka_spine_msgs__srv__GetParameters_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Response>, size: usize) -> bool;
    fn franka_spine_msgs__srv__GetParameters_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Response>);
    fn franka_spine_msgs__srv__GetParameters_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetParameters_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetParameters_Response>) -> bool;
}

// Corresponds to franka_spine_msgs__srv__GetParameters_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetParameters_Response {
    /// Calibration and limit values
    pub parameters: super::super::msg::rmw::SpineParameters,

    /// True if the REST call succeeded
    pub success: bool,

    /// Human-readable status or error description
    pub message: rosidl_runtime_rs::String,

}



impl Default for GetParameters_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !franka_spine_msgs__srv__GetParameters_Response__init(&mut msg as *mut _) {
        panic!("Call to franka_spine_msgs__srv__GetParameters_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetParameters_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetParameters_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetParameters_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { franka_spine_msgs__srv__GetParameters_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetParameters_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetParameters_Response where Self: Sized {
  const TYPE_NAME: &'static str = "franka_spine_msgs/srv/GetParameters_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__franka_spine_msgs__srv__GetParameters_Response() }
  }
}






#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__GetSpineState() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__GetSpineState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetSpineState;

impl rosidl_runtime_rs::Service for GetSpineState {
    type Request = GetSpineState_Request;
    type Response = GetSpineState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__GetSpineState() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__GetPosition() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__GetPosition
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPosition;

impl rosidl_runtime_rs::Service for GetPosition {
    type Request = GetPosition_Request;
    type Response = GetPosition_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__GetPosition() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__FaultReset() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__FaultReset
#[allow(missing_docs, non_camel_case_types)]
pub struct FaultReset;

impl rosidl_runtime_rs::Service for FaultReset {
    type Request = FaultReset_Request;
    type Response = FaultReset_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__FaultReset() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__SwitchOn() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__SwitchOn
#[allow(missing_docs, non_camel_case_types)]
pub struct SwitchOn;

impl rosidl_runtime_rs::Service for SwitchOn {
    type Request = SwitchOn_Request;
    type Response = SwitchOn_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__SwitchOn() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__SwitchOff() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__SwitchOff
#[allow(missing_docs, non_camel_case_types)]
pub struct SwitchOff;

impl rosidl_runtime_rs::Service for SwitchOff {
    type Request = SwitchOff_Request;
    type Response = SwitchOff_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__SwitchOff() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__Halt() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__Halt
#[allow(missing_docs, non_camel_case_types)]
pub struct Halt;

impl rosidl_runtime_rs::Service for Halt {
    type Request = Halt_Request;
    type Response = Halt_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__Halt() }
    }
}




#[link(name = "franka_spine_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__GetParameters() -> *const std::ffi::c_void;
}

// Corresponds to franka_spine_msgs__srv__GetParameters
#[allow(missing_docs, non_camel_case_types)]
pub struct GetParameters;

impl rosidl_runtime_rs::Service for GetParameters {
    type Request = GetParameters_Request;
    type Response = GetParameters_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__franka_spine_msgs__srv__GetParameters() }
    }
}


