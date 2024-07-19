// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__STRUCT_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__STRUCT_HPP_

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
// Member 'phase'
#include "std_msgs/msg/detail/float32_multi_array__struct.hpp"
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__msg__JointsTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__msg__JointsTrajectory __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointsTrajectory_
{
  using Type = JointsTrajectory_<ContainerAllocator>;

  explicit JointsTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    phase(_init),
    trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_indicator = false;
    }
  }

  explicit JointsTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    phase(_alloc, _init),
    trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_indicator = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _phase_type =
    std_msgs::msg::Float32MultiArray_<ContainerAllocator>;
  _phase_type phase;
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _new_indicator_type =
    bool;
  _new_indicator_type new_indicator;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__phase(
    const std_msgs::msg::Float32MultiArray_<ContainerAllocator> & _arg)
  {
    this->phase = _arg;
    return *this;
  }
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__new_indicator(
    const bool & _arg)
  {
    this->new_indicator = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__msg__JointsTrajectory
    std::shared_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__msg__JointsTrajectory
    std::shared_ptr<nimble_interfaces::msg::JointsTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointsTrajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->phase != other.phase) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->new_indicator != other.new_indicator) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointsTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointsTrajectory_

// alias to use template instance with default allocator
using JointsTrajectory =
  nimble_interfaces::msg::JointsTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__STRUCT_HPP_
