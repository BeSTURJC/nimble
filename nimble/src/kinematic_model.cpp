#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "kinetik_model/kineticModel.hpp"
#include "nimble_interfaces/msg/cartesian_full_trajectory.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/int64.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"

using namespace std::chrono_literals;

namespace kineticModel 
{

// *** Class initializer *** // 
KinematicModelNode::KinematicModelNode() : Node("kinematic_model") {
  // Possible internal parameters
  this->declare_parameter("contact_point", 1);
  this->declare_parameter("param2", 2);

  // Creates subscribers
  subscriber_joints_target_ =
      create_subscription<trajectory_msgs::msg::JointTrajectory>(
          "joints_target", 10,
          [this](const trajectory_msgs::msg::JointTrajectory msg) {
            call_back_joints_target(msg);
          });

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
          "measurements", 10,
          [this](const nimble_interfaces::msg::Measurements msg) {
            call_back_measurements(msg);
          });

  // Creates publishers
  publisher_stepTarget_ =
      create_publisher<nimble_interfaces::msg::TherapyRequirements>("step_target", 10);

  publisher_cartTarget_ =
      create_publisher<nimble_interfaces::msg::CartesianFullTrajectory>("cartesian_full_target", 10);

  publisher_cartState_ =
      create_publisher<nimble_interfaces::msg::CartesianFullTrajectory>("cartesian_state", 10);
}



// *** Callbacks *** //
void KinematicModelNode::call_back_joints_target(
    const trajectory_msgs::msg::JointTrajectory &joint_target_msg) {

  // Subscriber message
  JointAngles jointAng;

  // Publisher messages
  nimble_interfaces::msg::CartesianFullTrajectory cartesian_target;
  nimble_interfaces::msg::TherapyRequirements step_target;

  // Resizes
  int size = joint_target_msg.points.size();
  jointAng.hipR_abd.resize(size);
  jointAng.hipL_abd.resize(size);
  jointAng.pelvisList.resize(size);
  jointAng.pelvisTilt.resize(size);
  jointAng.phase.resize(size);

  // Fills joint ang
  for (int i = 0; i < size; i++) {
    // * ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
    jointAng.hipR.push_back(joint_target_msg.points[i].positions[0]);
    jointAng.hipL.push_back(joint_target_msg.points[i].positions[1]);
    jointAng.kneeR.push_back(joint_target_msg.points[i].positions[2]);
    jointAng.kneeL.push_back(joint_target_msg.points[i].positions[3]);
    jointAng.ankleR.push_back(joint_target_msg.points[i].positions[4]);
    jointAng.ankleL.push_back(joint_target_msg.points[i].positions[5]);
  }

  // Executes the kinematic model
  this->executeKinematicModel(jointAng, measurements_, cartesian_target,
                                      step_target);

  // Publishes the data
  publisher_cartTarget_->publish(cartesian_target);
  publisher_stepTarget_->publish(step_target);
}

void KinematicModelNode::call_back_joints_state(
    const sensor_msgs::msg::JointState &joint_state_msg) {

  const int bufferSize = 100;

  // TODO: IF TOPIC %STEP IS %5 STORE ONE POSITION

  JointAngles joint_state_ang;
  this->fillJointAngles(joint_state_msg, joint_state_ang);

  nimble_interfaces::msg::CartesianFullTrajectory cartesian_actual_state;
  nimble_interfaces::msg::TherapyRequirements step_target;

  // Uses a Ring Buffer to pop back the last elements of the buffer
  this->executeKinematicModel(joint_state_ang, measurements_,
                                      cartesian_actual_state, step_target);
  this->updateCartesianState(cartesian_state_.right_pelvis,
                                     cartesian_actual_state.right_pelvis[0],
                                     bufferSize);
  this->updateCartesianState(cartesian_state_.left_pelvis,
                                     cartesian_actual_state.right_pelvis[0],
                                     bufferSize);
  this->updateCartesianState(cartesian_state_.base_pelvis,
                                     cartesian_actual_state.right_pelvis[0],
                                     bufferSize);
  this->updateCartesianState(cartesian_state_.right_malleolus,
                                     cartesian_actual_state.right_pelvis[0],
                                     bufferSize);
  this->updateCartesianState(cartesian_state_.left_malleolus,
                                     cartesian_actual_state.right_pelvis[0],
                                     bufferSize);

  publisher_cartState_->publish(cartesian_state_);
}

