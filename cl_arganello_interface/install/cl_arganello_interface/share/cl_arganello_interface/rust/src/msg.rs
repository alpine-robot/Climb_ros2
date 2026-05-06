#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to cl_arganello_interface__msg__RopeCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RopeCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RopeCommand::default())
  }
}

impl rosidl_runtime_rs::Message for RopeCommand {
  type RmwMsg = super::msg::rmw::RopeCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        rope_force: msg.rope_force,
        rope_position: msg.rope_position,
        rope_velocity: msg.rope_velocity,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      rope_force: msg.rope_force,
      rope_position: msg.rope_position,
      rope_velocity: msg.rope_velocity,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      rope_force: msg.rope_force,
      rope_position: msg.rope_position,
      rope_velocity: msg.rope_velocity,
    }
  }
}


// Corresponds to cl_arganello_interface__msg__RopeTelemetry

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RopeTelemetry {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RopeTelemetry::default())
  }
}

impl rosidl_runtime_rs::Message for RopeTelemetry {
  type RmwMsg = super::msg::rmw::RopeTelemetry;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        rope_force: msg.rope_force,
        rope_length: msg.rope_length,
        rope_velocity: msg.rope_velocity,
        current: msg.current,
        brake_status: msg.brake_status,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      rope_force: msg.rope_force,
      rope_length: msg.rope_length,
      rope_velocity: msg.rope_velocity,
      current: msg.current,
      brake_status: msg.brake_status,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      rope_force: msg.rope_force,
      rope_length: msg.rope_length,
      rope_velocity: msg.rope_velocity,
      current: msg.current,
      brake_status: msg.brake_status,
    }
  }
}


// Corresponds to cl_arganello_interface__msg__DebugMessage
/// Timestamp so PlotJuggler can use ROS time

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DebugMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DebugMessage::default())
  }
}

impl rosidl_runtime_rs::Message for DebugMessage {
  type RmwMsg = super::msg::rmw::DebugMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        brake: msg.brake,
        current: msg.current,
        motor_torque: msg.motor_torque,
        syncronous_roller_raw_wrapped: msg.syncronous_roller_raw_wrapped,
        motor_position: msg.motor_position,
        motor_speed_rev_s: msg.motor_speed_rev_s,
        motor_speed_rad_s: msg.motor_speed_rad_s,
        sync_roller_speed_rev_s: msg.sync_roller_speed_rev_s,
        sync_roller_speed_rad_s: msg.sync_roller_speed_rad_s,
        rope_speed_m_s: msg.rope_speed_m_s,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      brake: msg.brake,
      current: msg.current,
      motor_torque: msg.motor_torque,
      syncronous_roller_raw_wrapped: msg.syncronous_roller_raw_wrapped,
      motor_position: msg.motor_position,
      motor_speed_rev_s: msg.motor_speed_rev_s,
      motor_speed_rad_s: msg.motor_speed_rad_s,
      sync_roller_speed_rev_s: msg.sync_roller_speed_rev_s,
      sync_roller_speed_rad_s: msg.sync_roller_speed_rad_s,
      rope_speed_m_s: msg.rope_speed_m_s,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      brake: msg.brake,
      current: msg.current,
      motor_torque: msg.motor_torque,
      syncronous_roller_raw_wrapped: msg.syncronous_roller_raw_wrapped,
      motor_position: msg.motor_position,
      motor_speed_rev_s: msg.motor_speed_rev_s,
      motor_speed_rad_s: msg.motor_speed_rad_s,
      sync_roller_speed_rev_s: msg.sync_roller_speed_rev_s,
      sync_roller_speed_rad_s: msg.sync_roller_speed_rad_s,
      rope_speed_m_s: msg.rope_speed_m_s,
    }
  }
}


// Corresponds to cl_arganello_interface__msg__Imus
/// alpine_msgs/msg/AlpineDualImu.msg

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Imus::default())
  }
}

impl rosidl_runtime_rs::Message for Imus {
  type RmwMsg = super::msg::rmw::Imus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        epoch_ms: msg.epoch_ms,
        imu1: msg.imu1,
        imu2: msg.imu2,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      epoch_ms: msg.epoch_ms,
        imu1: msg.imu1,
        imu2: msg.imu2,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      epoch_ms: msg.epoch_ms,
      imu1: msg.imu1,
      imu2: msg.imu2,
    }
  }
}


