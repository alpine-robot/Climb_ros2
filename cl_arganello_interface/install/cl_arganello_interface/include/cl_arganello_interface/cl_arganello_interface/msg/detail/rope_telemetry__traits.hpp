// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cl_arganello_interface:msg/RopeTelemetry.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_TELEMETRY__TRAITS_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_TELEMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cl_arganello_interface/msg/detail/rope_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cl_arganello_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RopeTelemetry & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: rope_force
  {
    out << "rope_force: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_force, out);
    out << ", ";
  }

  // member: rope_length
  {
    out << "rope_length: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_length, out);
    out << ", ";
  }

  // member: rope_velocity
  {
    out << "rope_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_velocity, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: brake_status
  {
    out << "brake_status: ";
    rosidl_generator_traits::value_to_yaml(msg.brake_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RopeTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: rope_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_force: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_force, out);
    out << "\n";
  }

  // member: rope_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_length: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_length, out);
    out << "\n";
  }

  // member: rope_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_velocity, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: brake_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "brake_status: ";
    rosidl_generator_traits::value_to_yaml(msg.brake_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RopeTelemetry & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cl_arganello_interface

namespace rosidl_generator_traits
{

[[deprecated("use cl_arganello_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cl_arganello_interface::msg::RopeTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  cl_arganello_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cl_arganello_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const cl_arganello_interface::msg::RopeTelemetry & msg)
{
  return cl_arganello_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cl_arganello_interface::msg::RopeTelemetry>()
{
  return "cl_arganello_interface::msg::RopeTelemetry";
}

template<>
inline const char * name<cl_arganello_interface::msg::RopeTelemetry>()
{
  return "cl_arganello_interface/msg/RopeTelemetry";
}

template<>
struct has_fixed_size<cl_arganello_interface::msg::RopeTelemetry>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cl_arganello_interface::msg::RopeTelemetry>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cl_arganello_interface::msg::RopeTelemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_TELEMETRY__TRAITS_HPP_
