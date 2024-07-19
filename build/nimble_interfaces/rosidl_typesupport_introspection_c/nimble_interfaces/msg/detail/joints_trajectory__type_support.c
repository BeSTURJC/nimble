// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nimble_interfaces/msg/detail/joints_trajectory__rosidl_typesupport_introspection_c.h"
#include "nimble_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nimble_interfaces/msg/detail/joints_trajectory__functions.h"
#include "nimble_interfaces/msg/detail/joints_trajectory__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `phase`
#include "std_msgs/msg/float32_multi_array.h"
// Member `phase`
#include "std_msgs/msg/detail/float32_multi_array__rosidl_typesupport_introspection_c.h"
// Member `trajectory`
#include "trajectory_msgs/msg/joint_trajectory.h"
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nimble_interfaces__msg__JointsTrajectory__init(message_memory);
}

void nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_fini_function(void * message_memory)
{
  nimble_interfaces__msg__JointsTrajectory__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__JointsTrajectory, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "phase",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__JointsTrajectory, phase),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__JointsTrajectory, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "new_indicator",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__msg__JointsTrajectory, new_indicator),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_members = {
  "nimble_interfaces__msg",  // message namespace
  "JointsTrajectory",  // message name
  4,  // number of fields
  sizeof(nimble_interfaces__msg__JointsTrajectory),
  nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_member_array,  // message members
  nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_type_support_handle = {
  0,
  &nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, JointsTrajectory)() {
  nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_msgs, msg, JointTrajectory)();
  if (!nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_type_support_handle.typesupport_identifier) {
    nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nimble_interfaces__msg__JointsTrajectory__rosidl_typesupport_introspection_c__JointsTrajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
