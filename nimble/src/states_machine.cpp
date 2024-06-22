#include <chrono>
#include <cstdlib>
#include <functional>
#include <memory>
#include <string>

#include "nimble_interfaces/srv/traj_generator_service.hpp"
#include "state_machine/stateMachine.hpp"

using namespace std::chrono_literals;

namespace stateMachine {

StatesMachineNode::StatesMachineNode() : Node("states_machine") {
  // Possible internal parameters
  this->declare_parameter("joints_target_ts", 10.0);
  this->declare_parameter("joints_trajectory_ts", 3000.0);
  this->get_parameter("joints_trajectory_ts",joints_trajectory_ts);
  this->get_parameter("joints_target_ts",joints_target_ts);

  th_req_received=false;
  meas_received=false;
  
  // Create all subscribers

  subscriber_joints_state = create_subscription<sensor_msgs::msg::JointState>(
      "joints_state", 10, [this](const sensor_msgs::msg::JointState msg) { 
        call_back_joints_state(msg);});

  subscriber_cartesian_trajectory =
      create_subscription<nimble_interfaces::msg::CartesianTrajectory>(
          "cartesian_trajectory", 10, [this](const nimble_interfaces::msg::CartesianTrajectory msg) {
            call_back_cartesian_trajectory(msg);});

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
  publisher_joints_target = create_publisher<nimble_interfaces::msg::JointsTrajectory>("joints_target", 10);
  publisher_joints_trajectory = create_publisher<nimble_interfaces::msg::JointsTrajectory>("joints_trajectory", 10);
  publisher_assistLevel = create_publisher<std_msgs::msg::Int32MultiArray>("assistLevel", 10);
  publisher_executionMode = create_publisher<std_msgs::msg::Int32>("executionMode", 10);
  publisher_controlMode = create_publisher<std_msgs::msg::Int32MultiArray>("controlMode", 10);
  

  // Create callback groups to avoid multi-executor issues
  client_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  // Create a client for your service
  client_ = this->create_client<nimble_interfaces::srv::TrajGeneratorService>(
      "traj_generator_service", rmw_qos_profile_services_default, client_cb_group_);

  // Create wall timer to publish periodically
  timer_joint_trajectory_ = this->create_wall_timer(std::chrono::duration<double>(joints_trajectory_ts/1000), std::bind(&StatesMachineNode::call_back_joints_trajectory_timer, this));
  timer_joint_target_= this->create_wall_timer(std::chrono::duration<double>(joints_target_ts/1000), std::bind(&StatesMachineNode::call_back_joints_current_target, this));
}


// Function to check for modifications in patient measurements or physiotherapist requirements 
// and request ideal trajectory (also executed with the first message)
bool StatesMachineNode::check_variations_in_therapy() {

  bool therapy_variation = false;

  if (shared_data_.measurements.height_ankle != shared_data_.measurements_previous.height_ankle) {
    therapy_variation = true;
    shared_data_.measurements_previous.height_ankle = shared_data_.measurements.height_ankle;

  }
  if (shared_data_.measurements.distance_to_heel != shared_data_.measurements_previous.distance_to_heel) {
    therapy_variation = true;
    shared_data_.measurements_previous.distance_to_heel = shared_data_.measurements.distance_to_heel;

  }
  if (shared_data_.measurements.distance_to_toe != shared_data_.measurements_previous.distance_to_toe) {
    therapy_variation = true;
    shared_data_.measurements_previous.distance_to_toe = shared_data_.measurements.distance_to_toe;

  }
  if (shared_data_.measurements.depth_pelvis != shared_data_.measurements_previous.depth_pelvis) {
    therapy_variation = true;
    shared_data_.measurements_previous.depth_pelvis = shared_data_.measurements.depth_pelvis;

  }
  if (shared_data_.measurements.width_pelvis !=  shared_data_.measurements_previous.width_pelvis) {
    therapy_variation = true;
    shared_data_.measurements_previous.width_pelvis = shared_data_.measurements.width_pelvis;

  }
  if (shared_data_.measurements.height != shared_data_.measurements_previous.height) {
    therapy_variation = true;
    shared_data_.measurements_previous.height = shared_data_.measurements.height;

  }
  if (shared_data_.measurements.tibia != shared_data_.measurements_previous.tibia) {
    therapy_variation = true;
    shared_data_.measurements_previous.tibia = shared_data_.measurements.tibia;

  }
  if (shared_data_.measurements.femur != shared_data_.measurements_previous.femur) {
    therapy_variation = true;
    shared_data_.measurements_previous.femur = shared_data_.measurements.femur;

  }
  if (shared_data_.therapy_requirements.step_length != shared_data_.therapy_requirements_previous.step_length) {
    therapy_variation = true;
    shared_data_.therapy_requirements_previous.step_length = shared_data_.therapy_requirements.step_length;

  }
  if (shared_data_.therapy_requirements.step_height != shared_data_.therapy_requirements_previous.step_height) {
    therapy_variation = true;
    shared_data_.therapy_requirements_previous.step_height = shared_data_.therapy_requirements.step_height;
  }
  if (shared_data_.therapy_requirements.speed != shared_data_.therapy_requirements_previous.speed) {
    therapy_variation = true;
    shared_data_.therapy_requirements_previous.speed = shared_data_.therapy_requirements.speed;
  }

  return therapy_variation;
}

// Function to convert a JointTrajectory message to a string
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
        ss << "  Time from start: " << point.time_from_start.sec << " seconds" << std::endl;
    }

    return ss.str();
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

  while (!client_->wait_for_service(3s)) {
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
    shared_data_.joints_trajectory.trajectory=result.get()->joints_trajectory;
    
    //auto joint_trajectory_msg_ptr = std::make_shared<trajectory_msgs::msg::JointTrajectory>(shared_data_.joints_trajectory.trajectory);
    /*RCLCPP_INFO(this->get_logger(), "JointTrajectory message:\n%s",
        jointTrajectoryToString(joint_trajectory_msg_ptr).c_str());*/
        
    // Gets the timestamp for step percentage 
    time_jt_received_ = std::chrono::steady_clock::now();
    
    //Adapt complete trajectory to control frequency (joints_target_ts). Adapting number of points
    //calculate steps in gait percentage depending on the frecuency
    float delta_phase=shared_data_.therapy_requirements.speed/1000*joints_target_ts/shared_data_.therapy_requirements.step_length*100;
    //number of points to interpolate with that step
    int num_samples=1+100/delta_phase;
    RCLCPP_INFO(this->get_logger(), "Delta:%f, Samples:%i",delta_phase,num_samples);

    auto traj=trajectory_msgs::msg::JointTrajectory();
    std::vector<float> linspaced_phases;
    for (int i = 0; i < num_samples; ++i) {
        linspaced_phases.push_back(delta_phase * i);
        trajectory_msgs::msg::JointTrajectoryPoint target = get_actual_joint_state(delta_phase * i);
        traj.points.push_back(target);
    }
    std_msgs::msg::Float32MultiArray phases_msg;
    phases_msg.data=linspaced_phases;
    shared_data_.joints_trajectory.phase=phases_msg;
    shared_data_.joints_trajectory.trajectory=traj;
  }
  //auto joint_trajectory_msg_ptr = std::make_shared<trajectory_msgs::msg::JointTrajectory>(shared_data_.joints_trajectory.trajectory);
  //RCLCPP_INFO(this->get_logger(), "JointTrajectory message:\n%s",jointTrajectoryToString(joint_trajectory_msg_ptr).c_str());
}

