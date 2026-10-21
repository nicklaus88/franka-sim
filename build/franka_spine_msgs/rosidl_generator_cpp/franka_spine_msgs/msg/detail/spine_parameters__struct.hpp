// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_parameters.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__STRUCT_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'user_limits'
#include "franka_spine_msgs/msg/detail/user_limits__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__franka_spine_msgs__msg__SpineParameters __attribute__((deprecated))
#else
# define DEPRECATED__franka_spine_msgs__msg__SpineParameters __declspec(deprecated)
#endif

namespace franka_spine_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpineParameters_
{
  using Type = SpineParameters_<ContainerAllocator>;

  explicit SpineParameters_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : user_limits(_init)
  {
    (void)_init;
  }

  explicit SpineParameters_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : user_limits(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _user_limits_type =
    franka_spine_msgs::msg::UserLimits_<ContainerAllocator>;
  _user_limits_type user_limits;

  // setters for named parameter idiom
  Type & set__user_limits(
    const franka_spine_msgs::msg::UserLimits_<ContainerAllocator> & _arg)
  {
    this->user_limits = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_spine_msgs::msg::SpineParameters_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_spine_msgs::msg::SpineParameters_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::msg::SpineParameters_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::msg::SpineParameters_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_spine_msgs__msg__SpineParameters
    std::shared_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_spine_msgs__msg__SpineParameters
    std::shared_ptr<franka_spine_msgs::msg::SpineParameters_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpineParameters_ & other) const
  {
    if (this->user_limits != other.user_limits) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpineParameters_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpineParameters_

// alias to use template instance with default allocator
using SpineParameters =
  franka_spine_msgs::msg::SpineParameters_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__STRUCT_HPP_
