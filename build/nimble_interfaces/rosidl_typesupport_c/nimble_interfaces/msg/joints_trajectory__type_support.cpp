// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "nimble_interfaces/msg/detail/joints_trajectory__struct.h"
#include "nimble_interfaces/msg/detail/joints_trajectory__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace nimble_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _JointsTrajectory_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _JointsTrajectory_type_support_ids_t;

static const _JointsTrajectory_type_support_ids_t _JointsTrajectory_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _JointsTrajectory_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _JointsTrajectory_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _JointsTrajectory_type_support_symbol_names_t _JointsTrajectory_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, JointsTrajectory)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, JointsTrajectory)),
  }
};

typedef struct _JointsTrajectory_type_support_data_t
{
  void * data[2];
} _JointsTrajectory_type_support_data_t;

static _JointsTrajectory_type_support_data_t _JointsTrajectory_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _JointsTrajectory_message_typesupport_map = {
  2,
  "nimble_interfaces",
  &_JointsTrajectory_message_typesupport_ids.typesupport_identifier[0],
  &_JointsTrajectory_message_typesupport_symbol_names.symbol_name[0],
  &_JointsTrajectory_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t JointsTrajectory_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_JointsTrajectory_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace nimble_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, nimble_interfaces, msg, JointsTrajectory)() {
  return &::nimble_interfaces::msg::rosidl_typesupport_c::JointsTrajectory_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
