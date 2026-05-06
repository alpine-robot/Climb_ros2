// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__TRAITS_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cl_arganello_interface/msg/detail/imus__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cl_arganello_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Imus & msg,
  std::ostream & out)
{
  out << "{";
  // member: epoch_ms
  {
    out << "epoch_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.epoch_ms, out);
    out << ", ";
  }

  // member: imu1
  {
    if (msg.imu1.size() == 0) {
      out << "imu1: []";
    } else {
      out << "imu1: [";
      size_t pending_items = msg.imu1.size();
      for (auto item : msg.imu1) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: imu2
  {
    if (msg.imu2.size() == 0) {
      out << "imu2: []";
    } else {
      out << "imu2: [";
      size_t pending_items = msg.imu2.size();
      for (auto item : msg.imu2) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Imus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: epoch_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "epoch_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.epoch_ms, out);
    out << "\n";
  }

  // member: imu1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imu1.size() == 0) {
      out << "imu1: []\n";
    } else {
      out << "imu1:\n";
      for (auto item : msg.imu1) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: imu2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imu2.size() == 0) {
      out << "imu2: []\n";
    } else {
      out << "imu2:\n";
      for (auto item : msg.imu2) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Imus & msg, bool use_flow_style = false)
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
  const cl_arganello_interface::msg::Imus & msg,
  std::ostream & out, size_t indentation = 0)
{
  cl_arganello_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cl_arganello_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const cl_arganello_interface::msg::Imus & msg)
{
  return cl_arganello_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cl_arganello_interface::msg::Imus>()
{
  return "cl_arganello_interface::msg::Imus";
}

template<>
inline const char * name<cl_arganello_interface::msg::Imus>()
{
  return "cl_arganello_interface/msg/Imus";
}

template<>
struct has_fixed_size<cl_arganello_interface::msg::Imus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cl_arganello_interface::msg::Imus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cl_arganello_interface::msg::Imus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__TRAITS_HPP_
