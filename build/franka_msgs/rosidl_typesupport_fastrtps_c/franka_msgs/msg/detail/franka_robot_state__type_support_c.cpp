// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from franka_msgs:msg/FrankaRobotState.idl
// generated code does not contain a copyright notice
#include "franka_msgs/msg/detail/franka_robot_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "franka_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "franka_msgs/msg/detail/franka_robot_state__struct.h"
#include "franka_msgs/msg/detail/franka_robot_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "franka_msgs/msg/detail/collision_indicators__functions.h"  // collision_indicators
#include "franka_msgs/msg/detail/elbow__functions.h"  // elbow
#include "franka_msgs/msg/detail/errors__functions.h"  // current_errors, last_motion_errors
#include "geometry_msgs/msg/detail/accel_stamped__functions.h"  // o_ddp_ee_c
#include "geometry_msgs/msg/detail/inertia_stamped__functions.h"  // inertia_ee, inertia_load, inertia_total
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"  // ee_t_k, f_t_ee, o_t_ee, o_t_ee_c, o_t_ee_d
#include "geometry_msgs/msg/detail/twist_stamped__functions.h"  // o_dp_ee_c, o_dp_ee_d
#include "geometry_msgs/msg/detail/vector3_stamped__functions.h"  // accelerometer_bottom, accelerometer_top
#include "geometry_msgs/msg/detail/wrench_stamped__functions.h"  // k_f_ext_hat_k, o_f_ext_hat_k
#include "sensor_msgs/msg/detail/joint_state__functions.h"  // desired_joint_state, measured_joint_motor_state, measured_joint_state, tau_ext_hat_filtered
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

