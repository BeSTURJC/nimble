// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__STRUCT_HPP_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__STRUCT_HPP_

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
// Member 'malleolus'
// Member 'pelvis'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__msg__CartesianTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__msg__CartesianTrajectory __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CartesianTrajectory_
{
  using Type = CartesianTrajectory_<ContainerAllocator>;

  explicit CartesianTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit CartesianTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _malleolus_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _malleolus_type malleolus;
  using _pelvis_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _pelvis_type pelvis;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__malleolus(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->malleolus = _arg;
    return *this;
  }
  Type & set__pelvis(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->pelvis = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__msg__CartesianTrajectory
    std::shared_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__msg__CartesianTrajectory
    std::shared_ptr<nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianTrajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->malleolus != other.malleolus) {
      return false;
    }
    if (this->pelvis != other.pelvis) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianTrajectory_

// alias to use template instance with default allocator
using CartesianTrajectory =
  nimble_interfaces::msg::CartesianTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__STRUCT_HPP_
