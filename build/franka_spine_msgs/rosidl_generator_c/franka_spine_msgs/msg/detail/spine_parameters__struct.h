// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_parameters.h"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__STRUCT_H_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'user_limits'
#include "franka_spine_msgs/msg/detail/user_limits__struct.h"

/// Struct defined in msg/SpineParameters in the package franka_spine_msgs.
/**
  * Aggregated spine parameters returned by the GetParameters service.
 */
typedef struct franka_spine_msgs__msg__SpineParameters
{
  /// User-defined motion limits
  franka_spine_msgs__msg__UserLimits user_limits;
} franka_spine_msgs__msg__SpineParameters;

// Struct for a sequence of franka_spine_msgs__msg__SpineParameters.
typedef struct franka_spine_msgs__msg__SpineParameters__Sequence
{
  franka_spine_msgs__msg__SpineParameters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__msg__SpineParameters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__STRUCT_H_
