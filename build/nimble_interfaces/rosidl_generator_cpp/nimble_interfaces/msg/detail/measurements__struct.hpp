// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:msg/Measurements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__STRUCT_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__STRUCT_HPP_

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
# define DEPRECATED__nimble_interfaces__msg__Measurements __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__msg__Measurements __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Measurements_
{
  using Type = Measurements_<ContainerAllocator>;

  explicit Measurements_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0.0;
      this->femur = 0.0;
      this->tibia = 0.0;
      this->height_ankle = 0.0;
      this->distance_to_heel = 0.0;
      this->distance_to_toe = 0.0;
      this->depth_pelvis = 0.0;
      this->width_pelvis = 0.0;
    }
  }

  explicit Measurements_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0.0;
      this->femur = 0.0;
      this->tibia = 0.0;
      this->height_ankle = 0.0;
      this->distance_to_heel = 0.0;
      this->distance_to_toe = 0.0;
      this->depth_pelvis = 0.0;
      this->width_pelvis = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _height_type =
    double;
  _height_type height;
  using _femur_type =
    double;
  _femur_type femur;
  using _tibia_type =
    double;
  _tibia_type tibia;
  using _height_ankle_type =
    double;
  _height_ankle_type height_ankle;
  using _distance_to_heel_type =
    double;
  _distance_to_heel_type distance_to_heel;
  using _distance_to_toe_type =
    double;
  _distance_to_toe_type distance_to_toe;
  using _depth_pelvis_type =
    double;
  _depth_pelvis_type depth_pelvis;
  using _width_pelvis_type =
    double;
  _width_pelvis_type width_pelvis;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__femur(
    const double & _arg)
  {
    this->femur = _arg;
    return *this;
  }
  Type & set__tibia(
    const double & _arg)
  {
    this->tibia = _arg;
    return *this;
  }
  Type & set__height_ankle(
    const double & _arg)
  {
    this->height_ankle = _arg;
    return *this;
  }
  Type & set__distance_to_heel(
    const double & _arg)
  {
    this->distance_to_heel = _arg;
    return *this;
  }
  Type & set__distance_to_toe(
    const double & _arg)
  {
    this->distance_to_toe = _arg;
    return *this;
  }
  Type & set__depth_pelvis(
    const double & _arg)
  {
    this->depth_pelvis = _arg;
    return *this;
  }
  Type & set__width_pelvis(
    const double & _arg)
  {
    this->width_pelvis = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::msg::Measurements_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::msg::Measurements_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::Measurements_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::Measurements_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__msg__Measurements
    std::shared_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__msg__Measurements
    std::shared_ptr<nimble_interfaces::msg::Measurements_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Measurements_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->femur != other.femur) {
      return false;
    }
    if (this->tibia != other.tibia) {
      return false;
    }
    if (this->height_ankle != other.height_ankle) {
      return false;
    }
    if (this->distance_to_heel != other.distance_to_heel) {
      return false;
    }
    if (this->distance_to_toe != other.distance_to_toe) {
      return false;
    }
    if (this->depth_pelvis != other.depth_pelvis) {
      return false;
    }
    if (this->width_pelvis != other.width_pelvis) {
      return false;
    }
    return true;
  }
  bool operator!=(const Measurements_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Measurements_

// alias to use template instance with default allocator
using Measurements =
  nimble_interfaces::msg::Measurements_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__STRUCT_HPP_
