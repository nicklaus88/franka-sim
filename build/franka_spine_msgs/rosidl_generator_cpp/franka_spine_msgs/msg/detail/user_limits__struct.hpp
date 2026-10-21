// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/user_limits.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__STRUCT_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__franka_spine_msgs__msg__UserLimits __attribute__((deprecated))
#else
# define DEPRECATED__franka_spine_msgs__msg__UserLimits __declspec(deprecated)
#endif

namespace franka_spine_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserLimits_
{
  using Type = UserLimits_<ContainerAllocator>;

  explicit UserLimits_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lower_limit = 0.0;
      this->upper_limit = 0.0;
    }
  }

  explicit UserLimits_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lower_limit = 0.0;
      this->upper_limit = 0.0;
    }
  }

  // field types and members
  using _lower_limit_type =
    double;
  _lower_limit_type lower_limit;
  using _upper_limit_type =
    double;
  _upper_limit_type upper_limit;

  // setters for named parameter idiom
  Type & set__lower_limit(
    const double & _arg)
  {
    this->lower_limit = _arg;
    return *this;
  }
  Type & set__upper_limit(
    const double & _arg)
  {
    this->upper_limit = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    franka_spine_msgs::msg::UserLimits_<ContainerAllocator> *;
  using ConstRawPtr =
    const franka_spine_msgs::msg::UserLimits_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::msg::UserLimits_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      franka_spine_msgs::msg::UserLimits_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__franka_spine_msgs__msg__UserLimits
    std::shared_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__franka_spine_msgs__msg__UserLimits
    std::shared_ptr<franka_spine_msgs::msg::UserLimits_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserLimits_ & other) const
  {
    if (this->lower_limit != other.lower_limit) {
      return false;
    }
    if (this->upper_limit != other.upper_limit) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserLimits_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserLimits_

// alias to use template instance with default allocator
using UserLimits =
  franka_spine_msgs::msg::UserLimits_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__STRUCT_HPP_
