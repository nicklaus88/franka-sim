// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/user_limits.h"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__STRUCT_H_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/UserLimits in the package franka_spine_msgs.
/**
  * User-defined soft motion limits for the spine.
 */
typedef struct franka_spine_msgs__msg__UserLimits
{
  /// Lower motion limit
  double lower_limit;
  /// Upper motion limit
  double upper_limit;
} franka_spine_msgs__msg__UserLimits;

// Struct for a sequence of franka_spine_msgs__msg__UserLimits.
typedef struct franka_spine_msgs__msg__UserLimits__Sequence
{
  franka_spine_msgs__msg__UserLimits * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__msg__UserLimits__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__STRUCT_H_
