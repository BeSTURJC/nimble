// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__BUILDER_HPP_
#define NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/srv/detail/traj_generator_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace srv
{

namespace builder
{

class Init_TrajGeneratorService_Request_therapy_requirements
{
public:
  explicit Init_TrajGeneratorService_Request_therapy_requirements(::nimble_interfaces::srv::TrajGeneratorService_Request & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::srv::TrajGeneratorService_Request therapy_requirements(::nimble_interfaces::srv::TrajGeneratorService_Request::_therapy_requirements_type arg)
  {
    msg_.therapy_requirements = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::srv::TrajGeneratorService_Request msg_;
};

class Init_TrajGeneratorService_Request_measurements
{
public:
  Init_TrajGeneratorService_Request_measurements()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajGeneratorService_Request_therapy_requirements measurements(::nimble_interfaces::srv::TrajGeneratorService_Request::_measurements_type arg)
  {
    msg_.measurements = std::move(arg);
    return Init_TrajGeneratorService_Request_therapy_requirements(msg_);
  }

private:
  ::nimble_interfaces::srv::TrajGeneratorService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::srv::TrajGeneratorService_Request>()
{
  return nimble_interfaces::srv::builder::Init_TrajGeneratorService_Request_measurements();
}

}  // namespace nimble_interfaces


namespace nimble_interfaces
{

namespace srv
{

namespace builder
{

class Init_TrajGeneratorService_Response_joints_trajectory
{
public:
  Init_TrajGeneratorService_Response_joints_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::nimble_interfaces::srv::TrajGeneratorService_Response joints_trajectory(::nimble_interfaces::srv::TrajGeneratorService_Response::_joints_trajectory_type arg)
  {
    msg_.joints_trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::srv::TrajGeneratorService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::srv::TrajGeneratorService_Response>()
{
  return nimble_interfaces::srv::builder::Init_TrajGeneratorService_Response_joints_trajectory();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__BUILDER_HPP_
