// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from franka_spine_msgs:srv/GetSpineState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/srv/get_spine_state.hpp"


#ifndef FRANKA_SPINE_MSGS__SRV__DETAIL__GET_SPINE_STATE__STRUCT_HPP_
#define FRANKA_SPINE_MSGS__SRV__DETAIL__GET_SPINE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__franka_spine_msgs__srv__GetSpineState_Request __attribute__((deprecated))
#else
# define DEPRECATED__franka_spine_msgs__srv__GetSpineState_Request __declspec(deprecated)
#endif

namespace franka_spine_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSpineState_Request_
{
  using Type = GetSpineState_Request_<ContainerAllocator>;

  explicit GetSpineState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetSpineState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_spine_msgs__srv__GetSpineState_Request
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_spine_msgs__srv__GetSpineState_Request
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSpineState_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSpineState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSpineState_Request_

// alias to use template instance with default allocator
using GetSpineState_Request =
  franka_spine_msgs::srv::GetSpineState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace franka_spine_msgs


#ifndef _WIN32
# define DEPRECATED__franka_spine_msgs__srv__GetSpineState_Response __attribute__((deprecated))
#else
# define DEPRECATED__franka_spine_msgs__srv__GetSpineState_Response __declspec(deprecated)
#endif

namespace franka_spine_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSpineState_Response_
{
  using Type = GetSpineState_Response_<ContainerAllocator>;

  explicit GetSpineState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = "";
      this->error_code = "";
      this->error_description = "";
      this->success = false;
    }
  }

  explicit GetSpineState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc),
    error_code(_alloc),
    error_description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = "";
      this->error_code = "";
      this->error_description = "";
      this->success = false;
    }
  }

  // field types and members
  using _state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_type state;
  using _error_code_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_code_type error_code;
  using _error_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_description_type error_description;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__error_code(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__error_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_description = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_spine_msgs__srv__GetSpineState_Response
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_spine_msgs__srv__GetSpineState_Response
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSpineState_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->error_description != other.error_description) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSpineState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSpineState_Response_

// alias to use template instance with default allocator
using GetSpineState_Response =
  franka_spine_msgs::srv::GetSpineState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace franka_spine_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__franka_spine_msgs__srv__GetSpineState_Event __attribute__((deprecated))
#else
# define DEPRECATED__franka_spine_msgs__srv__GetSpineState_Event __declspec(deprecated)
#endif

namespace franka_spine_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetSpineState_Event_
{
  using Type = GetSpineState_Event_<ContainerAllocator>;

  explicit GetSpineState_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetSpineState_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<franka_spine_msgs::srv::GetSpineState_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<franka_spine_msgs::srv::GetSpineState_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_spine_msgs__srv__GetSpineState_Event
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_spine_msgs__srv__GetSpineState_Event
    std::shared_ptr<franka_spine_msgs::srv::GetSpineState_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSpineState_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSpineState_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSpineState_Event_

// alias to use template instance with default allocator
using GetSpineState_Event =
  franka_spine_msgs::srv::GetSpineState_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace franka_spine_msgs

namespace franka_spine_msgs
{

namespace srv
{

struct GetSpineState
{
  using Request = franka_spine_msgs::srv::GetSpineState_Request;
  using Response = franka_spine_msgs::srv::GetSpineState_Response;
  using Event = franka_spine_msgs::srv::GetSpineState_Event;
};

}  // namespace srv

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__SRV__DETAIL__GET_SPINE_STATE__STRUCT_HPP_
