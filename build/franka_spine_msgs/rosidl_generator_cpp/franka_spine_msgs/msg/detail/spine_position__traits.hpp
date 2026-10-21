// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from franka_spine_msgs:msg/SpinePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_position.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__TRAITS_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "franka_spine_msgs/msg/detail/spine_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace franka_spine_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpinePosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
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
  const SpinePosition & msg,
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

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
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

inline std::string to_yaml(const SpinePosition & msg, bool use_flow_style = false)
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
  const franka_spine_msgs::msg::SpinePosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_spine_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_spine_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const franka_spine_msgs::msg::SpinePosition & msg)
{
  return franka_spine_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<franka_spine_msgs::msg::SpinePosition>()
{
  return "franka_spine_msgs::msg::SpinePosition";
}

template<>
inline const char * name<franka_spine_msgs::msg::SpinePosition>()
{
  return "franka_spine_msgs/msg/SpinePosition";
}

template<>
struct has_fixed_size<franka_spine_msgs::msg::SpinePosition>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<franka_spine_msgs::msg::SpinePosition>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<franka_spine_msgs::msg::SpinePosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__TRAITS_HPP_
