// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__TRAITS_HPP_
#define NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'joints_trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__traits.hpp"
// Member 'measurements'
#include "nimble_interfaces/msg/detail/measurements__traits.hpp"

namespace nimble_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CartesianTrajService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: joints_trajectory
  {
    out << "joints_trajectory: ";
    to_flow_style_yaml(msg.joints_trajectory, out);
    out << ", ";
  }

  // member: measurements
  {
    out << "measurements: ";
    to_flow_style_yaml(msg.measurements, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CartesianTrajService_Request & msg,
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

  // member: measurements
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "measurements:\n";
    to_block_style_yaml(msg.measurements, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CartesianTrajService_Request & msg, bool use_flow_style = false)
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
  const nimble_interfaces::srv::CartesianTrajService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::srv::CartesianTrajService_Request & msg)
{
  return nimble_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::srv::CartesianTrajService_Request>()
{
  return "nimble_interfaces::srv::CartesianTrajService_Request";
}

template<>
inline const char * name<nimble_interfaces::srv::CartesianTrajService_Request>()
{
  return "nimble_interfaces/srv/CartesianTrajService_Request";
}

template<>
struct has_fixed_size<nimble_interfaces::srv::CartesianTrajService_Request>
  : std::integral_constant<bool, has_fixed_size<nimble_interfaces::msg::Measurements>::value && has_fixed_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::srv::CartesianTrajService_Request>
  : std::integral_constant<bool, has_bounded_size<nimble_interfaces::msg::Measurements>::value && has_bounded_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct is_message<nimble_interfaces::srv::CartesianTrajService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'cartesian_trajectory'
#include "nimble_interfaces/msg/detail/cartesian_trajectory__traits.hpp"
// Member 'step_target'
#include "nimble_interfaces/msg/detail/therapy_requirements__traits.hpp"

namespace nimble_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CartesianTrajService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: cartesian_trajectory
  {
    out << "cartesian_trajectory: ";
    to_flow_style_yaml(msg.cartesian_trajectory, out);
    out << ", ";
  }

  // member: step_target
  {
    out << "step_target: ";
    to_flow_style_yaml(msg.step_target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CartesianTrajService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cartesian_trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cartesian_trajectory:\n";
    to_block_style_yaml(msg.cartesian_trajectory, out, indentation + 2);
  }

  // member: step_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_target:\n";
    to_block_style_yaml(msg.step_target, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CartesianTrajService_Response & msg, bool use_flow_style = false)
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
  const nimble_interfaces::srv::CartesianTrajService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  nimble_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nimble_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const nimble_interfaces::srv::CartesianTrajService_Response & msg)
{
  return nimble_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<nimble_interfaces::srv::CartesianTrajService_Response>()
{
  return "nimble_interfaces::srv::CartesianTrajService_Response";
}

template<>
inline const char * name<nimble_interfaces::srv::CartesianTrajService_Response>()
{
  return "nimble_interfaces/srv/CartesianTrajService_Response";
}

template<>
struct has_fixed_size<nimble_interfaces::srv::CartesianTrajService_Response>
  : std::integral_constant<bool, has_fixed_size<nimble_interfaces::msg::CartesianTrajectory>::value && has_fixed_size<nimble_interfaces::msg::TherapyRequirements>::value> {};

template<>
struct has_bounded_size<nimble_interfaces::srv::CartesianTrajService_Response>
  : std::integral_constant<bool, has_bounded_size<nimble_interfaces::msg::CartesianTrajectory>::value && has_bounded_size<nimble_interfaces::msg::TherapyRequirements>::value> {};

template<>
struct is_message<nimble_interfaces::srv::CartesianTrajService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nimble_interfaces::srv::CartesianTrajService>()
{
  return "nimble_interfaces::srv::CartesianTrajService";
}

template<>
inline const char * name<nimble_interfaces::srv::CartesianTrajService>()
{
  return "nimble_interfaces/srv/CartesianTrajService";
}

template<>
struct has_fixed_size<nimble_interfaces::srv::CartesianTrajService>
  : std::integral_constant<
    bool,
    has_fixed_size<nimble_interfaces::srv::CartesianTrajService_Request>::value &&
    has_fixed_size<nimble_interfaces::srv::CartesianTrajService_Response>::value
  >
{
};

template<>
struct has_bounded_size<nimble_interfaces::srv::CartesianTrajService>
  : std::integral_constant<
    bool,
    has_bounded_size<nimble_interfaces::srv::CartesianTrajService_Request>::value &&
    has_bounded_size<nimble_interfaces::srv::CartesianTrajService_Response>::value
  >
{
};

template<>
struct is_service<nimble_interfaces::srv::CartesianTrajService>
  : std::true_type
{
};

template<>
struct is_service_request<nimble_interfaces::srv::CartesianTrajService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<nimble_interfaces::srv::CartesianTrajService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__TRAITS_HPP_
