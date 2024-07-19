#ifndef STATE_MACHINE__STATEMACHINE_HPP_
#define STATE_MACHINE__STATEMACHINE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/frame_state.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "nimble_interfaces/msg/joints_trajectory.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "nimble_interfaces/srv/traj_generator_service.hpp"
#include "nimble_interfaces/srv/cartesian_traj_service.hpp"

namespace stateMachine
{

// ***** Structs ***** // 
struct SharedData {
    nimble_interfaces::msg::JointsTrajectory joints_trajectory;
    nimble_interfaces::msg::CartesianTrajectory cartesian_trajectory;
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
        therapy_requirements_previous.speed=0;
    
    }
};

class StatesMachineNode : public rclcpp::Node
{
public:
    StatesMachineNode();

private:

    // Instances	
    rclcpp::CallbackGroup::SharedPtr client_cb_group_; // Callback group to enable simultaneous service and node operation
    rclcpp::Client<nimble_interfaces::srv::TrajGeneratorService>::SharedPtr joints_client_; // Client for the trajectory service
    rclcpp::Client<nimble_interfaces::srv::CartesianTrajService>::SharedPtr cart_client_; // Client for the trajectory service
    rclcpp::TimerBase::SharedPtr timer_joint_trajectory_;
    SharedData shared_data_;
    bool th_req_received;
    bool meas_received;
    
    
    // Subscribers
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_joints_state;
    rclcpp::Subscription<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr subscriber_cartesian_trajectory;
    rclcpp::Subscription<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr subscriber_cartesian_state;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_state_cables;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_step_target;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_therapy_requirements;
    rclcpp::Subscription<nimble_interfaces::msg::Measurements>::SharedPtr subscriber_measurements;
    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr subscriber_interaction_torque;
    rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr subscriber_FSR;
    
    // Publishers
    rclcpp::Publisher<nimble_interfaces::msg::JointsTrajectory>::SharedPtr publisher_joints_trajectory;
    rclcpp::Publisher<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr publisher_cartesian_trajectory;
    rclcpp::Publisher<nimble_interfaces::msg::TherapyRequirements>::SharedPtr publisher_step_target;
    rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr publisher_assistLevel;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_executionMode;
    rclcpp::Publisher<std_msgs::msg::Int32MultiArray>::SharedPtr publisher_controlMode;

    // Functions
    std::string jointTrajectoryToString(const trajectory_msgs::msg::JointTrajectory::SharedPtr& joint_trajectory);
    bool check_variations_in_therapy();
    void call_TrajGenerationService(const nimble_interfaces::msg::Measurements& measurements,
    const nimble_interfaces::msg::TherapyRequirements& requirements);

    // Subscribers callbacks
    void call_back_joints_state(const sensor_msgs::msg::JointState & joint_state_msg);
    void call_back_cartesian_trajectory(const nimble_interfaces::msg::CartesianTrajectory & cartesian_trajectory_msg);
    void call_back_cartesian_state(const nimble_interfaces::msg::CartesianTrajectory & cartesian_state_msg);
    void call_back_state_cables(const sensor_msgs::msg::JointState & joint_state_cables_msg);
    void call_back_step_target(const nimble_interfaces::msg::TherapyRequirements & step_target_msg);
    void call_back_therapy_requirements(const nimble_interfaces::msg::TherapyRequirements & therapy_requirements_msg);
    void call_back_measurements(const nimble_interfaces::msg::Measurements & measurements_msg);
    void call_back_interaction_torque(const std_msgs::msg::Float32MultiArray & interaction_torque_msg);
    void call_back_FSR(const std_msgs::msg::ByteMultiArray & FSR_msg);

    void call_cartesian_traj_service(const trajectory_msgs::msg::JointTrajectory traj_response);

    // Publisher functions
    trajectory_msgs::msg::JointTrajectoryPoint get_joint_target_from_index(float step_percent);
    void processData();

    // Timer callbacks for publishers
    void call_back_joints_trajectory_timer();
    //Timers periods
    double joints_target_ts;
    double joints_trajectory_ts;
};

}; // namespace stateMachine


#endif // STATE_MACHINE__STATEMACHINE_HPP_
