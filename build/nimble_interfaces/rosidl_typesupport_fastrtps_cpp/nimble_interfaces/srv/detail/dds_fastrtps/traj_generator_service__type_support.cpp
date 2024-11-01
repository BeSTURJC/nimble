// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/srv/detail/traj_generator_service__rosidl_typesupport_fastrtps_cpp.hpp"
#include "nimble_interfaces/srv/detail/traj_generator_service__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace nimble_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const nimble_interfaces::msg::Measurements &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  nimble_interfaces::msg::Measurements &);
size_t get_serialized_size(
  const nimble_interfaces::msg::Measurements &,
  size_t current_alignment);
size_t
max_serialized_size_Measurements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace nimble_interfaces

namespace nimble_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const nimble_interfaces::msg::TherapyRequirements &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  nimble_interfaces::msg::TherapyRequirements &);
size_t get_serialized_size(
  const nimble_interfaces::msg::TherapyRequirements &,
  size_t current_alignment);
size_t
max_serialized_size_TherapyRequirements(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace nimble_interfaces


namespace nimble_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
cdr_serialize(
  const nimble_interfaces::srv::TrajGeneratorService_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: measurements
  nimble_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.measurements,
    cdr);
  // Member: therapy_requirements
  nimble_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.therapy_requirements,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nimble_interfaces::srv::TrajGeneratorService_Request & ros_message)
{
  // Member: measurements
  nimble_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.measurements);

  // Member: therapy_requirements
  nimble_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.therapy_requirements);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
get_serialized_size(
  const nimble_interfaces::srv::TrajGeneratorService_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: measurements

  current_alignment +=
    nimble_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.measurements, current_alignment);
  // Member: therapy_requirements

  current_alignment +=
    nimble_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.therapy_requirements, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
max_serialized_size_TrajGeneratorService_Request(
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


  // Member: measurements
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        nimble_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Measurements(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: therapy_requirements
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        nimble_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_TherapyRequirements(
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
    using DataType = nimble_interfaces::srv::TrajGeneratorService_Request;
    is_plain =
      (
      offsetof(DataType, therapy_requirements) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _TrajGeneratorService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const nimble_interfaces::srv::TrajGeneratorService_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TrajGeneratorService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nimble_interfaces::srv::TrajGeneratorService_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TrajGeneratorService_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nimble_interfaces::srv::TrajGeneratorService_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TrajGeneratorService_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TrajGeneratorService_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TrajGeneratorService_Request__callbacks = {
  "nimble_interfaces::srv",
  "TrajGeneratorService_Request",
  _TrajGeneratorService_Request__cdr_serialize,
  _TrajGeneratorService_Request__cdr_deserialize,
  _TrajGeneratorService_Request__get_serialized_size,
  _TrajGeneratorService_Request__max_serialized_size
};

static rosidl_message_type_support_t _TrajGeneratorService_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TrajGeneratorService_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<nimble_interfaces::srv::TrajGeneratorService_Request>()
{
  return &nimble_interfaces::srv::typesupport_fastrtps_cpp::_TrajGeneratorService_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService_Request)() {
  return &nimble_interfaces::srv::typesupport_fastrtps_cpp::_TrajGeneratorService_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace trajectory_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const trajectory_msgs::msg::JointTrajectory &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  trajectory_msgs::msg::JointTrajectory &);
size_t get_serialized_size(
  const trajectory_msgs::msg::JointTrajectory &,
  size_t current_alignment);
size_t
max_serialized_size_JointTrajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace trajectory_msgs


namespace nimble_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
cdr_serialize(
  const nimble_interfaces::srv::TrajGeneratorService_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: joints_trajectory
  trajectory_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.joints_trajectory,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nimble_interfaces::srv::TrajGeneratorService_Response & ros_message)
{
  // Member: joints_trajectory
  trajectory_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.joints_trajectory);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
get_serialized_size(
  const nimble_interfaces::srv::TrajGeneratorService_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: joints_trajectory

  current_alignment +=
    trajectory_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.joints_trajectory, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
max_serialized_size_TrajGeneratorService_Response(
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


  // Member: joints_trajectory
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        trajectory_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_JointTrajectory(
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
    using DataType = nimble_interfaces::srv::TrajGeneratorService_Response;
    is_plain =
      (
      offsetof(DataType, joints_trajectory) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _TrajGeneratorService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const nimble_interfaces::srv::TrajGeneratorService_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TrajGeneratorService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nimble_interfaces::srv::TrajGeneratorService_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TrajGeneratorService_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nimble_interfaces::srv::TrajGeneratorService_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TrajGeneratorService_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TrajGeneratorService_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TrajGeneratorService_Response__callbacks = {
  "nimble_interfaces::srv",
  "TrajGeneratorService_Response",
  _TrajGeneratorService_Response__cdr_serialize,
  _TrajGeneratorService_Response__cdr_deserialize,
  _TrajGeneratorService_Response__get_serialized_size,
  _TrajGeneratorService_Response__max_serialized_size
};

static rosidl_message_type_support_t _TrajGeneratorService_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TrajGeneratorService_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nimble_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<nimble_interfaces::srv::TrajGeneratorService_Response>()
{
  return &nimble_interfaces::srv::typesupport_fastrtps_cpp::_TrajGeneratorService_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService_Response)() {
  return &nimble_interfaces::srv::typesupport_fastrtps_cpp::_TrajGeneratorService_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace nimble_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _TrajGeneratorService__callbacks = {
  "nimble_interfaces::srv",
  "TrajGeneratorService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService_Response)(),
};

static rosidl_service_type_support_t _TrajGeneratorService__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TrajGeneratorService__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nimble_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<nimble_interfaces::srv::TrajGeneratorService>()
{
  return &nimble_interfaces::srv::typesupport_fastrtps_cpp::_TrajGeneratorService__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, srv, TrajGeneratorService)() {
  return &nimble_interfaces::srv::typesupport_fastrtps_cpp::_TrajGeneratorService__handle;
}

#ifdef __cplusplus
}
#endif
