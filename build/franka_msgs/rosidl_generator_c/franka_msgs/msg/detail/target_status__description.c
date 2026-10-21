// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/TargetStatus.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/target_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__TargetStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7f, 0xee, 0x69, 0x4c, 0xe8, 0xc9, 0xef, 0xcf,
      0x79, 0x8c, 0x0c, 0x4b, 0xb3, 0x2b, 0x7f, 0x86,
      0x1e, 0xc9, 0x0f, 0x2d, 0x95, 0x4e, 0xca, 0x62,
      0x4a, 0x48, 0xb2, 0x68, 0x24, 0x1d, 0x64, 0xdf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char franka_msgs__msg__TargetStatus__TYPE_NAME[] = "franka_msgs/msg/TargetStatus";

// Define type names, field names, and default values
static char franka_msgs__msg__TargetStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__TargetStatus__FIELDS[] = {
  {
    {franka_msgs__msg__TargetStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__TargetStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__TargetStatus__TYPE_NAME, 28, 28},
      {franka_msgs__msg__TargetStatus__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "## The status of a motion action\n"
  "# IDLE: The robot is idle, no motion is being executed\n"
  "uint8 IDLE = 0\n"
  "\n"
  "# EXECUTING: The robot is currently executing the motion\n"
  "uint8 EXECUTING = 1\n"
  "\n"
  "# TARGET_REACHED: The robot has reached the target position given two conditions:\n"
  "# - the absolute difference between the current and goal joint positions is within the goal_tolerance\n"
  "# - the joint velocities are below a small threshold\n"
  "uint8 TARGET_REACHED = 2\n"
  "\n"
  "# ABORTED: The motion was aborted due to an error or external intervention\n"
  "uint8 ABORTED = 3\n"
  "\n"
  "## The current status of the motion (one of the above states)\n"
  "uint8 status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__TargetStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__TargetStatus__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 614, 614},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__TargetStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__TargetStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
