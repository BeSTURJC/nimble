#ifndef KINETIK_MODEL__KINETICMODEL_HPP_
#define KINETIK_MODEL__KINETICMODEL_HPP_

#define EIGEN_RUNTIME_NO_MALLOC
#include <iostream>
#include <eigen3/Eigen/Dense> 
#include <vector>
#include <cmath>

namespace kineticModel
{

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


Eigen::Vector3d position_fromSR(const Eigen::Matrix4d& T) {
    Eigen::Vector3d pos;
    
    pos(0) = T(0, 3);
    pos(1) = -T(2, 3);
    pos(2) = T(1, 3);
    
    return pos;
}


Eigen::Vector3d position_fromSR_pelvisTilt(const Eigen::Matrix4d& T) {
    Eigen::Vector3d pos;

    pos(0) = -T(2, 3);
    pos(1) = -T(0, 3);
    pos(2) = T(1, 3);

    return pos;
}


// Function for extracting gait features
// {lenght, height, swingPercent}
Eigen::Vector3d gaitFeatureExtraction(//const std::vector<double>& ankleIpsi_X,
                            const std::vector<double>& ankleContra_X,
                            //const std::vector<double>& ankleIpsi_Z,
                            const std::vector<double>& ankleContra_Z,
                            const std::vector<double>& heelIpsi_Z,
                            const std::vector<double>& heelContra_Z,
                            const std::vector<double>& toeIpsi_Z,
                            const std::vector<double>& toeContra_Z,
                            const std::vector<double>& phase) {
    
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


Eigen::Matrix4d DH_deg(double theta, double d, double a, double alpha) {
    Eigen::Matrix4d trans_Z, trans_X;

    // Z-axis transformation matrix
    trans_Z << cos(theta), -sin(theta), 0, 0,
               sin(theta), cos(theta), 0, 0,
               0, 0, 1, d,
               0, 0, 0, 1;

    // X-axis transformation matrix
    trans_X << 1, 0, 0, a,
               0, cos(alpha), -sin(alpha), 0,
               0, sin(alpha), cos(alpha), 0,
               0, 0, 0, 1;

    Eigen::Matrix4d A = trans_Z * trans_X;

    return A;
}


// Main function for the kinematic model of the exoskeleton
// Changes data in pointers nexoPositions_fixedBase, exoPositions_movilBase
void exoKinematicModel_pelvisMov(const JointAngle& jointAngles, const nimble_interfaces::msg::Measurements& measurements, const ExoPositions& previousExoPosition,
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

    // Posiciones de referencia en base fija
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
    std::vector<Eigen::Vector3d> refSys_feet = {exoPositions_fixedBase.refSystems.leftHeel, exoPositions_fixedBase.refSystems.leftToe,
                                                exoPositions_fixedBase.refSystems.rightHeel, exoPositions_fixedBase.refSystems.rightToe};
    double zMin;
    int id;
    refSys_feet[0].minCoeff(&id);  // Finds the minimun index
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

};

#endif // KINETIK_MODEL__KINETICMODEL_HPP_