void KinematicModelNode::call_back_state_cables(
    const sensor_msgs::msg::JointState &joint_state_cables_msg) {
  // shared_data_.cables_state = joint_state_cables_msg;
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

  joint_state_ang.hipR.insert(joint_state_ang.hipR.begin(),
                              joint_state_msg.position[0]);

  joint_state_ang.hipL.insert(joint_state_ang.hipL.begin(),
                              joint_state_msg.position[1]);

  joint_state_ang.kneeR.insert(joint_state_ang.kneeR.begin(),
                               joint_state_msg.position[2]);

  joint_state_ang.kneeL.insert(joint_state_ang.kneeL.begin(),
                               joint_state_msg.position[3]);

  joint_state_ang.ankleR.insert(joint_state_ang.ankleR.begin(),
                                joint_state_msg.position[4]);

  joint_state_ang.ankleL.insert(joint_state_ang.ankleL.begin(),
                                joint_state_msg.position[5]);
}

template <typename T>
void KinematicModelNode::updateCartesianState(std::vector<T> &target,
                                            const T &value,
                                            std::size_t bufferSize) {
  target.push_back(value);
  if (target.size() > bufferSize) {
    target.pop_back();
  }
}

void KinematicModelNode::fill_joint_state(
    jointPosition &pelvisPosition,
    jointPosition &anklePositions,
    nimble_interfaces::msg::CartesianFullTrajectory &cartesian_target) {
  // Resizes the publisher message
  cartesian_target.right_pelvis.resize(pelvisPosition.R.X.size());
  cartesian_target.left_pelvis.resize(pelvisPosition.L.X.size());
  cartesian_target.base_pelvis.resize(pelvisPosition.base.X.size());
  cartesian_target.right_malleolus.resize(anklePositions.R.X.size());
  cartesian_target.left_malleolus.resize(anklePositions.R.X.size());

  // Assigns each value
  for (size_t i = 0; i < pelvisPosition.R.X.size(); i++) {
    cartesian_target.right_pelvis[i].x = pelvisPosition.R.X[i];
    cartesian_target.right_pelvis[i].y = pelvisPosition.R.Y[i];
    cartesian_target.right_pelvis[i].z = pelvisPosition.R.Z[i];
  }
  for (size_t i = 0; i < pelvisPosition.L.X.size(); i++) {
    cartesian_target.left_pelvis[i].x = pelvisPosition.L.X[i];
    cartesian_target.left_pelvis[i].y = pelvisPosition.L.Y[i];
    cartesian_target.left_pelvis[i].z = pelvisPosition.L.Z[i];
  }
  for (size_t i = 0; i < pelvisPosition.base.X.size(); i++) {
    cartesian_target.base_pelvis[i].x = pelvisPosition.base.X[i];
    cartesian_target.base_pelvis[i].y = pelvisPosition.base.Y[i];
    cartesian_target.base_pelvis[i].z = pelvisPosition.base.Z[i];
  }
  for (size_t i = 0; i < anklePositions.R.X.size(); i++) {
    cartesian_target.right_malleolus[i].x = anklePositions.R.X[i];
    cartesian_target.right_malleolus[i].y = anklePositions.R.Y[i];
    cartesian_target.right_malleolus[i].z = anklePositions.R.Z[i];
  }
  for (size_t i = 0; i < anklePositions.R.X.size(); i++) {
    cartesian_target.left_malleolus[i].x = anklePositions.L.X[i];
    cartesian_target.left_malleolus[i].y = anklePositions.L.Y[i];
    cartesian_target.left_malleolus[i].z = anklePositions.L.Z[i];
  }
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
    Eigen::Vector3d right, int index) {

  joint_pos.L.X[index] = left[0];
  joint_pos.L.Y[index] = left[1];
  joint_pos.L.Z[index] = left[2];

  joint_pos.R.X[index] = right[0];
  joint_pos.R.Y[index] = right[1];
  joint_pos.R.Z[index] = right[2];
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

  // Z-axis transformation matrix
  trans_Z << cos(theta), -sin(theta), 0, 0, sin(theta), cos(theta), 0, 0, 0, 0,
      1, d, 0, 0, 0, 1;

  // X-axis transformation matrix
  trans_X << 1, 0, 0, a, 0, cos(alpha), -sin(alpha), 0, 0, sin(alpha),
      cos(alpha), 0, 0, 0, 0, 1;

  Eigen::Matrix4d A = trans_Z * trans_X;

  return A;
}


