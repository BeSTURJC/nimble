// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__TRAITS_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/msg/detail/joints_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'phase'
#include "std_msgs/msg/detail/float32_multi_array__traits.hpp"
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__traits.hpp"

namespace nimble_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointsTrajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: phase
  {
    out << "phase: ";
    to_flow_style_yaml(msg.phase, out);
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointsTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: phase
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phase:\n";
    to_block_style_yaml(msg.phase, out, indentation + 2);
  }

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointsTrajectory & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace nimble_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nimble_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nimble_interfaces::msg::JointsTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::msg::JointsTrajectory & msg)
{
  return nimble_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::msg::JointsTrajectory>()
{
  return "nimble_interfaces::msg::JointsTrajectory";
}

template<>
inline const char * name<nimble_interfaces::msg::JointsTrajectory>()
{
  return "nimble_interfaces/msg/JointsTrajectory";
}

template<>
struct has_fixed_size<nimble_interfaces::msg::JointsTrajectory>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float32MultiArray>::value && has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::msg::JointsTrajectory>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float32MultiArray>::value && has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct is_message<nimble_interfaces::msg::JointsTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__TRAITS_HPP_