float StatesMachineNode::get_step_percent() {

    float step_percent = 0;
    size_t num_points = shared_data_.joints_trajectory.trajectory.points.size();

    // joints_target not received
    if (num_points != 0) {
        // Gets  linux clock to avoid resets
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - time_jt_received_);
        int time_act = static_cast<int>(elapsed.count());

        float step_speed = shared_data_.therapy_requirements.speed; // m/s

        // (m/s * m) * 1000 (ms)    
        float time_step = (shared_data_.therapy_requirements.step_length/step_speed) * 1000;  

        // Restarts timer if its in other step
        if (time_act >= time_step) {
            time_jt_received_ = std::chrono::steady_clock::now();
            time_act = time_act - time_step;
        } 
            
        step_percent = time_act / time_step * 100;
    }

    return step_percent;
}

trajectory_msgs::msg::JointTrajectoryPoint StatesMachineNode::get_actual_joint_state(float gait_percent) {
    trajectory_msgs::msg::JointTrajectoryPoint point;
    
    int num_joints = shared_data_.joints_trajectory.trajectory.points[0].positions.size();
    int num_points = shared_data_.joints_trajectory.trajectory.points.size();
    //RCLCPP_INFO(this->get_logger(), "Delta:%f,Points:%i, Joints:%i",gait_percent,num_points,num_joints);
    // Ensure floating-point division
    float index = (static_cast<float>(gait_percent) / 100.0f) * (num_points-1);
    //RCLCPP_INFO(this->get_logger(), "Raw Index:%f",index);
    // Check if its an integer within a small threshold
    if (std::abs(index - static_cast<int>(index)) < 0.001) {
        point = shared_data_.joints_trajectory.trajectory .points[int(index)];

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
            float floorPose = shared_data_.joints_trajectory.trajectory .points[floorIndex].positions[i];
            float ceilPose = shared_data_.joints_trajectory.trajectory .points[ceilIndex].positions[i];

            float m = ceilPose - floorPose;
            float jointPos = m*std::abs(index - static_cast<int>(index)) + floorPose;

            point.positions.push_back(jointPos);
        }
    }
    return point;
}


