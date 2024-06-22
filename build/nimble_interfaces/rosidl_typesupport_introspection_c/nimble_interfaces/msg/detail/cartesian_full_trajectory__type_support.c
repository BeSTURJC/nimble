// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nimble_interfaces/msg/detail/cartesian_full_trajectory__rosidl_typesupport_introspection_c.h"
#include "nimble_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nimble_interfaces/msg/detail/cartesian_full_trajectory__functions.h"
#include "nimble_interfaces/msg/detail/cartesian_full_trajectory__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `left_pelvis`
// Member `right_pelvis`
// Member `base_pelvis`
// Member `left_hip`
// Member `right_hip`
// Member `left_knee`
// Member `right_knee`
// Member `left_ankle`
// Member `right_ankle`
// Member `left_heel`
// Member `right_heel`
// Member `left_toe`
// Member `right_toe`
#include "geometry_msgs/msg/point.h"
// Member `left_pelvis`
// Member `right_pelvis`
// Member `base_pelvis`
// Member `left_hip`
// Member `right_hip`
// Member `left_knee`
// Member `right_knee`
// Member `left_ankle`
// Member `right_ankle`
// Member `left_heel`
// Member `right_heel`
// Member `left_toe`
// Member `right_toe`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nimble_interfaces__msg__CartesianFullTrajectory__init(message_memory);
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_fini_function(void * message_memory)
{
  nimble_interfaces__msg__CartesianFullTrajectory__fini(message_memory);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_pelvis(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_pelvis(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_pelvis(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_pelvis(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_pelvis(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_pelvis(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_pelvis(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_pelvis(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_pelvis(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_pelvis(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_pelvis(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_pelvis(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__base_pelvis(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__base_pelvis(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__base_pelvis(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__base_pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__base_pelvis(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__base_pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__base_pelvis(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__base_pelvis(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_hip(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_hip(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_hip(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_hip(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_hip(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_hip(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_hip(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_hip(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_hip(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_hip(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_hip(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_hip(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_hip(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_hip(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_hip(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_hip(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_knee(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_knee(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_knee(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_knee(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_knee(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_knee(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_knee(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_knee(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_knee(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_knee(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_knee(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_knee(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_knee(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_knee(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_knee(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_knee(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_ankle(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_ankle(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_ankle(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_ankle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_ankle(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_ankle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_ankle(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_ankle(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_ankle(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_ankle(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_ankle(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_ankle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_ankle(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_ankle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_ankle(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_ankle(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_heel(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_heel(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_heel(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_heel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_heel(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_heel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_heel(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_heel(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_heel(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_heel(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_heel(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_heel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_heel(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_heel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_heel(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_heel(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_toe(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_toe(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_toe(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_toe(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_toe(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_toe(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_toe(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_toe(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_toe(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_toe(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_toe(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_toe(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_toe(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_toe(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_toe(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_toe(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[14] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_pelvis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, left_pelvis),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_pelvis,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_pelvis,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_pelvis,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_pelvis,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_pelvis,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_pelvis  // resize(index) function pointer
  },
  {
    "right_pelvis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, right_pelvis),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_pelvis,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_pelvis,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_pelvis,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_pelvis,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_pelvis,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_pelvis  // resize(index) function pointer
  },
  {
    "base_pelvis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, base_pelvis),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__base_pelvis,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__base_pelvis,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__base_pelvis,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__base_pelvis,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__base_pelvis,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__base_pelvis  // resize(index) function pointer
  },
  {
    "left_hip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, left_hip),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_hip,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_hip,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_hip,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_hip,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_hip,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_hip  // resize(index) function pointer
  },
  {
    "right_hip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, right_hip),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_hip,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_hip,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_hip,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_hip,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_hip,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_hip  // resize(index) function pointer
  },
  {
    "left_knee",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, left_knee),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_knee,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_knee,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_knee,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_knee,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_knee,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_knee  // resize(index) function pointer
  },
  {
    "right_knee",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, right_knee),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_knee,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_knee,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_knee,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_knee,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_knee,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_knee  // resize(index) function pointer
  },
  {
    "left_ankle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, left_ankle),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_ankle,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_ankle,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_ankle,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_ankle,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_ankle,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_ankle  // resize(index) function pointer
  },
  {
    "right_ankle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, right_ankle),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_ankle,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_ankle,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_ankle,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_ankle,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_ankle,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_ankle  // resize(index) function pointer
  },
  {
    "left_heel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, left_heel),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_heel,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_heel,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_heel,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_heel,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_heel,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_heel  // resize(index) function pointer
  },
  {
    "right_heel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, right_heel),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_heel,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_heel,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_heel,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_heel,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_heel,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_heel  // resize(index) function pointer
  },
  {
    "left_toe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, left_toe),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__left_toe,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__left_toe,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__left_toe,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__left_toe,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__left_toe,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__left_toe  // resize(index) function pointer
  },
  {
    "right_toe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianFullTrajectory, right_toe),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianFullTrajectory__right_toe,  // size() function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianFullTrajectory__right_toe,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianFullTrajectory__right_toe,  // get(index) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianFullTrajectory__right_toe,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianFullTrajectory__right_toe,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianFullTrajectory__right_toe  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_members = {
  "nimble_interfaces__msg",  // message namespace
  "CartesianFullTrajectory",  // message name
  14,  // number of fields
  sizeof(nimble_interfaces__msg__CartesianFullTrajectory),
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array,  // message members
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_type_support_handle = {
  0,
  &nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, CartesianFullTrajectory)() {
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_member_array[13].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_type_support_handle.typesupport_identifier) {
    nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nimble_interfaces__msg__CartesianFullTrajectory__rosidl_typesupport_introspection_c__CartesianFullTrajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
