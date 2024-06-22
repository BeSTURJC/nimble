// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:msg/TherapyRequirements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__BUILDER_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/msg/detail/therapy_requirements__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace msg
{

namespace builder
{

class Init_TherapyRequirements_max_assist_level
{
public:
  explicit Init_TherapyRequirements_max_assist_level(::nimble_interfaces::msg::TherapyRequirements & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::msg::TherapyRequirements max_assist_level(::nimble_interfaces::msg::TherapyRequirements::_max_assist_level_type arg)
  {
    msg_.max_assist_level = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::msg::TherapyRequirements msg_;
};

class Init_TherapyRequirements_min_assist_level
{
public:
  explicit Init_TherapyRequirements_min_assist_level(::nimble_interfaces::msg::TherapyRequirements & msg)
  : msg_(msg)
  {}
  Init_TherapyRequirements_max_assist_level min_assist_level(::nimble_interfaces::msg::TherapyRequirements::_min_assist_level_type arg)
  {
    msg_.min_assist_level = std::move(arg);
    return Init_TherapyRequirements_max_assist_level(msg_);
  }

private:
  ::nimble_interfaces::msg::TherapyRequirements msg_;
};

class Init_TherapyRequirements_step_height
{
public:
  explicit Init_TherapyRequirements_step_height(::nimble_interfaces::msg::TherapyRequirements & msg)
  : msg_(msg)
  {}
  Init_TherapyRequirements_min_assist_level step_height(::nimble_interfaces::msg::TherapyRequirements::_step_height_type arg)
  {
    msg_.step_height = std::move(arg);
    return Init_TherapyRequirements_min_assist_level(msg_);
  }

private:
  ::nimble_interfaces::msg::TherapyRequirements msg_;
};

class Init_TherapyRequirements_step_length
{
public:
  explicit Init_TherapyRequirements_step_length(::nimble_interfaces::msg::TherapyRequirements & msg)
  : msg_(msg)
  {}
  Init_TherapyRequirements_step_height step_length(::nimble_interfaces::msg::TherapyRequirements::_step_length_type arg)
  {
    msg_.step_length = std::move(arg);
    return Init_TherapyRequirements_step_height(msg_);
  }

private:
  ::nimble_interfaces::msg::TherapyRequirements msg_;
};

class Init_TherapyRequirements_speed
{
public:
  explicit Init_TherapyRequirements_speed(::nimble_interfaces::msg::TherapyRequirements & msg)
  : msg_(msg)
  {}
  Init_TherapyRequirements_step_length speed(::nimble_interfaces::msg::TherapyRequirements::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_TherapyRequirements_step_length(msg_);
  }

private:
  ::nimble_interfaces::msg::TherapyRequirements msg_;
};

class Init_TherapyRequirements_header
{
public:
  Init_TherapyRequirements_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TherapyRequirements_speed header(::nimble_interfaces::msg::TherapyRequirements::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TherapyRequirements_speed(msg_);
  }

private:
  ::nimble_interfaces::msg::TherapyRequirements msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::msg::TherapyRequirements>()
{
  return nimble_interfaces::msg::builder::Init_TherapyRequirements_header();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__BUILDER_HPP_
