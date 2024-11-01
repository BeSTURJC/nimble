// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:msg/FrameState.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__TRAITS_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/msg/detail/frame_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nimble_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FrameState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: optic_sensor
  {
    out << "optic_sensor: ";
    rosidl_generator_traits::value_to_yaml(msg.optic_sensor, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FrameState & msg,
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

  // member: optic_sensor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "optic_sensor: ";
    rosidl_generator_traits::value_to_yaml(msg.optic_sensor, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FrameState & msg, bool use_flow_style = false)
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
  const nimble_interfaces::msg::FrameState & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::msg::FrameState & msg)
{
  return nimble_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::msg::FrameState>()
{
  return "nimble_interfaces::msg::FrameState";
}

template<>
inline const char * name<nimble_interfaces::msg::FrameState>()
{
  return "nimble_interfaces/msg/FrameState";
}

template<>
struct has_fixed_size<nimble_interfaces::msg::FrameState>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::msg::FrameState>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<nimble_interfaces::msg::FrameState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__TRAITS_HPP_
