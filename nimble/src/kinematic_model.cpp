#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iterator>

#include "kinetik_model/kineticModel.hpp"
#include "nimble_interfaces/msg/cartesian_full_trajectory.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
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

  // Fills joint ang
  for (int i = 0; i < size; i++) {
    // **["pelvisList", "pelvisTilt", "hipR", "hipR_abd", "hipL", "hipL_abd", "kneeR", "kneeL", "ankleR", "ankleL"]  

    jointAng.pelvisList.push_back(joint_target_msg.points[i].positions[0]);
    jointAng.pelvisTilt.push_back(joint_target_msg.points[i].positions[1]);
    jointAng.kneeR.push_back(joint_target_msg.points[i].positions[2]);
    jointAng.hipR.push_back(joint_target_msg.points[i].positions[3]);
    jointAng.hipR_abd.push_back(joint_target_msg.points[i].positions[4]);
    jointAng.ankleR.push_back(joint_target_msg.points[i].positions[5]);
    jointAng.kneeL.push_back(joint_target_msg.points[i].positions[6]);
    jointAng.hipL.push_back(joint_target_msg.points[i].positions[7]);
    jointAng.hipL_abd.push_back(joint_target_msg.points[i].positions[8]);
    jointAng.ankleL.push_back(joint_target_msg.points[i].positions[9]);
    jointAng.phase.push_back(i);
  }

  // Executes the kinematic model
  this->executeKinematicModel(jointAng, measurements_, cartesian_target, step_target);

  // Gets the timestamp
  rclcpp::Clock clock;
  auto timestamp = clock.now();

  cartesian_target.header.stamp = timestamp;
  step_target.header.stamp = timestamp;

  // Publishes the data
  publisher_cartTarget_->publish(cartesian_target);
  publisher_stepTarget_->publish(step_target);
}

