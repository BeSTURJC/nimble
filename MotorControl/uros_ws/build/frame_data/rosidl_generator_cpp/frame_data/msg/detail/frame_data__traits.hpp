// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice

#ifndef FRAME_DATA__MSG__DETAIL__FRAME_DATA__TRAITS_HPP_
#define FRAME_DATA__MSG__DETAIL__FRAME_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "frame_data/msg/detail/frame_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace frame_data
{

namespace msg
{

inline void to_flow_style_yaml(
  const FrameData & msg,
  std::ostream & out)
{
  out << "{";
  // member: contador
  {
    out << "contador: ";
    rosidl_generator_traits::value_to_yaml(msg.contador, out);
    out << ", ";
  }

  // member: frame_position
  {
    out << "frame_position: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_position, out);
    out << ", ";
  }

  // member: frame_speed
  {
    out << "frame_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_speed, out);
    out << ", ";
  }

  // member: sensor_dist
  {
    out << "sensor_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_dist, out);
    out << ", ";
  }

  // member: position_ref
  {
    out << "position_ref: ";
    rosidl_generator_traits::value_to_yaml(msg.position_ref, out);
    out << ", ";
  }

  // member: speed_ref
  {
    out << "speed_ref: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_ref, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FrameData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: contador
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "contador: ";
    rosidl_generator_traits::value_to_yaml(msg.contador, out);
    out << "\n";
  }

  // member: frame_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_position: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_position, out);
    out << "\n";
  }

  // member: frame_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_speed, out);
    out << "\n";
  }

  // member: sensor_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor_dist: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor_dist, out);
    out << "\n";
  }

  // member: position_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_ref: ";
    rosidl_generator_traits::value_to_yaml(msg.position_ref, out);
    out << "\n";
  }

  // member: speed_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_ref: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_ref, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FrameData & msg, bool use_flow_style = false)
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

}  // namespace frame_data

namespace rosidl_generator_traits
{

[[deprecated("use frame_data::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const frame_data::msg::FrameData & msg,
  std::ostream & out, size_t indentation = 0)
{
  frame_data::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use frame_data::msg::to_yaml() instead")]]
inline std::string to_yaml(const frame_data::msg::FrameData & msg)
{
  return frame_data::msg::to_yaml(msg);
}

template<>
inline const char * data_type<frame_data::msg::FrameData>()
{
  return "frame_data::msg::FrameData";
}

template<>
inline const char * name<frame_data::msg::FrameData>()
{
  return "frame_data/msg/FrameData";
}

template<>
struct has_fixed_size<frame_data::msg::FrameData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<frame_data::msg::FrameData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<frame_data::msg::FrameData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FRAME_DATA__MSG__DETAIL__FRAME_DATA__TRAITS_HPP_
