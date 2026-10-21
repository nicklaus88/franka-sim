// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/CollisionIndicators.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/collision_indicators__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__CollisionIndicators__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x17, 0xd0, 0x21, 0x13, 0xf0, 0xe8, 0xec, 0x37,
      0x68, 0x43, 0x3b, 0xaa, 0xfd, 0x4f, 0x27, 0xfe,
      0x5e, 0xaa, 0xcf, 0x95, 0xd6, 0xc2, 0x1f, 0x59,
      0x1b, 0xf3, 0x47, 0x3e, 0x54, 0x1e, 0x08, 0x40,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/vector3__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
#endif

static char franka_msgs__msg__CollisionIndicators__TYPE_NAME[] = "franka_msgs/msg/CollisionIndicators";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";

// Define type names, field names, and default values
static char franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_linear_collision[] = "is_cartesian_linear_collision";
static char franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_angular_collision[] = "is_cartesian_angular_collision";
static char franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_linear_contact[] = "is_cartesian_linear_contact";
static char franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_angular_contact[] = "is_cartesian_angular_contact";
static char franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_joint_collision[] = "is_joint_collision";
static char franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_joint_contact[] = "is_joint_contact";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__CollisionIndicators__FIELDS[] = {
  {
    {franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_linear_collision, 29, 29},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_angular_collision, 30, 30},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_linear_contact, 27, 27},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_cartesian_angular_contact, 28, 28},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_joint_collision, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__CollisionIndicators__FIELD_NAME__is_joint_contact, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__msg__CollisionIndicators__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__CollisionIndicators__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__CollisionIndicators__TYPE_NAME, 35, 35},
      {franka_msgs__msg__CollisionIndicators__FIELDS, 6, 6},
    },
    {franka_msgs__msg__CollisionIndicators__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "### Indicates which dimensions have an active contact/collision flag raised\n"
  "geometry_msgs/Vector3 is_cartesian_linear_collision\n"
  "geometry_msgs/Vector3 is_cartesian_angular_collision\n"
  "geometry_msgs/Vector3 is_cartesian_linear_contact\n"
  "geometry_msgs/Vector3 is_cartesian_angular_contact\n"
  "\n"
  "float64[7] is_joint_collision\n"
  "float64[7] is_joint_contact";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__CollisionIndicators__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__CollisionIndicators__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 341, 341},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__CollisionIndicators__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__CollisionIndicators__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
