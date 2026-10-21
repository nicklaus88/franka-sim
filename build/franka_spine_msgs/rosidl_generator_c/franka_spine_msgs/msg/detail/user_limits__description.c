// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice

#include "franka_spine_msgs/msg/detail/user_limits__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_spine_msgs
const rosidl_type_hash_t *
franka_spine_msgs__msg__UserLimits__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3c, 0x37, 0x9d, 0xa6, 0x91, 0x6b, 0x72, 0xa9,
      0x7a, 0xf7, 0x69, 0x79, 0x62, 0x4f, 0x8b, 0xf9,
      0xf3, 0xf3, 0xec, 0xbd, 0xc3, 0x23, 0x5f, 0x40,
      0x5b, 0x5f, 0x69, 0xfe, 0x8a, 0xbd, 0xa5, 0x3b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char franka_spine_msgs__msg__UserLimits__TYPE_NAME[] = "franka_spine_msgs/msg/UserLimits";

// Define type names, field names, and default values
static char franka_spine_msgs__msg__UserLimits__FIELD_NAME__lower_limit[] = "lower_limit";
static char franka_spine_msgs__msg__UserLimits__FIELD_NAME__upper_limit[] = "upper_limit";

static rosidl_runtime_c__type_description__Field franka_spine_msgs__msg__UserLimits__FIELDS[] = {
  {
    {franka_spine_msgs__msg__UserLimits__FIELD_NAME__lower_limit, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__msg__UserLimits__FIELD_NAME__upper_limit, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_spine_msgs__msg__UserLimits__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_spine_msgs__msg__UserLimits__TYPE_NAME, 32, 32},
      {franka_spine_msgs__msg__UserLimits__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# User-defined soft motion limits for the spine.\n"
  "float64 lower_limit  # Lower motion limit [m]\n"
  "float64 upper_limit  # Upper motion limit [m]";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_spine_msgs__msg__UserLimits__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_spine_msgs__msg__UserLimits__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 141, 141},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_spine_msgs__msg__UserLimits__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_spine_msgs__msg__UserLimits__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
