// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cl_arganello_interface:msg/RopeTelemetry.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_TELEMETRY__BUILDER_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cl_arganello_interface/msg/detail/rope_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cl_arganello_interface
{

namespace msg
{

namespace builder
{

class Init_RopeTelemetry_brake_status
{
public:
  explicit Init_RopeTelemetry_brake_status(::cl_arganello_interface::msg::RopeTelemetry & msg)
  : msg_(msg)
  {}
  ::cl_arganello_interface::msg::RopeTelemetry brake_status(::cl_arganello_interface::msg::RopeTelemetry::_brake_status_type arg)
  {
    msg_.brake_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeTelemetry msg_;
};

class Init_RopeTelemetry_current
{
public:
  explicit Init_RopeTelemetry_current(::cl_arganello_interface::msg::RopeTelemetry & msg)
  : msg_(msg)
  {}
  Init_RopeTelemetry_brake_status current(::cl_arganello_interface::msg::RopeTelemetry::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_RopeTelemetry_brake_status(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeTelemetry msg_;
};

class Init_RopeTelemetry_rope_velocity
{
public:
  explicit Init_RopeTelemetry_rope_velocity(::cl_arganello_interface::msg::RopeTelemetry & msg)
  : msg_(msg)
  {}
  Init_RopeTelemetry_current rope_velocity(::cl_arganello_interface::msg::RopeTelemetry::_rope_velocity_type arg)
  {
    msg_.rope_velocity = std::move(arg);
    return Init_RopeTelemetry_current(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeTelemetry msg_;
};

class Init_RopeTelemetry_rope_length
{
public:
  explicit Init_RopeTelemetry_rope_length(::cl_arganello_interface::msg::RopeTelemetry & msg)
  : msg_(msg)
  {}
  Init_RopeTelemetry_rope_velocity rope_length(::cl_arganello_interface::msg::RopeTelemetry::_rope_length_type arg)
  {
    msg_.rope_length = std::move(arg);
    return Init_RopeTelemetry_rope_velocity(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeTelemetry msg_;
};

class Init_RopeTelemetry_rope_force
{
public:
  explicit Init_RopeTelemetry_rope_force(::cl_arganello_interface::msg::RopeTelemetry & msg)
  : msg_(msg)
  {}
  Init_RopeTelemetry_rope_length rope_force(::cl_arganello_interface::msg::RopeTelemetry::_rope_force_type arg)
  {
    msg_.rope_force = std::move(arg);
    return Init_RopeTelemetry_rope_length(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeTelemetry msg_;
};

class Init_RopeTelemetry_header
{
public:
  Init_RopeTelemetry_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RopeTelemetry_rope_force header(::cl_arganello_interface::msg::RopeTelemetry::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RopeTelemetry_rope_force(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeTelemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cl_arganello_interface::msg::RopeTelemetry>()
{
  return cl_arganello_interface::msg::builder::Init_RopeTelemetry_header();
}

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_TELEMETRY__BUILDER_HPP_
