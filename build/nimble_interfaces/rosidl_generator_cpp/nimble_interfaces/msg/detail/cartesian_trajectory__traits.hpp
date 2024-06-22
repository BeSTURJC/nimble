// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__TRAITS_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/msg/detail/cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'malleolus'
// Member 'pelvis'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace nimble_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CartesianTrajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: malleolus
  {
    if (msg.malleolus.size() == 0) {
      out << "malleolus: []";
    } else {
      out << "malleolus: [";
      size_t pending_items = msg.malleolus.size();
      for (auto item : msg.malleolus) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pelvis
  {
    if (msg.pelvis.size() == 0) {
      out << "pelvis: []";
    } else {
      out << "pelvis: [";
      size_t pending_items = msg.pelvis.size();
      for (auto item : msg.pelvis) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CartesianTrajectory & msg,
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

  // member: malleolus
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.malleolus.size() == 0) {
      out << "malleolus: []\n";
    } else {
      out << "malleolus:\n";
      for (auto item : msg.malleolus) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: pelvis
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pelvis.size() == 0) {
      out << "pelvis: []\n";
    } else {
      out << "pelvis:\n";
      for (auto item : msg.pelvis) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CartesianTrajectory & msg, bool use_flow_style = false)
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
  const nimble_interfaces::msg::CartesianTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::msg::CartesianTrajectory & msg)
{
  return nimble_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::msg::CartesianTrajectory>()
{
  return "nimble_interfaces::msg::CartesianTrajectory";
}

template<>
inline const char * name<nimble_interfaces::msg::CartesianTrajectory>()
{
  return "nimble_interfaces/msg/CartesianTrajectory";
}

template<>
struct has_fixed_size<nimble_interfaces::msg::CartesianTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nimble_interfaces::msg::CartesianTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nimble_interfaces::msg::CartesianTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__TRAITS_HPP_
