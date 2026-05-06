// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cl_arganello_interface:msg/DebugMessage.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__BUILDER_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cl_arganello_interface/msg/detail/debug_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cl_arganello_interface
{

namespace msg
{

namespace builder
{

class Init_DebugMessage_rope_speed_m_s
{
public:
  explicit Init_DebugMessage_rope_speed_m_s(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  ::cl_arganello_interface::msg::DebugMessage rope_speed_m_s(::cl_arganello_interface::msg::DebugMessage::_rope_speed_m_s_type arg)
  {
    msg_.rope_speed_m_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_sync_roller_speed_rad_s
{
public:
  explicit Init_DebugMessage_sync_roller_speed_rad_s(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_rope_speed_m_s sync_roller_speed_rad_s(::cl_arganello_interface::msg::DebugMessage::_sync_roller_speed_rad_s_type arg)
  {
    msg_.sync_roller_speed_rad_s = std::move(arg);
    return Init_DebugMessage_rope_speed_m_s(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_sync_roller_speed_rev_s
{
public:
  explicit Init_DebugMessage_sync_roller_speed_rev_s(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_sync_roller_speed_rad_s sync_roller_speed_rev_s(::cl_arganello_interface::msg::DebugMessage::_sync_roller_speed_rev_s_type arg)
  {
    msg_.sync_roller_speed_rev_s = std::move(arg);
    return Init_DebugMessage_sync_roller_speed_rad_s(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_motor_speed_rad_s
{
public:
  explicit Init_DebugMessage_motor_speed_rad_s(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_sync_roller_speed_rev_s motor_speed_rad_s(::cl_arganello_interface::msg::DebugMessage::_motor_speed_rad_s_type arg)
  {
    msg_.motor_speed_rad_s = std::move(arg);
    return Init_DebugMessage_sync_roller_speed_rev_s(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_motor_speed_rev_s
{
public:
  explicit Init_DebugMessage_motor_speed_rev_s(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_motor_speed_rad_s motor_speed_rev_s(::cl_arganello_interface::msg::DebugMessage::_motor_speed_rev_s_type arg)
  {
    msg_.motor_speed_rev_s = std::move(arg);
    return Init_DebugMessage_motor_speed_rad_s(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_motor_position
{
public:
  explicit Init_DebugMessage_motor_position(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_motor_speed_rev_s motor_position(::cl_arganello_interface::msg::DebugMessage::_motor_position_type arg)
  {
    msg_.motor_position = std::move(arg);
    return Init_DebugMessage_motor_speed_rev_s(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_syncronous_roller_raw_wrapped
{
public:
  explicit Init_DebugMessage_syncronous_roller_raw_wrapped(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_motor_position syncronous_roller_raw_wrapped(::cl_arganello_interface::msg::DebugMessage::_syncronous_roller_raw_wrapped_type arg)
  {
    msg_.syncronous_roller_raw_wrapped = std::move(arg);
    return Init_DebugMessage_motor_position(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_motor_torque
{
public:
  explicit Init_DebugMessage_motor_torque(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_syncronous_roller_raw_wrapped motor_torque(::cl_arganello_interface::msg::DebugMessage::_motor_torque_type arg)
  {
    msg_.motor_torque = std::move(arg);
    return Init_DebugMessage_syncronous_roller_raw_wrapped(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_current
{
public:
  explicit Init_DebugMessage_current(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_motor_torque current(::cl_arganello_interface::msg::DebugMessage::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_DebugMessage_motor_torque(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_brake
{
public:
  explicit Init_DebugMessage_brake(::cl_arganello_interface::msg::DebugMessage & msg)
  : msg_(msg)
  {}
  Init_DebugMessage_current brake(::cl_arganello_interface::msg::DebugMessage::_brake_type arg)
  {
    msg_.brake = std::move(arg);
    return Init_DebugMessage_current(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

class Init_DebugMessage_header
{
public:
  Init_DebugMessage_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DebugMessage_brake header(::cl_arganello_interface::msg::DebugMessage::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DebugMessage_brake(msg_);
  }

private:
  ::cl_arganello_interface::msg::DebugMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cl_arganello_interface::msg::DebugMessage>()
{
  return cl_arganello_interface::msg::builder::Init_DebugMessage_header();
}

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__BUILDER_HPP_
