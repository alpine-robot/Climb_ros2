#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__srv__RopeControlMode_Request() -> *const std::ffi::c_void;
}

#[link(name = "cl_arganello_interface__rosidl_generator_c")]
extern "C" {
    fn cl_arganello_interface__srv__RopeControlMode_Request__init(msg: *mut RopeControlMode_Request) -> bool;
    fn cl_arganello_interface__srv__RopeControlMode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RopeControlMode_Request>, size: usize) -> bool;
    fn cl_arganello_interface__srv__RopeControlMode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RopeControlMode_Request>);
    fn cl_arganello_interface__srv__RopeControlMode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RopeControlMode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RopeControlMode_Request>) -> bool;
}

// Corresponds to cl_arganello_interface__srv__RopeControlMode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RopeControlMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for RopeControlMode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cl_arganello_interface__srv__RopeControlMode_Request__init(&mut msg as *mut _) {
        panic!("Call to cl_arganello_interface__srv__RopeControlMode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RopeControlMode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__srv__RopeControlMode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__srv__RopeControlMode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__srv__RopeControlMode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RopeControlMode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RopeControlMode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "cl_arganello_interface/srv/RopeControlMode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__srv__RopeControlMode_Request() }
  }
}


#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__srv__RopeControlMode_Response() -> *const std::ffi::c_void;
}

#[link(name = "cl_arganello_interface__rosidl_generator_c")]
extern "C" {
    fn cl_arganello_interface__srv__RopeControlMode_Response__init(msg: *mut RopeControlMode_Response) -> bool;
    fn cl_arganello_interface__srv__RopeControlMode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RopeControlMode_Response>, size: usize) -> bool;
    fn cl_arganello_interface__srv__RopeControlMode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RopeControlMode_Response>);
    fn cl_arganello_interface__srv__RopeControlMode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RopeControlMode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RopeControlMode_Response>) -> bool;
}

// Corresponds to cl_arganello_interface__srv__RopeControlMode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RopeControlMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for RopeControlMode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cl_arganello_interface__srv__RopeControlMode_Response__init(&mut msg as *mut _) {
        panic!("Call to cl_arganello_interface__srv__RopeControlMode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RopeControlMode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__srv__RopeControlMode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__srv__RopeControlMode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__srv__RopeControlMode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RopeControlMode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RopeControlMode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "cl_arganello_interface/srv/RopeControlMode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__srv__RopeControlMode_Response() }
  }
}






#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__cl_arganello_interface__srv__RopeControlMode() -> *const std::ffi::c_void;
}

// Corresponds to cl_arganello_interface__srv__RopeControlMode
#[allow(missing_docs, non_camel_case_types)]
pub struct RopeControlMode;

impl rosidl_runtime_rs::Service for RopeControlMode {
    type Request = RopeControlMode_Request;
    type Response = RopeControlMode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__cl_arganello_interface__srv__RopeControlMode() }
    }
}