// ***** Main functions ***** //
Eigen::Vector3d
KinematicModelNode::gaitFeatureExtraction(  
    // const std::vector<double>& ankleIpsi_X,
    const std::vector<double> &ankleContra_X,
    // const std::vector<double>& ankleIpsi_Z,
    const std::vector<double> &ankleContra_Z,
    const std::vector<double> &heelIpsi_Z,
    const std::vector<double> &heelContra_Z,
    const std::vector<double> &toeIpsi_Z,
    const std::vector<double> &toeContra_Z, const std::vector<double> &phase) {

  Eigen::Vector3d data;

  // Stride length calculation
  data(0) = ankleContra_X.back() - ankleContra_X.front();

  // Height calculation
  data(1) = *std::max_element(ankleContra_Z.begin(), ankleContra_Z.end()) -
            *std::min_element(ankleContra_Z.begin(), ankleContra_Z.end());

  // Swing percent calculation
  size_t id_toeOff = 1;
  bool lookFor_toeOff = true;
  while (lookFor_toeOff) {
    if (toeContra_Z[id_toeOff] >= toeIpsi_Z[id_toeOff]) {
      lookFor_toeOff = false;
    } else {
      ++id_toeOff;
    }
  }

  size_t id_heelStrike = id_toeOff;
  bool lookFor_heelStrike = true;
  while (lookFor_heelStrike) {
    if (heelContra_Z[id_heelStrike] <= heelIpsi_Z[id_heelStrike]) {
      lookFor_heelStrike = false;
    } else {
      ++id_heelStrike;
    }
  }

  data(2) = phase[id_heelStrike] - phase[id_toeOff];
  return data;
}