void KinematicModelNode::call_back_joints_state(
    const sensor_msgs::msg::JointState &joint_state_msg) {

  const int bufferSize = 1;
  const int nJoints = 13;

  // TODO: IF TOPIC %STEP IS %5 STORE ONE POSITION

  JointAngles joint_state_ang;
  this->fillJointAngles(joint_state_msg, joint_state_ang);

  nimble_interfaces::msg::CartesianFullTrajectory cartesian_actual_state;
  nimble_interfaces::msg::TherapyRequirements step_target;
  
  // Define an array of pointers to the geometry_msgs/Point arrays
  std::array<std::vector<geometry_msgs::msg::Point>*, nJoints> actual_point_arrays = {
      &cartesian_actual_state.right_pelvis,
      &cartesian_actual_state.left_pelvis,
      &cartesian_actual_state.base_pelvis,
      &cartesian_actual_state.right_hip,
      &cartesian_actual_state.left_hip,
      &cartesian_actual_state.right_knee,
      &cartesian_actual_state.left_knee,
      &cartesian_actual_state.right_ankle,
      &cartesian_actual_state.left_ankle,
      &cartesian_actual_state.right_heel,
      &cartesian_actual_state.left_heel,
      &cartesian_actual_state.right_toe,
      &cartesian_actual_state.left_toe
  };
  
  std::array<std::vector<geometry_msgs::msg::Point>*, nJoints> cartesian_states = {
      &cartesian_state_.right_pelvis,
      &cartesian_state_.left_pelvis,
      &cartesian_state_.base_pelvis,
      &cartesian_state_.right_hip,
      &cartesian_state_.left_hip,
      &cartesian_state_.right_knee,
      &cartesian_state_.left_knee,
      &cartesian_state_.right_ankle,
      &cartesian_state_.left_ankle,
      &cartesian_state_.right_heel,
      &cartesian_state_.left_heel,
      &cartesian_state_.right_toe,
      &cartesian_state_.left_toe
  };

  // Iterate over the arrays and update the Cartesian states
  for (int i = 0; i < nJoints; ++i) {
      if (!actual_point_arrays[i]->empty()) {
          // Uses a Ring Buffer to pop back the last elements of the buffer
          this->updateCartesianState(*cartesian_states[i], (*actual_point_arrays[i])[0], bufferSize);
      }
  }

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
    jointPosition &hipPositions,
    jointPosition &anklePositions,
    jointPosition &heelsPositions,
    jointPosition &toePositions,
    jointPosition &kneePositions,
    nimble_interfaces::msg::CartesianFullTrajectory &cartesian_target) {

  // Resizes the publisher message for all articulations
  cartesian_target.right_pelvis.resize(pelvisPosition.R.X.size());
  cartesian_target.left_pelvis.resize(pelvisPosition.L.X.size());
  cartesian_target.base_pelvis.resize(pelvisPosition.base.X.size());
  cartesian_target.right_hip.resize(hipPositions.R.X.size());
  cartesian_target.left_hip.resize(hipPositions.L.X.size());
  cartesian_target.right_ankle.resize(anklePositions.R.X.size());
  cartesian_target.left_ankle.resize(anklePositions.L.X.size());
  cartesian_target.right_heel.resize(heelsPositions.R.X.size());
  cartesian_target.left_heel.resize(heelsPositions.L.X.size());
  cartesian_target.right_toe.resize(toePositions.R.X.size());
  cartesian_target.left_toe.resize(toePositions.L.X.size());
  cartesian_target.right_knee.resize(kneePositions.R.X.size());
  cartesian_target.left_knee.resize(kneePositions.L.X.size());

  // Optimized assignment loop for all articulations
  auto fill_cartesian_positions = [](auto& positions, auto& target) {
    for (size_t i = 0; i < positions.X.size(); ++i) {
      target[i].x = positions.X[i];
      target[i].y = positions.Y[i];
      target[i].z = positions.Z[i];
    }
  };

  fill_cartesian_positions(pelvisPosition.R, cartesian_target.right_pelvis);
  fill_cartesian_positions(pelvisPosition.L, cartesian_target.left_pelvis);
  fill_cartesian_positions(pelvisPosition.base, cartesian_target.base_pelvis);
  fill_cartesian_positions(hipPositions.R, cartesian_target.right_hip);
  fill_cartesian_positions(hipPositions.L, cartesian_target.left_hip);
  fill_cartesian_positions(anklePositions.R, cartesian_target.right_ankle);
  fill_cartesian_positions(anklePositions.L, cartesian_target.left_ankle);
  fill_cartesian_positions(heelsPositions.R, cartesian_target.right_heel);
  fill_cartesian_positions(heelsPositions.L, cartesian_target.left_heel);
  fill_cartesian_positions(toePositions.R, cartesian_target.right_toe);
  fill_cartesian_positions(toePositions.L, cartesian_target.left_toe);
  fill_cartesian_positions(kneePositions.R, cartesian_target.right_knee);
  fill_cartesian_positions(kneePositions.L, cartesian_target.left_knee);
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
Eigen::Vector3d KinematicModelNode::gaitFeatureExtraction(  
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

    auto last_error = previousExoPosition.refSystems.leftHeel;
    // Determine the point of contact
    switch (minIndex) {
        case 0:
            exoPositions_movilBase.contactPoint.name = "leftHeel";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.leftHeel(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.leftHeel(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.leftHeel(2);

            //auto last_error = previousExoPosition.refSystems.leftHeel;
            break;
        case 1:
            exoPositions_movilBase.contactPoint.name = "leftToe";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.leftToe(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.leftToe(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.leftToe(2);

            last_error = previousExoPosition.refSystems.leftToe;
            break;
        case 2:
            exoPositions_movilBase.contactPoint.name = "rightHeel";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.rightHeel(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.rightHeel(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.rightHeel(2);

            last_error = previousExoPosition.refSystems.rightHeel;
            break;
        case 3:
            exoPositions_movilBase.contactPoint.name = "rightToe";
            exoPositions_movilBase.contactPoint.X = exoPositions_fixedBase.refSystems.rightToe(0);
            exoPositions_movilBase.contactPoint.Y = exoPositions_fixedBase.refSystems.rightToe(1);
            exoPositions_movilBase.contactPoint.Z = exoPositions_fixedBase.refSystems.rightToe(2);

            last_error = previousExoPosition.refSystems.rightToe;
            break;
    }

    
    // Error correction
    Eigen::Vector3d offset;
    if (previousExoPosition.refSystems.base.size() == 0) {
        // Considers the last point
        
        offset << exoPositions_movilBase.contactPoint.X - last_error(0),
            exoPositions_movilBase.contactPoint.Y - last_error(1),
            exoPositions_movilBase.contactPoint.Z - zMin;

    } else{
        Eigen::Vector3d initialOffset(0, 0, zMin);
        offset << initialOffset(0),
            initialOffset(1),
            exoPositions_movilBase.contactPoint.Z - initialOffset(2);
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

  
    // RCLCPP_INFO_STREAM(this->get_logger(), "Offset: '" << offset << "'"); 
    // std::this_thread::sleep_for(std::chrono::seconds(1));
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
        
    ExoPositions last_exoPositions;

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
                exoPositions.contactPoint.name = "rightHeel";
            } else {
                exoPositions.contactPoint.name = "leftHeel";
            }
            exoPositions.contactPoint.X = 0;
            exoPositions.contactPoint.Y = measurements.width_pelvis * 0.5;
            exoPositions.contactPoint.Z = 0;
        } 

        // Kinematic model of the pelvis movement
        // Set all elements of exoPositions_movilBase to 0

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

        // --Knee positions
        fill_jointPos_with_exopos(kneePositions,  exoPositions.refSystems.leftKnee, 
                                                exoPositions.refSystems.rightKnee, i);

        // --Phases
        pelvisPosition.phase[i] = jointAng.phase[i];
        hipPositions.phase[i] = jointAng.phase[i];
        anklePositions.phase[i] = jointAng.phase[i];
        heelsPositions.phase[i] = jointAng.phase[i];
        toePositions.phase[i] = jointAng.phase[i];
        kneePositions.phase[i] = jointAng.phase[i];
            
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
    fill_joint_state(pelvisPosition, hipPositions, anklePositions, heelsPositions,
    toePositions, kneePositions, cartesian_target);
    }

};  // namespace kineticModel




int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<kineticModel::KinematicModelNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
