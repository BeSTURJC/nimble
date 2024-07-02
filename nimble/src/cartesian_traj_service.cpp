#define EIGEN_RUNTIME_NO_MALLOC

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <boost/tokenizer.hpp>
#include <eigen3/Eigen/Dense>
#include <cmath>


#include "rclcpp/rclcpp.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "nimble_interfaces/srv/cartesian_traj_service.hpp"
#include "nimble_interfaces/msg/joints_trajectory.hpp"
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
    bool initialized{false};
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


// ***** Structs functions ***** //

void fill_joint_state(
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

void resize_joint_position(
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

void fill_jointPos_with_exopos(
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
Eigen::Vector3d position_fromSR(const Eigen::Matrix4d &T) {

  Eigen::Vector3d pos;
  pos(0) = T(0, 3);
  pos(1) = -T(2, 3);
  pos(2) = T(1, 3);

  return pos;
}

Eigen::Vector3d position_fromSR_pelvisTilt(
    const Eigen::Matrix4d &T) {

  Eigen::Vector3d pos;

  pos(0) = -T(2, 3);
  pos(1) = -T(0, 3);
  pos(2) = T(1, 3);

  return pos;
}

Eigen::Matrix4d DH_deg(double theta, double d, double a,
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
Eigen::Vector3d gaitFeatureExtraction(  
    const std::vector<double>& ankleIpsi_X,
    const std::vector<double> &ankleContra_X,
    const std::vector<double>& ankleIpsi_Z,
    const std::vector<double> &ankleContra_Z,
    const std::vector<double> &heelIpsi_Z,
    const std::vector<double> &heelContra_Z,
    const std::vector<double> &toeIpsi_Z,
    const std::vector<double> &toeContra_Z, const std::vector<double> &phase) {

  Eigen::Vector3d data;
  int legcross=0;
  int ind=0;

  // Stride length calculation
  data(0) = ankleContra_X[-1] - ankleContra_X[0];

  while (legcross==0 && ind!=static_cast<int>(phase.size())){
    ind=ind+1;
    if (ankleIpsi_X[ind]>=ankleContra_X[ind]){
       legcross=1;
       data(1)=std::min(heelIpsi_Z[ind],toeIpsi_Z[ind]);
    } 
  }
  if (ind==(static_cast<int>(phase.size())-1)){
    data(1)=static_cast<int>(phase.size());
  }
  // Height calculation
  //data(1) = *std::max_element(ankleContra_Z.begin(), ankleContra_Z.end()) -
  //          *std::min_element(ankleContra_Z.begin(), ankleContra_Z.end());

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

void exoKinematicModel_pelvisMov(const JointAngle& jointAngles, 
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
    if (previousExoPosition.initialized) {
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

void executeKinematicModel(JointAngles& jointAng,
            nimble_interfaces::msg::Measurements& measurements,
            nimble_interfaces::msg::CartesianTrajectory& cartesian_trajectory, 
            nimble_interfaces::msg::TherapyRequirements& step_target,bool extract_features)
{ 
    int numPoints = jointAng.hipR_abd.size();
    //RCLCPP_INFO(this->get_logger(), "Feat:%s, NumPoints:%i",extract_features ? "true" : "false",numPoints);
    
    // Theres no joint data received, return
    if (numPoints == 0) {
        return;
    }
        
    ExoPositions last_exoPositions;
    last_exoPositions.initialized = false;
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
        exoKinematicModel_pelvisMov(q_model, measurements, last_exoPositions, 
                                                exoPositions_fixedBase, exoPositions);

        // Store positions
        // Rebases for positive values
        float z_error = measurements.femur + measurements.tibia + measurements.distance_to_heel + measurements.distance_to_toe;

        // --Pelvis positions
        fill_jointPos_with_exopos(pelvisPosition, exoPositions.refSystems.leftPelvis, 
                                                exoPositions.refSystems.rightPelvis, i, z_error);

        pelvisPosition.base.X[i] = exoPositions.refSystems.base[0];
        pelvisPosition.base.Y[i] = exoPositions.refSystems.base[1];
        pelvisPosition.base.Z[i] = exoPositions.refSystems.base[2];

        // --Hip positions
        fill_jointPos_with_exopos(hipPositions, exoPositions.refSystems.leftHip, 
                                                exoPositions.refSystems.rightHip, i, z_error);

        // --Ankle positions
        fill_jointPos_with_exopos(anklePositions, exoPositions.refSystems.leftAnkle, 
                                                exoPositions.refSystems.rightAnkle, i, z_error);

        // --Heel positions
        fill_jointPos_with_exopos(heelsPositions, exoPositions.refSystems.leftHeel, 
                                                exoPositions.refSystems.rightHeel, i, z_error);

        // --Toe positions
        fill_jointPos_with_exopos(toePositions,  exoPositions.refSystems.leftToe, 
                                                exoPositions.refSystems.rightToe, i, z_error);

        // --Knee positions
        fill_jointPos_with_exopos(kneePositions,  exoPositions.refSystems.leftKnee, 
                                                exoPositions.refSystems.rightKnee, i, z_error);

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
  if (extract_features==true){
    // Gets the step length and the height
    Eigen::Vector3d data;   // {length, height, swingPercent}
    data = gaitFeatureExtraction(anklePositions.R.X, anklePositions.L.X,
                        anklePositions.R.Z, anklePositions.L.Z,
                        heelsPositions.R.Z, heelsPositions.L.Z,
                        toePositions.R.Z, toePositions.L.Z,
                        toePositions.phase);
        

    // Fills step_target message
    step_target.step_length = data(0);
    step_target.step_height = data(1);
    // Swing percent = data(3);
  }
  // Fills cartesian target message
  fill_joint_state(pelvisPosition, hipPositions, anklePositions, heelsPositions,
  toePositions, kneePositions, cartesian_trajectory);
  
}


void calculate_trajectory(const std::shared_ptr<nimble_interfaces::srv::CartesianTrajService::Request> request,
          std::shared_ptr<nimble_interfaces::srv::CartesianTrajService::Response>      response)
{   	
    //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request");
                
    // Create a CartesianTrajectory message
    //auto cartesian_trajectory = std::make_shared<nimble_interfaces::msg::CartesianTrajectory>();
    //auto step_target = std::make_shared<nimble_interfaces::msg::TherapyRequirements>();
    nimble_interfaces::msg::CartesianTrajectory cartesian_trajectory;
    nimble_interfaces::msg::TherapyRequirements step_target;
    trajectory_msgs::msg::JointTrajectory joints_trajectory=request->joints_trajectory;
    nimble_interfaces::msg::Measurements measurements=request->measurements;
    int size = joints_trajectory.points.size();
    JointAngles jointAng;
    for (int i = 0; i < size; i++) {
      jointAng.hipR.push_back(joints_trajectory.points[i].positions[0]);
      jointAng.kneeR.push_back(joints_trajectory.points[i].positions[1]);
      jointAng.ankleR.push_back(joints_trajectory.points[i].positions[2]);
      jointAng.hipL.push_back(joints_trajectory.points[i].positions[3]);
      jointAng.kneeL.push_back(joints_trajectory.points[i].positions[4]);
      jointAng.ankleL.push_back(joints_trajectory.points[i].positions[5]);
      jointAng.pelvisList.push_back(joints_trajectory.points[i].positions[6]);
      jointAng.pelvisTilt.push_back(joints_trajectory.points[i].positions[7]);
      jointAng.hipR_abd.push_back(joints_trajectory.points[i].positions[8]);
      jointAng.hipL_abd.push_back(joints_trajectory.points[i].positions[9]);
      jointAng.phase.push_back(i);
    }

    bool extract_features=true;
    executeKinematicModel(jointAng, measurements, cartesian_trajectory, step_target,extract_features);
    rclcpp::Clock clock;
    auto timestamp = clock.now();

    //cartesian_trajectory->header.stamp = timestamp;
    //step_target->header.stamp = timestamp;

    response->cartesian_trajectory = cartesian_trajectory;
    response->step_target = step_target;                  
  
}


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("cartesian_traj_service");

  rclcpp::Service<nimble_interfaces::srv::CartesianTrajService>::SharedPtr service =
    node->create_service<nimble_interfaces::srv::CartesianTrajService>("cartesian_traj_service", &calculate_trajectory);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Trajectory Generator Service: Ready.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}

