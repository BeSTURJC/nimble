// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__BUILDER_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nimble_interfaces/msg/detail/cartesian_full_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nimble_interfaces
{

namespace msg
{

namespace builder
{

class Init_CartesianFullTrajectory_right_toe
{
public:
  explicit Init_CartesianFullTrajectory_right_toe(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  ::nimble_interfaces::msg::CartesianFullTrajectory right_toe(::nimble_interfaces::msg::CartesianFullTrajectory::_right_toe_type arg)
  {
    msg_.right_toe = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_left_toe
{
public:
  explicit Init_CartesianFullTrajectory_left_toe(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_right_toe left_toe(::nimble_interfaces::msg::CartesianFullTrajectory::_left_toe_type arg)
  {
    msg_.left_toe = std::move(arg);
    return Init_CartesianFullTrajectory_right_toe(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_right_heel
{
public:
  explicit Init_CartesianFullTrajectory_right_heel(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_left_toe right_heel(::nimble_interfaces::msg::CartesianFullTrajectory::_right_heel_type arg)
  {
    msg_.right_heel = std::move(arg);
    return Init_CartesianFullTrajectory_left_toe(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_left_heel
{
public:
  explicit Init_CartesianFullTrajectory_left_heel(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_right_heel left_heel(::nimble_interfaces::msg::CartesianFullTrajectory::_left_heel_type arg)
  {
    msg_.left_heel = std::move(arg);
    return Init_CartesianFullTrajectory_right_heel(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_right_ankle
{
public:
  explicit Init_CartesianFullTrajectory_right_ankle(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_left_heel right_ankle(::nimble_interfaces::msg::CartesianFullTrajectory::_right_ankle_type arg)
  {
    msg_.right_ankle = std::move(arg);
    return Init_CartesianFullTrajectory_left_heel(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_left_ankle
{
public:
  explicit Init_CartesianFullTrajectory_left_ankle(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_right_ankle left_ankle(::nimble_interfaces::msg::CartesianFullTrajectory::_left_ankle_type arg)
  {
    msg_.left_ankle = std::move(arg);
    return Init_CartesianFullTrajectory_right_ankle(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_right_knee
{
public:
  explicit Init_CartesianFullTrajectory_right_knee(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_left_ankle right_knee(::nimble_interfaces::msg::CartesianFullTrajectory::_right_knee_type arg)
  {
    msg_.right_knee = std::move(arg);
    return Init_CartesianFullTrajectory_left_ankle(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_left_knee
{
public:
  explicit Init_CartesianFullTrajectory_left_knee(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_right_knee left_knee(::nimble_interfaces::msg::CartesianFullTrajectory::_left_knee_type arg)
  {
    msg_.left_knee = std::move(arg);
    return Init_CartesianFullTrajectory_right_knee(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_right_hip
{
public:
  explicit Init_CartesianFullTrajectory_right_hip(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_left_knee right_hip(::nimble_interfaces::msg::CartesianFullTrajectory::_right_hip_type arg)
  {
    msg_.right_hip = std::move(arg);
    return Init_CartesianFullTrajectory_left_knee(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_left_hip
{
public:
  explicit Init_CartesianFullTrajectory_left_hip(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_right_hip left_hip(::nimble_interfaces::msg::CartesianFullTrajectory::_left_hip_type arg)
  {
    msg_.left_hip = std::move(arg);
    return Init_CartesianFullTrajectory_right_hip(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_base_pelvis
{
public:
  explicit Init_CartesianFullTrajectory_base_pelvis(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_left_hip base_pelvis(::nimble_interfaces::msg::CartesianFullTrajectory::_base_pelvis_type arg)
  {
    msg_.base_pelvis = std::move(arg);
    return Init_CartesianFullTrajectory_left_hip(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_right_pelvis
{
public:
  explicit Init_CartesianFullTrajectory_right_pelvis(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_base_pelvis right_pelvis(::nimble_interfaces::msg::CartesianFullTrajectory::_right_pelvis_type arg)
  {
    msg_.right_pelvis = std::move(arg);
    return Init_CartesianFullTrajectory_base_pelvis(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_left_pelvis
{
public:
  explicit Init_CartesianFullTrajectory_left_pelvis(::nimble_interfaces::msg::CartesianFullTrajectory & msg)
  : msg_(msg)
  {}
  Init_CartesianFullTrajectory_right_pelvis left_pelvis(::nimble_interfaces::msg::CartesianFullTrajectory::_left_pelvis_type arg)
  {
    msg_.left_pelvis = std::move(arg);
    return Init_CartesianFullTrajectory_right_pelvis(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

class Init_CartesianFullTrajectory_header
{
public:
  Init_CartesianFullTrajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianFullTrajectory_left_pelvis header(::nimble_interfaces::msg::CartesianFullTrajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CartesianFullTrajectory_left_pelvis(msg_);
  }

private:
  ::nimble_interfaces::msg::CartesianFullTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nimble_interfaces::msg::CartesianFullTrajectory>()
{
  return nimble_interfaces::msg::builder::Init_CartesianFullTrajectory_header();
}

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__BUILDER_HPP_
