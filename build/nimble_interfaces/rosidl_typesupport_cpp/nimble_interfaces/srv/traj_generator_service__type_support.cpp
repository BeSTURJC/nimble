// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "nimble_interfaces/srv/detail/traj_generator_service__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace nimble_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TrajGeneratorService_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TrajGeneratorService_Request_type_support_ids_t;

static const _TrajGeneratorService_Request_type_support_ids_t _TrajGeneratorService_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TrajGeneratorService_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TrajGeneratorService_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TrajGeneratorService_Request_type_support_symbol_names_t _TrajGeneratorService_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nimble_interfaces, srv, TrajGeneratorService_Request)),
  }
};

typedef struct _TrajGeneratorService_Request_type_support_data_t
{
  void * data[2];
} _TrajGeneratorService_Request_type_support_data_t;

static _TrajGeneratorService_Request_type_support_data_t _TrajGeneratorService_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TrajGeneratorService_Request_message_typesupport_map = {
  2,
  "nimble_interfaces",
  &_TrajGeneratorService_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TrajGeneratorService_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TrajGeneratorService_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TrajGeneratorService_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TrajGeneratorService_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nimble_interfaces::srv::TrajGeneratorService_Request>()
{
  return &::nimble_interfaces::srv::rosidl_typesupport_cpp::TrajGeneratorService_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nimble_interfaces, srv, TrajGeneratorService_Request)() {
  return get_message_type_support_handle<nimble_interfaces::srv::TrajGeneratorService_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "nimble_interfaces/srv/detail/traj_generator_service__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nimble_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TrajGeneratorService_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TrajGeneratorService_Response_type_support_ids_t;

static const _TrajGeneratorService_Response_type_support_ids_t _TrajGeneratorService_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TrajGeneratorService_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TrajGeneratorService_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TrajGeneratorService_Response_type_support_symbol_names_t _TrajGeneratorService_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nimble_interfaces, srv, TrajGeneratorService_Response)),
  }
};

typedef struct _TrajGeneratorService_Response_type_support_data_t
{
  void * data[2];
} _TrajGeneratorService_Response_type_support_data_t;

static _TrajGeneratorService_Response_type_support_data_t _TrajGeneratorService_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TrajGeneratorService_Response_message_typesupport_map = {
  2,
  "nimble_interfaces",
  &_TrajGeneratorService_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TrajGeneratorService_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TrajGeneratorService_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TrajGeneratorService_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TrajGeneratorService_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nimble_interfaces::srv::TrajGeneratorService_Response>()
{
  return &::nimble_interfaces::srv::rosidl_typesupport_cpp::TrajGeneratorService_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, nimble_interfaces, srv, TrajGeneratorService_Response)() {
  return get_message_type_support_handle<nimble_interfaces::srv::TrajGeneratorService_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "nimble_interfaces/srv/detail/traj_generator_service__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace nimble_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TrajGeneratorService_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TrajGeneratorService_type_support_ids_t;

static const _TrajGeneratorService_type_support_ids_t _TrajGeneratorService_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TrajGeneratorService_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TrajGeneratorService_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TrajGeneratorService_type_support_symbol_names_t _TrajGeneratorService_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nimble_interfaces, srv, TrajGeneratorService)),
  }
};

typedef struct _TrajGeneratorService_type_support_data_t
{
  void * data[2];
} _TrajGeneratorService_type_support_data_t;

static _TrajGeneratorService_type_support_data_t _TrajGeneratorService_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TrajGeneratorService_service_typesupport_map = {
  2,
  "nimble_interfaces",
  &_TrajGeneratorService_service_typesupport_ids.typesupport_identifier[0],
  &_TrajGeneratorService_service_typesupport_symbol_names.symbol_name[0],
  &_TrajGeneratorService_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TrajGeneratorService_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TrajGeneratorService_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<nimble_interfaces::srv::TrajGeneratorService>()
{
  return &::nimble_interfaces::srv::rosidl_typesupport_cpp::TrajGeneratorService_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
