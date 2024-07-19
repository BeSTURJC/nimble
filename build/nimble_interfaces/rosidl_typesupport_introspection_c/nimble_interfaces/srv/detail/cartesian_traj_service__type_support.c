// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nimble_interfaces/srv/detail/cartesian_traj_service__rosidl_typesupport_introspection_c.h"
#include "nimble_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nimble_interfaces/srv/detail/cartesian_traj_service__functions.h"
#include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.h"


// Include directives for member types
// Member `joints_trajectory`
#include "trajectory_msgs/msg/joint_trajectory.h"
// Member `joints_trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__rosidl_typesupport_introspection_c.h"
// Member `measurements`
#include "nimble_interfaces/msg/measurements.h"
// Member `measurements`
#include "nimble_interfaces/msg/detail/measurements__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nimble_interfaces__srv__CartesianTrajService_Request__init(message_memory);
}

void nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_fini_function(void * message_memory)
{
  nimble_interfaces__srv__CartesianTrajService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_member_array[2] = {
  {
    "joints_trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__srv__CartesianTrajService_Request, joints_trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "measurements",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__srv__CartesianTrajService_Request, measurements),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_members = {
  "nimble_interfaces__srv",  // message namespace
  "CartesianTrajService_Request",  // message name
  2,  // number of fields
  sizeof(nimble_interfaces__srv__CartesianTrajService_Request),
  nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_member_array,  // message members
  nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_type_support_handle = {
  0,
  &nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService_Request)() {
  nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_msgs, msg, JointTrajectory)();
  nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, Measurements)();
  if (!nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_type_support_handle.typesupport_identifier) {
    nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nimble_interfaces__srv__CartesianTrajService_Request__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "nimble_interfaces/srv/detail/cartesian_traj_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "nimble_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "nimble_interfaces/srv/detail/cartesian_traj_service__functions.h"
// already included above
// #include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.h"


// Include directives for member types
// Member `cartesian_trajectory`
#include "nimble_interfaces/msg/cartesian_trajectory.h"
// Member `cartesian_trajectory`
#include "nimble_interfaces/msg/detail/cartesian_trajectory__rosidl_typesupport_introspection_c.h"
// Member `step_target`
#include "nimble_interfaces/msg/therapy_requirements.h"
// Member `step_target`
#include "nimble_interfaces/msg/detail/therapy_requirements__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nimble_interfaces__srv__CartesianTrajService_Response__init(message_memory);
}

void nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_fini_function(void * message_memory)
{
  nimble_interfaces__srv__CartesianTrajService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_member_array[2] = {
  {
    "cartesian_trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__srv__CartesianTrajService_Response, cartesian_trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step_target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces__srv__CartesianTrajService_Response, step_target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_members = {
  "nimble_interfaces__srv",  // message namespace
  "CartesianTrajService_Response",  // message name
  2,  // number of fields
  sizeof(nimble_interfaces__srv__CartesianTrajService_Response),
  nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_member_array,  // message members
  nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_type_support_handle = {
  0,
  &nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService_Response)() {
  nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, CartesianTrajectory)();
  nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, msg, TherapyRequirements)();
  if (!nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_type_support_handle.typesupport_identifier) {
    nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nimble_interfaces__srv__CartesianTrajService_Response__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "nimble_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "nimble_interfaces/srv/detail/cartesian_traj_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_members = {
  "nimble_interfaces__srv",  // service namespace
  "CartesianTrajService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_Request_message_type_support_handle,
  NULL  // response message
  // nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_Response_message_type_support_handle
};

static rosidl_service_type_support_t nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_type_support_handle = {
  0,
  &nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nimble_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService)() {
  if (!nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_type_support_handle.typesupport_identifier) {
    nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nimble_interfaces, srv, CartesianTrajService_Response)()->data;
  }

  return &nimble_interfaces__srv__detail__cartesian_traj_service__rosidl_typesupport_introspection_c__CartesianTrajService_service_type_support_handle;
}
