// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "frame_data/msg/detail/frame_data__rosidl_typesupport_introspection_c.h"
#include "frame_data/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "frame_data/msg/detail/frame_data__functions.h"
#include "frame_data/msg/detail/frame_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  frame_data__msg__FrameData__init(message_memory);
}

void frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_fini_function(void * message_memory)
{
  frame_data__msg__FrameData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_member_array[6] = {
  {
    "contador",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frame_data__msg__FrameData, contador),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frame_data__msg__FrameData, frame_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frame_data__msg__FrameData, frame_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sensor_dist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frame_data__msg__FrameData, sensor_dist),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_ref",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frame_data__msg__FrameData, position_ref),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_ref",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frame_data__msg__FrameData, speed_ref),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_members = {
  "frame_data__msg",  // message namespace
  "FrameData",  // message name
  6,  // number of fields
  sizeof(frame_data__msg__FrameData),
  frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_member_array,  // message members
  frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_init_function,  // function to initialize message memory (memory has to be allocated)
  frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_type_support_handle = {
  0,
  &frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_frame_data
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, frame_data, msg, FrameData)() {
  if (!frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_type_support_handle.typesupport_identifier) {
    frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &frame_data__msg__FrameData__rosidl_typesupport_introspection_c__FrameData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
