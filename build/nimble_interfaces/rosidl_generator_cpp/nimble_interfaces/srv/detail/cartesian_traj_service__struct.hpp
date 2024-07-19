// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__STRUCT_HPP_
#define NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'joints_trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"
// Member 'measurements'
#include "nimble_interfaces/msg/detail/measurements__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Request __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Request __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CartesianTrajService_Request_
{
  using Type = CartesianTrajService_Request_<ContainerAllocator>;

  explicit CartesianTrajService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joints_trajectory(_init),
    measurements(_init)
  {
    (void)_init;
  }

  explicit CartesianTrajService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joints_trajectory(_alloc, _init),
    measurements(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _joints_trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _joints_trajectory_type joints_trajectory;
  using _measurements_type =
    nimble_interfaces::msg::Measurements_<ContainerAllocator>;
  _measurements_type measurements;

  // setters for named parameter idiom
  Type & set__joints_trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->joints_trajectory = _arg;
    return *this;
  }
  Type & set__measurements(
    const nimble_interfaces::msg::Measurements_<ContainerAllocator> & _arg)
  {
    this->measurements = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Request
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Request
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianTrajService_Request_ & other) const
  {
    if (this->joints_trajectory != other.joints_trajectory) {
      return false;
    }
    if (this->measurements != other.measurements) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianTrajService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianTrajService_Request_

// alias to use template instance with default allocator
using CartesianTrajService_Request =
  nimble_interfaces::srv::CartesianTrajService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nimble_interfaces


// Include directives for member types
// Member 'cartesian_trajectory'
#include "nimble_interfaces/msg/detail/cartesian_trajectory__struct.hpp"
// Member 'step_target'
#include "nimble_interfaces/msg/detail/therapy_requirements__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Response __attribute__((deprecated))
#else
# define DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Response __declspec(deprecated)
#endif

namespace nimble_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CartesianTrajService_Response_
{
  using Type = CartesianTrajService_Response_<ContainerAllocator>;

  explicit CartesianTrajService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cartesian_trajectory(_init),
    step_target(_init)
  {
    (void)_init;
  }

  explicit CartesianTrajService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cartesian_trajectory(_alloc, _init),
    step_target(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _cartesian_trajectory_type =
    nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator>;
  _cartesian_trajectory_type cartesian_trajectory;
  using _step_target_type =
    nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator>;
  _step_target_type step_target;

  // setters for named parameter idiom
  Type & set__cartesian_trajectory(
    const nimble_interfaces::msg::CartesianTrajectory_<ContainerAllocator> & _arg)
  {
    this->cartesian_trajectory = _arg;
    return *this;
  }
  Type & set__step_target(
    const nimble_interfaces::msg::TherapyRequirements_<ContainerAllocator> & _arg)
  {
    this->step_target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Response
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nimble_interfaces__srv__CartesianTrajService_Response
    std::shared_ptr<nimble_interfaces::srv::CartesianTrajService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianTrajService_Response_ & other) const
  {
    if (this->cartesian_trajectory != other.cartesian_trajectory) {
      return false;
    }
    if (this->step_target != other.step_target) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianTrajService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianTrajService_Response_

// alias to use template instance with default allocator
using CartesianTrajService_Response =
  nimble_interfaces::srv::CartesianTrajService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace nimble_interfaces

namespace nimble_interfaces
{

namespace srv
{

struct CartesianTrajService
{
  using Request = nimble_interfaces::srv::CartesianTrajService_Request;
  using Response = nimble_interfaces::srv::CartesianTrajService_Response;
};

}  // namespace srv

}  // namespace nimble_interfaces

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__STRUCT_HPP_
