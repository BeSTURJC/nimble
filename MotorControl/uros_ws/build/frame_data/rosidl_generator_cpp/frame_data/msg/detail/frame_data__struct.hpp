// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice

#ifndef FRAME_DATA__MSG__DETAIL__FRAME_DATA__STRUCT_HPP_
#define FRAME_DATA__MSG__DETAIL__FRAME_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__frame_data__msg__FrameData __attribute__((deprecated))
#else
# define DEPRECATED__frame_data__msg__FrameData __declspec(deprecated)
#endif

namespace frame_data
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FrameData_
{
  using Type = FrameData_<ContainerAllocator>;

  explicit FrameData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->contador = 0ul;
      this->frame_position = 0.0f;
      this->frame_speed = 0.0f;
      this->sensor_dist = 0.0f;
      this->position_ref = 0.0f;
      this->speed_ref = 0.0f;
    }
  }

  explicit FrameData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->contador = 0ul;
      this->frame_position = 0.0f;
      this->frame_speed = 0.0f;
      this->sensor_dist = 0.0f;
      this->position_ref = 0.0f;
      this->speed_ref = 0.0f;
    }
  }

  // field types and members
  using _contador_type =
    uint32_t;
  _contador_type contador;
  using _frame_position_type =
    float;
  _frame_position_type frame_position;
  using _frame_speed_type =
    float;
  _frame_speed_type frame_speed;
  using _sensor_dist_type =
    float;
  _sensor_dist_type sensor_dist;
  using _position_ref_type =
    float;
  _position_ref_type position_ref;
  using _speed_ref_type =
    float;
  _speed_ref_type speed_ref;

  // setters for named parameter idiom
  Type & set__contador(
    const uint32_t & _arg)
  {
    this->contador = _arg;
    return *this;
  }
  Type & set__frame_position(
    const float & _arg)
  {
    this->frame_position = _arg;
    return *this;
  }
  Type & set__frame_speed(
    const float & _arg)
  {
    this->frame_speed = _arg;
    return *this;
  }
  Type & set__sensor_dist(
    const float & _arg)
  {
    this->sensor_dist = _arg;
    return *this;
  }
  Type & set__position_ref(
    const float & _arg)
  {
    this->position_ref = _arg;
    return *this;
  }
  Type & set__speed_ref(
    const float & _arg)
  {
    this->speed_ref = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    frame_data::msg::FrameData_<ContainerAllocator> *;
  using ConstRawPtr =
    const frame_data::msg::FrameData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<frame_data::msg::FrameData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<frame_data::msg::FrameData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      frame_data::msg::FrameData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<frame_data::msg::FrameData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      frame_data::msg::FrameData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<frame_data::msg::FrameData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<frame_data::msg::FrameData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<frame_data::msg::FrameData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__frame_data__msg__FrameData
    std::shared_ptr<frame_data::msg::FrameData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__frame_data__msg__FrameData
    std::shared_ptr<frame_data::msg::FrameData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameData_ & other) const
  {
    if (this->contador != other.contador) {
      return false;
    }
    if (this->frame_position != other.frame_position) {
      return false;
    }
    if (this->frame_speed != other.frame_speed) {
      return false;
    }
    if (this->sensor_dist != other.sensor_dist) {
      return false;
    }
    if (this->position_ref != other.position_ref) {
      return false;
    }
    if (this->speed_ref != other.speed_ref) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameData_

// alias to use template instance with default allocator
using FrameData =
  frame_data::msg::FrameData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace frame_data

#endif  // FRAME_DATA__MSG__DETAIL__FRAME_DATA__STRUCT_HPP_
