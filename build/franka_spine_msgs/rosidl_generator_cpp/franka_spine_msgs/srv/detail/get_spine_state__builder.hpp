// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:srv/GetSpineState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/srv/get_spine_state.hpp"


#ifndef FRANKA_SPINE_MSGS__SRV__DETAIL__GET_SPINE_STATE__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__SRV__DETAIL__GET_SPINE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/srv/detail/get_spine_state__struct.hpp"
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
auto build<::franka_spine_msgs::srv::GetSpineState_Request>()
{
  return ::franka_spine_msgs::srv::GetSpineState_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSpineState_Response_success
{
public:
  explicit Init_GetSpineState_Response_success(::franka_spine_msgs::srv::GetSpineState_Response & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::srv::GetSpineState_Response success(::franka_spine_msgs::srv::GetSpineState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Response msg_;
};

class Init_GetSpineState_Response_error_description
{
public:
  explicit Init_GetSpineState_Response_error_description(::franka_spine_msgs::srv::GetSpineState_Response & msg)
  : msg_(msg)
  {}
  Init_GetSpineState_Response_success error_description(::franka_spine_msgs::srv::GetSpineState_Response::_error_description_type arg)
  {
    msg_.error_description = std::move(arg);
    return Init_GetSpineState_Response_success(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Response msg_;
};

class Init_GetSpineState_Response_error_code
{
public:
  explicit Init_GetSpineState_Response_error_code(::franka_spine_msgs::srv::GetSpineState_Response & msg)
  : msg_(msg)
  {}
  Init_GetSpineState_Response_error_description error_code(::franka_spine_msgs::srv::GetSpineState_Response::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_GetSpineState_Response_error_description(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Response msg_;
};

class Init_GetSpineState_Response_state
{
public:
  Init_GetSpineState_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSpineState_Response_error_code state(::franka_spine_msgs::srv::GetSpineState_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_GetSpineState_Response_error_code(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::GetSpineState_Response>()
{
  return franka_spine_msgs::srv::builder::Init_GetSpineState_Response_state();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSpineState_Event_response
{
public:
  explicit Init_GetSpineState_Event_response(::franka_spine_msgs::srv::GetSpineState_Event & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::srv::GetSpineState_Event response(::franka_spine_msgs::srv::GetSpineState_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Event msg_;
};

class Init_GetSpineState_Event_request
{
public:
  explicit Init_GetSpineState_Event_request(::franka_spine_msgs::srv::GetSpineState_Event & msg)
  : msg_(msg)
  {}
  Init_GetSpineState_Event_response request(::franka_spine_msgs::srv::GetSpineState_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetSpineState_Event_response(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Event msg_;
};

class Init_GetSpineState_Event_info
{
public:
  Init_GetSpineState_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSpineState_Event_request info(::franka_spine_msgs::srv::GetSpineState_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetSpineState_Event_request(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetSpineState_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::GetSpineState_Event>()
{
  return franka_spine_msgs::srv::builder::Init_GetSpineState_Event_info();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__SRV__DETAIL__GET_SPINE_STATE__BUILDER_HPP_
