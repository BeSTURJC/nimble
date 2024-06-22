// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__TRAITS_HPP_
#define NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/srv/detail/traj_generator_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'measurements'
#include "nimble_interfaces/msg/detail/measurements__traits.hpp"
// Member 'therapy_requirements'
#include "nimble_interfaces/msg/detail/therapy_requirements__traits.hpp"

namespace nimble_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TrajGeneratorService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: measurements
  {
    out << "measurements: ";
    to_flow_style_yaml(msg.measurements, out);
    out << ", ";
  }

  // member: therapy_requirements
  {
    out << "therapy_requirements: ";
    to_flow_style_yaml(msg.therapy_requirements, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajGeneratorService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: measurements
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "measurements:\n";
    to_block_style_yaml(msg.measurements, out, indentation + 2);
  }

  // member: therapy_requirements
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "therapy_requirements:\n";
    to_block_style_yaml(msg.therapy_requirements, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajGeneratorService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nimble_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nimble_interfaces::srv::TrajGeneratorService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::srv::TrajGeneratorService_Request & msg)
{
  return nimble_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::srv::TrajGeneratorService_Request>()
{
  return "nimble_interfaces::srv::TrajGeneratorService_Request";
}

template<>
inline const char * name<nimble_interfaces::srv::TrajGeneratorService_Request>()
{
  return "nimble_interfaces/srv/TrajGeneratorService_Request";
}

template<>
struct has_fixed_size<nimble_interfaces::srv::TrajGeneratorService_Request>
  : std::integral_constant<bool, has_fixed_size<nimble_interfaces::msg::Measurements>::value && has_fixed_size<nimble_interfaces::msg::TherapyRequirements>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::srv::TrajGeneratorService_Request>
  : std::integral_constant<bool, has_bounded_size<nimble_interfaces::msg::Measurements>::value && has_bounded_size<nimble_interfaces::msg::TherapyRequirements>::value> {};

template<>
struct is_message<nimble_interfaces::srv::TrajGeneratorService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'joints_trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__traits.hpp"

namespace nimble_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TrajGeneratorService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: joints_trajectory
  {
    out << "joints_trajectory: ";
    to_flow_style_yaml(msg.joints_trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajGeneratorService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joints_trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joints_trajectory:\n";
    to_block_style_yaml(msg.joints_trajectory, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajGeneratorService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace nimble_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nimble_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nimble_interfaces::srv::TrajGeneratorService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::srv::TrajGeneratorService_Response & msg)
{
  return nimble_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::srv::TrajGeneratorService_Response>()
{
  return "nimble_interfaces::srv::TrajGeneratorService_Response";
}

template<>
inline const char * name<nimble_interfaces::srv::TrajGeneratorService_Response>()
{
  return "nimble_interfaces/srv/TrajGeneratorService_Response";
}

template<>
struct has_fixed_size<nimble_interfaces::srv::TrajGeneratorService_Response>
  : std::integral_constant<bool, has_fixed_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::srv::TrajGeneratorService_Response>
  : std::integral_constant<bool, has_bounded_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct is_message<nimble_interfaces::srv::TrajGeneratorService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nimble_interfaces::srv::TrajGeneratorService>()
{
  return "nimble_interfaces::srv::TrajGeneratorService";
}

template<>
inline const char * name<nimble_interfaces::srv::TrajGeneratorService>()
{
  return "nimble_interfaces/srv/TrajGeneratorService";
}

template<>
struct has_fixed_size<nimble_interfaces::srv::TrajGeneratorService>
  : std::integral_constant<
    bool,
    has_fixed_size<nimble_interfaces::srv::TrajGeneratorService_Request>::value &&
    has_fixed_size<nimble_interfaces::srv::TrajGeneratorService_Response>::value
  >
{
};

template<>
struct has_bounded_size<nimble_interfaces::srv::TrajGeneratorService>
  : std::integral_constant<
    bool,
    has_bounded_size<nimble_interfaces::srv::TrajGeneratorService_Request>::value &&
    has_bounded_size<nimble_interfaces::srv::TrajGeneratorService_Response>::value
  >
{
};

template<>
struct is_service<nimble_interfaces::srv::TrajGeneratorService>
  : std::true_type
{
};

template<>
struct is_service_request<nimble_interfaces::srv::TrajGeneratorService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nimble_interfaces::srv::TrajGeneratorService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__TRAITS_HPP_
