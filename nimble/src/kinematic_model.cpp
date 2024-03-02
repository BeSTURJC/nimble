#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/cartesian_full_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include "kinetik_model/kineticModel.hpp"

using namespace std::chrono_literals;


class KinematicModelNode : public rclcpp::Node
{
public:
    KinematicModelNode() : Node("kinematic_model")
    {	
    	// Possible internal parameters
        this->declare_parameter("contact_point", 1);
    	this->declare_parameter("param2", 2);
    	
        // Creates subscribers 
        subscriber_joints_target_ = create_subscription<trajectory_msgs::msg::JointTrajectory>(
            "joints_target", 10,
            [this](const trajectory_msgs::msg::JointTrajectory msg) {
                call_back_joints_target(msg);
            });
            
        subscriber_joints_state_ = create_subscription<sensor_msgs::msg::JointState>(
            "joints_state", 10,
            [this](const sensor_msgs::msg::JointState msg) {
                call_back_joints_state(msg);
            }); 
        subscriber_state_cables_ = create_subscription<sensor_msgs::msg::JointState>(
            "cables_state", 10,
            [this](const sensor_msgs::msg::JointState msg) {
                
                call_back_state_cables(msg);
            });
            
        subscriber_measurements_ = create_subscription<nimble_interfaces::msg::Measurements>(
            "measurements", 10,
            [this](const nimble_interfaces::msg::Measurements msg) {
                
                call_back_measurements(msg);
            });  
            
                   
        // Creates publishers
        publisher_stepTarget_ = create_publisher<nimble_interfaces::msg::TherapyRequirements>("step_target", 10);
        publisher_cartTarget_ = create_publisher<nimble_interfaces::msg::CartesianFullTrajectory>("cartesian_full_target", 10);
        publisher_cartState_ = create_publisher<nimble_interfaces::msg::CartesianFullTrajectory>("cartesian_state", 10);
    }

private:

    //Subscribers	
    rclcpp::Subscription<trajectory_msgs::msg::JointTrajectory>::SharedPtr subscriber_joints_target_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_joints_state_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_state_cables_;
    rclcpp::Subscription<nimble_interfaces::msg::Measurements>::SharedPtr subscriber_measurements_;
    
    //Publishers
    rclcpp::Publisher<nimble_interfaces::msg::CartesianFullTrajectory>::SharedPtr publisher_cartTarget_;
    rclcpp::Publisher<nimble_interfaces::msg::CartesianFullTrajectory>::SharedPtr publisher_cartState_;
    rclcpp::Publisher<nimble_interfaces::msg::TherapyRequirements>::SharedPtr publisher_stepTarget_;

    // Data publisher timer
    rclcpp::TimerBase::SharedPtr timer_;

    // Message data for publishers
    nimble_interfaces::msg::CartesianFullTrajectory cartesian_state_;

    // Message data for subscribers
    nimble_interfaces::msg::Measurements measurements_;
    
    //Callbacks	        
    void call_back_joints_target(const trajectory_msgs::msg::JointTrajectory & joint_target_msg) 
    {   
        // Subscriber message
        kineticModel::JointAngles jointAng;

        // Publisher messages
        nimble_interfaces::msg::CartesianFullTrajectory cartesian_target;
        nimble_interfaces::msg::TherapyRequirements step_target;

        // * ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
        // Resizes
        int size = joint_target_msg.points.size();
        jointAng.hipR.resize(size);
        jointAng.hipR_abd.resize(size);
        jointAng.hipL.resize(size);
        jointAng.hipL_abd.resize(size);
        jointAng.kneeR.resize(size);
        jointAng.kneeL.resize(size);
        jointAng.ankleR.resize(size);
        jointAng.ankleL.resize(size);
        jointAng.pelvisList.resize(size);
        jointAng.pelvisTilt.resize(size);
        jointAng.phase.resize(size);

        // Fills joint ang
        for (int i = 0; i < size; i++){

            jointAng.hipR[i] = joint_target_msg.points[i].positions[0];
            jointAng.hipL[i] = joint_target_msg.points[i].positions[1];

            jointAng.kneeR[i] = joint_target_msg.points[i].positions[2];
            jointAng.kneeL[i] = joint_target_msg.points[i].positions[3];

            jointAng.ankleR[i] = joint_target_msg.points[i].positions[4];
            jointAng.ankleL[i] = joint_target_msg.points[i].positions[5];
        }

        // Executes the kinematic model
        kineticModel::executeKinematicModel(jointAng, measurements_, cartesian_target, step_target);
    
        // Publishes the data
        publisher_cartTarget_->publish(cartesian_target);
        publisher_stepTarget_->publish(step_target);
    }
    
    void call_back_joints_state(const sensor_msgs::msg::JointState &joint_state_msg) {
        const int bufferSize = 100;


        // TODO: IF TOPIC %STEP IS %5 STORE ONE POSITION 

        kineticModel::JointAngles joint_state_ang;
        kineticModel::fillJointAngles(joint_state_msg, joint_state_ang);

        nimble_interfaces::msg::CartesianFullTrajectory cartesian_actual_state;
        nimble_interfaces::msg::TherapyRequirements step_target;

        // Uses a Ring Buffer to pop back the last elements of the buffer
        kineticModel::executeKinematicModel(joint_state_ang, measurements_, cartesian_actual_state, step_target);
        kineticModel::updateCartesianState(cartesian_state_.right_pelvis, cartesian_actual_state.right_pelvis[0], bufferSize);
        kineticModel::updateCartesianState(cartesian_state_.left_pelvis, cartesian_actual_state.right_pelvis[0], bufferSize);
        kineticModel::updateCartesianState(cartesian_state_.base_pelvis, cartesian_actual_state.right_pelvis[0], bufferSize);
        kineticModel::updateCartesianState(cartesian_state_.right_malleolus, cartesian_actual_state.right_pelvis[0], bufferSize);
        kineticModel::updateCartesianState(cartesian_state_.left_malleolus, cartesian_actual_state.right_pelvis[0], bufferSize);

        publisher_cartState_->publish(cartesian_state_);
    }
    
    void call_back_state_cables(const sensor_msgs::msg::JointState & joint_state_cables_msg) 
    {
        // shared_data_.cables_state = joint_state_cables_msg;
    }

    // Always updates measurements callback
    void call_back_measurements(const nimble_interfaces::msg::Measurements & measurements_msg) 
    {
        measurements_ = measurements_msg;
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<KinematicModelNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

