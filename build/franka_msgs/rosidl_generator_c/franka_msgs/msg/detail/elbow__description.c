// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/Elbow.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/elbow__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__Elbow__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf5, 0x41, 0x41, 0xb9, 0x2a, 0x05, 0x44, 0x7b,
      0xfa, 0x2f, 0x99, 0x3a, 0xc2, 0x8c, 0x28, 0x9b,
      0x47, 0x73, 0x58, 0xa3, 0xd5, 0x43, 0xad, 0x09,
      0x9e, 0x1a, 0x34, 0xc1, 0x0d, 0x70, 0xd9, 0xbb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char franka_msgs__msg__Elbow__TYPE_NAME[] = "franka_msgs/msg/Elbow";

// Define type names, field names, and default values
static char franka_msgs__msg__Elbow__FIELD_NAME__position[] = "position";
static char franka_msgs__msg__Elbow__FIELD_NAME__desired_position[] = "desired_position";
static char franka_msgs__msg__Elbow__FIELD_NAME__commanded_position[] = "commanded_position";
static char franka_msgs__msg__Elbow__FIELD_NAME__commanded_velocity[] = "commanded_velocity";
static char franka_msgs__msg__Elbow__FIELD_NAME__commanded_acceleration[] = "commanded_acceleration";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__Elbow__FIELDS[] = {
  {
    {franka_msgs__msg__Elbow__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Elbow__FIELD_NAME__desired_position, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Elbow__FIELD_NAME__commanded_position, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Elbow__FIELD_NAME__commanded_velocity, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Elbow__FIELD_NAME__commanded_acceleration, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__Elbow__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__Elbow__TYPE_NAME, 21, 21},
      {franka_msgs__msg__Elbow__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "### The state of the elbow\n"
  "float64[2] position\n"
  "float64[2] desired_position\n"
  "float64[2] commanded_position\n"
  "float64[2] commanded_velocity\n"
  "float64[2] commanded_acceleration";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__Elbow__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__Elbow__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 169, 169},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__Elbow__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__Elbow__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
