// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from franka_spine_msgs:msg/SpinePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_position.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__STRUCT_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__franka_spine_msgs__msg__SpinePosition __attribute__((deprecated))
#else
# define DEPRECATED__franka_spine_msgs__msg__SpinePosition __declspec(deprecated)
#endif

namespace franka_spine_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpinePosition_
{
  using Type = SpinePosition_<ContainerAllocator>;

  explicit SpinePosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0.0;
      this->valid = false;
    }
  }

  explicit SpinePosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0.0;
      this->valid = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _position_type =
    double;
  _position_type position;
  using _valid_type =
    bool;
  _valid_type valid;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__position(
    const double & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__valid(
    const bool & _arg)
  {
    this->valid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_spine_msgs::msg::SpinePosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_spine_msgs::msg::SpinePosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::msg::SpinePosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::msg::SpinePosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_spine_msgs__msg__SpinePosition
    std::shared_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_spine_msgs__msg__SpinePosition
    std::shared_ptr<franka_spine_msgs::msg::SpinePosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpinePosition_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->valid != other.valid) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpinePosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpinePosition_

// alias to use template instance with default allocator
using SpinePosition =
  franka_spine_msgs::msg::SpinePosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__STRUCT_HPP_
