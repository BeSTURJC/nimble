// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "nimble_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "nimble_interfaces/msg/detail/cartesian_full_trajectory__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace nimble_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
cdr_serialize(
  const nimble_interfaces::msg::CartesianFullTrajectory & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nimble_interfaces::msg::CartesianFullTrajectory & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
get_serialized_size(
  const nimble_interfaces::msg::CartesianFullTrajectory & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
max_serialized_size_CartesianFullTrajectory(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace nimble_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nimble_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nimble_interfaces, msg, CartesianFullTrajectory)();

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
