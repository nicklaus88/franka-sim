// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/FrankaRobotState.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/franka_robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__FrankaRobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x81, 0xe4, 0xe2, 0x01, 0x50, 0x60, 0x80, 0xdd,
      0x1b, 0x62, 0x42, 0x4e, 0xd4, 0x37, 0x07, 0xf2,
      0x78, 0x96, 0xf4, 0x61, 0x9f, 0xd0, 0xde, 0x17,
      0x3f, 0x27, 0x8c, 0x23, 0x72, 0x23, 0xed, 0x28,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "franka_msgs/msg/detail/errors__functions.h"
#include "geometry_msgs/msg/detail/vector3_stamped__functions.h"
#include "sensor_msgs/msg/detail/joint_state__functions.h"
#include "geometry_msgs/msg/detail/inertia__functions.h"
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "geometry_msgs/msg/detail/twist__functions.h"
#include "geometry_msgs/msg/detail/twist_stamped__functions.h"
#include "geometry_msgs/msg/detail/wrench__functions.h"
#include "geometry_msgs/msg/detail/inertia_stamped__functions.h"
#include "franka_msgs/msg/detail/elbow__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "franka_msgs/msg/detail/collision_indicators__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/accel__functions.h"
#include "geometry_msgs/msg/detail/wrench_stamped__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"
#include "geometry_msgs/msg/detail/accel_stamped__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t franka_msgs__msg__CollisionIndicators__EXPECTED_HASH = {1, {
    0x17, 0xd0, 0x21, 0x13, 0xf0, 0xe8, 0xec, 0x37,
    0x68, 0x43, 0x3b, 0xaa, 0xfd, 0x4f, 0x27, 0xfe,
    0x5e, 0xaa, 0xcf, 0x95, 0xd6, 0xc2, 0x1f, 0x59,
    0x1b, 0xf3, 0x47, 0x3e, 0x54, 0x1e, 0x08, 0x40,
  }};
static const rosidl_type_hash_t franka_msgs__msg__Elbow__EXPECTED_HASH = {1, {
    0xf5, 0x41, 0x41, 0xb9, 0x2a, 0x05, 0x44, 0x7b,
    0xfa, 0x2f, 0x99, 0x3a, 0xc2, 0x8c, 0x28, 0x9b,
    0x47, 0x73, 0x58, 0xa3, 0xd5, 0x43, 0xad, 0x09,
    0x9e, 0x1a, 0x34, 0xc1, 0x0d, 0x70, 0xd9, 0xbb,
  }};
