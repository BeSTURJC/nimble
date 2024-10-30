#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iterator>

#include "kinetik_model/kineticModel.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/joints_trajectory.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/int64.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "geometry_msgs/msg/point.hpp"

using namespace std::chrono_literals;

namespace kineticModel 
{

// *** Class initializer *** // 
KinematicModelNode::KinematicModelNode() : Node("kinematic_model") {
  // Possible internal parameters
  this->declare_parameter("contact_point", 1);
  this->declare_parameter("param2", 2);

  
    // Creates subscribers
  subscriber_joints_state_ = create_subscription<sensor_msgs::msg::JointState>(
      "joints_state", 10, [this](const sensor_msgs::msg::JointState msg) {
        call_back_joints_state(msg);
      });

  subscriber_state_cables_ = create_subscription<sensor_msgs::msg::JointState>(
      "cables_state", 10, [this](const sensor_msgs::msg::JointState msg) {
        call_back_state_cables(msg);
      });

  subscriber_measurements_ =
      create_subscription<nimble_interfaces::msg::Measurements>(
          "measurements", 10,[this](const nimble_interfaces::msg::Measurements msg) {
            call_back_measurements(msg);
          });

  // Creates publishers
  publisher_cartState_ =
      create_publisher<nimble_interfaces::msg::CartesianTrajectory>("cartesian_state", 10);
}

// *** Callbacks *** //
void KinematicModelNode::call_back_joints_state(
    const sensor_msgs::msg::JointState &joint_state_msg) {
    
    if (!joint_state_msg.position.empty()) { 
            //RCLCPP_INFO(this->get_logger(), "JOINT STATE RECEIVED");		
	    JointAngles curr_jointAng;
	    //Fill structure with current angles from Exo  
	    this->fillJointAngles(joint_state_msg, curr_jointAng);
	    
	    //Pelvis List Will be filled with joint_state_cables_msg if existing
	    if (!cables_state_.position.empty()) { curr_jointAng.pelvisList.push_back(cables_state_.position[0]);}
	    else{curr_jointAng.pelvisList.push_back(0); }
	    
	    curr_jointAng.pelvisTilt.push_back(0);
	    curr_jointAng.hipR_abd.push_back(0);
	    curr_jointAng.hipL_abd.push_back(0);

	    nimble_interfaces::msg::CartesianTrajectory cartesian_actual_state;
	    nimble_interfaces::msg::TherapyRequirements step_target;

	    bool extract_features=false;
	    //RCLCPP_INFO(this->get_logger(), "Previous Position:%s",last_exoPositions.initialized ? "true" : "false");
	    this->executeKinematicModel(curr_jointAng, measurements_,
		                                cartesian_actual_state);
	    publisher_cartState_->publish(cartesian_actual_state);

   } 
   
}

void KinematicModelNode::call_back_state_cables(
    const sensor_msgs::msg::JointState &joint_state_cables_msg) {
  	cables_state_ = joint_state_cables_msg;
  	
}
// Always updates measurements callback
void KinematicModelNode::call_back_measurements(
    const nimble_interfaces::msg::Measurements &measurements_msg) {
    measurements_ = measurements_msg;
}



// ***** Structs functions ***** //
void KinematicModelNode::fillJointAngles(
    const sensor_msgs::msg::JointState &joint_state_msg,
    JointAngles &joint_state_ang) {

  joint_state_ang.hipR.push_back(joint_state_msg.position[0]);
  joint_state_ang.kneeR.push_back(joint_state_msg.position[1]);
  joint_state_ang.ankleR.push_back(joint_state_msg.position[2]);
  joint_state_ang.hipL.push_back(joint_state_msg.position[3]);
  joint_state_ang.kneeL.push_back(joint_state_msg.position[4]);
  joint_state_ang.ankleL.push_back(joint_state_msg.position[5]);

}

void KinematicModelNode::fill_joint_state(
    jointPosition &pelvisPosition,
    jointPosition &hipPositions,
    jointPosition &anklePositions,
    jointPosition &heelsPositions,
    jointPosition &toePositions,
    jointPosition &kneePositions,
    nimble_interfaces::msg::CartesianTrajectory &cartesian_trajectory) {

  // Resizes the publisher message for all articulations
  cartesian_trajectory.right_pelvis.resize(pelvisPosition.R.X.size());
  cartesian_trajectory.left_pelvis.resize(pelvisPosition.L.X.size());
  cartesian_trajectory.base_pelvis.resize(pelvisPosition.base.X.size());
  cartesian_trajectory.right_hip.resize(hipPositions.R.X.size());
  cartesian_trajectory.left_hip.resize(hipPositions.L.X.size());
  cartesian_trajectory.right_ankle.resize(anklePositions.R.X.size());
  cartesian_trajectory.left_ankle.resize(anklePositions.L.X.size());
  cartesian_trajectory.right_heel.resize(heelsPositions.R.X.size());
  cartesian_trajectory.left_heel.resize(heelsPositions.L.X.size());
  cartesian_trajectory.right_toe.resize(toePositions.R.X.size());
  cartesian_trajectory.left_toe.resize(toePositions.L.X.size());
  cartesian_trajectory.right_knee.resize(kneePositions.R.X.size());
  cartesian_trajectory.left_knee.resize(kneePositions.L.X.size());

  // Optimized assignment loop for all articulations
  auto fill_cartesian_positions = [](auto& positions, auto& target) {
    for (size_t i = 0; i < positions.X.size(); ++i) {
      target[i].x = positions.X[i];
      target[i].y = positions.Y[i];
      target[i].z = positions.Z[i];
    }
  };

  fill_cartesian_positions(pelvisPosition.R, cartesian_trajectory.right_pelvis);
  fill_cartesian_positions(pelvisPosition.L, cartesian_trajectory.left_pelvis);
  fill_cartesian_positions(pelvisPosition.base, cartesian_trajectory.base_pelvis);
  fill_cartesian_positions(hipPositions.R, cartesian_trajectory.right_hip);
  fill_cartesian_positions(hipPositions.L, cartesian_trajectory.left_hip);
  fill_cartesian_positions(anklePositions.R, cartesian_trajectory.right_ankle);
  fill_cartesian_positions(anklePositions.L, cartesian_trajectory.left_ankle);
  fill_cartesian_positions(heelsPositions.R, cartesian_trajectory.right_heel);
  fill_cartesian_positions(heelsPositions.L, cartesian_trajectory.left_heel);
  fill_cartesian_positions(toePositions.R, cartesian_trajectory.right_toe);
  fill_cartesian_positions(toePositions.L, cartesian_trajectory.left_toe);
  fill_cartesian_positions(kneePositions.R, cartesian_trajectory.right_knee);
  fill_cartesian_positions(kneePositions.L, cartesian_trajectory.left_knee);
}

void KinematicModelNode::resize_joint_position(
    jointPosition &position, int size) {
        
  position.R.X.resize(size);
  position.R.Y.resize(size);
  position.R.Z.resize(size);
  position.base.X.resize(size);
  position.base.Y.resize(size);
  position.base.Z.resize(size);
  position.L.X.resize(size);
  position.L.Y.resize(size);
  position.L.Z.resize(size);
  position.phase.resize(size);
}

void KinematicModelNode::fill_jointPos_with_exopos(
    jointPosition &joint_pos, Eigen::Vector3d left,
    Eigen::Vector3d right, int index, float z_error) {

  joint_pos.L.X[index] = left[0];
  joint_pos.L.Y[index] = left[1];
  joint_pos.L.Z[index] = left[2] + z_error;

  joint_pos.R.X[index] = right[0];
  joint_pos.R.Y[index] = right[1];
  joint_pos.R.Z[index] = right[2] + z_error;
}



// ******* Matrix operations***** //
Eigen::Vector3d KinematicModelNode::position_fromSR(const Eigen::Matrix4d &T) {

  Eigen::Vector3d pos;
  pos(0) = T(0, 3);
  pos(1) = -T(2, 3);
  pos(2) = T(1, 3);

  return pos;
}

Eigen::Vector3d KinematicModelNode::position_fromSR_pelvisTilt(
    const Eigen::Matrix4d &T) {

  Eigen::Vector3d pos;

  pos(0) = -T(2, 3);
  pos(1) = -T(0, 3);
  pos(2) = T(1, 3);

  return pos;
}

Eigen::Matrix4d KinematicModelNode::DH_deg(double theta, double d, double a,
                                           double alpha) {
  Eigen::Matrix4d trans_Z, trans_X;

  // Converts to radians
  double thetaRads = theta * 3.14 /  180;
  double alphaRads = alpha * 3.14 / 180;

  // Z-axis transformation matrix
  trans_Z << cos(thetaRads), -sin(thetaRads), 0, 0, sin(thetaRads), cos(thetaRads), 0, 0, 0, 0,
      1, d, 0, 0, 0, 1;

  // X-axis transformation matrix
  trans_X << 1, 0, 0, a, 0, cos(alphaRads), -sin(alphaRads), 0, 0, sin(alphaRads),
      cos(alphaRads), 0, 0, 0, 0, 1;

  Eigen::Matrix4d A = trans_Z * trans_X;

  return A;
}

// ***** Main functions ***** //
void KinematicModelNode::exoKinematicModel_pelvisMov(const JointAngle& jointAngles, 
        const nimble_interfaces::msg::Measurements& measurements, 
        ExoPositions& exoPositions_fixedBase, ExoPositions& exoPositions_movilBase) {
    
    //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Cont Point Before: %s",last_exoPositions.contactPoint.name.c_str());
    // Model for the left leg
    Eigen::Matrix4d A0_L = DH_deg(jointAngles.pelvisList, 0, -measurements.width_pelvis/2, 0);
    Eigen::Matrix4d A1_L = DH_deg((-jointAngles.hipL_abd)-90, -measurements.depth_pelvis, 0, -90);
    Eigen::Matrix4d A2_L = DH_deg(jointAngles.hipL+jointAngles.pelvisTilt, 0, measurements.femur, -180);
    Eigen::Matrix4d A3_L = DH_deg(jointAngles.kneeL, 0, measurements.tibia, 180);
    Eigen::Matrix4d A4_L = DH_deg(jointAngles.ankleL, 0, measurements.height_ankle, -90);
    Eigen::Matrix4d A5_toeL = DH_deg(0, measurements.distance_to_toe, 0, 0);
    Eigen::Matrix4d A5_heelL = DH_deg(0, -measurements.distance_to_heel, 0, 0);
    
    Eigen::Matrix4d S_leftPelvis = A0_L;
    Eigen::Matrix4d S_leftHip = S_leftPelvis * A1_L;
    Eigen::Matrix4d S_leftKnee = S_leftHip * A2_L;
    Eigen::Matrix4d S_leftAnkle = S_leftKnee * A3_L;
    Eigen::Matrix4d S_leftFoot = S_leftAnkle * A4_L;
    Eigen::Matrix4d S_leftToe = S_leftFoot * A5_toeL;
    Eigen::Matrix4d S_leftHeel = S_leftFoot * A5_heelL;

    // Model for the right leg
    Eigen::Matrix4d A0_R = DH_deg(jointAngles.pelvisList, 0, measurements.width_pelvis/2, 0);
    Eigen::Matrix4d A1_R = DH_deg(jointAngles.hipR_abd-90, -measurements.depth_pelvis, 0, -90);
    Eigen::Matrix4d A2_R = DH_deg(jointAngles.hipR+jointAngles.pelvisTilt, 0, measurements.femur, -180);
    Eigen::Matrix4d A3_R = DH_deg(jointAngles.kneeR, 0, measurements.tibia, 180);
    Eigen::Matrix4d A4_R = DH_deg(jointAngles.ankleR, 0, measurements.height_ankle, -90);
    Eigen::Matrix4d A5_toeR = DH_deg(0, measurements.distance_to_toe, 0, 0);
    Eigen::Matrix4d A5_heelR = DH_deg(0, -measurements.distance_to_heel, 0, 0);

    Eigen::Matrix4d S_rightPelvis = A0_R;
    Eigen::Matrix4d S_rightHip = S_rightPelvis * A1_R;
    Eigen::Matrix4d S_rightKnee = S_rightHip * A2_R;
    Eigen::Matrix4d S_rightAnkle = S_rightKnee * A3_R;
    Eigen::Matrix4d S_rightFoot = S_rightAnkle * A4_R;
    Eigen::Matrix4d S_rightToe = S_rightFoot * A5_toeR;
    Eigen::Matrix4d S_rightHeel = S_rightFoot * A5_heelR;

    // Fixed base reference 
    exoPositions_fixedBase.refSystems.base << 0, 0, 0;

    // Left leg
    exoPositions_fixedBase.refSystems.leftPelvis = position_fromSR_pelvisTilt(S_leftPelvis);
    exoPositions_fixedBase.refSystems.leftHip = position_fromSR_pelvisTilt(S_leftHip);
    exoPositions_fixedBase.refSystems.leftKnee = position_fromSR_pelvisTilt(S_leftKnee);
    exoPositions_fixedBase.refSystems.leftAnkle = position_fromSR_pelvisTilt(S_leftAnkle);
    exoPositions_fixedBase.refSystems.leftFoot = position_fromSR_pelvisTilt(S_leftFoot);
    exoPositions_fixedBase.refSystems.leftToe = position_fromSR_pelvisTilt(S_leftToe);
    exoPositions_fixedBase.refSystems.leftHeel = position_fromSR_pelvisTilt(S_leftHeel);

    // Right leg
    exoPositions_fixedBase.refSystems.rightPelvis = position_fromSR_pelvisTilt(S_rightPelvis);
    exoPositions_fixedBase.refSystems.rightHip = position_fromSR_pelvisTilt(S_rightHip);
    exoPositions_fixedBase.refSystems.rightKnee = position_fromSR_pelvisTilt(S_rightKnee);
    exoPositions_fixedBase.refSystems.rightAnkle = position_fromSR_pelvisTilt(S_rightAnkle);
    exoPositions_fixedBase.refSystems.rightFoot = position_fromSR_pelvisTilt(S_rightFoot);
    exoPositions_fixedBase.refSystems.rightToe = position_fromSR_pelvisTilt(S_rightToe);
    exoPositions_fixedBase.refSystems.rightHeel = position_fromSR_pelvisTilt(S_rightHeel);

    // Looking for the contact point
    std::vector<Eigen::Vector3d> refSys_feet = {exoPositions_fixedBase.refSystems.leftHeel,
                                                exoPositions_fixedBase.refSystems.leftToe,
                                                exoPositions_fixedBase.refSystems.rightHeel, 
                                                exoPositions_fixedBase.refSystems.rightToe};

    int minIndex = 0;
  
    // Search's the smaller Z
    for (size_t i = 1; i < refSys_feet.size(); ++i) {
        if (refSys_feet[i].z() < refSys_feet[minIndex].z()) {
            minIndex = i;
        }
    }

    double zMin = refSys_feet[minIndex].z();
    
    auto last_error = last_exoPositions.refSystems.leftHeel;
    // Determine the point of contact
    switch (minIndex) {
        case 0:
            exoPositions_movilBase.contactPoint.name = "leftHeel";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.leftHeel(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.leftHeel(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.leftHeel(2);

            //auto last_error = last_exoPositions.refSystems.leftHeel;
            break;
        case 1:
            exoPositions_movilBase.contactPoint.name = "leftToe";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.leftToe(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.leftToe(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.leftToe(2);

            last_error = last_exoPositions.refSystems.leftToe;
            break;
        case 2:
            exoPositions_movilBase.contactPoint.name = "rightHeel";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.rightHeel(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.rightHeel(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.rightHeel(2);

            last_error = last_exoPositions.refSystems.rightHeel;
            break;
        case 3:
            exoPositions_movilBase.contactPoint.name = "rightToe";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.rightToe(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.rightToe(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.rightToe(2);

            last_error = last_exoPositions.refSystems.rightToe;
            break;
    }

    
    // Error correction
    Eigen::Vector3d offset;
    if (last_exoPositions.initialized) {
        // Considers the last point
        offset << exoPositions_movilBase.contactPoint.X - last_error(0),
            exoPositions_movilBase.contactPoint.Y - last_error(1),
            zMin;    
            

    } else{
        Eigen::Vector3d initialOffset(0, 0, zMin);
        offset=initialOffset;    
    }

    // Apply the correction to all references in the system 
    exoPositions_movilBase.refSystems.base = exoPositions_fixedBase.refSystems.base - offset;
    exoPositions_movilBase.refSystems.leftPelvis = exoPositions_fixedBase.refSystems.leftPelvis - offset;
    exoPositions_movilBase.refSystems.leftHip = exoPositions_fixedBase.refSystems.leftHip - offset;
    exoPositions_movilBase.refSystems.leftKnee = exoPositions_fixedBase.refSystems.leftKnee - offset;
    exoPositions_movilBase.refSystems.leftAnkle = exoPositions_fixedBase.refSystems.leftAnkle - offset;
    exoPositions_movilBase.refSystems.leftFoot = exoPositions_fixedBase.refSystems.leftFoot - offset;
    exoPositions_movilBase.refSystems.leftToe = exoPositions_fixedBase.refSystems.leftToe - offset;
    exoPositions_movilBase.refSystems.leftHeel = exoPositions_fixedBase.refSystems.leftHeel - offset;

    exoPositions_movilBase.refSystems.rightPelvis = exoPositions_fixedBase.refSystems.rightPelvis - offset;
    exoPositions_movilBase.refSystems.rightHip = exoPositions_fixedBase.refSystems.rightHip - offset;
    exoPositions_movilBase.refSystems.rightKnee = exoPositions_fixedBase.refSystems.rightKnee - offset;
    exoPositions_movilBase.refSystems.rightAnkle = exoPositions_fixedBase.refSystems.rightAnkle - offset;
    exoPositions_movilBase.refSystems.rightFoot = exoPositions_fixedBase.refSystems.rightFoot - offset;
    exoPositions_movilBase.refSystems.rightToe = exoPositions_fixedBase.refSystems.rightToe - offset;
    exoPositions_movilBase.refSystems.rightHeel = exoPositions_fixedBase.refSystems.rightHeel - offset;
    
    //Update the coordinates of the point of contact
    exoPositions_movilBase.contactPoint.X -= offset.x();
    exoPositions_movilBase.contactPoint.Y -= offset.y();
    exoPositions_movilBase.contactPoint.Z -= offset.z();

    //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Cont Point: %s, AnkleX:%f",last_exoPositions.contactPoint.name.c_str(),exoPositions_movilBase.refSystems.rightToe(0));

      
    // Generate output variables for fixed base
    Eigen::MatrixXd posExo_L_fixedBase(3, 8);
    posExo_L_fixedBase << exoPositions_fixedBase.refSystems.base,
                        exoPositions_fixedBase.refSystems.leftPelvis,
                        exoPositions_fixedBase.refSystems.leftHip,
                        exoPositions_fixedBase.refSystems.leftKnee,
                        exoPositions_fixedBase.refSystems.leftAnkle,
                        exoPositions_fixedBase.refSystems.leftHeel,
                        exoPositions_fixedBase.refSystems.leftToe,
                        exoPositions_fixedBase.refSystems.leftAnkle;

    exoPositions_fixedBase.leftLeg.X = posExo_L_fixedBase.row(0);
    exoPositions_fixedBase.leftLeg.Y = posExo_L_fixedBase.row(1);
    exoPositions_fixedBase.leftLeg.Z = posExo_L_fixedBase.row(2);

    Eigen::MatrixXd posExo_R_fixedBase(3, 8);
    posExo_R_fixedBase << exoPositions_fixedBase.refSystems.base,
                           exoPositions_fixedBase.refSystems.rightPelvis,
                           exoPositions_fixedBase.refSystems.rightHip,
                           exoPositions_fixedBase.refSystems.rightKnee,
                           exoPositions_fixedBase.refSystems.rightAnkle,
                           exoPositions_fixedBase.refSystems.rightHeel,
                           exoPositions_fixedBase.refSystems.rightToe,
                           exoPositions_fixedBase.refSystems.rightAnkle;

    exoPositions_fixedBase.rightLeg.X = posExo_R_fixedBase.row(0);
    exoPositions_fixedBase.rightLeg.Y = posExo_R_fixedBase.row(1);
    exoPositions_fixedBase.rightLeg.Z = posExo_R_fixedBase.row(2);

    // Generate output variables for mobile base
    Eigen::MatrixXd posExo_L_movilBase(3, 8);
    posExo_L_movilBase << exoPositions_movilBase.refSystems.base,
                           exoPositions_movilBase.refSystems.leftPelvis,
                           exoPositions_movilBase.refSystems.leftHip,
                           exoPositions_movilBase.refSystems.leftKnee,
                           exoPositions_movilBase.refSystems.leftAnkle,
                           exoPositions_movilBase.refSystems.leftHeel,
                           exoPositions_movilBase.refSystems.leftToe,
                           exoPositions_movilBase.refSystems.leftAnkle;

    exoPositions_movilBase.leftLeg.X = posExo_L_movilBase.row(0);
    exoPositions_movilBase.leftLeg.Y = posExo_L_movilBase.row(1);
    exoPositions_movilBase.leftLeg.Z = posExo_L_movilBase.row(2);

    Eigen::MatrixXd posExo_R_movilBase(3, 8);
    posExo_R_movilBase << exoPositions_movilBase.refSystems.base,
                           exoPositions_movilBase.refSystems.rightPelvis,
                           exoPositions_movilBase.refSystems.rightHip,
                           exoPositions_movilBase.refSystems.rightKnee,
                           exoPositions_movilBase.refSystems.rightAnkle,
                           exoPositions_movilBase.refSystems.rightHeel,
                           exoPositions_movilBase.refSystems.rightToe,
                           exoPositions_movilBase.refSystems.rightAnkle;

    exoPositions_movilBase.rightLeg.X = posExo_R_movilBase.row(0);
    exoPositions_movilBase.rightLeg.Y = posExo_R_movilBase.row(1);
    exoPositions_movilBase.rightLeg.Z = posExo_R_movilBase.row(2);
  
    // RCLCPP_INFO_STREAM(this->get_logger(), "Offset: '" << exoPositions_movilBase.refSystems.leftPelvis << "'"); 
}

void KinematicModelNode::executeKinematicModel(JointAngles& jointAng,
            nimble_interfaces::msg::Measurements& measurements,
            nimble_interfaces::msg::CartesianTrajectory& cartesian_trajectory)
{ 
  int numPoints = jointAng.hipR.size();
      
  // Theres no joint data received, return
  if (numPoints == 0) {
      return;
  }
      
   
  // Initializes all the arrays of each jointPosition structure
  jointPosition pelvisPosition;
  resize_joint_position(pelvisPosition, numPoints);

  jointPosition kneePositions;
  resize_joint_position(kneePositions, numPoints);

  jointPosition hipPositions;
  resize_joint_position(hipPositions, numPoints);

  jointPosition anklePositions;
  resize_joint_position(anklePositions, numPoints);

  jointPosition heelsPositions;
  resize_joint_position(heelsPositions, numPoints);

  jointPosition toePositions;
  resize_joint_position(toePositions, numPoints);

  for (int i = 0; i < numPoints; ++i) {
    ExoPositions exoPositions_fixedBase, exoPositions;

    // Set joint angles
    JointAngle q_model;
    
    q_model.hipR = jointAng.hipR[i];
    q_model.hipL = jointAng.hipL[i];
        
    q_model.kneeL = jointAng.kneeL[i];
    q_model.kneeR = jointAng.kneeR[i];

    q_model.ankleR = jointAng.ankleR[i];
    q_model.ankleL = jointAng.ankleL[i];

    q_model.pelvisList = jointAng.pelvisList[i];
    q_model.pelvisTilt = jointAng.pelvisTilt[i];

    q_model.hipR_abd = jointAng.hipR_abd[i];
    q_model.hipL_abd = jointAng.hipL_abd[i];

    q_model.hipR_abd = jointAng.hipR_abd[i];
    q_model.hipL_abd = jointAng.hipL_abd[i];

    // Determine contact point
    if (i == 0) {
        if (q_model.hipR > q_model.hipL) {
            exoPositions.contactPoint.name = "rightHeel";
        } else {
            exoPositions.contactPoint.name = "leftHeel";
        }
        exoPositions.contactPoint.X = 0;
        exoPositions.contactPoint.Y = measurements.width_pelvis * 0.5;
        exoPositions.contactPoint.Z = 0;
    } 

    // Kinematic model of the pelvis movement
    this->exoKinematicModel_pelvisMov(q_model, measurements,exoPositions_fixedBase, exoPositions);

       
    // Store positions
    // Rebases for positive values
    float z_error = measurements.femur + measurements.tibia + measurements.distance_to_heel + measurements.distance_to_toe;
    z_error = 0;
    // --Pelvis positions
    this->fill_jointPos_with_exopos(pelvisPosition, exoPositions.refSystems.leftPelvis, 
                                            exoPositions.refSystems.rightPelvis, i, z_error);

    pelvisPosition.base.X[i] = exoPositions.refSystems.base[0];
    pelvisPosition.base.Y[i] = exoPositions.refSystems.base[1];
    pelvisPosition.base.Z[i] = exoPositions.refSystems.base[2];

    // --Hip positions
    this->fill_jointPos_with_exopos(hipPositions, exoPositions.refSystems.leftHip, 
                                            exoPositions.refSystems.rightHip, i, z_error);

    // --Ankle positions
    this->fill_jointPos_with_exopos(anklePositions, exoPositions.refSystems.leftAnkle, 
                                            exoPositions.refSystems.rightAnkle, i, z_error);

    // --Heel positions
    this->fill_jointPos_with_exopos(heelsPositions, exoPositions.refSystems.leftHeel, 
                                            exoPositions.refSystems.rightHeel, i, z_error);

    // --Toe positions
    this->fill_jointPos_with_exopos(toePositions,  exoPositions.refSystems.leftToe, 
                                            exoPositions.refSystems.rightToe, i, z_error);

    // --Knee positions
    this->fill_jointPos_with_exopos(kneePositions,  exoPositions.refSystems.leftKnee, 
                                            exoPositions.refSystems.rightKnee, i, z_error);

    /*// --Phases
    pelvisPosition.phase[i] = jointAng.phase[i];
    hipPositions.phase[i] = jointAng.phase[i];
    anklePositions.phase[i] = jointAng.phase[i];
    heelsPositions.phase[i] = jointAng.phase[i];
    toePositions.phase[i] = jointAng.phase[i];
    kneePositions.phase[i] = jointAng.phase[i];*/
    // Updates the last exo positions
    last_exoPositions = exoPositions;
    //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Cont Point After: %s",last_exoPositions.contactPoint.name.c_str());
    last_exoPositions.initialized=true;
  }      
  
  // Fills cartesian target message
  this->fill_joint_state(pelvisPosition, hipPositions, anklePositions, heelsPositions,
  toePositions, kneePositions, cartesian_trajectory);
  

}

};  // namespace kineticModel

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<kineticModel::KinematicModelNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
