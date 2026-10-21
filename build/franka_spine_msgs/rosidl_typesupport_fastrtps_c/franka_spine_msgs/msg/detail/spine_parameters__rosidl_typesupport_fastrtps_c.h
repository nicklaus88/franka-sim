// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice
#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "franka_spine_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "franka_spine_msgs/msg/detail/spine_parameters__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
bool cdr_serialize_franka_spine_msgs__msg__SpineParameters(
  const franka_spine_msgs__msg__SpineParameters * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
bool cdr_deserialize_franka_spine_msgs__msg__SpineParameters(
  eprosima::fastcdr::Cdr &,
  franka_spine_msgs__msg__SpineParameters * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
size_t get_serialized_size_franka_spine_msgs__msg__SpineParameters(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
size_t max_serialized_size_franka_spine_msgs__msg__SpineParameters(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
bool cdr_serialize_key_franka_spine_msgs__msg__SpineParameters(
  const franka_spine_msgs__msg__SpineParameters * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
size_t get_serialized_size_key_franka_spine_msgs__msg__SpineParameters(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
size_t max_serialized_size_key_franka_spine_msgs__msg__SpineParameters(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_spine_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, msg, SpineParameters)();

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
