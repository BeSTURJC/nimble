// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:msg/FrameState.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__BUILDER_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/msg/detail/frame_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace msg
{

namespace builder
{

class Init_FrameState_position
{
public:
  explicit Init_FrameState_position(::nimble_interfaces::msg::FrameState & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::msg::FrameState position(::nimble_interfaces::msg::FrameState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::msg::FrameState msg_;
};

class Init_FrameState_velocity
{
public:
  explicit Init_FrameState_velocity(::nimble_interfaces::msg::FrameState & msg)
  : msg_(msg)
  {}
  Init_FrameState_position velocity(::nimble_interfaces::msg::FrameState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_FrameState_position(msg_);
  }

private:
  ::nimble_interfaces::msg::FrameState msg_;
};

class Init_FrameState_optic_sensor
{
public:
  explicit Init_FrameState_optic_sensor(::nimble_interfaces::msg::FrameState & msg)
  : msg_(msg)
  {}
  Init_FrameState_velocity optic_sensor(::nimble_interfaces::msg::FrameState::_optic_sensor_type arg)
  {
    msg_.optic_sensor = std::move(arg);
    return Init_FrameState_velocity(msg_);
  }

private:
  ::nimble_interfaces::msg::FrameState msg_;
};

class Init_FrameState_header
{
public:
  Init_FrameState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrameState_optic_sensor header(::nimble_interfaces::msg::FrameState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FrameState_optic_sensor(msg_);
  }

private:
  ::nimble_interfaces::msg::FrameState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::msg::FrameState>()
{
  return nimble_interfaces::msg::builder::Init_FrameState_header();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__BUILDER_HPP_
