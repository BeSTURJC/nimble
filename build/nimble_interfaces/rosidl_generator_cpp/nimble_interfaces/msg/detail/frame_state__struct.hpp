// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:msg/FrameState.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__STRUCT_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__msg__FrameState __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__msg__FrameState __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FrameState_
{
  using Type = FrameState_<ContainerAllocator>;

  explicit FrameState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->optic_sensor = 0.0;
      this->velocity = 0.0;
      this->position = 0.0;
    }
  }

  explicit FrameState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->optic_sensor = 0.0;
      this->velocity = 0.0;
      this->position = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _optic_sensor_type =
    double;
  _optic_sensor_type optic_sensor;
  using _velocity_type =
    double;
  _velocity_type velocity;
  using _position_type =
    double;
  _position_type position;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__optic_sensor(
    const double & _arg)
  {
    this->optic_sensor = _arg;
    return *this;
  }
  Type & set__velocity(
    const double & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__position(
    const double & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::msg::FrameState_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::msg::FrameState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::FrameState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::FrameState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__msg__FrameState
    std::shared_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__msg__FrameState
    std::shared_ptr<nimble_interfaces::msg::FrameState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->optic_sensor != other.optic_sensor) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameState_

// alias to use template instance with default allocator
using FrameState =
  nimble_interfaces::msg::FrameState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__STRUCT_HPP_
