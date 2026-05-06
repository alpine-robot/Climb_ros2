// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cl_arganello_interface:msg/DebugMessage.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__TRAITS_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cl_arganello_interface/msg/detail/debug_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cl_arganello_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const DebugMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: brake
  {
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: motor_torque
  {
    out << "motor_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_torque, out);
    out << ", ";
  }

  // member: syncronous_roller_raw_wrapped
  {
    out << "syncronous_roller_raw_wrapped: ";
    rosidl_generator_traits::value_to_yaml(msg.syncronous_roller_raw_wrapped, out);
    out << ", ";
  }

  // member: motor_position
  {
    out << "motor_position: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_position, out);
    out << ", ";
  }

  // member: motor_speed_rev_s
  {
    out << "motor_speed_rev_s: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_speed_rev_s, out);
    out << ", ";
  }

  // member: motor_speed_rad_s
  {
    out << "motor_speed_rad_s: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_speed_rad_s, out);
    out << ", ";
  }

  // member: sync_roller_speed_rev_s
  {
    out << "sync_roller_speed_rev_s: ";
    rosidl_generator_traits::value_to_yaml(msg.sync_roller_speed_rev_s, out);
    out << ", ";
  }

  // member: sync_roller_speed_rad_s
  {
    out << "sync_roller_speed_rad_s: ";
    rosidl_generator_traits::value_to_yaml(msg.sync_roller_speed_rad_s, out);
    out << ", ";
  }

  // member: rope_speed_m_s
  {
    out << "rope_speed_m_s: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_speed_m_s, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DebugMessage & msg,
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

  // member: brake
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "brake: ";
    rosidl_generator_traits::value_to_yaml(msg.brake, out);
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

  // member: motor_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_torque, out);
    out << "\n";
  }

  // member: syncronous_roller_raw_wrapped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "syncronous_roller_raw_wrapped: ";
    rosidl_generator_traits::value_to_yaml(msg.syncronous_roller_raw_wrapped, out);
    out << "\n";
  }

  // member: motor_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_position: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_position, out);
    out << "\n";
  }

  // member: motor_speed_rev_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_speed_rev_s: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_speed_rev_s, out);
    out << "\n";
  }

  // member: motor_speed_rad_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_speed_rad_s: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_speed_rad_s, out);
    out << "\n";
  }

  // member: sync_roller_speed_rev_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sync_roller_speed_rev_s: ";
    rosidl_generator_traits::value_to_yaml(msg.sync_roller_speed_rev_s, out);
    out << "\n";
  }

  // member: sync_roller_speed_rad_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sync_roller_speed_rad_s: ";
    rosidl_generator_traits::value_to_yaml(msg.sync_roller_speed_rad_s, out);
    out << "\n";
  }

  // member: rope_speed_m_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_speed_m_s: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_speed_m_s, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DebugMessage & msg, bool use_flow_style = false)
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
  const cl_arganello_interface::msg::DebugMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  cl_arganello_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cl_arganello_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const cl_arganello_interface::msg::DebugMessage & msg)
{
  return cl_arganello_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cl_arganello_interface::msg::DebugMessage>()
{
  return "cl_arganello_interface::msg::DebugMessage";
}

template<>
inline const char * name<cl_arganello_interface::msg::DebugMessage>()
{
  return "cl_arganello_interface/msg/DebugMessage";
}

template<>
struct has_fixed_size<cl_arganello_interface::msg::DebugMessage>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cl_arganello_interface::msg::DebugMessage>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cl_arganello_interface::msg::DebugMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__TRAITS_HPP_
