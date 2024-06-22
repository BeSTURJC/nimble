// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nimble_interfaces/msg/detail/cartesian_full_trajectory__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nimble_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CartesianFullTrajectory_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nimble_interfaces::msg::CartesianFullTrajectory(_init);
}

void CartesianFullTrajectory_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nimble_interfaces::msg::CartesianFullTrajectory *>(message_memory);
  typed_message->~CartesianFullTrajectory();
}

size_t size_function__CartesianFullTrajectory__left_pelvis(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__left_pelvis(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__left_pelvis(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__left_pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__left_pelvis(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__left_pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__left_pelvis(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__left_pelvis(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__right_pelvis(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__right_pelvis(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__right_pelvis(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__right_pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__right_pelvis(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__right_pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__right_pelvis(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__right_pelvis(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__base_pelvis(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__base_pelvis(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__base_pelvis(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__base_pelvis(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__base_pelvis(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__base_pelvis(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__base_pelvis(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__base_pelvis(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__left_hip(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__left_hip(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__left_hip(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__left_hip(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__left_hip(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__left_hip(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__left_hip(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__left_hip(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__right_hip(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__right_hip(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__right_hip(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__right_hip(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__right_hip(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__right_hip(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__right_hip(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__right_hip(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__left_knee(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__left_knee(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__left_knee(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__left_knee(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__left_knee(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__left_knee(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__left_knee(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__left_knee(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__right_knee(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__right_knee(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__right_knee(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__right_knee(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__right_knee(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__right_knee(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__right_knee(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__right_knee(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__left_ankle(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__left_ankle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__left_ankle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__left_ankle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__left_ankle(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__left_ankle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__left_ankle(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__left_ankle(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__right_ankle(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__right_ankle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__right_ankle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__right_ankle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__right_ankle(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__right_ankle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__right_ankle(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__right_ankle(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__left_heel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__left_heel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__left_heel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__left_heel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__left_heel(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__left_heel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__left_heel(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__left_heel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__right_heel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__right_heel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__right_heel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__right_heel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__right_heel(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__right_heel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__right_heel(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__right_heel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__left_toe(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__left_toe(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__left_toe(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__left_toe(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__left_toe(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__left_toe(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__left_toe(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__left_toe(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__CartesianFullTrajectory__right_toe(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CartesianFullTrajectory__right_toe(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__CartesianFullTrajectory__right_toe(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__CartesianFullTrajectory__right_toe(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__CartesianFullTrajectory__right_toe(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__CartesianFullTrajectory__right_toe(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__CartesianFullTrajectory__right_toe(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__CartesianFullTrajectory__right_toe(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CartesianFullTrajectory_message_member_array[14] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "left_pelvis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, left_pelvis),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__left_pelvis,  // size() function pointer
    get_const_function__CartesianFullTrajectory__left_pelvis,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__left_pelvis,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__left_pelvis,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__left_pelvis,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__left_pelvis  // resize(index) function pointer
  },
  {
    "right_pelvis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, right_pelvis),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__right_pelvis,  // size() function pointer
    get_const_function__CartesianFullTrajectory__right_pelvis,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__right_pelvis,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__right_pelvis,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__right_pelvis,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__right_pelvis  // resize(index) function pointer
  },
  {
    "base_pelvis",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, base_pelvis),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__base_pelvis,  // size() function pointer
    get_const_function__CartesianFullTrajectory__base_pelvis,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__base_pelvis,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__base_pelvis,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__base_pelvis,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__base_pelvis  // resize(index) function pointer
  },
  {
    "left_hip",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, left_hip),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__left_hip,  // size() function pointer
    get_const_function__CartesianFullTrajectory__left_hip,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__left_hip,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__left_hip,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__left_hip,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__left_hip  // resize(index) function pointer
  },
  {
    "right_hip",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, right_hip),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__right_hip,  // size() function pointer
    get_const_function__CartesianFullTrajectory__right_hip,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__right_hip,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__right_hip,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__right_hip,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__right_hip  // resize(index) function pointer
  },
  {
    "left_knee",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, left_knee),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__left_knee,  // size() function pointer
    get_const_function__CartesianFullTrajectory__left_knee,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__left_knee,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__left_knee,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__left_knee,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__left_knee  // resize(index) function pointer
  },
  {
    "right_knee",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, right_knee),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__right_knee,  // size() function pointer
    get_const_function__CartesianFullTrajectory__right_knee,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__right_knee,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__right_knee,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__right_knee,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__right_knee  // resize(index) function pointer
  },
  {
    "left_ankle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, left_ankle),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__left_ankle,  // size() function pointer
    get_const_function__CartesianFullTrajectory__left_ankle,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__left_ankle,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__left_ankle,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__left_ankle,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__left_ankle  // resize(index) function pointer
  },
  {
    "right_ankle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, right_ankle),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__right_ankle,  // size() function pointer
    get_const_function__CartesianFullTrajectory__right_ankle,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__right_ankle,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__right_ankle,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__right_ankle,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__right_ankle  // resize(index) function pointer
  },
  {
    "left_heel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, left_heel),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__left_heel,  // size() function pointer
    get_const_function__CartesianFullTrajectory__left_heel,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__left_heel,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__left_heel,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__left_heel,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__left_heel  // resize(index) function pointer
  },
  {
    "right_heel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, right_heel),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__right_heel,  // size() function pointer
    get_const_function__CartesianFullTrajectory__right_heel,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__right_heel,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__right_heel,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__right_heel,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__right_heel  // resize(index) function pointer
  },
  {
    "left_toe",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, left_toe),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__left_toe,  // size() function pointer
    get_const_function__CartesianFullTrajectory__left_toe,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__left_toe,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__left_toe,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__left_toe,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__left_toe  // resize(index) function pointer
  },
  {
    "right_toe",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nimble_interfaces::msg::CartesianFullTrajectory, right_toe),  // bytes offset in struct
    nullptr,  // default value
    size_function__CartesianFullTrajectory__right_toe,  // size() function pointer
    get_const_function__CartesianFullTrajectory__right_toe,  // get_const(index) function pointer
    get_function__CartesianFullTrajectory__right_toe,  // get(index) function pointer
    fetch_function__CartesianFullTrajectory__right_toe,  // fetch(index, &value) function pointer
    assign_function__CartesianFullTrajectory__right_toe,  // assign(index, value) function pointer
    resize_function__CartesianFullTrajectory__right_toe  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CartesianFullTrajectory_message_members = {
  "nimble_interfaces::msg",  // message namespace
  "CartesianFullTrajectory",  // message name
  14,  // number of fields
  sizeof(nimble_interfaces::msg::CartesianFullTrajectory),
  CartesianFullTrajectory_message_member_array,  // message members
  CartesianFullTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  CartesianFullTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CartesianFullTrajectory_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CartesianFullTrajectory_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace nimble_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nimble_interfaces::msg::CartesianFullTrajectory>()
{
  return &::nimble_interfaces::msg::rosidl_typesupport_introspection_cpp::CartesianFullTrajectory_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nimble_interfaces, msg, CartesianFullTrajectory)() {
  return &::nimble_interfaces::msg::rosidl_typesupport_introspection_cpp::CartesianFullTrajectory_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
