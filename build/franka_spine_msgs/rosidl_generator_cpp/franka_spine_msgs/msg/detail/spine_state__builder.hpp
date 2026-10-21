// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:msg/SpineState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_state.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/msg/detail/spine_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace msg
{

namespace builder
{

class Init_SpineState_valid
{
public:
  explicit Init_SpineState_valid(::franka_spine_msgs::msg::SpineState & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::msg::SpineState valid(::franka_spine_msgs::msg::SpineState::_valid_type arg)
  {
    msg_.valid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpineState msg_;
};

class Init_SpineState_error_description
{
public:
  explicit Init_SpineState_error_description(::franka_spine_msgs::msg::SpineState & msg)
  : msg_(msg)
  {}
  Init_SpineState_valid error_description(::franka_spine_msgs::msg::SpineState::_error_description_type arg)
  {
    msg_.error_description = std::move(arg);
    return Init_SpineState_valid(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpineState msg_;
};

class Init_SpineState_error_code
{
public:
  explicit Init_SpineState_error_code(::franka_spine_msgs::msg::SpineState & msg)
  : msg_(msg)
  {}
  Init_SpineState_error_description error_code(::franka_spine_msgs::msg::SpineState::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_SpineState_error_description(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpineState msg_;
};

class Init_SpineState_state
{
public:
  explicit Init_SpineState_state(::franka_spine_msgs::msg::SpineState & msg)
  : msg_(msg)
  {}
  Init_SpineState_error_code state(::franka_spine_msgs::msg::SpineState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_SpineState_error_code(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpineState msg_;
};

class Init_SpineState_header
{
public:
  Init_SpineState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpineState_state header(::franka_spine_msgs::msg::SpineState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SpineState_state(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpineState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::msg::SpineState>()
{
  return franka_spine_msgs::msg::builder::Init_SpineState_header();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__BUILDER_HPP_
