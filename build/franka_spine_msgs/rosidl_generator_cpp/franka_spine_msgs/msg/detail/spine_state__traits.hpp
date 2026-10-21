// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from franka_spine_msgs:msg/SpineState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_state.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__TRAITS_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "franka_spine_msgs/msg/detail/spine_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace franka_spine_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpineState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: error_description
  {
    out << "error_description: ";
    rosidl_generator_traits::value_to_yaml(msg.error_description, out);
    out << ", ";
  }

  // member: valid
  {
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpineState & msg,
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

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }

  // member: error_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_description: ";
    rosidl_generator_traits::value_to_yaml(msg.error_description, out);
    out << "\n";
  }

  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid: ";
    rosidl_generator_traits::value_to_yaml(msg.valid, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpineState & msg, bool use_flow_style = false)
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

}  // namespace franka_spine_msgs

namespace rosidl_generator_traits
{

[[deprecated("use franka_spine_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_spine_msgs::msg::SpineState & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_spine_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_spine_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const franka_spine_msgs::msg::SpineState & msg)
{
  return franka_spine_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<franka_spine_msgs::msg::SpineState>()
{
  return "franka_spine_msgs::msg::SpineState";
}

template<>
inline const char * name<franka_spine_msgs::msg::SpineState>()
{
  return "franka_spine_msgs/msg/SpineState";
}

template<>
struct has_fixed_size<franka_spine_msgs::msg::SpineState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<franka_spine_msgs::msg::SpineState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<franka_spine_msgs::msg::SpineState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__TRAITS_HPP_
