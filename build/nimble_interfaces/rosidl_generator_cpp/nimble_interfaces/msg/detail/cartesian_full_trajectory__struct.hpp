// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__STRUCT_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__STRUCT_HPP_

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
// Member 'left_pelvis'
// Member 'right_pelvis'
// Member 'base_pelvis'
// Member 'left_hip'
// Member 'right_hip'
// Member 'left_knee'
// Member 'right_knee'
// Member 'left_ankle'
// Member 'right_ankle'
// Member 'left_heel'
// Member 'right_heel'
// Member 'left_toe'
// Member 'right_toe'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__msg__CartesianFullTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__msg__CartesianFullTrajectory __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CartesianFullTrajectory_
{
  using Type = CartesianFullTrajectory_<ContainerAllocator>;

  explicit CartesianFullTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit CartesianFullTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _left_pelvis_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _left_pelvis_type left_pelvis;
  using _right_pelvis_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _right_pelvis_type right_pelvis;
  using _base_pelvis_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _base_pelvis_type base_pelvis;
  using _left_hip_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _left_hip_type left_hip;
  using _right_hip_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _right_hip_type right_hip;
  using _left_knee_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _left_knee_type left_knee;
  using _right_knee_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _right_knee_type right_knee;
  using _left_ankle_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _left_ankle_type left_ankle;
  using _right_ankle_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _right_ankle_type right_ankle;
  using _left_heel_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _left_heel_type left_heel;
  using _right_heel_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _right_heel_type right_heel;
  using _left_toe_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _left_toe_type left_toe;
  using _right_toe_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _right_toe_type right_toe;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__left_pelvis(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->left_pelvis = _arg;
    return *this;
  }
  Type & set__right_pelvis(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->right_pelvis = _arg;
    return *this;
  }
  Type & set__base_pelvis(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->base_pelvis = _arg;
    return *this;
  }
  Type & set__left_hip(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->left_hip = _arg;
    return *this;
  }
  Type & set__right_hip(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->right_hip = _arg;
    return *this;
  }
  Type & set__left_knee(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->left_knee = _arg;
    return *this;
  }
  Type & set__right_knee(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->right_knee = _arg;
    return *this;
  }
  Type & set__left_ankle(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->left_ankle = _arg;
    return *this;
  }
  Type & set__right_ankle(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->right_ankle = _arg;
    return *this;
  }
  Type & set__left_heel(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->left_heel = _arg;
    return *this;
  }
  Type & set__right_heel(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->right_heel = _arg;
    return *this;
  }
  Type & set__left_toe(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->left_toe = _arg;
    return *this;
  }
  Type & set__right_toe(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->right_toe = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__msg__CartesianFullTrajectory
    std::shared_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__msg__CartesianFullTrajectory
    std::shared_ptr<nimble_interfaces::msg::CartesianFullTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianFullTrajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->left_pelvis != other.left_pelvis) {
      return false;
    }
    if (this->right_pelvis != other.right_pelvis) {
      return false;
    }
    if (this->base_pelvis != other.base_pelvis) {
      return false;
    }
    if (this->left_hip != other.left_hip) {
      return false;
    }
    if (this->right_hip != other.right_hip) {
      return false;
    }
    if (this->left_knee != other.left_knee) {
      return false;
    }
    if (this->right_knee != other.right_knee) {
      return false;
    }
    if (this->left_ankle != other.left_ankle) {
      return false;
    }
    if (this->right_ankle != other.right_ankle) {
      return false;
    }
    if (this->left_heel != other.left_heel) {
      return false;
    }
    if (this->right_heel != other.right_heel) {
      return false;
    }
    if (this->left_toe != other.left_toe) {
      return false;
    }
    if (this->right_toe != other.right_toe) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianFullTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianFullTrajectory_

// alias to use template instance with default allocator
using CartesianFullTrajectory =
  nimble_interfaces::msg::CartesianFullTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__STRUCT_HPP_
