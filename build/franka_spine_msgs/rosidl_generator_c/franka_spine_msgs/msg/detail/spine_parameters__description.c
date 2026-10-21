// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice

#include "franka_spine_msgs/msg/detail/spine_parameters__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_spine_msgs
const rosidl_type_hash_t *
franka_spine_msgs__msg__SpineParameters__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4f, 0x07, 0xf6, 0x8f, 0x56, 0xc9, 0x14, 0x4b,
      0xc7, 0xb4, 0xd9, 0x39, 0x11, 0xb6, 0x2b, 0x9e,
      0xc1, 0x12, 0xe2, 0x3c, 0x15, 0x91, 0xf5, 0x1c,
      0x92, 0xe4, 0x45, 0xc2, 0xa5, 0xb8, 0x16, 0x0f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "franka_spine_msgs/msg/detail/user_limits__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t franka_spine_msgs__msg__UserLimits__EXPECTED_HASH = {1, {
    0x3c, 0x37, 0x9d, 0xa6, 0x91, 0x6b, 0x72, 0xa9,
    0x7a, 0xf7, 0x69, 0x79, 0x62, 0x4f, 0x8b, 0xf9,
    0xf3, 0xf3, 0xec, 0xbd, 0xc3, 0x23, 0x5f, 0x40,
    0x5b, 0x5f, 0x69, 0xfe, 0x8a, 0xbd, 0xa5, 0x3b,
  }};
#endif

static char franka_spine_msgs__msg__SpineParameters__TYPE_NAME[] = "franka_spine_msgs/msg/SpineParameters";
static char franka_spine_msgs__msg__UserLimits__TYPE_NAME[] = "franka_spine_msgs/msg/UserLimits";

// Define type names, field names, and default values
static char franka_spine_msgs__msg__SpineParameters__FIELD_NAME__user_limits[] = "user_limits";

static rosidl_runtime_c__type_description__Field franka_spine_msgs__msg__SpineParameters__FIELDS[] = {
  {
    {franka_spine_msgs__msg__SpineParameters__FIELD_NAME__user_limits, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_spine_msgs__msg__UserLimits__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_spine_msgs__msg__SpineParameters__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {franka_spine_msgs__msg__UserLimits__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_spine_msgs__msg__SpineParameters__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_spine_msgs__msg__SpineParameters__TYPE_NAME, 37, 37},
      {franka_spine_msgs__msg__SpineParameters__FIELDS, 1, 1},
    },
    {franka_spine_msgs__msg__SpineParameters__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&franka_spine_msgs__msg__UserLimits__EXPECTED_HASH, franka_spine_msgs__msg__UserLimits__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = franka_spine_msgs__msg__UserLimits__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Aggregated spine parameters returned by the GetParameters service.\n"
  "franka_spine_msgs/UserLimits user_limits  # User-defined motion limits";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_spine_msgs__msg__SpineParameters__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_spine_msgs__msg__SpineParameters__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 140, 140},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_spine_msgs__msg__SpineParameters__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_spine_msgs__msg__SpineParameters__get_individual_type_description_source(NULL),
    sources[1] = *franka_spine_msgs__msg__UserLimits__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
