#include <chrono>
#include <cstdlib>
#include <functional>
#include <memory>
#include <string>

#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "nimble_interfaces/msg/frame_state.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/srv/traj_generator_service.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "state_machine/stateMachine.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"

using namespace std::chrono_literals;

namespace stateMachine {

StatesMachineNode::StatesMachineNode() : Node("states_machine") {
  // Possible internal parameters
  this->declare_parameter("contact_point", 1);
  this->declare_parameter("param2", 2);

  // Create all subscribers

  subscriber_joints_state = create_subscription<sensor_msgs::msg::JointState>(
      "joints_state", 10, [this](const sensor_msgs::msg::JointState msg) { 
        call_back_joints_state(msg); });

  subscriber_cartesian_target =
      create_subscription<nimble_interfaces::msg::CartesianTrajectory>(
          "cartesian_target", 10, [this](const nimble_interfaces::msg::CartesianTrajectory msg) {
            call_back_cartesian_target(msg);});

  subscriber_cartesian_state =
      create_subscription<nimble_interfaces::msg::CartesianTrajectory>(
          "cartesian_state", 10, [this](const nimble_interfaces::msg::CartesianTrajectory msg) {
            call_back_cartesian_state(msg);});

  subscriber_state_cables = create_subscription<sensor_msgs::msg::JointState>(
      "cables_state", 10, [this](const sensor_msgs::msg::JointState msg) {
        call_back_state_cables(msg);});

  subscriber_step_target =
      create_subscription<nimble_interfaces::msg::TherapyRequirements>(
          "step_target", 10, [this](const nimble_interfaces::msg::TherapyRequirements msg) {
            call_back_step_target(msg);});

  subscriber_therapy_requirements =
      create_subscription<nimble_interfaces::msg::TherapyRequirements>(
          "therapy_requirements", 10, [this](const nimble_interfaces::msg::TherapyRequirements msg) {
            call_back_therapy_requirements(msg); });

  subscriber_measurements =
      create_subscription<nimble_interfaces::msg::Measurements>(
          "measurements", 10, [this](const nimble_interfaces::msg::Measurements msg) {
            call_back_measurements(msg); });

  subscriber_interaction_torque =
      create_subscription<std_msgs::msg::Float32MultiArray>(
          "interactionTorque", 10, [this](const std_msgs::msg::Float32MultiArray msg) {
            call_back_interaction_torque(msg);});

  subscriber_FSR = create_subscription<std_msgs::msg::ByteMultiArray>(
      "FSR", 10,[this](const std_msgs::msg::ByteMultiArray msg) { 
        call_back_FSR(msg); });

  // Create publisher for topics
  publisher_joints_target = create_publisher<trajectory_msgs::msg::JointTrajectory>("joints_target", 10);
  publisher_assistLevel = create_publisher<std_msgs::msg::Int32MultiArray>("assistLevel", 10);
  publisher_executionMode = create_publisher<std_msgs::msg::Int32>("executionMode", 10);
  publisher_controlMode = create_publisher<std_msgs::msg::Int32MultiArray>("controlMode", 10);
  publisher_step_percent = create_publisher<std_msgs::msg::Int32>("step_percent", 10);

  // Create callback groups to avoid multi-executor issues
  client_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  // Create a client for your service
  client_ = this->create_client<nimble_interfaces::srv::TrajGeneratorService>(
      "traj_generator_service", rmw_qos_profile_services_default, client_cb_group_);

  // Create wall timer to publish periodically
  timer_joint_target_ = this->create_wall_timer(1000ms, std::bind(&StatesMachineNode::joints_target_timer_callback, this));
  timer_percent_ = this->create_wall_timer(10ms, std::bind(&StatesMachineNode::step_percent_timer_callback, this));
}

// Function to convert JointTrajectory to string (Debugging)
std::string StatesMachineNode::jointTrajectoryToString(const trajectory_msgs::msg::JointTrajectory::SharedPtr& joint_trajectory) {
  std::stringstream ss;

  ss << "Joint Names: ";
  for (const auto& joint_name : joint_trajectory->joint_names) {
    ss << joint_name << " ";
  }
  ss << std::endl;

  for (const auto& point : joint_trajectory->points) {
    ss << "Point:" << std::endl;
    ss << "  Positions: ";
    for (const auto& position : point.positions) {
      ss << position << " ";
    }
    ss << std::endl;
    ss << "  Time from start: " << point.time_from_start.sec << " seconds"
       << std::endl;
  }

  return ss.str();
}


// Function to check for modifications in patient measurements or physiotherapist requirements 
// and request ideal trajectory (also executed with the first message)
bool StatesMachineNode::check_variations_in_therapy(const nimble_interfaces::msg::Measurements& measurements,
    const nimble_interfaces::msg::TherapyRequirements& therapy_requirements) {

  bool therapy_variation = false;

  if (measurements.height_ankle != shared_data_.measurements_previous.height_ankle) {
    therapy_variation = true;
    shared_data_.measurements_previous.height_ankle = measurements.height_ankle;

  } else if (measurements.distance_to_heel != shared_data_.measurements_previous.distance_to_heel) {
    therapy_variation = true;
    shared_data_.measurements_previous.distance_to_heel = measurements.distance_to_heel;

  } else if (measurements.distance_to_toe != shared_data_.measurements_previous.distance_to_toe) {
    therapy_variation = true;
    shared_data_.measurements_previous.distance_to_toe = measurements.distance_to_toe;

  } else if (measurements.depth_pelvis != shared_data_.measurements_previous.depth_pelvis) {
    therapy_variation = true;
    shared_data_.measurements_previous.depth_pelvis = measurements.depth_pelvis;

  } else if (measurements.width_pelvis !=  shared_data_.measurements_previous.width_pelvis) {
    therapy_variation = true;
    shared_data_.measurements_previous.width_pelvis = measurements.width_pelvis;

  } else if (measurements.height != shared_data_.measurements_previous.height) {
    therapy_variation = true;
    shared_data_.measurements_previous.height = measurements.height;

  } else if (measurements.tibia != shared_data_.measurements_previous.tibia) {
    therapy_variation = true;
    shared_data_.measurements_previous.tibia = measurements.tibia;

  } else if (measurements.femur != shared_data_.measurements_previous.femur) {
    therapy_variation = true;
    shared_data_.measurements_previous.femur = measurements.femur;

  } else if (therapy_requirements.step_length != shared_data_.therapy_requirements_previous.step_length) {
    therapy_variation = true;
    shared_data_.therapy_requirements_previous.step_length = therapy_requirements.step_length;

  } else if (therapy_requirements.step_height != shared_data_.therapy_requirements_previous.step_height) {
    therapy_variation = true;
    shared_data_.therapy_requirements_previous.step_height = therapy_requirements.step_height;
  }

  return therapy_variation;
}

// Function to request the trajectory calculation service
void StatesMachineNode::call_TrajGenerationService(
    const nimble_interfaces::msg::Measurements& measurements,
    const nimble_interfaces::msg::TherapyRequirements& requirements) {

  RCLCPP_INFO(this->get_logger(), "Sending trajectory request");

  // Create a request to send to the service
  auto request = std::make_shared<nimble_interfaces::srv::TrajGeneratorService::Request>();

  // Populate the request fields as needed
  request->measurements = measurements;
  request->therapy_requirements = requirements;

  while (!client_->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      // return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  // Call the service using the client
  auto result = client_->async_send_request(request);

  // Wait for the result
  // Do this instead of rclcpp::spin_until_future_complete()
  std::future_status status = result.wait_for(10s);  // timeout to guarantee a graceful finish

  if (status == std::future_status::ready) {
    RCLCPP_INFO(this->get_logger(), "Received response");
    shared_data_.joints_target = result.get()->joints_target;

    // Gets the timestamp for step percentage 
    time_jt_received_ = std::chrono::steady_clock::now();
  }
}


// **Callbacks** //

void StatesMachineNode::call_back_joints_state(const sensor_msgs::msg::JointState& joint_state_msg) {
  shared_data_.joints_state =joint_state_msg;  
  processData();        
}

void StatesMachineNode::call_back_cartesian_target(const nimble_interfaces::msg::CartesianTrajectory& cartesian_target_msg) {
  shared_data_.cartesian_target = cartesian_target_msg;
  processData();
}
void StatesMachineNode::call_back_cartesian_state(const nimble_interfaces::msg::CartesianTrajectory& cartesian_state_msg) {
  shared_data_.cartesian_state = cartesian_state_msg;
  processData();
}

void StatesMachineNode::call_back_state_cables(const sensor_msgs::msg::JointState& joint_state_cables_msg) {
  shared_data_.cables_state = joint_state_cables_msg;
  processData();
}

void StatesMachineNode::call_back_step_target(const nimble_interfaces::msg::TherapyRequirements& step_target_msg) {
  shared_data_.step_target = step_target_msg;
  processData();
}

void StatesMachineNode::call_back_therapy_requirements(const nimble_interfaces::msg::TherapyRequirements&therapy_requirements_msg) {
  shared_data_.therapy_requirements = therapy_requirements_msg;
  processData();
}

void StatesMachineNode::call_back_measurements(const nimble_interfaces::msg::Measurements& measurements_msg) {
  shared_data_.measurements = measurements_msg;
  processData();
}

void StatesMachineNode::call_back_interaction_torque(const std_msgs::msg::Float32MultiArray& interaction_torque_msg) {
  shared_data_.interaction_torque = interaction_torque_msg;
  processData();
}

void StatesMachineNode::call_back_FSR(const std_msgs::msg::ByteMultiArray& FSR_msg) {
  shared_data_.FSR = FSR_msg;
  processData();
}

// Process function
void StatesMachineNode::processData() {
  // TODO: Aquí quizás habría que hacer distintas funciones de procesamiento y comprobar que existen datos de todo lo necesario con un if
  // TODO: Comprobar si hay modificaciones en los parametros de la terapia o el paciente

  bool therapy_variation = check_variations_in_therapy(shared_data_.measurements, shared_data_.therapy_requirements);
  if (therapy_variation == true) {
    // If there are any, request ideal trajectory calculation
    call_TrajGenerationService(shared_data_.measurements, shared_data_.therapy_requirements);
  }
}


int StatesMachineNode::get_step_percent() {

    float step_percent = 0;
    size_t num_points = shared_data_.joints_target.points.size();

    // joints_target not received
    if (num_points != 0) {
        // Gets  linux clock to avoid resets
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - time_jt_received_);
        int time_act = static_cast<int>(elapsed.count());

        float step_speed = shared_data_.therapy_requirements.speed; // m/s

        // (m/s * m) * 1000 (ms)    
        float time_step = (step_speed * shared_data_.therapy_requirements.step_length) * 1000;  

        // Restarts timer if its in other step
        if (time_act >= time_step) {
            time_jt_received_ = std::chrono::steady_clock::now();
            time_act = time_act - time_step;
        } 
            
        step_percent = time_act / time_step * 100;
    }

    return int(step_percent);
}

trajectory_msgs::msg::JointTrajectoryPoint StatesMachineNode::get_actual_joint_state(int step_percent) {
    trajectory_msgs::msg::JointTrajectoryPoint point;
    
    int ind = 0;

    int num_joints = shared_data_.joints_target.points[0].positions.size();
    int num_points = shared_data_.joints_target.points.size();

    // Ensure floating-point division
    float index = (static_cast<float>(step_percent) / 100.0f) * (num_points-1);

    // Check if its an integer within a small threshold
    if (std::abs(index - static_cast<int>(index)) < 0.001) {
        point = shared_data_.joints_target.points[int(index)];

    } 
    else {
        // Gets the floor and ceil index
        int floorIndex = static_cast<int>(std::floor(index));
        int ceilIndex = static_cast<int>(std::ceil(index));

        // Ensure that indices are within bounds
        floorIndex = std::max(0, std::min(floorIndex, num_points - 1));
        ceilIndex = std::max(0, std::min(ceilIndex, num_points - 1));

        // Interpolates for all values
        for (int i = 0; i < num_joints; i++){
            float floorPose = shared_data_.joints_target.points[floorIndex].positions[i];
            float ceilPose = shared_data_.joints_target.points[ceilIndex].positions[i];

            float m = ceilPose - floorPose;
            float jointPos = m*std::abs(index - static_cast<int>(index)) + floorPose;

            point.positions.push_back(jointPos);
        }
    }
    return point;
}


void StatesMachineNode::step_percent_timer_callback() {
  auto percent_message = std_msgs::msg::Int32();
  int percent = get_step_percent();
  
  // The array is not empty
  if (!shared_data_.joints_target.points.empty()) {
    trajectory_msgs::msg::JointTrajectoryPoint point = get_actual_joint_state(95);
  }

  percent_message.data = percent;

  publisher_step_percent->publish(percent_message);
}

void StatesMachineNode::joints_target_timer_callback() { 
  auto joints_target_msg = trajectory_msgs::msg::JointTrajectory();  
  joints_target_msg = shared_data_.joints_target; // Fill in with the corresponding information
  joints_target_msg.header.stamp = now();  // Header with the publication timestamp
  publisher_joints_target->publish(joints_target_msg);  // publish

}

};  // namespace stateMachine

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<stateMachine::StatesMachineNode>();
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);

  // RCLCPP_INFO(node->get_logger(), "Starting states machine node, shut down
  // with CTRL-C");
  executor.spin();
  // RCLCPP_INFO(node->get_logger(), "Keyboard interrupt, shutting down.\n");

  rclcpp::shutdown();
  return 0;
}
