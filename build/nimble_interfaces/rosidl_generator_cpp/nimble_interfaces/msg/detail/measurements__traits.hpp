// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:msg/Measurements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__TRAITS_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/msg/detail/measurements__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nimble_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Measurements & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: femur
  {
    out << "femur: ";
    rosidl_generator_traits::value_to_yaml(msg.femur, out);
    out << ", ";
  }

  // member: tibia
  {
    out << "tibia: ";
    rosidl_generator_traits::value_to_yaml(msg.tibia, out);
    out << ", ";
  }

  // member: height_ankle
  {
    out << "height_ankle: ";
    rosidl_generator_traits::value_to_yaml(msg.height_ankle, out);
    out << ", ";
  }

  // member: distance_to_heel
  {
    out << "distance_to_heel: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_heel, out);
    out << ", ";
  }

  // member: distance_to_toe
  {
    out << "distance_to_toe: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_toe, out);
    out << ", ";
  }

  // member: depth_pelvis
  {
    out << "depth_pelvis: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_pelvis, out);
    out << ", ";
  }

  // member: width_pelvis
  {
    out << "width_pelvis: ";
    rosidl_generator_traits::value_to_yaml(msg.width_pelvis, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Measurements & msg,
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

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: femur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "femur: ";
    rosidl_generator_traits::value_to_yaml(msg.femur, out);
    out << "\n";
  }

  // member: tibia
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tibia: ";
    rosidl_generator_traits::value_to_yaml(msg.tibia, out);
    out << "\n";
  }

  // member: height_ankle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height_ankle: ";
    rosidl_generator_traits::value_to_yaml(msg.height_ankle, out);
    out << "\n";
  }

  // member: distance_to_heel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_to_heel: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_heel, out);
    out << "\n";
  }

  // member: distance_to_toe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_to_toe: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_toe, out);
    out << "\n";
  }

  // member: depth_pelvis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_pelvis: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_pelvis, out);
    out << "\n";
  }

  // member: width_pelvis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width_pelvis: ";
    rosidl_generator_traits::value_to_yaml(msg.width_pelvis, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Measurements & msg, bool use_flow_style = false)
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
  const nimble_interfaces::msg::Measurements & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::msg::Measurements & msg)
{
  return nimble_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::msg::Measurements>()
{
  return "nimble_interfaces::msg::Measurements";
}

template<>
inline const char * name<nimble_interfaces::msg::Measurements>()
{
  return "nimble_interfaces/msg/Measurements";
}

template<>
struct has_fixed_size<nimble_interfaces::msg::Measurements>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::msg::Measurements>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<nimble_interfaces::msg::Measurements>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__TRAITS_HPP_