void KinematicModelNode::exoKinematicModel_pelvisMov(const JointAngle& jointAngles, 
        const nimble_interfaces::msg::Measurements& measurements, const ExoPositions& previousExoPosition,
        ExoPositions& exoPositions_fixedBase, ExoPositions& exoPositions_movilBase) {

    // Model for the left leg
    Eigen::Matrix4d A0_L = DH_deg(jointAngles.pelvisList, 0, -measurements.width_pelvis/2, 0);
    Eigen::Matrix4d A1_L = DH_deg(-jointAngles.hipL_abd-90, -measurements.depth_pelvis, 0, -90);
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
    double zMin;
    int id;
    refSys_feet[0].minCoeff(&id);  // Finds the minimum index
    zMin = refSys_feet[0](id);

    // Determine the point of contact
    switch (id) {
        case 0:
            exoPositions_fixedBase.contactPoint.name = "leftHeel";
            exoPositions_fixedBase.contactPoint.X = exoPositions_fixedBase.refSystems.leftHeel(0);
            exoPositions_fixedBase.contactPoint.Y = exoPositions_fixedBase.refSystems.leftHeel(1);
            exoPositions_fixedBase.contactPoint.Z = exoPositions_fixedBase.refSystems.leftHeel(2);
            break;
        case 1:
            exoPositions_fixedBase.contactPoint.name = "leftToe";
            exoPositions_fixedBase.contactPoint.X = exoPositions_fixedBase.refSystems.leftToe(0);
            exoPositions_fixedBase.contactPoint.Y = exoPositions_fixedBase.refSystems.leftToe(1);
            exoPositions_fixedBase.contactPoint.Z = exoPositions_fixedBase.refSystems.leftToe(2);
            break;
        case 2:
            exoPositions_fixedBase.contactPoint.name = "rightHeel";
            exoPositions_fixedBase.contactPoint.X = exoPositions_fixedBase.refSystems.rightHeel(0);
            exoPositions_fixedBase.contactPoint.Y = exoPositions_fixedBase.refSystems.rightHeel(1);
            exoPositions_fixedBase.contactPoint.Z = exoPositions_fixedBase.refSystems.rightHeel(2);
            break;
        case 3:
            exoPositions_fixedBase.contactPoint.name = "rightToe";
            exoPositions_fixedBase.contactPoint.X = exoPositions_fixedBase.refSystems.rightToe(0);
            exoPositions_fixedBase.contactPoint.Y = exoPositions_fixedBase.refSystems.rightToe(1);
            exoPositions_fixedBase.contactPoint.Z = exoPositions_fixedBase.refSystems.rightToe(2);
            break;
    }

    // Error correction
    Eigen::Vector3d offset;
    if (previousExoPosition.refSystems.base.size() > 0) {
        // Considers the last point
        
        offset << exoPositions_fixedBase.contactPoint.X - previousExoPosition.contactPoint.X,
            exoPositions_fixedBase.contactPoint.Y - previousExoPosition.contactPoint.Y,
            exoPositions_fixedBase.contactPoint.Z - previousExoPosition.contactPoint.Z;

        offset(2) = zMin;  // Height always 0
    } else{
        Eigen::Vector3d initialOffset(0, 0, zMin);
        offset << exoPositions_fixedBase.contactPoint.X - initialOffset(0),
            exoPositions_fixedBase.contactPoint.Y - initialOffset(1),
            exoPositions_fixedBase.contactPoint.Z - initialOffset(2);

        offset(2) = zMin;  // Height always 0
    }

    // Apply the correction to all references in the system
    exoPositions_movilBase.refSystems.base -= offset;
    exoPositions_movilBase.refSystems.leftPelvis -= offset;
    exoPositions_movilBase.refSystems.leftHip -= offset;
    exoPositions_movilBase.refSystems.leftKnee -= offset;
    exoPositions_movilBase.refSystems.leftAnkle -= offset;
    exoPositions_movilBase.refSystems.leftFoot -= offset;
    exoPositions_movilBase.refSystems.leftToe -= offset;
    exoPositions_movilBase.refSystems.leftHeel -= offset;
    exoPositions_movilBase.refSystems.rightPelvis -= offset;
    exoPositions_movilBase.refSystems.rightHip -= offset;
    exoPositions_movilBase.refSystems.rightKnee -= offset;
    exoPositions_movilBase.refSystems.rightAnkle -= offset;
    exoPositions_movilBase.refSystems.rightFoot -= offset;
    exoPositions_movilBase.refSystems.rightToe -= offset;
    exoPositions_movilBase.refSystems.rightHeel -= offset;

    // Update the coordinates of the point of contact
    exoPositions_movilBase.contactPoint.X -= offset.x();
    exoPositions_movilBase.contactPoint.Y -= offset.y();
    exoPositions_movilBase.contactPoint.Z -= offset.z();

    // Ensure that the height is always 0
    exoPositions_fixedBase.contactPoint.Z = 0;

    // Generate output variables for fixed base
    Eigen::MatrixXd posExo_L_fixedBase(3, 7);
    posExo_L_fixedBase << exoPositions_fixedBase.refSystems.base,
                        exoPositions_fixedBase.refSystems.leftPelvis,
                        exoPositions_fixedBase.refSystems.leftHip,
                        exoPositions_fixedBase.refSystems.leftKnee,
                        exoPositions_fixedBase.refSystems.leftAnkle,
                        exoPositions_fixedBase.refSystems.leftHeel,
                        exoPositions_fixedBase.refSystems.leftToe;

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

}

