#ifndef KINETIC_MODEL__KINETICMODEL_HPP_
#define KINETIC_MODEL__KINETICMODEL_HPP_

#define EIGEN_RUNTIME_NO_MALLOC
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "kinetik_model/kineticModel.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/joints_trajectory.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/int64.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"

// ***** Structs ***** // 
struct jointPosition {
    struct pos {
        std::vector<double> X;
        std::vector<double> Y;
        std::vector<double> Z;
    } R, L, base;

    std::vector<double> phase;
};


struct JointAngles {
    std::vector<double> hipR_abd;
    std::vector<double> hipL_abd;
    std::vector<double> hipR;
    std::vector<double> hipL;

    std::vector<double> kneeR;
    std::vector<double> kneeL;

    std::vector<double> ankleR;
    std::vector<double> ankleL;

    std::vector<double> pelvisList;
    std::vector<double> pelvisTilt;
    std::vector<double> phase;
};


struct JointAngle {
    double hipR_abd{0.0};
    double hipR{0.0};
    double kneeR{0.0};
    double ankleR{0.0};
    double hipL_abd{0.0};
    double hipL{0.0};
    double kneeL{0.0};
    double kneeL_flex{0.0};
    double kneeR_flex{0.0};
    double ankleR_flex{0.0};
    double ankleL{0.0};
    double pelvisList{0.0};
    double hipR_flex{0.0};
    double hipL_flex{0.0};
    double pelvisTilt{0.0};
    double ankleL_flex{0.0};
    double phase{0.0};
};


struct Leg {
    Eigen::VectorXd X;
    Eigen::VectorXd Y;
    Eigen::VectorXd Z;

    Leg() : X(Eigen::VectorXd::Zero(0)),
            Y(Eigen::VectorXd::Zero(0)),
            Z(Eigen::VectorXd::Zero(0)) {}
};

struct ExoPositions {
    bool initialized{true};
    struct RefSystems {
        Eigen::Vector3d base{0.0, 0.0, 0.0};
        Eigen::Vector3d leftPelvis{0.0, 0.0, 0.0};
        Eigen::Vector3d leftHip{0.0, 0.0, 0.0};
        Eigen::Vector3d leftKnee{0.0, 0.0, 0.0};
        Eigen::Vector3d leftAnkle{0.0, 0.0, 0.0};
        Eigen::Vector3d leftFoot{0.0, 0.0, 0.0};
        Eigen::Vector3d leftToe{0.0, 0.0, 0.0};
        Eigen::Vector3d leftHeel{0.0, 0.0, 0.0};
        Eigen::Vector3d rightPelvis{0.0, 0.0, 0.0};
        Eigen::Vector3d rightHip{0.0, 0.0, 0.0};
        Eigen::Vector3d rightKnee{0.0, 0.0, 0.0};
        Eigen::Vector3d rightAnkle{0.0, 0.0, 0.0};
        Eigen::Vector3d rightFoot{0.0, 0.0, 0.0};
        Eigen::Vector3d rightToe{0.0, 0.0, 0.0};
        Eigen::Vector3d rightHeel{0.0, 0.0, 0.0};
    } refSystems;

    Leg leftLeg;
    Leg rightLeg;

    // Defines contact points
    struct ContactPoint {
        std::string name;
        double X{0};
        double Y{0};
        double Z{0};
    } contactPoint;

};


namespace kineticModel
{

class KinematicModelNode : public rclcpp::Node 
{
public:
    KinematicModelNode();

private:
    int bufferSize;
    bool trajectory_received=false;
    JointAngles JointStateBuffer;


    // **** Atributes **** //
    // Subscribers
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_joints_state_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_state_cables_;
    rclcpp::Subscription<nimble_interfaces::msg::Measurements>::SharedPtr subscriber_measurements_;

    // Publishers
    rclcpp::Publisher<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr publisher_cartState_;
    

    // Message data for publishers
    nimble_interfaces::msg::CartesianTrajectory cartesian_state_buffer;

    // Message data for subscribers
    nimble_interfaces::msg::Measurements measurements_;

    // **** Functions **** //
    // Callback functions 
    void call_back_joints_trajectory(const nimble_interfaces::msg::JointsTrajectory & joint_trajectory_msg);
    void call_back_joints_state(const sensor_msgs::msg::JointState &joint_state_msg);
    void call_back_state_cables(const sensor_msgs::msg::JointState & joint_state_cables_msg);
    void call_back_measurements(const nimble_interfaces::msg::Measurements & measurements_msg);

    // Struct functions
    void fillJointAngles(const sensor_msgs::msg::JointState& joint_state_msg, JointAngles& joint_state_ang);
    
    template <typename T>
    void updateCartesianState(std::vector<T>& target, const T& value, std::size_t bufferSize);
    
    void fill_joint_state( jointPosition &pelvisPosition, jointPosition &hipPositions,
        jointPosition &anklePositions, jointPosition &heelsPositions,
        jointPosition &toePositions, jointPosition &kneePositions,
        nimble_interfaces::msg::CartesianTrajectory &cartesian_trajectory);

    void resize_joint_position(jointPosition &position, int size);
    //void fill_jointPos_with_exopos(jointPosition& joint_pos, Eigen::Vector3d left, Eigen::Vector3d right, int index);
    void fill_jointPos_with_exopos(jointPosition& joint_pos, Eigen::Vector3d left, Eigen::Vector3d right, int index, float z_error);
    
    // Matrix operations
    Eigen::Vector3d position_fromSR(const Eigen::Matrix4d& T);
    Eigen::Vector3d position_fromSR_pelvisTilt(const Eigen::Matrix4d& T);
    Eigen::Matrix4d DH_deg(double theta, double d, double a, double alpha);

    // Main functions
    Eigen::Vector3d gaitFeatureExtraction(  
        const std::vector<double>& ankleIpsi_X,
        const std::vector<double>& ankleContra_X,
        const std::vector<double>& ankleIpsi_Z,
        const std::vector<double>& ankleContra_Z,
        const std::vector<double>& heelIpsi_Z,
        const std::vector<double>& heelContra_Z,
        const std::vector<double>& toeIpsi_Z,
        const std::vector<double>& toeContra_Z,
        const std::vector<double>& phase);

    void exoKinematicModel_pelvisMov(
        const JointAngle& jointAngles,
        const nimble_interfaces::msg::Measurements& measurements,
        const ExoPositions& previousExoPosition,
        ExoPositions& exoPositions_fixedBase,
        ExoPositions& exoPositions_movilBase);

    
    void executeKinematicModel(JointAngles& jointAng,
            nimble_interfaces::msg::Measurements& measurements,
            nimble_interfaces::msg::CartesianTrajectory& cartesian_trajectory, 
            nimble_interfaces::msg::TherapyRequirements& step_target, bool extr_params);
};


}; // namespace kineticModel

#endif // KINETIC_MODEL__KINETICMODEL_HPP_
