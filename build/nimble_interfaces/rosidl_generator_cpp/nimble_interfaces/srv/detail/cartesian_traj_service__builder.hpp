// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__BUILDER_HPP_
#define NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace srv
{

namespace builder
{

class Init_CartesianTrajService_Request_measurements
{
public:
  explicit Init_CartesianTrajService_Request_measurements(::nimble_interfaces::srv::CartesianTrajService_Request & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::srv::CartesianTrajService_Request measurements(::nimble_interfaces::srv::CartesianTrajService_Request::_measurements_type arg)
  {
    msg_.measurements = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::srv::CartesianTrajService_Request msg_;
};

class Init_CartesianTrajService_Request_joints_trajectory
{
public:
  Init_CartesianTrajService_Request_joints_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianTrajService_Request_measurements joints_trajectory(::nimble_interfaces::srv::CartesianTrajService_Request::_joints_trajectory_type arg)
  {
    msg_.joints_trajectory = std::move(arg);
    return Init_CartesianTrajService_Request_measurements(msg_);
  }

private:
  ::nimble_interfaces::srv::CartesianTrajService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::srv::CartesianTrajService_Request>()
{
  return nimble_interfaces::srv::builder::Init_CartesianTrajService_Request_joints_trajectory();
}

}  // namespace nimble_interfaces


namespace nimble_interfaces
{

namespace srv
{

namespace builder
{

class Init_CartesianTrajService_Response_step_target
{
public:
  explicit Init_CartesianTrajService_Response_step_target(::nimble_interfaces::srv::CartesianTrajService_Response & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::srv::CartesianTrajService_Response step_target(::nimble_interfaces::srv::CartesianTrajService_Response::_step_target_type arg)
  {
    msg_.step_target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::srv::CartesianTrajService_Response msg_;
};

class Init_CartesianTrajService_Response_cartesian_trajectory
{
public:
  Init_CartesianTrajService_Response_cartesian_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianTrajService_Response_step_target cartesian_trajectory(::nimble_interfaces::srv::CartesianTrajService_Response::_cartesian_trajectory_type arg)
  {
    msg_.cartesian_trajectory = std::move(arg);
    return Init_CartesianTrajService_Response_step_target(msg_);
  }

private:
  ::nimble_interfaces::srv::CartesianTrajService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::srv::CartesianTrajService_Response>()
{
  return nimble_interfaces::srv::builder::Init_CartesianTrajService_Response_cartesian_trajectory();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__BUILDER_HPP_
