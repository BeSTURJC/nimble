// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:msg/TherapyRequirements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__TRAITS_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/msg/detail/therapy_requirements__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nimble_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TherapyRequirements & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: step_length
  {
    out << "step_length: ";
    rosidl_generator_traits::value_to_yaml(msg.step_length, out);
    out << ", ";
  }

  // member: step_height
  {
    out << "step_height: ";
    rosidl_generator_traits::value_to_yaml(msg.step_height, out);
    out << ", ";
  }

  // member: min_assist_level
  {
    out << "min_assist_level: ";
    rosidl_generator_traits::value_to_yaml(msg.min_assist_level, out);
    out << ", ";
  }

  // member: max_assist_level
  {
    out << "max_assist_level: ";
    rosidl_generator_traits::value_to_yaml(msg.max_assist_level, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TherapyRequirements & msg,
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

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: step_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_length: ";
    rosidl_generator_traits::value_to_yaml(msg.step_length, out);
    out << "\n";
  }

  // member: step_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_height: ";
    rosidl_generator_traits::value_to_yaml(msg.step_height, out);
    out << "\n";
  }

  // member: min_assist_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_assist_level: ";
    rosidl_generator_traits::value_to_yaml(msg.min_assist_level, out);
    out << "\n";
  }

  // member: max_assist_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_assist_level: ";
    rosidl_generator_traits::value_to_yaml(msg.max_assist_level, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TherapyRequirements & msg, bool use_flow_style = false)
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
  const nimble_interfaces::msg::TherapyRequirements & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::msg::TherapyRequirements & msg)
{
  return nimble_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::msg::TherapyRequirements>()
{
  return "nimble_interfaces::msg::TherapyRequirements";
}

template<>
inline const char * name<nimble_interfaces::msg::TherapyRequirements>()
{
  return "nimble_interfaces/msg/TherapyRequirements";
}

template<>
struct has_fixed_size<nimble_interfaces::msg::TherapyRequirements>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::msg::TherapyRequirements>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<nimble_interfaces::msg::TherapyRequirements>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__TRAITS_HPP_
