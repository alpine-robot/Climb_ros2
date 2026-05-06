#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__RopeCommand() -> *const std::ffi::c_void;
}

#[link(name = "cl_arganello_interface__rosidl_generator_c")]
extern "C" {
    fn cl_arganello_interface__msg__RopeCommand__init(msg: *mut RopeCommand) -> bool;
    fn cl_arganello_interface__msg__RopeCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RopeCommand>, size: usize) -> bool;
    fn cl_arganello_interface__msg__RopeCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RopeCommand>);
    fn cl_arganello_interface__msg__RopeCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RopeCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<RopeCommand>) -> bool;
}

// Corresponds to cl_arganello_interface__msg__RopeCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RopeCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rope_force: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rope_position: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rope_velocity: f32,

}



impl Default for RopeCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cl_arganello_interface__msg__RopeCommand__init(&mut msg as *mut _) {
        panic!("Call to cl_arganello_interface__msg__RopeCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RopeCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__RopeCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__RopeCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__RopeCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RopeCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RopeCommand where Self: Sized {
  const TYPE_NAME: &'static str = "cl_arganello_interface/msg/RopeCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__RopeCommand() }
  }
}


#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__RopeTelemetry() -> *const std::ffi::c_void;
}

#[link(name = "cl_arganello_interface__rosidl_generator_c")]
extern "C" {
    fn cl_arganello_interface__msg__RopeTelemetry__init(msg: *mut RopeTelemetry) -> bool;
    fn cl_arganello_interface__msg__RopeTelemetry__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RopeTelemetry>, size: usize) -> bool;
    fn cl_arganello_interface__msg__RopeTelemetry__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RopeTelemetry>);
    fn cl_arganello_interface__msg__RopeTelemetry__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RopeTelemetry>, out_seq: *mut rosidl_runtime_rs::Sequence<RopeTelemetry>) -> bool;
}

// Corresponds to cl_arganello_interface__msg__RopeTelemetry
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RopeTelemetry {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rope_force: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rope_length: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rope_velocity: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub brake_status: bool,

}



impl Default for RopeTelemetry {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cl_arganello_interface__msg__RopeTelemetry__init(&mut msg as *mut _) {
        panic!("Call to cl_arganello_interface__msg__RopeTelemetry__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RopeTelemetry {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__RopeTelemetry__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__RopeTelemetry__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__RopeTelemetry__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RopeTelemetry {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RopeTelemetry where Self: Sized {
  const TYPE_NAME: &'static str = "cl_arganello_interface/msg/RopeTelemetry";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__RopeTelemetry() }
  }
}


#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__DebugMessage() -> *const std::ffi::c_void;
}

#[link(name = "cl_arganello_interface__rosidl_generator_c")]
extern "C" {
    fn cl_arganello_interface__msg__DebugMessage__init(msg: *mut DebugMessage) -> bool;
    fn cl_arganello_interface__msg__DebugMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DebugMessage>, size: usize) -> bool;
    fn cl_arganello_interface__msg__DebugMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DebugMessage>);
    fn cl_arganello_interface__msg__DebugMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DebugMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<DebugMessage>) -> bool;
}

// Corresponds to cl_arganello_interface__msg__DebugMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Timestamp so PlotJuggler can use ROS time

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DebugMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// Raw inputs
    /// 1 if engaged
    pub brake: bool,

    /// A (ibus)
    pub current: f32,

    /// Nm (as reported by ODrive)
    pub motor_torque: f32,

    /// counts [0..CPR)
    pub syncronous_roller_raw_wrapped: i32,

    /// revs in [0..1)
    pub motor_position: f32,

    /// Derived (you just computed these)
    /// rev/s
    pub motor_speed_rev_s: f32,

    /// rad/s
    pub motor_speed_rad_s: f32,

    /// rev/s
    pub sync_roller_speed_rev_s: f32,

    /// rad/s
    pub sync_roller_speed_rad_s: f32,

    /// m/s (roller linear)
    pub rope_speed_m_s: f32,

}



impl Default for DebugMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cl_arganello_interface__msg__DebugMessage__init(&mut msg as *mut _) {
        panic!("Call to cl_arganello_interface__msg__DebugMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DebugMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__DebugMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__DebugMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__DebugMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DebugMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DebugMessage where Self: Sized {
  const TYPE_NAME: &'static str = "cl_arganello_interface/msg/DebugMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__DebugMessage() }
  }
}


#[link(name = "cl_arganello_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__Imus() -> *const std::ffi::c_void;
}

#[link(name = "cl_arganello_interface__rosidl_generator_c")]
extern "C" {
    fn cl_arganello_interface__msg__Imus__init(msg: *mut Imus) -> bool;
    fn cl_arganello_interface__msg__Imus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Imus>, size: usize) -> bool;
    fn cl_arganello_interface__msg__Imus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Imus>);
    fn cl_arganello_interface__msg__Imus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Imus>, out_seq: *mut rosidl_runtime_rs::Sequence<Imus>) -> bool;
}

// Corresponds to cl_arganello_interface__msg__Imus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// alpine_msgs/msg/AlpineDualImu.msg

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Imus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub epoch_ms: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imu1: [f32; 11],


    // This member is not documented.
    #[allow(missing_docs)]
    pub imu2: [f32; 11],

}



impl Default for Imus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cl_arganello_interface__msg__Imus__init(&mut msg as *mut _) {
        panic!("Call to cl_arganello_interface__msg__Imus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Imus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__Imus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__Imus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cl_arganello_interface__msg__Imus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Imus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Imus where Self: Sized {
  const TYPE_NAME: &'static str = "cl_arganello_interface/msg/Imus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cl_arganello_interface__msg__Imus() }
  }
}


