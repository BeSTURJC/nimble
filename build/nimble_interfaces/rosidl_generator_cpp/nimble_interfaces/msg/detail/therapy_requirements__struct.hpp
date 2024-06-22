// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:msg/TherapyRequirements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__STRUCT_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__STRUCT_HPP_

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
# define DEPRECATED__nimble_interfaces__msg__TherapyRequirements __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__msg__TherapyRequirements __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TherapyRequirements_
{
  using Type = TherapyRequirements_<ContainerAllocator>;

  explicit TherapyRequirements_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
      this->step_length = 0.0;
      this->step_height = 0.0;
      this->min_assist_level = 0l;
      this->max_assist_level = 0l;
    }
  }

  explicit TherapyRequirements_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0;
      this->step_length = 0.0;
      this->step_height = 0.0;
      this->min_assist_level = 0l;
      this->max_assist_level = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _speed_type =
    double;
  _speed_type speed;
  using _step_length_type =
    double;
  _step_length_type step_length;
  using _step_height_type =
    double;
  _step_height_type step_height;
  using _min_assist_level_type =
    int32_t;
  _min_assist_level_type min_assist_level;
  using _max_assist_level_type =
    int32_t;
  _max_assist_level_type max_assist_level;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__step_length(
    const double & _arg)
  {
    this->step_length = _arg;
    return *this;
  }
  Type & set__step_height(
    const double & _arg)
  {
    this->step_height = _arg;
    return *this;
  }
  Type & set__min_assist_level(
    const int32_t & _arg)
  {
    this->min_assist_level = _arg;
    return *this;
  }
  Type & set__max_assist_level(
    const int32_t & _arg)
  {
    this->max_assist_level = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__msg__TherapyRequirements
    std::shared_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__msg__TherapyRequirements
    std::shared_ptr<nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TherapyRequirements_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->step_length != other.step_length) {
      return false;
    }
    if (this->step_height != other.step_height) {
      return false;
    }
    if (this->min_assist_level != other.min_assist_level) {
      return false;
    }
    if (this->max_assist_level != other.max_assist_level) {
      return false;
    }
    return true;
  }
  bool operator!=(const TherapyRequirements_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TherapyRequirements_

// alias to use template instance with default allocator
using TherapyRequirements =
  nimble_interfaces::msg::TherapyRequirements_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__STRUCT_HPP_
