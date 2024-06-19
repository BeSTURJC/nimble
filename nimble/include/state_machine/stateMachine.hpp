#ifndef STATE_MACHINE__STATEMACHINE_HPP_
#define STATE_MACHINE__STATEMACHINE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/frame_state.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include "nimble_interfaces/srv/traj_generator_service.hpp"

namespace stateMachine
{

// ***** Structs ***** // 
struct SharedData {
    trajectory_msgs::msg::JointTrajectory joints_target;
    nimble_interfaces::msg::CartesianTrajectory cartesian_target;
    nimble_interfaces::msg::CartesianTrajectory cartesian_state;
    sensor_msgs::msg::JointState joints_state;
    sensor_msgs::msg::JointState cables_state;
    nimble_interfaces::msg::TherapyRequirements step_target;
    nimble_interfaces::msg::TherapyRequirements therapy_requirements;
    nimble_interfaces::msg::Measurements measurements;
    std_msgs::msg::Float32MultiArray interaction_torque;
    std_msgs::msg::ByteMultiArray FSR;
    
    // Duplicate data from measurements and th_requirements to only request trajectory 
    // calculation service if something is modified.
    nimble_interfaces::msg::TherapyRequirements therapy_requirements_previous;
    nimble_interfaces::msg::Measurements measurements_previous;
    
    // Initialize all values to 0
    SharedData(){

	    measurements_previous.femur=0;
	    measurements_previous.tibia=0;
	    measurements_previous.height=0;
	    measurements_previous.height_ankle=0;
	    measurements_previous.distance_to_heel=0;
	    measurements_previous.distance_to_toe=0;
	    measurements_previous.depth_pelvis=0;
	    measurements_previous.width_pelvis=0;
	    therapy_requirements_previous.step_length=0;
	    therapy_requirements_previous.step_height=0;
    
    }
};

class StatesMachineNode : public rclcpp::Node
{
public:
    StatesMachineNode();

private:

    // Instances	
    rclcpp::CallbackGroup::SharedPtr client_cb_group_; // Callback group to enable simultaneous service and node operation
    rclcpp::Client<nimble_interfaces::srv::TrajGeneratorService>::SharedPtr client_; // Client for the trajectory service
    rclcpp::TimerBase::SharedPtr timer_joint_target_;
    rclcpp::TimerBase::SharedPtr timer_percent_;
    SharedData shared_data_;
    std::chrono::steady_clock::time_point time_jt_received_;

    // Subscribers
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_joints_state;
    rclcpp::Subscription<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr subscriber_cartesian_target;
    rclcpp::Subscription<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr subscriber_cartesian_state;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_state_cables;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_step_target;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_therapy_requirements;
    rclcpp::Subscription<nimble_interfaces::msg::Measurements>::SharedPtr subscriber_measurements;
    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr subscriber_interaction_torque;
    rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr subscriber_FSR;
    
    // Publishers
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr publisher_joints_target;
    rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr publisher_assistLevel;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_executionMode;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_step_percent;
    rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr publisher_controlMode;

    // Functions
    std::string jointTrajectoryToString(const trajectory_msgs::msg::JointTrajectory::SharedPtr& joint_trajectory);
    bool check_variations_in_therapy(const nimble_interfaces::msg::Measurements & measurements, const nimble_interfaces::msg::TherapyRequirements & therapy_requirements);
    void call_TrajGenerationService(const nimble_interfaces::msg::Measurements & measurements, const nimble_interfaces::msg::TherapyRequirements & requirements);

    // Subscribers callbacks
    void call_back_joints_state(const sensor_msgs::msg::JointState & joint_state_msg);
    void call_back_cartesian_target(const nimble_interfaces::msg::CartesianTrajectory & cartesian_target_msg);
    void call_back_cartesian_state(const nimble_interfaces::msg::CartesianTrajectory & cartesian_state_msg);
    void call_back_state_cables(const sensor_msgs::msg::JointState & joint_state_cables_msg);
    void call_back_step_target(const nimble_interfaces::msg::TherapyRequirements & step_target_msg);
    void call_back_therapy_requirements(const nimble_interfaces::msg::TherapyRequirements & therapy_requirements_msg);
    void call_back_measurements(const nimble_interfaces::msg::Measurements & measurements_msg);
    void call_back_interaction_torque(const std_msgs::msg::Float32MultiArray & interaction_torque_msg);
    void call_back_FSR(const std_msgs::msg::ByteMultiArray & FSR_msg);

    // Publisher functions
    int get_step_percent();
    trajectory_msgs::msg::JointTrajectoryPoint get_actual_joint_state(int step_percent);
    void processData();

    // Timer callbacks for publishers
    void step_percent_timer_callback();
    void joints_target_timer_callback();
};

}; // namespace stateMachine


#endif // STATE_MACHINE__STATEMACHINE_HPP_