// **Callbacks** //

void StatesMachineNode::call_back_joints_state(const sensor_msgs::msg::JointState& joint_state_msg) {
  shared_data_.joints_state =joint_state_msg;  
  processData();        
}

void StatesMachineNode::call_back_cartesian_trajectory(const nimble_interfaces::msg::CartesianTrajectory& cartesian_trajectory_msg) {
  shared_data_.cartesian_trajectory = cartesian_trajectory_msg;
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

void StatesMachineNode::call_back_therapy_requirements(const nimble_interfaces::msg::TherapyRequirements& therapy_requirements_msg) {
  shared_data_.therapy_requirements = therapy_requirements_msg;
  th_req_received=true;
  bool therapy_variation = check_variations_in_therapy();
  RCLCPP_INFO(this->get_logger(), "The value of my_boolean is: %s", therapy_variation ? "true" : "false");
  RCLCPP_INFO(this->get_logger(), "Speed: %f", shared_data_.therapy_requirements.speed);
  if (th_req_received && meas_received && therapy_variation) {
      // If there are any, request ideal trajectory calculation
      call_TrajGenerationService(shared_data_.measurements, shared_data_.therapy_requirements);
      therapy_variation = false;
    
  }
    
}

void StatesMachineNode::call_back_measurements(const nimble_interfaces::msg::Measurements& measurements_msg) {
  shared_data_.measurements = measurements_msg;
  meas_received=true;
  bool therapy_variation = check_variations_in_therapy();
  if (th_req_received && meas_received && therapy_variation){  
    // If there are any, request ideal trajectory calculation
    call_TrajGenerationService(shared_data_.measurements, shared_data_.therapy_requirements);
    therapy_variation = false;
    
  }
  
}

void StatesMachineNode::call_back_interaction_torque(const std_msgs::msg::Float32MultiArray& interaction_torque_msg) {
  shared_data_.interaction_torque = interaction_torque_msg;
  processData();
}

void StatesMachineNode::call_back_FSR(const std_msgs::msg::ByteMultiArray& FSR_msg) {
  shared_data_.FSR = FSR_msg;
  processData();
}

void StatesMachineNode::call_back_joints_current_target() {
  auto curr_target_message = nimble_interfaces::msg::JointsTrajectory();
  
  std::vector<float> phases;
  float curr_percent = get_step_percent();
  
  // Is there an ideal trajectory?
  if (!shared_data_.joints_trajectory.trajectory .points.empty()) {
    trajectory_msgs::msg::JointTrajectoryPoint curr_target = get_actual_joint_state(curr_percent);
    phases.push_back(curr_percent);
    curr_target_message.phase.data = phases;
    curr_target_message.trajectory.joint_names={"hipR", "kneeR","ankleR","hipL", "kneeL","ankleL"};
    curr_target_message.trajectory.points.push_back(curr_target);

    publisher_joints_target->publish(curr_target_message);

  }
}

void StatesMachineNode::call_back_joints_trajectory_timer() {
  if (!shared_data_.joints_trajectory.trajectory.points.empty()) { 
    auto joints_trajectory_msg = nimble_interfaces::msg::JointsTrajectory();  
    joints_trajectory_msg = shared_data_.joints_trajectory; // Fill in with the corresponding information
    joints_trajectory_msg.header.stamp = now();  // Header with the publication timestamp
    //joints_trajectory_msg.trajectory.joint_names={"hipR", "kneeR","ankleR","hipL", "kneeL","ankleL"};
    publisher_joints_trajectory->publish(joints_trajectory_msg);  // publish
  }
}


// Process function
void StatesMachineNode::processData() {
  // TODO: Aquí quizás habría que hacer distintas funciones de procesamiento y comprobar que existen datos de todo lo necesario con un if


  
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
