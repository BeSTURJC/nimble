// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice

#ifndef FRAME_DATA__MSG__DETAIL__FRAME_DATA__BUILDER_HPP_
#define FRAME_DATA__MSG__DETAIL__FRAME_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "frame_data/msg/detail/frame_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace frame_data
{

namespace msg
{

namespace builder
{

class Init_FrameData_speed_ref
{
public:
  explicit Init_FrameData_speed_ref(::frame_data::msg::FrameData & msg)
  : msg_(msg)
  {}
  ::frame_data::msg::FrameData speed_ref(::frame_data::msg::FrameData::_speed_ref_type arg)
  {
    msg_.speed_ref = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frame_data::msg::FrameData msg_;
};

class Init_FrameData_position_ref
{
public:
  explicit Init_FrameData_position_ref(::frame_data::msg::FrameData & msg)
  : msg_(msg)
  {}
  Init_FrameData_speed_ref position_ref(::frame_data::msg::FrameData::_position_ref_type arg)
  {
    msg_.position_ref = std::move(arg);
    return Init_FrameData_speed_ref(msg_);
  }

private:
  ::frame_data::msg::FrameData msg_;
};

class Init_FrameData_sensor_dist
{
public:
  explicit Init_FrameData_sensor_dist(::frame_data::msg::FrameData & msg)
  : msg_(msg)
  {}
  Init_FrameData_position_ref sensor_dist(::frame_data::msg::FrameData::_sensor_dist_type arg)
  {
    msg_.sensor_dist = std::move(arg);
    return Init_FrameData_position_ref(msg_);
  }

private:
  ::frame_data::msg::FrameData msg_;
};

class Init_FrameData_frame_speed
{
public:
  explicit Init_FrameData_frame_speed(::frame_data::msg::FrameData & msg)
  : msg_(msg)
  {}
  Init_FrameData_sensor_dist frame_speed(::frame_data::msg::FrameData::_frame_speed_type arg)
  {
    msg_.frame_speed = std::move(arg);
    return Init_FrameData_sensor_dist(msg_);
  }

private:
  ::frame_data::msg::FrameData msg_;
};

class Init_FrameData_frame_position
{
public:
  explicit Init_FrameData_frame_position(::frame_data::msg::FrameData & msg)
  : msg_(msg)
  {}
  Init_FrameData_frame_speed frame_position(::frame_data::msg::FrameData::_frame_position_type arg)
  {
    msg_.frame_position = std::move(arg);
    return Init_FrameData_frame_speed(msg_);
  }

private:
  ::frame_data::msg::FrameData msg_;
};

class Init_FrameData_contador
{
public:
  Init_FrameData_contador()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrameData_frame_position contador(::frame_data::msg::FrameData::_contador_type arg)
  {
    msg_.contador = std::move(arg);
    return Init_FrameData_frame_position(msg_);
  }

private:
  ::frame_data::msg::FrameData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::frame_data::msg::FrameData>()
{
  return frame_data::msg::builder::Init_FrameData_contador();
}

}  // namespace frame_data

#endif  // FRAME_DATA__MSG__DETAIL__FRAME_DATA__BUILDER_HPP_
