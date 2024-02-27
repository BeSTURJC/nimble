#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
// #include "nimble_interfaces/msg/cartesian_trajectory.hpp"
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


    void fill_joint_state(kineticModel::jointPosition& pelvisPosition, kineticModel::jointPosition& anklePositions,
                nimble_interfaces::msg::CartesianFullTrajectory& cartesian_target)
    {
        // Resizes the publisher message
        cartesian_target.right_pelvis.resize(pelvisPosition.R.X.size());
        cartesian_target.left_pelvis.resize(pelvisPosition.L.X.size());
        cartesian_target.base_pelvis.resize(pelvisPosition.base.X.size());
        cartesian_target.right_malleolus.resize(anklePositions.R.X.size());
        cartesian_target.left_malleolus.resize(anklePositions.R.X.size());

        // Asigns each value
        for (size_t i = 0; i < pelvisPosition.R.X.size(); i++){
            cartesian_target.right_pelvis[i].x = pelvisPosition.R.X[i];
            cartesian_target.right_pelvis[i].y = pelvisPosition.R.Y[i];
            cartesian_target.right_pelvis[i].z = pelvisPosition.R.Z[i];
        }
        for (size_t i = 0; i < pelvisPosition.L.X.size(); i++){
            cartesian_target.left_pelvis[i].x = pelvisPosition.L.X[i];
            cartesian_target.left_pelvis[i].y = pelvisPosition.L.Y[i];
            cartesian_target.left_pelvis[i].z = pelvisPosition.L.Z[i];
        }
        for (size_t i = 0; i < pelvisPosition.base.X.size(); i++){
            cartesian_target.base_pelvis[i].x = pelvisPosition.base.X[i];
            cartesian_target.base_pelvis[i].y = pelvisPosition.base.Y[i];
            cartesian_target.base_pelvis[i].z = pelvisPosition.base.Z[i];
        }
        for (size_t i = 0; i < anklePositions.R.X.size(); i++){
            cartesian_target.right_malleolus[i].x = anklePositions.R.X[i];
            cartesian_target.right_malleolus[i].y = anklePositions.R.Y[i];
            cartesian_target.right_malleolus[i].z = anklePositions.R.Z[i];
        }
        for (size_t i = 0; i < anklePositions.R.X.size(); i++){
            cartesian_target.left_malleolus[i].x = anklePositions.L.X[i];
            cartesian_target.left_malleolus[i].y = anklePositions.L.Y[i];
            cartesian_target.left_malleolus[i].z = anklePositions.L.Z[i];
        }
    }

    void executeKinematicModel(kineticModel::JointAngles& jointAng,
                nimble_interfaces::msg::CartesianFullTrajectory& cartesian_target, 
                nimble_interfaces::msg::TherapyRequirements& step_target)
    { 
        int numPoints = jointAng.hipR_abd.size();

        // Theres no joint data recived, return
        if (numPoints == 0) {
            return;
        }
        
        // Initializes all the arrays of each jointPosition structure
        kineticModel::ExoPositions exoPositions_fixedBase, exoPositions, last_exoPositions;
        kineticModel::jointPosition pelvisPosition;
        pelvisPosition.R.X.resize(numPoints);
        pelvisPosition.R.Y.resize(numPoints);
        pelvisPosition.R.Z.resize(numPoints);
        pelvisPosition.base.X.resize(numPoints);
        pelvisPosition.base.Y.resize(numPoints);
        pelvisPosition.base.Z.resize(numPoints);
        pelvisPosition.L.X.resize(numPoints);
        pelvisPosition.L.Y.resize(numPoints);
        pelvisPosition.L.Z.resize(numPoints);
        pelvisPosition.phase.resize(numPoints);

        kineticModel::jointPosition hipPositions;
        hipPositions.L.X.resize(numPoints);
        hipPositions.L.Y.resize(numPoints);
        hipPositions.L.Z.resize(numPoints);
        hipPositions.R.X.resize(numPoints);
        hipPositions.R.Y.resize(numPoints);
        hipPositions.R.Z.resize(numPoints);
        hipPositions.phase.resize(numPoints);

        kineticModel::jointPosition anklePositions;
        anklePositions.L.X.resize(numPoints);
        anklePositions.L.Y.resize(numPoints);
        anklePositions.L.Z.resize(numPoints);
        anklePositions.R.X.resize(numPoints);
        anklePositions.R.Y.resize(numPoints);
        anklePositions.R.Z.resize(numPoints);
        anklePositions.phase.resize(numPoints);

        kineticModel::jointPosition heelsPositions;
        heelsPositions.L.X.resize(numPoints);
        heelsPositions.L.Y.resize(numPoints);
        heelsPositions.L.Z.resize(numPoints);
        heelsPositions.R.X.resize(numPoints);
        heelsPositions.R.Y.resize(numPoints);
        heelsPositions.R.Z.resize(numPoints);
        heelsPositions.phase.resize(numPoints);

        kineticModel::jointPosition toePositions;
        toePositions.L.X.resize(numPoints);
        toePositions.L.Y.resize(numPoints);
        toePositions.L.Z.resize(numPoints);
        toePositions.R.X.resize(numPoints);
        toePositions.R.Y.resize(numPoints);
        toePositions.R.Z.resize(numPoints);
        toePositions.phase.resize(numPoints);

        for (int i = 0; i < numPoints; ++i) {

            // Set joint angles
            kineticModel::JointAngle q_model;
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
                exoPositions_fixedBase.contactPoint.Y = measurements_.width_pelvis * 0.5;
                exoPositions_fixedBase.contactPoint.Z = 0;
            } 

            // Kinematic model of the pelvis movement
            kineticModel::exoKinematicModel_pelvisMov(q_model, measurements_, last_exoPositions, exoPositions_fixedBase, exoPositions);

            // Store positions
            // --Pelvis positions
            pelvisPosition.R.X[i] = exoPositions.refSystems.rightPelvis[0];
            pelvisPosition.R.Y[i] = exoPositions.refSystems.rightPelvis[1];
            pelvisPosition.R.Z[i] = exoPositions.refSystems.rightPelvis[2];

            pelvisPosition.base.X[i] = exoPositions.refSystems.base[0];
            pelvisPosition.base.Y[i] = exoPositions.refSystems.base[1];
            pelvisPosition.base.Z[i] = exoPositions.refSystems.base[2];

            pelvisPosition.L.X[i] = exoPositions.refSystems.leftPelvis[0];
            pelvisPosition.L.Y[i] = exoPositions.refSystems.leftPelvis[1];
            pelvisPosition.L.Z[i] = exoPositions.refSystems.leftPelvis[2];

            // --Hip positions
            hipPositions.L.X[i] = exoPositions.refSystems.leftHip[0];
            hipPositions.L.Y[i] = exoPositions.refSystems.leftHip[1];
            hipPositions.L.Z[i] = exoPositions.refSystems.leftHip[2];

            hipPositions.R.X[i] = exoPositions.refSystems.rightHip[0];
            hipPositions.R.Y[i] = exoPositions.refSystems.rightHip[1];
            hipPositions.R.Z[i] = exoPositions.refSystems.rightHip[2];

            // --Ankle positions
            anklePositions.L.X[i] = exoPositions.refSystems.leftAnkle[0];
            anklePositions.L.Y[i] = exoPositions.refSystems.leftAnkle[1];
            anklePositions.L.Z[i] = exoPositions.refSystems.leftAnkle[2];

            anklePositions.R.X[i] = exoPositions.refSystems.rightAnkle[0];
            anklePositions.R.Y[i] = exoPositions.refSystems.rightAnkle[1];
            anklePositions.R.Z[i] = exoPositions.refSystems.rightAnkle[2];

            // --Heel positions
            heelsPositions.L.X[i] = exoPositions.refSystems.leftHeel[0];
            heelsPositions.L.Y[i] = exoPositions.refSystems.leftHeel[1];
            heelsPositions.L.Z[i] = exoPositions.refSystems.leftHeel[2];

            heelsPositions.R.X[i] = exoPositions.refSystems.rightHeel[0];
            heelsPositions.R.Y[i] = exoPositions.refSystems.rightHeel[1];
            heelsPositions.R.Z[i] = exoPositions.refSystems.rightHeel[2];

            // --Toe positions
            toePositions.L.X[i] = exoPositions.refSystems.leftToe[0];
            toePositions.L.Y[i] = exoPositions.refSystems.leftToe[1];
            toePositions.L.Z[i] = exoPositions.refSystems.leftToe[2];

            toePositions.R.X[i] = exoPositions.refSystems.rightToe[0];
            toePositions.R.Y[i] = exoPositions.refSystems.rightToe[1];
            toePositions.R.Z[i] = exoPositions.refSystems.rightToe[2];

            // --Phases
            pelvisPosition.phase[i] = jointAng.phase[i];
            hipPositions.phase[i] = jointAng.phase[i];
            anklePositions.phase[i] = jointAng.phase[i];
            heelsPositions.phase[i] = jointAng.phase[i];
            toePositions.phase[i] = jointAng.phase[i];
            
            // Updates the last exo positions
            last_exoPositions = exoPositions;
        }

        // Gets the step lenght and the height
        Eigen::Vector3d data;   // {lenght, height, swingPercent}
        data = kineticModel::gaitFeatureExtraction(/*anklePositions.R.X,*/ anklePositions.L.X,
                            /*anklePositions.R.Z,*/ anklePositions.L.Z,
                            heelsPositions.R.Z, heelsPositions.L.Z,
                            toePositions.R.Z, toePositions.L.Z,
                            toePositions.phase);
        

        // Fills step_target message
        step_target.step_length = data(0);
        step_target.step_height = data(1);
        // Swing percent = data(3);

        // Fills cartesian target message
        this->fill_joint_state(pelvisPosition, anklePositions, cartesian_target);
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
    kineticModel::JointAngles joint_state_ang_;

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

        // ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
        // -- Resizes
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
            /** Hip R**/
            jointAng.hipR[i] = joint_target_msg.points[i].positions[0];

            /** Hip L**/
            jointAng.hipL[i] = joint_target_msg.points[i].positions[1];
                    
            /** Knee R**/
            jointAng.kneeR[i] = joint_target_msg.points[i].positions[2];

            /** Knee L**/
            jointAng.kneeL[i] = joint_target_msg.points[i].positions[3];

            /** Ankle R**/
            jointAng.ankleR[i] = joint_target_msg.points[i].positions[4];

            /** Ankle L**/
            jointAng.ankleL[i] = joint_target_msg.points[i].positions[5];
        }

        // Executes the kinematic model
        this->executeKinematicModel(jointAng, cartesian_target, step_target);
    
        // Publishes the data
        publisher_cartTarget_->publish(cartesian_target);
        publisher_stepTarget_->publish(step_target);                 // El publish data en un timer o directamente en el callback para obtener los datos cuuanto antes??????
    }
    
   
  
    
    // Uses a Ring Buffer to pop back the last elements of the buffer
    void call_back_joints_state(const sensor_msgs::msg::JointState &joint_state_msg) {
        // Publisher messages
        nimble_interfaces::msg::CartesianFullTrajectory cartesian_state;
        nimble_interfaces::msg::TherapyRequirements step_target;

        const int bufferSize = 100;

        // !!!!!!!!!!!! Recivo de topic if index = x % 2: (Ejemplo) añadir posición  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // Lista de puntos y pasarles el modelo cinematico o a cada punto pasarle el modelo cinematico y añadirlo a la lista?


        // Fills joint ang
        /** Hip R**/
        joint_state_ang_.hipR.insert(joint_state_ang_.hipR.begin(), joint_state_msg.position[0]);
        if (joint_state_ang_.hipR.size() > bufferSize) {
            joint_state_ang_.hipR.pop_back();
        }

        /** Hip L**/
        joint_state_ang_.hipL.insert(joint_state_ang_.hipL.begin(), joint_state_msg.position[1]);
        if (joint_state_ang_.hipL.size() > bufferSize) {
            joint_state_ang_.hipL.pop_back();
        }

        /** Knee R**/
        joint_state_ang_.kneeR.insert(joint_state_ang_.kneeR.begin(), joint_state_msg.position[2]);
        if (joint_state_ang_.kneeR.size() > bufferSize) {
            joint_state_ang_.kneeR.pop_back();
        }

        /** Knee L**/
        joint_state_ang_.kneeL.insert(joint_state_ang_.kneeL.begin(), joint_state_msg.position[3]);
        if (joint_state_ang_.kneeL.size() > bufferSize) {
            joint_state_ang_.kneeL.pop_back();
        }

        /** Ankle R**/
        joint_state_ang_.ankleR.insert(joint_state_ang_.ankleR.begin(), joint_state_msg.position[4]);
        if (joint_state_ang_.ankleR.size() > bufferSize) {
            joint_state_ang_.ankleR.pop_back();
        }

        /** Ankle L**/
        joint_state_ang_.ankleL.insert(joint_state_ang_.ankleL.begin(), joint_state_msg.position[5]);
        if (joint_state_ang_.ankleL.size() > bufferSize) {
            joint_state_ang_.ankleL.pop_back();
        }

        // Executes the kinematic model
        this->executeKinematicModel(joint_state_ang_, cartesian_state, step_target);

        publisher_cartState_->publish(cartesian_state);
    }
    
    void call_back_state_cables(const sensor_msgs::msg::JointState & joint_state_cables_msg) 
    {
        // shared_data_.cables_state = joint_state_cables_msg;
    }

    // Always updates mesaurements callback
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

