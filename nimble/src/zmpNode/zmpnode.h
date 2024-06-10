#ifndef ZMPNODE_H
#define ZMPNODE_H

#include "rclcpp/rclcpp.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "nimble_interfaces/msg/frame_state.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"

#include <iostream>


using namespace std::chrono_literals;

//Estructura compartida para almacenar datos al recibir cada topic
struct SharedData {

    nimble_interfaces::msg::CartesianTrajectory cart_target;
    nimble_interfaces::msg::TherapyRequirements imposed_step_target;
    nimble_interfaces::msg::TherapyRequirements modified_step_target;
    nimble_interfaces::msg::FrameState frame_state;
    sensor_msgs::msg::JointState cables_state;
    std_msgs::msg::ByteMultiArray FSR;
    std_msgs::msg::Float32 COMx;
    std_msgs::msg::Float32 COMy;

};
class ZMPNode : public rclcpp::Node
{
public:
    ZMPNode() : Node("control_ZMP"){
        //Possible internal parameters
        this->declare_parameter("param", 1);
        this->declare_parameter("param2", 2);
        // Create a subscribers
        //This subscriber can e used to read the pelvis/COM from dynamic modeling
        subscriber_cartTarget = create_subscription<nimble_interfaces::msg::CartesianTrajectory>(
                    "cartesian_target", 10,
                    [this](const nimble_interfaces::msg::CartesianTrajectory msg) {
            // Callback function
            call_back_carTarget(msg);
        });
        //This subscriber describes the desired stepping impossed by the therapist
        subscriber_ImposedStepTarget = create_subscription<nimble_interfaces::msg::TherapyRequirements>(
                    "step_target", 10,
                    [this](const nimble_interfaces::msg::TherapyRequirements msg) {
            // Callback function
            call_back_ImposedStepTarget(msg);
        });
        //This subscriber describes the desired step impossed by the program
        subscriber_ModifiedStepTarget = create_subscription<nimble_interfaces::msg::TherapyRequirements>(
                    "step_target", 10,
                    [this](const nimble_interfaces::msg::TherapyRequirements msg) {
            // Callback function
            call_back_ModifiedStepTarget(msg);
        });


        //This subscriber read sensor state from the ST, This probably changes to used simple messages
        subscriber_framestate = create_subscription<nimble_interfaces::msg::FrameState>(
                    "frame_state", 10,
                    [this](const nimble_interfaces::msg::FrameState msg) {
            // Callback function
            call_back_framestate(msg);
        });

        /*
        subscriber_cablestate = create_subscription<sensor_msgs::msg::JointState>(
                    "cables_state", 10,
                    [this](const sensor_msgs::msg::JointState msg) {
            // Callback function
            call_back_cablestate(msg);
        });   */
        /*
        suscriber_FSR = create_subscription<std_msgs::msg::ByteMultiArray>(
                    "FSR", 10,
                    [this](const std_msgs::msg::ByteMultiArray msg) {

            call_back_FSR(msg);
        });
        */

        // Create a publishers
        // Publisher to write the x COM to the frame write simple to send to the ST through microRos
        publisher_COMx = create_publisher<std_msgs::msg::Float32>("COMx", 10);
        // Publisher to write the y COM to the cables robot
        publisher_COMy = create_publisher<std_msgs::msg::Float32>("COMy", 10);

        //Control Publishers
        publisher_posReference = create_publisher<std_msgs::msg::Float32>("PositionReference", 10);
        publisher_velReference = create_publisher<std_msgs::msg::Float32>("SpeedReference", 10);
        publisher_ControlMode= create_publisher<std_msgs::msg::Float32>("ControlMode", 10);

        //Create wall timer to publish periodically (eliminar si no se usa)
        timer_ = this->create_wall_timer(1000ms, std::bind(&ZMPNode::timer_callback, this));

    };
    SharedData	shared_data_;    //estructura de datos
    //********************************************//
    //**************SUBSCRIBERS *****************/
    //********************************************//


    rclcpp::Subscription<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr subscriber_cartTarget;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_ImposedStepTarget;
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_ModifiedStepTarget;
    rclcpp::Subscription<nimble_interfaces::msg::FrameState>::SharedPtr subscriber_framestate;

    //rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_cablestate;
    //rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr suscriber_FSR;
    //********************************************//
    //*************PUBLISHERS*******************************//
    //********************************************//
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_COMx;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_COMy; //publishers
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_posReference;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_velReference;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_ControlMode;
    rclcpp::TimerBase::SharedPtr timer_; //timer (eliminar si no se usa)


    //Callbacks, funciones asociadas a la recepcion de cada topic
    void call_back_carTarget(const nimble_interfaces::msg::CartesianTrajectory & cart_target_msg);
    void call_back_ModifiedStepTarget(const nimble_interfaces::msg::TherapyRequirements & step_target_msg);
    void call_back_ImposedStepTarget(const nimble_interfaces::msg::TherapyRequirements & step_target_msg);
    void call_back_framestate(const nimble_interfaces::msg::FrameState & frame_state_msg);

    /* void call_back_cablestate(const sensor_msgs::msg::JointState & cables_state_msg)
    {
        shared_data_.cables_state = cables_state_msg;
        processData();

    }

    void call_back_FSR(const std_msgs::msg::ByteMultiArray & FSR_msg)
    {
        shared_data_.FSR = FSR_msg;
        processData();
    }*/

    //Funcion para procesamiento y publicacion
    void processData();
    // Callback ejecutado cada cierto tiempo (eliminar si no se usa)
    void timer_callback();
public:
    void PublishComRefx(double data);
    void PublishComRefy(double data);
    void PublishPosReference(double reference);
    void PublishVelReference(double reference);
    void PublishCommand(double reference);
    void command(std::string line);
};

#endif // ZMPNODE_H
