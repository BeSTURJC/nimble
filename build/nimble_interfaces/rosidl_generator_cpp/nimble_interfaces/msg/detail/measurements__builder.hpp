// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:msg/Measurements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__BUILDER_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/msg/detail/measurements__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace msg
{

namespace builder
{

class Init_Measurements_width_pelvis
{
public:
  explicit Init_Measurements_width_pelvis(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::msg::Measurements width_pelvis(::nimble_interfaces::msg::Measurements::_width_pelvis_type arg)
  {
    msg_.width_pelvis = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_depth_pelvis
{
public:
  explicit Init_Measurements_depth_pelvis(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_width_pelvis depth_pelvis(::nimble_interfaces::msg::Measurements::_depth_pelvis_type arg)
  {
    msg_.depth_pelvis = std::move(arg);
    return Init_Measurements_width_pelvis(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_distance_to_toe
{
public:
  explicit Init_Measurements_distance_to_toe(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_depth_pelvis distance_to_toe(::nimble_interfaces::msg::Measurements::_distance_to_toe_type arg)
  {
    msg_.distance_to_toe = std::move(arg);
    return Init_Measurements_depth_pelvis(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_distance_to_heel
{
public:
  explicit Init_Measurements_distance_to_heel(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_distance_to_toe distance_to_heel(::nimble_interfaces::msg::Measurements::_distance_to_heel_type arg)
  {
    msg_.distance_to_heel = std::move(arg);
    return Init_Measurements_distance_to_toe(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_height_ankle
{
public:
  explicit Init_Measurements_height_ankle(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_distance_to_heel height_ankle(::nimble_interfaces::msg::Measurements::_height_ankle_type arg)
  {
    msg_.height_ankle = std::move(arg);
    return Init_Measurements_distance_to_heel(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_tibia
{
public:
  explicit Init_Measurements_tibia(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_height_ankle tibia(::nimble_interfaces::msg::Measurements::_tibia_type arg)
  {
    msg_.tibia = std::move(arg);
    return Init_Measurements_height_ankle(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_femur
{
public:
  explicit Init_Measurements_femur(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_tibia femur(::nimble_interfaces::msg::Measurements::_femur_type arg)
  {
    msg_.femur = std::move(arg);
    return Init_Measurements_tibia(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_height
{
public:
  explicit Init_Measurements_height(::nimble_interfaces::msg::Measurements & msg)
  : msg_(msg)
  {}
  Init_Measurements_femur height(::nimble_interfaces::msg::Measurements::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Measurements_femur(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

class Init_Measurements_header
{
public:
  Init_Measurements_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Measurements_height header(::nimble_interfaces::msg::Measurements::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Measurements_height(msg_);
  }

private:
  ::nimble_interfaces::msg::Measurements msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::msg::Measurements>()
{
  return nimble_interfaces::msg::builder::Init_Measurements_header();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__BUILDER_HPP_
