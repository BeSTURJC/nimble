#ifndef GAIT_CONTROL__GAITCONTROL_HPP_
#define GAIT_CONTROL__GAITCONTROL_HPP_

#include "rclcpp/rclcpp.hpp"
#include <cstdlib>
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "nimble_interfaces/msg/joints_trajectory.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/zmp_target.hpp"
#include "geometry_msgs/msg/point.hpp"

namespace gaitControl
{

// ***** Structs ***** // 
struct SharedData {
    nimble_interfaces::msg::JointsTrajectory joints_trajectory;
    nimble_interfaces::msg::CartesianTrajectory cartesian_trajectory;
    nimble_interfaces::msg::TherapyRequirements therapy_requirements;
};

class gaitControlNode : public rclcpp::Node
{
public:
    gaitControlNode();

private:

    // Instances	
    rclcpp::TimerBase::SharedPtr timer_joint_target_;
    SharedData shared_data_;
    std::chrono::steady_clock::time_point time_jt_received_;
     bool th_req_received;
     bool cart_tr_received;
     bool joints_tr_received;
    float prev_index;
    int pasos;
    
    // Subscribers
    rclcpp::Subscription<nimble_interfaces::msg::JointsTrajectory>::SharedPtr subscriber_joints_trajectory;
    rclcpp::Subscription<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr subscriber_cartesian_trajectory;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_therapy_requirements;
   
    // Publishers
    rclcpp::Publisher<nimble_interfaces::msg::JointsTrajectory>::SharedPtr publisher_joints_target;
    rclcpp::Publisher<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr publisher_cartesian_target;
    rclcpp::Publisher<nimble_interfaces::msg::ZMPTarget>::SharedPtr publisher_pelvis_target;

    // Subscribers callbacks
    void call_back_joints_trajectory(const nimble_interfaces::msg::JointsTrajectory & joints_trajectory_msg);
    void call_back_cartesian_trajectory(const nimble_interfaces::msg::CartesianTrajectory & cartesian_trajectory_msg);
    void call_back_therapy_requirements(const nimble_interfaces::msg::TherapyRequirements & therapy_requirements_msg);

    // Publisher functions
    float get_step_percent();
    trajectory_msgs::msg::JointTrajectoryPoint get_joint_target_from_index(float step_percent);
    std::vector<geometry_msgs::msg::Point> get_cartesian_target_from_index(float step_percent, std::vector<geometry_msgs::msg::Point> points);
    void processData();
 
     // Timer callbacks for publishers
    void call_back_current_target();
    //Timers periods
    double joints_target_ts;

};

}; // namespace stateMachine


#endif // STATE_MACHINE__STATEMACHINE_HPP_