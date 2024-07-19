// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__BUILDER_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/msg/detail/joints_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace msg
{

namespace builder
{

class Init_JointsTrajectory_new_indicator
{
public:
  explicit Init_JointsTrajectory_new_indicator(::nimble_interfaces::msg::JointsTrajectory & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::msg::JointsTrajectory new_indicator(::nimble_interfaces::msg::JointsTrajectory::_new_indicator_type arg)
  {
    msg_.new_indicator = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::msg::JointsTrajectory msg_;
};

class Init_JointsTrajectory_trajectory
{
public:
  explicit Init_JointsTrajectory_trajectory(::nimble_interfaces::msg::JointsTrajectory & msg)
  : msg_(msg)
  {}
  Init_JointsTrajectory_new_indicator trajectory(::nimble_interfaces::msg::JointsTrajectory::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_JointsTrajectory_new_indicator(msg_);
  }

private:
  ::nimble_interfaces::msg::JointsTrajectory msg_;
};

class Init_JointsTrajectory_phase
{
public:
  explicit Init_JointsTrajectory_phase(::nimble_interfaces::msg::JointsTrajectory & msg)
  : msg_(msg)
  {}
  Init_JointsTrajectory_trajectory phase(::nimble_interfaces::msg::JointsTrajectory::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_JointsTrajectory_trajectory(msg_);
  }

private:
  ::nimble_interfaces::msg::JointsTrajectory msg_;
};

class Init_JointsTrajectory_header
{
public:
  Init_JointsTrajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointsTrajectory_phase header(::nimble_interfaces::msg::JointsTrajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_JointsTrajectory_phase(msg_);
  }

private:
  ::nimble_interfaces::msg::JointsTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::msg::JointsTrajectory>()
{
  return nimble_interfaces::msg::builder::Init_JointsTrajectory_header();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__BUILDER_HPP_
