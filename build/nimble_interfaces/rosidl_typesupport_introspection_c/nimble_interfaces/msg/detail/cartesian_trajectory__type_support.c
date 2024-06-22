// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nimble_interfaces/msg/detail/cartesian_trajectory__rosidl_typesupport_introspection_c.h"
#include "nimble_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nimble_interfaces/msg/detail/cartesian_trajectory__functions.h"
#include "nimble_interfaces/msg/detail/cartesian_trajectory__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `malleolus`
// Member `pelvis`
#include "geometry_msgs/msg/point.h"
// Member `malleolus`
// Member `pelvis`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nimble_interfaces__msg__CartesianTrajectory__init(message_memory);
}

void nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_fini_function(void * message_memory)
{
  nimble_interfaces__msg__CartesianTrajectory__fini(message_memory);
}

size_t nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianTrajectory__malleolus(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianTrajectory__malleolus(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianTrajectory__malleolus(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianTrajectory__malleolus(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianTrajectory__malleolus(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianTrajectory__malleolus(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianTrajectory__malleolus(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianTrajectory__malleolus(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianTrajectory__pelvis(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianTrajectory__pelvis(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianTrajectory__pelvis(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianTrajectory__pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianTrajectory__pelvis(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianTrajectory__pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianTrajectory__pelvis(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianTrajectory__pelvis(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianTrajectory, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "malleolus",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianTrajectory, malleolus),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianTrajectory__malleolus,  // size() function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianTrajectory__malleolus,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianTrajectory__malleolus,  // get(index) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianTrajectory__malleolus,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianTrajectory__malleolus,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianTrajectory__malleolus  // resize(index) function pointer
  },
  {
    "pelvis",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__CartesianTrajectory, pelvis),  // bytes offset in struct
    NULL,  // default value
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__size_function__CartesianTrajectory__pelvis,  // size() function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_const_function__CartesianTrajectory__pelvis,  // get_const(index) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__get_function__CartesianTrajectory__pelvis,  // get(index) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__fetch_function__CartesianTrajectory__pelvis,  // fetch(index, &value) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__assign_function__CartesianTrajectory__pelvis,  // assign(index, value) function pointer
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__resize_function__CartesianTrajectory__pelvis  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_members = {
  "nimble_interfaces__msg",  // message namespace
  "CartesianTrajectory",  // message name
  3,  // number of fields
  sizeof(nimble_interfaces__msg__CartesianTrajectory),
  nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_member_array,  // message members
  nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_type_support_handle = {
  0,
  &nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, CartesianTrajectory)() {
  nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_type_support_handle.typesupport_identifier) {
    nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nimble_interfaces__msg__CartesianTrajectory__rosidl_typesupport_introspection_c__CartesianTrajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
