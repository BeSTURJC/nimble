cmake_minimum_required(VERSION 3.8)
project(nimble)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nimble_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Directories
include_directories(include)

# Executables
add_executable(kinematic_model src/kinematic_model.cpp)
ament_target_dependencies(kinematic_model rclcpp nimble_interfaces sensor_msgs trajectory_msgs)

add_executable(states_machine src/states_machine.cpp)
ament_target_dependencies(states_machine rclcpp nimble_interfaces sensor_msgs trajectory_msgs std_msgs)

add_executable(control_ZMP src/control_ZMP.cpp)
ament_target_dependencies(control_ZMP rclcpp nimble_interfaces sensor_msgs trajectory_msgs)

add_executable(control_MSD src/control_MSD.cpp)
ament_target_dependencies(control_MSD rclcpp nimble_interfaces sensor_msgs trajectory_msgs std_msgs)

add_executable(cables_robot src/cables_robot.cpp)
ament_target_dependencies(cables_robot rclcpp sensor_msgs)

add_executable(frame src/frame.cpp)
ament_target_dependencies(frame rclcpp sensor_msgs nimble_interfaces)

add_executable(gamming src/gamming.cpp)
ament_target_dependencies(gamming rclcpp nimble_interfaces)

add_executable(traj_generator_server src/traj_generator_service.cpp)
ament_target_dependencies(traj_generator_server rclcpp nimble_interfaces)

install(TARGETS
  kinematic_model
  control_ZMP
  control_MSD
  cables_robot
  gamming
  frame
  states_machine
  traj_generator_server
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch include
  DESTINATION share/${PROJECT_NAME})

# Python executables
install(PROGRAMS src/hmi.py
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