bool cdr_serialize_franka_msgs__msg__CollisionIndicators(
  const franka_msgs__msg__CollisionIndicators * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_franka_msgs__msg__CollisionIndicators(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__CollisionIndicators * ros_message);

size_t get_serialized_size_franka_msgs__msg__CollisionIndicators(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_franka_msgs__msg__CollisionIndicators(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_franka_msgs__msg__CollisionIndicators(
  const franka_msgs__msg__CollisionIndicators * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_franka_msgs__msg__CollisionIndicators(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_franka_msgs__msg__CollisionIndicators(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, CollisionIndicators)();

bool cdr_serialize_franka_msgs__msg__Elbow(
  const franka_msgs__msg__Elbow * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_franka_msgs__msg__Elbow(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__Elbow * ros_message);

size_t get_serialized_size_franka_msgs__msg__Elbow(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_franka_msgs__msg__Elbow(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_franka_msgs__msg__Elbow(
  const franka_msgs__msg__Elbow * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_franka_msgs__msg__Elbow(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_franka_msgs__msg__Elbow(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, Elbow)();

bool cdr_serialize_franka_msgs__msg__Errors(
  const franka_msgs__msg__Errors * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_franka_msgs__msg__Errors(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__Errors * ros_message);

size_t get_serialized_size_franka_msgs__msg__Errors(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_franka_msgs__msg__Errors(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_franka_msgs__msg__Errors(
  const franka_msgs__msg__Errors * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_franka_msgs__msg__Errors(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_franka_msgs__msg__Errors(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, Errors)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__AccelStamped(
  const geometry_msgs__msg__AccelStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__AccelStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__AccelStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__AccelStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__AccelStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__AccelStamped(
  const geometry_msgs__msg__AccelStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__AccelStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__AccelStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, AccelStamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__InertiaStamped(
  const geometry_msgs__msg__InertiaStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__InertiaStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__InertiaStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__InertiaStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__InertiaStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__InertiaStamped(
  const geometry_msgs__msg__InertiaStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__InertiaStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__InertiaStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, InertiaStamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__PoseStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PoseStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__PoseStamped(
  const geometry_msgs__msg__PoseStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__PoseStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__PoseStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PoseStamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__TwistStamped(
  const geometry_msgs__msg__TwistStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__TwistStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__TwistStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__TwistStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__TwistStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__TwistStamped(
  const geometry_msgs__msg__TwistStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__TwistStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__TwistStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, TwistStamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__Vector3Stamped(
  const geometry_msgs__msg__Vector3Stamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__Vector3Stamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Vector3Stamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__Vector3Stamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__Vector3Stamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__Vector3Stamped(
  const geometry_msgs__msg__Vector3Stamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Vector3Stamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Vector3Stamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3Stamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__WrenchStamped(
  const geometry_msgs__msg__WrenchStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__WrenchStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__WrenchStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__WrenchStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__WrenchStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__WrenchStamped(
  const geometry_msgs__msg__WrenchStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__WrenchStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__WrenchStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, WrenchStamped)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_sensor_msgs__msg__JointState(
  const sensor_msgs__msg__JointState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_sensor_msgs__msg__JointState(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__JointState * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_sensor_msgs__msg__JointState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_sensor_msgs__msg__JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_sensor_msgs__msg__JointState(
  const sensor_msgs__msg__JointState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_sensor_msgs__msg__JointState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_sensor_msgs__msg__JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, JointState)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _FrankaRobotState__ros_msg_type = franka_msgs__msg__FrankaRobotState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_serialize_franka_msgs__msg__FrankaRobotState(
  const franka_msgs__msg__FrankaRobotState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: collision_indicators
  {
    cdr_serialize_franka_msgs__msg__CollisionIndicators(
      &ros_message->collision_indicators, cdr);
  }

  // Field name: measured_joint_state
  {
    cdr_serialize_sensor_msgs__msg__JointState(
      &ros_message->measured_joint_state, cdr);
  }

  // Field name: desired_joint_state
  {
    cdr_serialize_sensor_msgs__msg__JointState(
      &ros_message->desired_joint_state, cdr);
  }

  // Field name: measured_joint_motor_state
  {
    cdr_serialize_sensor_msgs__msg__JointState(
      &ros_message->measured_joint_motor_state, cdr);
  }

  // Field name: ddq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->ddq_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dtau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtau_j;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_ext_hat_filtered
  {
    cdr_serialize_sensor_msgs__msg__JointState(
      &ros_message->tau_ext_hat_filtered, cdr);
  }

  // Field name: elbow
  {
    cdr_serialize_franka_msgs__msg__Elbow(
      &ros_message->elbow, cdr);
  }

  // Field name: k_f_ext_hat_k
  {
    cdr_serialize_geometry_msgs__msg__WrenchStamped(
      &ros_message->k_f_ext_hat_k, cdr);
  }

  // Field name: o_f_ext_hat_k
  {
    cdr_serialize_geometry_msgs__msg__WrenchStamped(
      &ros_message->o_f_ext_hat_k, cdr);
  }

  // Field name: inertia_ee
  {
    cdr_serialize_geometry_msgs__msg__InertiaStamped(
      &ros_message->inertia_ee, cdr);
  }

  // Field name: inertia_load
  {
    cdr_serialize_geometry_msgs__msg__InertiaStamped(
      &ros_message->inertia_load, cdr);
  }

  // Field name: inertia_total
  {
    cdr_serialize_geometry_msgs__msg__InertiaStamped(
      &ros_message->inertia_total, cdr);
  }

  // Field name: o_t_ee
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->o_t_ee, cdr);
  }

  // Field name: o_t_ee_d
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->o_t_ee_d, cdr);
  }

  // Field name: o_t_ee_c
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->o_t_ee_c, cdr);
  }

  // Field name: f_t_ee
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->f_t_ee, cdr);
  }

  // Field name: ee_t_k
  {
    cdr_serialize_geometry_msgs__msg__PoseStamped(
      &ros_message->ee_t_k, cdr);
  }

  // Field name: o_dp_ee_d
  {
    cdr_serialize_geometry_msgs__msg__TwistStamped(
      &ros_message->o_dp_ee_d, cdr);
  }

  // Field name: o_dp_ee_c
  {
    cdr_serialize_geometry_msgs__msg__TwistStamped(
      &ros_message->o_dp_ee_c, cdr);
  }

  // Field name: o_ddp_ee_c
  {
    cdr_serialize_geometry_msgs__msg__AccelStamped(
      &ros_message->o_ddp_ee_c, cdr);
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: control_command_success_rate
  {
    cdr << ros_message->control_command_success_rate;
  }

  // Field name: robot_mode
  {
    cdr << ros_message->robot_mode;
  }

  // Field name: current_errors
  {
    cdr_serialize_franka_msgs__msg__Errors(
      &ros_message->current_errors, cdr);
  }

  // Field name: last_motion_errors
  {
    cdr_serialize_franka_msgs__msg__Errors(
      &ros_message->last_motion_errors, cdr);
  }

  // Field name: accelerometer_top
  {
    size_t size = 6;
    auto array_ptr = ros_message->accelerometer_top;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[i], cdr);
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t size = 6;
    auto array_ptr = ros_message->accelerometer_bottom;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_deserialize_franka_msgs__msg__FrankaRobotState(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__FrankaRobotState * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: collision_indicators
  {
    cdr_deserialize_franka_msgs__msg__CollisionIndicators(cdr, &ros_message->collision_indicators);
  }

  // Field name: measured_joint_state
  {
    cdr_deserialize_sensor_msgs__msg__JointState(cdr, &ros_message->measured_joint_state);
  }

  // Field name: desired_joint_state
  {
    cdr_deserialize_sensor_msgs__msg__JointState(cdr, &ros_message->desired_joint_state);
  }

  // Field name: measured_joint_motor_state
  {
    cdr_deserialize_sensor_msgs__msg__JointState(cdr, &ros_message->measured_joint_motor_state);
  }

  // Field name: ddq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->ddq_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: dtau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtau_j;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: tau_ext_hat_filtered
  {
    cdr_deserialize_sensor_msgs__msg__JointState(cdr, &ros_message->tau_ext_hat_filtered);
  }

  // Field name: elbow
  {
    cdr_deserialize_franka_msgs__msg__Elbow(cdr, &ros_message->elbow);
  }

  // Field name: k_f_ext_hat_k
  {
    cdr_deserialize_geometry_msgs__msg__WrenchStamped(cdr, &ros_message->k_f_ext_hat_k);
  }

  // Field name: o_f_ext_hat_k
  {
    cdr_deserialize_geometry_msgs__msg__WrenchStamped(cdr, &ros_message->o_f_ext_hat_k);
  }

  // Field name: inertia_ee
  {
    cdr_deserialize_geometry_msgs__msg__InertiaStamped(cdr, &ros_message->inertia_ee);
  }

  // Field name: inertia_load
  {
    cdr_deserialize_geometry_msgs__msg__InertiaStamped(cdr, &ros_message->inertia_load);
  }

  // Field name: inertia_total
  {
    cdr_deserialize_geometry_msgs__msg__InertiaStamped(cdr, &ros_message->inertia_total);
  }

  // Field name: o_t_ee
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->o_t_ee);
  }

  // Field name: o_t_ee_d
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->o_t_ee_d);
  }

  // Field name: o_t_ee_c
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->o_t_ee_c);
  }

  // Field name: f_t_ee
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->f_t_ee);
  }

  // Field name: ee_t_k
  {
    cdr_deserialize_geometry_msgs__msg__PoseStamped(cdr, &ros_message->ee_t_k);
  }

  // Field name: o_dp_ee_d
  {
    cdr_deserialize_geometry_msgs__msg__TwistStamped(cdr, &ros_message->o_dp_ee_d);
  }

  // Field name: o_dp_ee_c
  {
    cdr_deserialize_geometry_msgs__msg__TwistStamped(cdr, &ros_message->o_dp_ee_c);
  }

  // Field name: o_ddp_ee_c
  {
    cdr_deserialize_geometry_msgs__msg__AccelStamped(cdr, &ros_message->o_ddp_ee_c);
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  // Field name: control_command_success_rate
  {
    cdr >> ros_message->control_command_success_rate;
  }

  // Field name: robot_mode
  {
    cdr >> ros_message->robot_mode;
  }

  // Field name: current_errors
  {
    cdr_deserialize_franka_msgs__msg__Errors(cdr, &ros_message->current_errors);
  }

  // Field name: last_motion_errors
  {
    cdr_deserialize_franka_msgs__msg__Errors(cdr, &ros_message->last_motion_errors);
  }

  // Field name: accelerometer_top
  {
    size_t size = 6;
    auto array_ptr = ros_message->accelerometer_top;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_geometry_msgs__msg__Vector3Stamped(cdr, &array_ptr[i]);
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t size = 6;
    auto array_ptr = ros_message->accelerometer_bottom;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_geometry_msgs__msg__Vector3Stamped(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t get_serialized_size_franka_msgs__msg__FrankaRobotState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrankaRobotState__ros_msg_type * ros_message = static_cast<const _FrankaRobotState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: collision_indicators
  current_alignment += get_serialized_size_franka_msgs__msg__CollisionIndicators(
    &(ros_message->collision_indicators), current_alignment);

  // Field name: measured_joint_state
  current_alignment += get_serialized_size_sensor_msgs__msg__JointState(
    &(ros_message->measured_joint_state), current_alignment);

  // Field name: desired_joint_state
  current_alignment += get_serialized_size_sensor_msgs__msg__JointState(
    &(ros_message->desired_joint_state), current_alignment);

  // Field name: measured_joint_motor_state
  current_alignment += get_serialized_size_sensor_msgs__msg__JointState(
    &(ros_message->measured_joint_motor_state), current_alignment);

  // Field name: ddq_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->ddq_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtau_j;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_ext_hat_filtered
  current_alignment += get_serialized_size_sensor_msgs__msg__JointState(
    &(ros_message->tau_ext_hat_filtered), current_alignment);

  // Field name: elbow
  current_alignment += get_serialized_size_franka_msgs__msg__Elbow(
    &(ros_message->elbow), current_alignment);

  // Field name: k_f_ext_hat_k
  current_alignment += get_serialized_size_geometry_msgs__msg__WrenchStamped(
    &(ros_message->k_f_ext_hat_k), current_alignment);

  // Field name: o_f_ext_hat_k
  current_alignment += get_serialized_size_geometry_msgs__msg__WrenchStamped(
    &(ros_message->o_f_ext_hat_k), current_alignment);

  // Field name: inertia_ee
  current_alignment += get_serialized_size_geometry_msgs__msg__InertiaStamped(
    &(ros_message->inertia_ee), current_alignment);

  // Field name: inertia_load
  current_alignment += get_serialized_size_geometry_msgs__msg__InertiaStamped(
    &(ros_message->inertia_load), current_alignment);

  // Field name: inertia_total
  current_alignment += get_serialized_size_geometry_msgs__msg__InertiaStamped(
    &(ros_message->inertia_total), current_alignment);

  // Field name: o_t_ee
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->o_t_ee), current_alignment);

  // Field name: o_t_ee_d
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->o_t_ee_d), current_alignment);

  // Field name: o_t_ee_c
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->o_t_ee_c), current_alignment);

  // Field name: f_t_ee
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->f_t_ee), current_alignment);

  // Field name: ee_t_k
  current_alignment += get_serialized_size_geometry_msgs__msg__PoseStamped(
    &(ros_message->ee_t_k), current_alignment);

  // Field name: o_dp_ee_d
  current_alignment += get_serialized_size_geometry_msgs__msg__TwistStamped(
    &(ros_message->o_dp_ee_d), current_alignment);

  // Field name: o_dp_ee_c
  current_alignment += get_serialized_size_geometry_msgs__msg__TwistStamped(
    &(ros_message->o_dp_ee_c), current_alignment);

  // Field name: o_ddp_ee_c
  current_alignment += get_serialized_size_geometry_msgs__msg__AccelStamped(
    &(ros_message->o_ddp_ee_c), current_alignment);

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: control_command_success_rate
  {
    size_t item_size = sizeof(ros_message->control_command_success_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: robot_mode
  {
    size_t item_size = sizeof(ros_message->robot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: current_errors
  current_alignment += get_serialized_size_franka_msgs__msg__Errors(
    &(ros_message->current_errors), current_alignment);

  // Field name: last_motion_errors
  current_alignment += get_serialized_size_franka_msgs__msg__Errors(
    &(ros_message->last_motion_errors), current_alignment);

  // Field name: accelerometer_top
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->accelerometer_top;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->accelerometer_bottom;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t max_serialized_size_franka_msgs__msg__FrankaRobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: collision_indicators
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_franka_msgs__msg__CollisionIndicators(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: measured_joint_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: desired_joint_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: measured_joint_motor_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: ddq_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: elbow
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_franka_msgs__msg__Elbow(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: k_f_ext_hat_k
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__WrenchStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_f_ext_hat_k
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__WrenchStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: inertia_ee
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__InertiaStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: inertia_load
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__InertiaStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: inertia_total
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__InertiaStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_t_ee
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_t_ee_d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_t_ee_c
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: f_t_ee
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: ee_t_k
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_dp_ee_d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__TwistStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_dp_ee_c
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__TwistStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_ddp_ee_c
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__AccelStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: control_command_success_rate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: robot_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: current_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: last_motion_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accelerometer_top
  {
    size_t array_size = 6;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Vector3Stamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t array_size = 6;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Vector3Stamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_msgs__msg__FrankaRobotState;
    is_plain =
      (
      offsetof(DataType, accelerometer_bottom) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_serialize_key_franka_msgs__msg__FrankaRobotState(
  const franka_msgs__msg__FrankaRobotState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: collision_indicators
  {
    cdr_serialize_key_franka_msgs__msg__CollisionIndicators(
      &ros_message->collision_indicators, cdr);
  }

  // Field name: measured_joint_state
  {
    cdr_serialize_key_sensor_msgs__msg__JointState(
      &ros_message->measured_joint_state, cdr);
  }

  // Field name: desired_joint_state
  {
    cdr_serialize_key_sensor_msgs__msg__JointState(
      &ros_message->desired_joint_state, cdr);
  }

  // Field name: measured_joint_motor_state
  {
    cdr_serialize_key_sensor_msgs__msg__JointState(
      &ros_message->measured_joint_motor_state, cdr);
  }

  // Field name: ddq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->ddq_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dtau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtau_j;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_ext_hat_filtered
  {
    cdr_serialize_key_sensor_msgs__msg__JointState(
      &ros_message->tau_ext_hat_filtered, cdr);
  }

  // Field name: elbow
  {
    cdr_serialize_key_franka_msgs__msg__Elbow(
      &ros_message->elbow, cdr);
  }

  // Field name: k_f_ext_hat_k
  {
    cdr_serialize_key_geometry_msgs__msg__WrenchStamped(
      &ros_message->k_f_ext_hat_k, cdr);
  }

  // Field name: o_f_ext_hat_k
  {
    cdr_serialize_key_geometry_msgs__msg__WrenchStamped(
      &ros_message->o_f_ext_hat_k, cdr);
  }

  // Field name: inertia_ee
  {
    cdr_serialize_key_geometry_msgs__msg__InertiaStamped(
      &ros_message->inertia_ee, cdr);
  }

  // Field name: inertia_load
  {
    cdr_serialize_key_geometry_msgs__msg__InertiaStamped(
      &ros_message->inertia_load, cdr);
  }

  // Field name: inertia_total
  {
    cdr_serialize_key_geometry_msgs__msg__InertiaStamped(
      &ros_message->inertia_total, cdr);
  }

  // Field name: o_t_ee
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->o_t_ee, cdr);
  }

  // Field name: o_t_ee_d
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->o_t_ee_d, cdr);
  }

  // Field name: o_t_ee_c
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->o_t_ee_c, cdr);
  }

  // Field name: f_t_ee
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->f_t_ee, cdr);
  }

  // Field name: ee_t_k
  {
    cdr_serialize_key_geometry_msgs__msg__PoseStamped(
      &ros_message->ee_t_k, cdr);
  }

  // Field name: o_dp_ee_d
  {
    cdr_serialize_key_geometry_msgs__msg__TwistStamped(
      &ros_message->o_dp_ee_d, cdr);
  }

  // Field name: o_dp_ee_c
  {
    cdr_serialize_key_geometry_msgs__msg__TwistStamped(
      &ros_message->o_dp_ee_c, cdr);
  }

  // Field name: o_ddp_ee_c
  {
    cdr_serialize_key_geometry_msgs__msg__AccelStamped(
      &ros_message->o_ddp_ee_c, cdr);
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: control_command_success_rate
  {
    cdr << ros_message->control_command_success_rate;
  }

  // Field name: robot_mode
  {
    cdr << ros_message->robot_mode;
  }

  // Field name: current_errors
  {
    cdr_serialize_key_franka_msgs__msg__Errors(
      &ros_message->current_errors, cdr);
  }

  // Field name: last_motion_errors
  {
    cdr_serialize_key_franka_msgs__msg__Errors(
      &ros_message->last_motion_errors, cdr);
  }

  // Field name: accelerometer_top
  {
    size_t size = 6;
    auto array_ptr = ros_message->accelerometer_top;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[i], cdr);
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t size = 6;
    auto array_ptr = ros_message->accelerometer_bottom;
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t get_serialized_size_key_franka_msgs__msg__FrankaRobotState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrankaRobotState__ros_msg_type * ros_message = static_cast<const _FrankaRobotState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: collision_indicators
  current_alignment += get_serialized_size_key_franka_msgs__msg__CollisionIndicators(
    &(ros_message->collision_indicators), current_alignment);

  // Field name: measured_joint_state
  current_alignment += get_serialized_size_key_sensor_msgs__msg__JointState(
    &(ros_message->measured_joint_state), current_alignment);

  // Field name: desired_joint_state
  current_alignment += get_serialized_size_key_sensor_msgs__msg__JointState(
    &(ros_message->desired_joint_state), current_alignment);

  // Field name: measured_joint_motor_state
  current_alignment += get_serialized_size_key_sensor_msgs__msg__JointState(
    &(ros_message->measured_joint_motor_state), current_alignment);

  // Field name: ddq_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->ddq_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtau_j;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_ext_hat_filtered
  current_alignment += get_serialized_size_key_sensor_msgs__msg__JointState(
    &(ros_message->tau_ext_hat_filtered), current_alignment);

  // Field name: elbow
  current_alignment += get_serialized_size_key_franka_msgs__msg__Elbow(
    &(ros_message->elbow), current_alignment);

  // Field name: k_f_ext_hat_k
  current_alignment += get_serialized_size_key_geometry_msgs__msg__WrenchStamped(
    &(ros_message->k_f_ext_hat_k), current_alignment);

  // Field name: o_f_ext_hat_k
  current_alignment += get_serialized_size_key_geometry_msgs__msg__WrenchStamped(
    &(ros_message->o_f_ext_hat_k), current_alignment);

  // Field name: inertia_ee
  current_alignment += get_serialized_size_key_geometry_msgs__msg__InertiaStamped(
    &(ros_message->inertia_ee), current_alignment);

  // Field name: inertia_load
  current_alignment += get_serialized_size_key_geometry_msgs__msg__InertiaStamped(
    &(ros_message->inertia_load), current_alignment);

  // Field name: inertia_total
  current_alignment += get_serialized_size_key_geometry_msgs__msg__InertiaStamped(
    &(ros_message->inertia_total), current_alignment);

  // Field name: o_t_ee
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->o_t_ee), current_alignment);

  // Field name: o_t_ee_d
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->o_t_ee_d), current_alignment);

  // Field name: o_t_ee_c
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->o_t_ee_c), current_alignment);

  // Field name: f_t_ee
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->f_t_ee), current_alignment);

  // Field name: ee_t_k
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PoseStamped(
    &(ros_message->ee_t_k), current_alignment);

  // Field name: o_dp_ee_d
  current_alignment += get_serialized_size_key_geometry_msgs__msg__TwistStamped(
    &(ros_message->o_dp_ee_d), current_alignment);

  // Field name: o_dp_ee_c
  current_alignment += get_serialized_size_key_geometry_msgs__msg__TwistStamped(
    &(ros_message->o_dp_ee_c), current_alignment);

  // Field name: o_ddp_ee_c
  current_alignment += get_serialized_size_key_geometry_msgs__msg__AccelStamped(
    &(ros_message->o_ddp_ee_c), current_alignment);

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: control_command_success_rate
  {
    size_t item_size = sizeof(ros_message->control_command_success_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: robot_mode
  {
    size_t item_size = sizeof(ros_message->robot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: current_errors
  current_alignment += get_serialized_size_key_franka_msgs__msg__Errors(
    &(ros_message->current_errors), current_alignment);

  // Field name: last_motion_errors
  current_alignment += get_serialized_size_key_franka_msgs__msg__Errors(
    &(ros_message->last_motion_errors), current_alignment);

  // Field name: accelerometer_top
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->accelerometer_top;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->accelerometer_bottom;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_geometry_msgs__msg__Vector3Stamped(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t max_serialized_size_key_franka_msgs__msg__FrankaRobotState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: collision_indicators
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_franka_msgs__msg__CollisionIndicators(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: measured_joint_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: desired_joint_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: measured_joint_motor_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: ddq_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__JointState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: elbow
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_franka_msgs__msg__Elbow(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: k_f_ext_hat_k
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__WrenchStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_f_ext_hat_k
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__WrenchStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: inertia_ee
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__InertiaStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: inertia_load
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__InertiaStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: inertia_total
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__InertiaStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_t_ee
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_t_ee_d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_t_ee_c
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: f_t_ee
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: ee_t_k
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PoseStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_dp_ee_d
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__TwistStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_dp_ee_c
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__TwistStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: o_ddp_ee_c
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__AccelStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: control_command_success_rate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: robot_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: current_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: last_motion_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accelerometer_top
  {
    size_t array_size = 6;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Vector3Stamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: accelerometer_bottom
  {
    size_t array_size = 6;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Vector3Stamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_msgs__msg__FrankaRobotState;
    is_plain =
      (
      offsetof(DataType, accelerometer_bottom) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _FrankaRobotState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const franka_msgs__msg__FrankaRobotState * ros_message = static_cast<const franka_msgs__msg__FrankaRobotState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_franka_msgs__msg__FrankaRobotState(ros_message, cdr);
}

static bool _FrankaRobotState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  franka_msgs__msg__FrankaRobotState * ros_message = static_cast<franka_msgs__msg__FrankaRobotState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_franka_msgs__msg__FrankaRobotState(cdr, ros_message);
}

static uint32_t _FrankaRobotState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_franka_msgs__msg__FrankaRobotState(
      untyped_ros_message, 0));
}

static size_t _FrankaRobotState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_franka_msgs__msg__FrankaRobotState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FrankaRobotState = {
  "franka_msgs::msg",
  "FrankaRobotState",
  _FrankaRobotState__cdr_serialize,
  _FrankaRobotState__cdr_deserialize,
  _FrankaRobotState__get_serialized_size,
  _FrankaRobotState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FrankaRobotState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FrankaRobotState,
  get_message_typesupport_handle_function,
  &franka_msgs__msg__FrankaRobotState__get_type_hash,
  &franka_msgs__msg__FrankaRobotState__get_type_description,
  &franka_msgs__msg__FrankaRobotState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, FrankaRobotState)() {
  return &_FrankaRobotState__type_support;
}

#if defined(__cplusplus)
}
#endif
