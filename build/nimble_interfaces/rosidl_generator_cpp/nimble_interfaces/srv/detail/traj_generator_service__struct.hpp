// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__STRUCT_HPP_
#define NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'measurements'
#include "nimble_interfaces/msg/detail/measurements__struct.hpp"
// Member 'therapy_requirements'
#include "nimble_interfaces/msg/detail/therapy_requirements__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Request __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Request __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TrajGeneratorService_Request_
{
  using Type = TrajGeneratorService_Request_<ContainerAllocator>;

  explicit TrajGeneratorService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : measurements(_init),
    therapy_requirements(_init)
  {
    (void)_init;
  }

  explicit TrajGeneratorService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : measurements(_alloc, _init),
    therapy_requirements(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _measurements_type =
    nimble_interfaces::msg::Measurements_<ContainerAllocator>;
  _measurements_type measurements;
  using _therapy_requirements_type =
    nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>;
  _therapy_requirements_type therapy_requirements;

  // setters for named parameter idiom
  Type & set__measurements(
    const nimble_interfaces::msg::Measurements_<ContainerAllocator> & _arg)
  {
    this->measurements = _arg;
    return *this;
  }
  Type & set__therapy_requirements(
    const nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> & _arg)
  {
    this->therapy_requirements = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Request
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Request
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajGeneratorService_Request_ & other) const
  {
    if (this->measurements != other.measurements) {
      return false;
    }
    if (this->therapy_requirements != other.therapy_requirements) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajGeneratorService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajGeneratorService_Request_

// alias to use template instance with default allocator
using TrajGeneratorService_Request =
  nimble_interfaces::srv::TrajGeneratorService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nimble_interfaces


// Include directives for member types
// Member 'joints_trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Response __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Response __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TrajGeneratorService_Response_
{
  using Type = TrajGeneratorService_Response_<ContainerAllocator>;

  explicit TrajGeneratorService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joints_trajectory(_init)
  {
    (void)_init;
  }

  explicit TrajGeneratorService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joints_trajectory(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _joints_trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _joints_trajectory_type joints_trajectory;

  // setters for named parameter idiom
  Type & set__joints_trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->joints_trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Response
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__srv__TrajGeneratorService_Response
    std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajGeneratorService_Response_ & other) const
  {
    if (this->joints_trajectory != other.joints_trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajGeneratorService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajGeneratorService_Response_

// alias to use template instance with default allocator
using TrajGeneratorService_Response =
  nimble_interfaces::srv::TrajGeneratorService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nimble_interfaces

namespace nimble_interfaces
{

namespace srv
{

struct TrajGeneratorService
{
  using Request = nimble_interfaces::srv::TrajGeneratorService_Request;
  using Response = nimble_interfaces::srv::TrajGeneratorService_Response;
};

}  // namespace srv

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__STRUCT_HPP_
