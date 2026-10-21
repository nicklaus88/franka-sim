// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:srv/Halt.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/srv/halt.hpp"


#ifndef FRANKA_SPINE_MSGS__SRV__DETAIL__HALT__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__SRV__DETAIL__HALT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/srv/detail/halt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::Halt_Request>()
{
  return ::franka_spine_msgs::srv::Halt_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace srv
{

namespace builder
{

class Init_Halt_Response_message
{
public:
  explicit Init_Halt_Response_message(::franka_spine_msgs::srv::Halt_Response & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::srv::Halt_Response message(::franka_spine_msgs::srv::Halt_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::srv::Halt_Response msg_;
};

class Init_Halt_Response_success
{
public:
  explicit Init_Halt_Response_success(::franka_spine_msgs::srv::Halt_Response & msg)
  : msg_(msg)
  {}
  Init_Halt_Response_message success(::franka_spine_msgs::srv::Halt_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Halt_Response_message(msg_);
  }

private:
  ::franka_spine_msgs::srv::Halt_Response msg_;
};

class Init_Halt_Response_state
{
public:
  Init_Halt_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Halt_Response_success state(::franka_spine_msgs::srv::Halt_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_Halt_Response_success(msg_);
  }

private:
  ::franka_spine_msgs::srv::Halt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::Halt_Response>()
{
  return franka_spine_msgs::srv::builder::Init_Halt_Response_state();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace srv
{

namespace builder
{

class Init_Halt_Event_response
{
public:
  explicit Init_Halt_Event_response(::franka_spine_msgs::srv::Halt_Event & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::srv::Halt_Event response(::franka_spine_msgs::srv::Halt_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::srv::Halt_Event msg_;
};

class Init_Halt_Event_request
{
public:
  explicit Init_Halt_Event_request(::franka_spine_msgs::srv::Halt_Event & msg)
  : msg_(msg)
  {}
  Init_Halt_Event_response request(::franka_spine_msgs::srv::Halt_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Halt_Event_response(msg_);
  }

private:
  ::franka_spine_msgs::srv::Halt_Event msg_;
};

class Init_Halt_Event_info
{
public:
  Init_Halt_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Halt_Event_request info(::franka_spine_msgs::srv::Halt_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Halt_Event_request(msg_);
  }

private:
  ::franka_spine_msgs::srv::Halt_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::Halt_Event>()
{
  return franka_spine_msgs::srv::builder::Init_Halt_Event_info();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__SRV__DETAIL__HALT__BUILDER_HPP_
