#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cstdlib>
#include "gait_control/gaitControl.hpp"


using namespace std::chrono_literals;

namespace gaitControl {

gaitControlNode::gaitControlNode() : Node("gait_control") {
  // Possible internal parameters
  this->declare_parameter("joints_target_ts", 10.0);
  this->get_parameter("joints_target_ts",joints_target_ts);
 
  //Possible internal parameters
  this->declare_parameter("param1", 1);
  this->declare_parameter("param2", 2);

  th_req_received=false;
  cart_tr_received=false;
  joints_tr_received=false;
  prev_index=0;
    	
  // Create a subscribers 
  subscriber_cartesian_trajectory = create_subscription<nimble_interfaces::msg::CartesianTrajectory>(
  "cartesian_trajectory", 10, [this](const nimble_interfaces::msg::CartesianTrajectory msg) {
  call_back_cartesian_trajectory(msg);});

  subscriber_joints_trajectory = create_subscription<nimble_interfaces::msg::JointsTrajectory>(
  "joints_trajectory", 10, [this](const nimble_interfaces::msg::JointsTrajectory msg) {
  call_back_joints_trajectory(msg);}); 

  subscriber_therapy_requirements =
      create_subscription<nimble_interfaces::msg::TherapyRequirements>(
          "therapy_requirements", 10, [this](const nimble_interfaces::msg::TherapyRequirements msg) {
            call_back_therapy_requirements(msg); });    

  // Create a publisher
  publisher_joints_target = create_publisher<nimble_interfaces::msg::JointsTrajectory>("joints_target", 10);
  publisher_cartesian_target = create_publisher<nimble_interfaces::msg::CartesianTrajectory>("cartesian_target", 10);
  publisher_pelvis_target = create_publisher<nimble_interfaces::msg::ZMPTarget>("pelvis_target", 10);
        
  timer_joint_target_= this->create_wall_timer(std::chrono::duration<double>(joints_target_ts/1000), std::bind(&gaitControlNode::call_back_current_target, this));
        
}

// Function to convert a JointTrajectory message to a string

float gaitControlNode::get_step_percent() {

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

trajectory_msgs::msg::JointTrajectoryPoint gaitControlNode::get_joint_target_from_index(float gait_percent) {
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

std::vector<geometry_msgs::msg::Point> gaitControlNode::get_cartesian_target_from_index(float gait_percent, std::vector<geometry_msgs::msg::Point> points ){

  std::vector<geometry_msgs::msg::Point> curr_point;
  int num_points = points.size();
  float index = (static_cast<float>(gait_percent) / 100.0f) * (num_points-1);
  if (std::abs(index - static_cast<int>(index)) < 0.001) {
        curr_point.push_back(points[int(index)]); 

    } 
  else{
      // Gets the floor and ceil index
      int floorIndex = static_cast<int>(std::floor(index));
      int ceilIndex = static_cast<int>(std::ceil(index));

      // Ensure that indices are within bounds
      floorIndex = std::max(0, std::min(floorIndex, num_points - 1));
      ceilIndex = std::max(0, std::min(ceilIndex, num_points - 1));
      
      geometry_msgs::msg::Point point;
      float floor_X = points[floorIndex].x;
      float ceil_X = points[ceilIndex].x;

      point.x= (ceil_X - floor_X)*std::abs(index - static_cast<int>(index)) + floor_X;

      float floor_Y = points[floorIndex].y;
      float ceil_Y = points[ceilIndex].y;

      point.y = (ceil_Y - floor_Y)*std::abs(index - static_cast<int>(index)) + floor_Y;

      float floor_Z = points[floorIndex].z;
      float ceil_Z = points[ceilIndex].z;

      point.z = (ceil_Z - floor_Z)*std::abs(index - static_cast<int>(index)) + floor_Z;

      curr_point.push_back(point); 
  }   
  return curr_point;
}

//CALLBACKS
void gaitControlNode::call_back_cartesian_trajectory(const nimble_interfaces::msg::CartesianTrajectory& cartesian_trajectory_msg) {
  shared_data_.cartesian_trajectory = cartesian_trajectory_msg;
 cart_tr_received=true;
}

void gaitControlNode::call_back_joints_trajectory(const nimble_interfaces::msg::JointsTrajectory& joints_trajectory_msg) {
  shared_data_.joints_trajectory = joints_trajectory_msg;
  //RCLCPP_INFO(this->get_logger(), "Indicator Received: %s", joints_trajectory_msg.new_indicator ? "true" : "false");
  if (shared_data_.joints_trajectory.new_indicator){
    time_jt_received_ = std::chrono::steady_clock::now();
    RCLCPP_INFO(this->get_logger(), "Reset Time New");
    joints_tr_received=true;
    
  }
  if (shared_data_.joints_trajectory.trajectory.points.empty()) {
    time_jt_received_ = std::chrono::steady_clock::now();
    joints_tr_received=true;
    RCLCPP_INFO(this->get_logger(), "Reset Time First");
  }    
  
   
}

void gaitControlNode::call_back_therapy_requirements(const nimble_interfaces::msg::TherapyRequirements& therapy_requirements_msg) {
  shared_data_.therapy_requirements = therapy_requirements_msg;
  th_req_received=true;
    
}

void gaitControlNode::call_back_current_target() {
  
  auto curr_joint_target_message = nimble_interfaces::msg::JointsTrajectory();
  
  std::vector<float> phases;
  float curr_percent = get_step_percent();
  
  // Is there an ideal trajectory?
  if (!shared_data_.joints_trajectory.trajectory .points.empty() && !shared_data_.cartesian_trajectory.base_pelvis.empty() && th_req_received==true) {
    trajectory_msgs::msg::JointTrajectoryPoint curr_joint_target = get_joint_target_from_index(curr_percent);
    nimble_interfaces::msg::CartesianTrajectory curr_cartesian_target;
    if (prev_index>curr_percent+90){
      pasos=pasos+1;
          
    }

    //RCLCPP_INFO(this->get_logger(), "Index:%.2f, PrevIndex:%.2f, Pasos:%i",curr_percent,prev_index,pasos);
    //Fill Complete Cartesian Current Target (For Representation)
    curr_cartesian_target.left_pelvis=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.left_pelvis); 
    curr_cartesian_target.left_pelvis[0].x =curr_cartesian_target.left_pelvis[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.right_pelvis=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.right_pelvis); 
    curr_cartesian_target.right_pelvis[0].x =curr_cartesian_target.right_pelvis[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.base_pelvis =get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.base_pelvis);
    curr_cartesian_target.base_pelvis[0].x =curr_cartesian_target.base_pelvis[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.left_hip=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.left_hip); 
    curr_cartesian_target.left_hip[0].x =curr_cartesian_target.left_hip[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.right_hip=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.right_hip); 
    curr_cartesian_target.right_hip[0].x =curr_cartesian_target.right_hip[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.left_knee=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.left_knee); 
    curr_cartesian_target.left_knee[0].x =curr_cartesian_target.left_knee[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.right_knee=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.right_knee); 
    curr_cartesian_target.right_knee[0].x =curr_cartesian_target.right_knee[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.left_ankle=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.left_ankle); 
    curr_cartesian_target.left_ankle[0].x =curr_cartesian_target.left_ankle[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.right_ankle=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.right_ankle); 
    curr_cartesian_target.right_ankle[0].x =curr_cartesian_target.right_ankle[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.left_heel=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.left_heel); 
    curr_cartesian_target.left_heel[0].x =curr_cartesian_target.left_heel[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.right_heel=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.right_heel); 
    curr_cartesian_target.right_heel[0].x =curr_cartesian_target.right_heel[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.left_toe=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.left_toe); 
    curr_cartesian_target.left_toe[0].x =curr_cartesian_target.left_toe[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 

    curr_cartesian_target.right_toe=get_cartesian_target_from_index(curr_percent, shared_data_.cartesian_trajectory.right_toe); 
    curr_cartesian_target.right_toe[0].x =curr_cartesian_target.right_toe[0].x+pasos*shared_data_.cartesian_trajectory.base_pelvis.back().x; 
    //RCLCPP_INFO(this->get_logger(), "Pasos:%i",pasos);
    //RCLCPP_INFO(this->get_logger(), "End pelvis:%f",shared_data_.cartesian_trajectory.base_pelvis.back().x);
    

    phases.push_back(curr_percent);
    curr_joint_target_message.phase.data = phases;
    curr_joint_target_message.header.stamp=now();
    curr_joint_target_message.trajectory.joint_names={"hipR","kneeR", "ankleR", "hipL", "kneeL", "ankleL", "pelvisList", "pelvisTilt", "hipR_abd", "hipL_abd"};
    curr_joint_target_message.trajectory.points.push_back(curr_joint_target);

    publisher_joints_target->publish(curr_joint_target_message);
    publisher_cartesian_target->publish(curr_cartesian_target);
    //Publish pelvis SP individually

    nimble_interfaces::msg::ZMPTarget pelvis_target_msg;
    pelvis_target_msg.phase.data=phases;
    pelvis_target_msg.header.stamp=now();
    pelvis_target_msg.point=curr_cartesian_target.base_pelvis[0];
    publisher_pelvis_target->publish(pelvis_target_msg);
    prev_index=curr_percent;
  }

}


};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<gaitControl::gaitControlNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

