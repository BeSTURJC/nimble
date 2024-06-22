// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__BUILDER_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/msg/detail/cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace msg
{

namespace builder
{

class Init_CartesianTrajectory_pelvis
{
public:
  explicit Init_CartesianTrajectory_pelvis(::nimble_interfaces::msg::CartesianTrajectory & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::msg::CartesianTrajectory pelvis(::nimble_interfaces::msg::CartesianTrajectory::_pelvis_type arg)
  {
    msg_.pelvis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianTrajectory msg_;
};

class Init_CartesianTrajectory_malleolus
{
public:
  explicit Init_CartesianTrajectory_malleolus(::nimble_interfaces::msg::CartesianTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianTrajectory_pelvis malleolus(::nimble_interfaces::msg::CartesianTrajectory::_malleolus_type arg)
  {
    msg_.malleolus = std::move(arg);
    return Init_CartesianTrajectory_pelvis(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianTrajectory msg_;
};

class Init_CartesianTrajectory_header
{
public:
  Init_CartesianTrajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianTrajectory_malleolus header(::nimble_interfaces::msg::CartesianTrajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CartesianTrajectory_malleolus(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::msg::CartesianTrajectory>()
{
  return nimble_interfaces::msg::builder::Init_CartesianTrajectory_header();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__BUILDER_HPP_
