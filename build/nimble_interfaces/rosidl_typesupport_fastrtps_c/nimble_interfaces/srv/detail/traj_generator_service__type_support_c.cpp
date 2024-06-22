// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/srv/detail/traj_generator_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "nimble_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nimble_interfaces/srv/detail/traj_generator_service__struct.h"
#include "nimble_interfaces/srv/detail/traj_generator_service__functions.h"
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

#include "nimble_interfaces/msg/detail/measurements__functions.h"  // measurements
#include "nimble_interfaces/msg/detail/therapy_requirements__functions.h"  // therapy_requirements

// forward declare type support functions
size_t get_serialized_size_nimble_interfaces__msg__Measurements(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nimble_interfaces__msg__Measurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, Measurements)();
size_t get_serialized_size_nimble_interfaces__msg__TherapyRequirements(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_nimble_interfaces__msg__TherapyRequirements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, TherapyRequirements)();


using _TrajGeneratorService_Request__ros_msg_type = nimble_interfaces__srv__TrajGeneratorService_Request;

static bool _TrajGeneratorService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TrajGeneratorService_Request__ros_msg_type * ros_message = static_cast<const _TrajGeneratorService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: measurements
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, Measurements
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->measurements, cdr))
    {
      return false;
    }
  }

  // Field name: therapy_requirements
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, TherapyRequirements
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->therapy_requirements, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _TrajGeneratorService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TrajGeneratorService_Request__ros_msg_type * ros_message = static_cast<_TrajGeneratorService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: measurements
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, Measurements
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->measurements))
    {
      return false;
    }
  }

  // Field name: therapy_requirements
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nimble_interfaces, msg, TherapyRequirements
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->therapy_requirements))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nimble_interfaces
size_t get_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TrajGeneratorService_Request__ros_msg_type * ros_message = static_cast<const _TrajGeneratorService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name measurements

  current_alignment += get_serialized_size_nimble_interfaces__msg__Measurements(
    &(ros_message->measurements), current_alignment);
  // field.name therapy_requirements

  current_alignment += get_serialized_size_nimble_interfaces__msg__TherapyRequirements(
    &(ros_message->therapy_requirements), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _TrajGeneratorService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nimble_interfaces
size_t max_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Request(
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

  // member: measurements
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nimble_interfaces__msg__Measurements(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: therapy_requirements
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_nimble_interfaces__msg__TherapyRequirements(
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
    using DataType = nimble_interfaces__srv__TrajGeneratorService_Request;
    is_plain =
      (
      offsetof(DataType, therapy_requirements) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TrajGeneratorService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TrajGeneratorService_Request = {
  "nimble_interfaces::srv",
  "TrajGeneratorService_Request",
  _TrajGeneratorService_Request__cdr_serialize,
  _TrajGeneratorService_Request__cdr_deserialize,
  _TrajGeneratorService_Request__get_serialized_size,
  _TrajGeneratorService_Request__max_serialized_size
};

static rosidl_message_type_support_t _TrajGeneratorService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TrajGeneratorService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, srv, TrajGeneratorService_Request)() {
  return &_TrajGeneratorService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "nimble_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "nimble_interfaces/srv/detail/traj_generator_service__struct.h"
// already included above
// #include "nimble_interfaces/srv/detail/traj_generator_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "trajectory_msgs/msg/detail/joint_trajectory__functions.h"  // joints_trajectory

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nimble_interfaces
size_t get_serialized_size_trajectory_msgs__msg__JointTrajectory(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nimble_interfaces
size_t max_serialized_size_trajectory_msgs__msg__JointTrajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_nimble_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trajectory_msgs, msg, JointTrajectory)();


using _TrajGeneratorService_Response__ros_msg_type = nimble_interfaces__srv__TrajGeneratorService_Response;

static bool _TrajGeneratorService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TrajGeneratorService_Response__ros_msg_type * ros_message = static_cast<const _TrajGeneratorService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: joints_trajectory
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trajectory_msgs, msg, JointTrajectory
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joints_trajectory, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _TrajGeneratorService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TrajGeneratorService_Response__ros_msg_type * ros_message = static_cast<_TrajGeneratorService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: joints_trajectory
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trajectory_msgs, msg, JointTrajectory
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joints_trajectory))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nimble_interfaces
size_t get_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TrajGeneratorService_Response__ros_msg_type * ros_message = static_cast<const _TrajGeneratorService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name joints_trajectory

  current_alignment += get_serialized_size_trajectory_msgs__msg__JointTrajectory(
    &(ros_message->joints_trajectory), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _TrajGeneratorService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nimble_interfaces
size_t max_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Response(
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

  // member: joints_trajectory
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_trajectory_msgs__msg__JointTrajectory(
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
    using DataType = nimble_interfaces__srv__TrajGeneratorService_Response;
    is_plain =
      (
      offsetof(DataType, joints_trajectory) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TrajGeneratorService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_nimble_interfaces__srv__TrajGeneratorService_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TrajGeneratorService_Response = {
  "nimble_interfaces::srv",
  "TrajGeneratorService_Response",
  _TrajGeneratorService_Response__cdr_serialize,
  _TrajGeneratorService_Response__cdr_deserialize,
  _TrajGeneratorService_Response__get_serialized_size,
  _TrajGeneratorService_Response__max_serialized_size
};

static rosidl_message_type_support_t _TrajGeneratorService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TrajGeneratorService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, srv, TrajGeneratorService_Response)() {
  return &_TrajGeneratorService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "nimble_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nimble_interfaces/srv/traj_generator_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t TrajGeneratorService__callbacks = {
  "nimble_interfaces::srv",
  "TrajGeneratorService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, srv, TrajGeneratorService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, srv, TrajGeneratorService_Response)(),
};

static rosidl_service_type_support_t TrajGeneratorService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &TrajGeneratorService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nimble_interfaces, srv, TrajGeneratorService)() {
  return &TrajGeneratorService__handle;
}

#if defined(__cplusplus)
}
#endif