static const rosidl_type_hash_t franka_msgs__msg__Errors__EXPECTED_HASH = {1, {
    0xea, 0xf7, 0xa9, 0x75, 0x2f, 0x64, 0xef, 0xac,
    0x23, 0x93, 0x06, 0x10, 0x10, 0x20, 0x54, 0x5c,
    0xeb, 0xeb, 0xff, 0x8b, 0x51, 0x30, 0x87, 0x5d,
    0x95, 0xbf, 0x0e, 0xd4, 0xd8, 0xbb, 0x77, 0x4d,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Accel__EXPECTED_HASH = {1, {
    0xdc, 0x44, 0x82, 0x43, 0xde, 0xd9, 0xb1, 0xfc,
    0xbc, 0xca, 0x24, 0xab, 0xa0, 0xc2, 0x2f, 0x01,
    0x3d, 0xae, 0x06, 0xc3, 0x54, 0xba, 0x2d, 0x84,
    0x95, 0x71, 0xc0, 0xa2, 0xa3, 0xf5, 0x7c, 0xa0,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__AccelStamped__EXPECTED_HASH = {1, {
    0xef, 0x1d, 0xf9, 0xea, 0xba, 0xe0, 0xa7, 0x08,
    0xcc, 0x04, 0x9a, 0x06, 0x1e, 0xbc, 0xdd, 0xc4,
    0xe2, 0xa5, 0xf7, 0x45, 0x73, 0x01, 0x00, 0xba,
    0x68, 0x0e, 0x08, 0x6a, 0x96, 0x98, 0xb1, 0x65,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Inertia__EXPECTED_HASH = {1, {
    0x2d, 0xdd, 0x5d, 0xab, 0x5c, 0x34, 0x78, 0x25,
    0xba, 0x2e, 0x56, 0xc8, 0x95, 0xdd, 0xcc, 0xfd,
    0x0b, 0x8e, 0xfe, 0x53, 0xae, 0x93, 0x1b, 0xf6,
    0x7f, 0x90, 0x55, 0x29, 0x93, 0x0b, 0x4b, 0xd7,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__InertiaStamped__EXPECTED_HASH = {1, {
    0x76, 0x6b, 0xe4, 0x59, 0x76, 0x25, 0x2b, 0xab,
    0xf7, 0xf9, 0xd8, 0xac, 0x4a, 0xe7, 0xc9, 0x12,
    0xa7, 0xce, 0xcc, 0xf7, 0x10, 0x35, 0x62, 0x25,
    0x29, 0xf2, 0x75, 0x18, 0xb6, 0x95, 0xaa, 0x09,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Pose__EXPECTED_HASH = {1, {
    0xd5, 0x01, 0x95, 0x4e, 0x94, 0x76, 0xce, 0xa2,
    0x99, 0x69, 0x84, 0xe8, 0x12, 0x05, 0x4b, 0x68,
    0x02, 0x6a, 0xe0, 0xbf, 0xae, 0x78, 0x9d, 0x9a,
    0x10, 0xb2, 0x3d, 0xaf, 0x35, 0xcc, 0x90, 0xfa,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__PoseStamped__EXPECTED_HASH = {1, {
    0x10, 0xf3, 0x78, 0x6d, 0x7d, 0x40, 0xfd, 0x2b,
    0x54, 0x36, 0x78, 0x35, 0x61, 0x4b, 0xff, 0x85,
    0xd4, 0xad, 0x3b, 0x5d, 0xab, 0x62, 0xbf, 0x8b,
    0xca, 0x0c, 0xc2, 0x32, 0xd7, 0x3b, 0x4c, 0xd8,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Twist__EXPECTED_HASH = {1, {
    0x9c, 0x45, 0xbf, 0x16, 0xfe, 0x09, 0x83, 0xd8,
    0x0e, 0x3c, 0xfe, 0x75, 0x0d, 0x68, 0x35, 0x84,
    0x3d, 0x26, 0x5a, 0x9a, 0x6c, 0x46, 0xbd, 0x2e,
    0x60, 0x9f, 0xcd, 0xdd, 0xe6, 0xfb, 0x8d, 0x2a,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__TwistStamped__EXPECTED_HASH = {1, {
    0x5f, 0x0f, 0xcd, 0x4f, 0x81, 0xd5, 0xd0, 0x6a,
    0xd9, 0xb4, 0xc4, 0xc6, 0x3e, 0x3e, 0xa5, 0x1b,
    0x82, 0xd6, 0xae, 0x4d, 0x05, 0x58, 0xf1, 0xd4,
    0x75, 0x22, 0x9b, 0x11, 0x21, 0xdb, 0x6f, 0x64,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3Stamped__EXPECTED_HASH = {1, {
    0xd4, 0x82, 0x96, 0x22, 0x28, 0x8c, 0xbb, 0x44,
    0x38, 0x86, 0xe7, 0xea, 0x94, 0xea, 0x56, 0x71,
    0xa3, 0xb1, 0xbe, 0x6b, 0xab, 0x4a, 0xd0, 0x42,
    0x24, 0x43, 0x2a, 0x65, 0xf7, 0xd7, 0x88, 0x7a,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Wrench__EXPECTED_HASH = {1, {
    0x01, 0x8e, 0x85, 0x19, 0xd5, 0x7c, 0x16, 0xad,
    0xbe, 0x97, 0xc9, 0xfe, 0x14, 0x60, 0xef, 0x21,
    0xfe, 0xc7, 0xe3, 0x1b, 0xc5, 0x41, 0xde, 0x3d,
    0x65, 0x3a, 0x35, 0x89, 0x56, 0x77, 0xce, 0x52,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__WrenchStamped__EXPECTED_HASH = {1, {
    0x8d, 0xc3, 0xde, 0xaf, 0x06, 0xb2, 0xab, 0x28,
    0x1f, 0x9f, 0x9a, 0x74, 0x2a, 0x89, 0x61, 0xc3,
    0x28, 0xca, 0x7c, 0xec, 0x16, 0xe3, 0xfd, 0x65,
    0x86, 0xd3, 0xa5, 0xc8, 0x3f, 0xa7, 0x8f, 0x77,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__JointState__EXPECTED_HASH = {1, {
    0xa1, 0x3e, 0xe3, 0xa3, 0x30, 0xe3, 0x46, 0xc9,
    0xd8, 0x7b, 0x5a, 0xa1, 0x8d, 0x24, 0xe1, 0x16,
    0x90, 0x75, 0x2b, 0xd3, 0x3a, 0x03, 0x50, 0xf1,
    0x1c, 0x58, 0x82, 0xbc, 0x91, 0x79, 0x26, 0x0e,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char franka_msgs__msg__FrankaRobotState__TYPE_NAME[] = "franka_msgs/msg/FrankaRobotState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char franka_msgs__msg__CollisionIndicators__TYPE_NAME[] = "franka_msgs/msg/CollisionIndicators";
static char franka_msgs__msg__Elbow__TYPE_NAME[] = "franka_msgs/msg/Elbow";
static char franka_msgs__msg__Errors__TYPE_NAME[] = "franka_msgs/msg/Errors";
static char geometry_msgs__msg__Accel__TYPE_NAME[] = "geometry_msgs/msg/Accel";
static char geometry_msgs__msg__AccelStamped__TYPE_NAME[] = "geometry_msgs/msg/AccelStamped";
static char geometry_msgs__msg__Inertia__TYPE_NAME[] = "geometry_msgs/msg/Inertia";
static char geometry_msgs__msg__InertiaStamped__TYPE_NAME[] = "geometry_msgs/msg/InertiaStamped";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__PoseStamped__TYPE_NAME[] = "geometry_msgs/msg/PoseStamped";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char geometry_msgs__msg__Twist__TYPE_NAME[] = "geometry_msgs/msg/Twist";
static char geometry_msgs__msg__TwistStamped__TYPE_NAME[] = "geometry_msgs/msg/TwistStamped";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char geometry_msgs__msg__Vector3Stamped__TYPE_NAME[] = "geometry_msgs/msg/Vector3Stamped";
static char geometry_msgs__msg__Wrench__TYPE_NAME[] = "geometry_msgs/msg/Wrench";
static char geometry_msgs__msg__WrenchStamped__TYPE_NAME[] = "geometry_msgs/msg/WrenchStamped";
static char sensor_msgs__msg__JointState__TYPE_NAME[] = "sensor_msgs/msg/JointState";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__header[] = "header";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__collision_indicators[] = "collision_indicators";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__measured_joint_state[] = "measured_joint_state";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__desired_joint_state[] = "desired_joint_state";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__measured_joint_motor_state[] = "measured_joint_motor_state";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__ddq_d[] = "ddq_d";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__dtau_j[] = "dtau_j";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__tau_ext_hat_filtered[] = "tau_ext_hat_filtered";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__elbow[] = "elbow";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__k_f_ext_hat_k[] = "k_f_ext_hat_k";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_f_ext_hat_k[] = "o_f_ext_hat_k";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__inertia_ee[] = "inertia_ee";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__inertia_load[] = "inertia_load";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__inertia_total[] = "inertia_total";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_t_ee[] = "o_t_ee";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_t_ee_d[] = "o_t_ee_d";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_t_ee_c[] = "o_t_ee_c";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__f_t_ee[] = "f_t_ee";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__ee_t_k[] = "ee_t_k";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_dp_ee_d[] = "o_dp_ee_d";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_dp_ee_c[] = "o_dp_ee_c";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_ddp_ee_c[] = "o_ddp_ee_c";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__time[] = "time";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__control_command_success_rate[] = "control_command_success_rate";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__robot_mode[] = "robot_mode";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__current_errors[] = "current_errors";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__last_motion_errors[] = "last_motion_errors";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__accelerometer_top[] = "accelerometer_top";
static char franka_msgs__msg__FrankaRobotState__FIELD_NAME__accelerometer_bottom[] = "accelerometer_bottom";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__FrankaRobotState__FIELDS[] = {
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__collision_indicators, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__msg__CollisionIndicators__TYPE_NAME, 35, 35},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__measured_joint_state, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__JointState__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__desired_joint_state, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__JointState__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__measured_joint_motor_state, 26, 26},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__JointState__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__ddq_d, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__dtau_j, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__tau_ext_hat_filtered, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__JointState__TYPE_NAME, 26, 26},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__elbow, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__msg__Elbow__TYPE_NAME, 21, 21},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__k_f_ext_hat_k, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__WrenchStamped__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_f_ext_hat_k, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__WrenchStamped__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__inertia_ee, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__InertiaStamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__inertia_load, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__InertiaStamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__inertia_total, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__InertiaStamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_t_ee, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_t_ee_d, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_t_ee_c, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__f_t_ee, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__ee_t_k, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_dp_ee_d, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__TwistStamped__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_dp_ee_c, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__TwistStamped__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__o_ddp_ee_c, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__AccelStamped__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__time, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__control_command_success_rate, 28, 28},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__robot_mode, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__current_errors, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__last_motion_errors, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__accelerometer_top, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      6,
      0,
      {geometry_msgs__msg__Vector3Stamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaRobotState__FIELD_NAME__accelerometer_bottom, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      6,
      0,
      {geometry_msgs__msg__Vector3Stamped__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__msg__FrankaRobotState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__CollisionIndicators__TYPE_NAME, 35, 35},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Elbow__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Accel__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__AccelStamped__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Inertia__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__InertiaStamped__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__PoseStamped__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Twist__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__TwistStamped__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3Stamped__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Wrench__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__WrenchStamped__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__JointState__TYPE_NAME, 26, 26},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__FrankaRobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__FrankaRobotState__TYPE_NAME, 32, 32},
      {franka_msgs__msg__FrankaRobotState__FIELDS, 29, 29},
    },
    {franka_msgs__msg__FrankaRobotState__REFERENCED_TYPE_DESCRIPTIONS, 20, 20},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__CollisionIndicators__EXPECTED_HASH, franka_msgs__msg__CollisionIndicators__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = franka_msgs__msg__CollisionIndicators__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__Elbow__EXPECTED_HASH, franka_msgs__msg__Elbow__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = franka_msgs__msg__Elbow__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__Errors__EXPECTED_HASH, franka_msgs__msg__Errors__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = franka_msgs__msg__Errors__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Accel__EXPECTED_HASH, geometry_msgs__msg__Accel__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = geometry_msgs__msg__Accel__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__AccelStamped__EXPECTED_HASH, geometry_msgs__msg__AccelStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = geometry_msgs__msg__AccelStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Inertia__EXPECTED_HASH, geometry_msgs__msg__Inertia__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = geometry_msgs__msg__Inertia__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__InertiaStamped__EXPECTED_HASH, geometry_msgs__msg__InertiaStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = geometry_msgs__msg__InertiaStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[9].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__PoseStamped__EXPECTED_HASH, geometry_msgs__msg__PoseStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[10].fields = geometry_msgs__msg__PoseStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[11].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Twist__EXPECTED_HASH, geometry_msgs__msg__Twist__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[12].fields = geometry_msgs__msg__Twist__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__TwistStamped__EXPECTED_HASH, geometry_msgs__msg__TwistStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[13].fields = geometry_msgs__msg__TwistStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[14].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3Stamped__EXPECTED_HASH, geometry_msgs__msg__Vector3Stamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[15].fields = geometry_msgs__msg__Vector3Stamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Wrench__EXPECTED_HASH, geometry_msgs__msg__Wrench__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[16].fields = geometry_msgs__msg__Wrench__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__WrenchStamped__EXPECTED_HASH, geometry_msgs__msg__WrenchStamped__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[17].fields = geometry_msgs__msg__WrenchStamped__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__JointState__EXPECTED_HASH, sensor_msgs__msg__JointState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[18].fields = sensor_msgs__msg__JointState__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[19].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "### Default parts of the message\n"
  "std_msgs/Header header\n"
  "\n"
  "### Indicates which dimensions have an active contact/collision flag raised\n"
  "CollisionIndicators collision_indicators\n"
  "\n"
  "### The state of the arm in joint space\n"
  "# The joint state consisting out of position (q), velocity (dq) and effort (tau_J)\n"
  "sensor_msgs/JointState measured_joint_state\n"
  "\n"
  "# The desired joint state consisting out of position (q_d), velocity (dq_d) and effort (tau_J_d)\n"
  "sensor_msgs/JointState desired_joint_state\n"
  "\n"
  "# The measured motor state of the joints consisting out of position (theta) and velocity (dtheta)\n"
  "sensor_msgs/JointState measured_joint_motor_state\n"
  "\n"
  "# The desired joint acceleration\n"
  "float64[7] ddq_d\n"
  "# The derivative of the measured torque signal\n"
  "float64[7] dtau_j\n"
  "# Filtered external torque. The JointState consists out of effort (tau_ext_hat_filtered)\n"
  "sensor_msgs/JointState tau_ext_hat_filtered\n"
  "\n"
  "### The state of the elbow\n"
  "Elbow elbow\n"
  "\n"
  "### The active wrenches acting on the stiffness frame expressed relative to\n"
  "# stiffness frame\n"
  "geometry_msgs/WrenchStamped k_f_ext_hat_k\n"
  "# base frame\n"
  "geometry_msgs/WrenchStamped o_f_ext_hat_k\n"
  "\n"
  "### The different inertias of the arm\n"
  "# The end-effector inertia\n"
  "geometry_msgs/InertiaStamped inertia_ee\n"
  "# The load inertia\n"
  "geometry_msgs/InertiaStamped inertia_load\n"
  "# The total (end-effector + load) inertia\n"
  "geometry_msgs/InertiaStamped inertia_total\n"
  "\n"
  "### The poses describing the transformations between different frames of the arm\n"
  "# Measured end-effector pose in base frame\n"
  "geometry_msgs/PoseStamped o_t_ee\n"
  "# Last desired end-effector pose of motion generation in base frame\n"
  "geometry_msgs/PoseStamped o_t_ee_d\n"
  "# Last commanded end-effector pose of motion generation in base frame\n"
  "geometry_msgs/PoseStamped o_t_ee_c\n"
  "# Flange to end-effector frame\n"
  "geometry_msgs/PoseStamped f_t_ee\n"
  "# End-effector to stiffness frame\n"
  "geometry_msgs/PoseStamped ee_t_k\n"
  "\n"
  "# Desired end effector twist in base frame\n"
  "geometry_msgs/TwistStamped o_dp_ee_d\n"
  "# Last commanded end effector twist in base frame\n"
  "geometry_msgs/TwistStamped o_dp_ee_c\n"
  "# Last commanded end effector acceleration in base frame\n"
  "geometry_msgs/AccelStamped o_ddp_ee_c\n"
  "\n"
  "### Additional information\n"
  "float64 time\n"
  "float64 control_command_success_rate\n"
  "\n"
  "uint8 ROBOT_MODE_OTHER=0\n"
  "uint8 ROBOT_MODE_IDLE=1\n"
  "uint8 ROBOT_MODE_MOVE=2\n"
  "uint8 ROBOT_MODE_GUIDING=3\n"
  "uint8 ROBOT_MODE_REFLEX=4\n"
  "uint8 ROBOT_MODE_USER_STOPPED=5\n"
  "uint8 ROBOT_MODE_AUTOMATIC_ERROR_RECOVERY=6\n"
  "uint8 robot_mode\n"
  "\n"
  "Errors current_errors\n"
  "Errors last_motion_errors\n"
  "\n"
  "### Translational acceleration data from the joint-mounted accelerometers,\n"
  "# expressed in the \"<prefix>link<i>_accelerometer_<side>\" frame named in each header\n"
  "# (joints 1 through 6, mounted on links 0 through 5; no accelerometer on joint 7)\n"
  "geometry_msgs/Vector3Stamped[6] accelerometer_top\n"
  "geometry_msgs/Vector3Stamped[6] accelerometer_bottom";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__FrankaRobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__FrankaRobotState__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 2818, 2818},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__FrankaRobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[21];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 21, 21};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__FrankaRobotState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__msg__CollisionIndicators__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__msg__Elbow__get_individual_type_description_source(NULL);
    sources[4] = *franka_msgs__msg__Errors__get_individual_type_description_source(NULL);
    sources[5] = *geometry_msgs__msg__Accel__get_individual_type_description_source(NULL);
    sources[6] = *geometry_msgs__msg__AccelStamped__get_individual_type_description_source(NULL);
    sources[7] = *geometry_msgs__msg__Inertia__get_individual_type_description_source(NULL);
    sources[8] = *geometry_msgs__msg__InertiaStamped__get_individual_type_description_source(NULL);
    sources[9] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[10] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[11] = *geometry_msgs__msg__PoseStamped__get_individual_type_description_source(NULL);
    sources[12] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[13] = *geometry_msgs__msg__Twist__get_individual_type_description_source(NULL);
    sources[14] = *geometry_msgs__msg__TwistStamped__get_individual_type_description_source(NULL);
    sources[15] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[16] = *geometry_msgs__msg__Vector3Stamped__get_individual_type_description_source(NULL);
    sources[17] = *geometry_msgs__msg__Wrench__get_individual_type_description_source(NULL);
    sources[18] = *geometry_msgs__msg__WrenchStamped__get_individual_type_description_source(NULL);
    sources[19] = *sensor_msgs__msg__JointState__get_individual_type_description_source(NULL);
    sources[20] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