void KinematicModelNode::executeKinematicModel(JointAngles& jointAng,
            nimble_interfaces::msg::Measurements& measurements,
            nimble_interfaces::msg::CartesianFullTrajectory& cartesian_target, 
            nimble_interfaces::msg::TherapyRequirements& step_target)
{ 
    int numPoints = jointAng.hipR_abd.size();

    // Theres no joint data received, return
    if (numPoints == 0) {
        return;
    }
        
    ExoPositions exoPositions_fixedBase, exoPositions, last_exoPositions;

    // Initializes all the arrays of each jointPosition structure
    jointPosition pelvisPosition;
    resize_joint_position(pelvisPosition, numPoints);

    jointPosition hipPositions;
    resize_joint_position(hipPositions, numPoints);

    jointPosition anklePositions;
    resize_joint_position(anklePositions, numPoints);

    jointPosition heelsPositions;
    resize_joint_position(heelsPositions, numPoints);

    jointPosition toePositions;
    resize_joint_position(toePositions, numPoints);

    for (int i = 0; i < numPoints; ++i) {

        // Set joint angles
        JointAngle q_model;
        q_model.hipR_abd = jointAng.hipR_abd[i];
        q_model.hipR = jointAng.hipR[i];
        q_model.hipL_abd = jointAng.hipL_abd[i];
        q_model.hipL = jointAng.hipL[i];
            
        q_model.kneeL = jointAng.kneeL[i];
        q_model.kneeR = jointAng.kneeR[i];

        q_model.ankleR = jointAng.ankleR[i];
        q_model.ankleL = jointAng.ankleL[i];

        q_model.pelvisList = jointAng.pelvisList[i];
        q_model.pelvisTilt = jointAng.pelvisTilt[i];

        // Determine contact point
        if (i == 0) {
            if (q_model.hipR > q_model.hipL) {
                exoPositions_fixedBase.contactPoint.name = "rightHeel";
            } else {
                exoPositions_fixedBase.contactPoint.name = "leftHeel";
            }
            exoPositions_fixedBase.contactPoint.X = 0;
            exoPositions_fixedBase.contactPoint.Y = measurements.width_pelvis * 0.5;
            exoPositions_fixedBase.contactPoint.Z = 0;
        } 

        // Kinematic model of the pelvis movement
        this->exoKinematicModel_pelvisMov(q_model, measurements, last_exoPositions, 
                                                exoPositions_fixedBase, exoPositions);

        // Store positions
        // --Pelvis positions
        fill_jointPos_with_exopos(pelvisPosition, exoPositions.refSystems.leftPelvis, 
                                                exoPositions.refSystems.rightPelvis, i);

        pelvisPosition.base.X[i] = exoPositions.refSystems.base[0];
        pelvisPosition.base.Y[i] = exoPositions.refSystems.base[1];
        pelvisPosition.base.Z[i] = exoPositions.refSystems.base[2];

        // --Hip positions
        fill_jointPos_with_exopos(hipPositions, exoPositions.refSystems.leftHip, 
                                                exoPositions.refSystems.rightHip, i);

        // --Ankle positions
        fill_jointPos_with_exopos(anklePositions, exoPositions.refSystems.leftAnkle, 
                                                exoPositions.refSystems.rightAnkle, i);

        // --Heel positions
        fill_jointPos_with_exopos(heelsPositions, exoPositions.refSystems.leftHeel, 
                                                exoPositions.refSystems.rightHeel, i);

        // --Toe positions
        fill_jointPos_with_exopos(toePositions,  exoPositions.refSystems.leftToe, 
                                                exoPositions.refSystems.rightToe, i);

        // --Phases
        pelvisPosition.phase[i] = jointAng.phase[i];
        hipPositions.phase[i] = jointAng.phase[i];
        anklePositions.phase[i] = jointAng.phase[i];
        heelsPositions.phase[i] = jointAng.phase[i];
        toePositions.phase[i] = jointAng.phase[i];
            
        // Updates the last exo positions
            last_exoPositions = exoPositions;
    }

    // Gets the step length and the height
    Eigen::Vector3d data;   // {length, height, swingPercent}
    data = this->gaitFeatureExtraction(/*anklePositions.R.X,*/ anklePositions.L.X,
                        /*anklePositions.R.Z,*/ anklePositions.L.Z,
                        heelsPositions.R.Z, heelsPositions.L.Z,
                        toePositions.R.Z, toePositions.L.Z,
                        toePositions.phase);
        

    // Fills step_target message
    step_target.step_length = data(0);
    step_target.step_height = data(1);
    // Swing percent = data(3);

    // Fills cartesian target message
    fill_joint_state(pelvisPosition, anklePositions, cartesian_target);
    }

};  // namespace kineticModel




int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<kineticModel::KinematicModelNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
