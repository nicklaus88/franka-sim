// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:msg/SpinePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_position.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/msg/detail/spine_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace msg
{

namespace builder
{

class Init_SpinePosition_valid
{
public:
  explicit Init_SpinePosition_valid(::franka_spine_msgs::msg::SpinePosition & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::msg::SpinePosition valid(::franka_spine_msgs::msg::SpinePosition::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpinePosition msg_;
};

class Init_SpinePosition_position
{
public:
  explicit Init_SpinePosition_position(::franka_spine_msgs::msg::SpinePosition & msg)
  : msg_(msg)
  {}
  Init_SpinePosition_valid position(::franka_spine_msgs::msg::SpinePosition::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_SpinePosition_valid(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpinePosition msg_;
};

class Init_SpinePosition_header
{
public:
  Init_SpinePosition_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpinePosition_position header(::franka_spine_msgs::msg::SpinePosition::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SpinePosition_position(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpinePosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::msg::SpinePosition>()
{
  return franka_spine_msgs::msg::builder::Init_SpinePosition_header();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__BUILDER_HPP_
