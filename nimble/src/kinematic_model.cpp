#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/msg/cartesian_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "sensor_msgs/msg/joint_state.hpp"


using namespace std::chrono_literals;

//Estructura compartida para almacenar datos al recibir cada topic
struct SharedData {
    nimble_interfaces::msg::Measurements measurements;
    trajectory_msgs::msg::JointTrajectory joints_target;
    sensor_msgs::msg::JointState joints_state;
    sensor_msgs::msg::JointState cables_state;

};

//Nodo
class KinematicModelNode : public rclcpp::Node
{
public:
    KinematicModelNode() : Node("kinematic_model")
    {	
    	//Possible internal parameters
        this->declare_parameter("contact_point", 1);
    	this->declare_parameter("param2", 2);
    	
        // Create a subscribers 
        subscriber_joints_target = create_subscription<trajectory_msgs::msg::JointTrajectory>(
            "joints_target", 10,
            [this](const trajectory_msgs::msg::JointTrajectory msg) {
                // Callback function that publishes the received Int64 message
                call_back_joints_target(msg);
            });
            
        subscriber_joints_state = create_subscription<sensor_msgs::msg::JointState>(
            "joints_state", 10,
            [this](const sensor_msgs::msg::JointState msg) {
                // Callback function that publishes the received Int64 message
                call_back_joints_state(msg);
            }); 
        subscriber_state_cables = create_subscription<sensor_msgs::msg::JointState>(
            "cables_state", 10,
            [this](const sensor_msgs::msg::JointState msg) {
                
                call_back_state_cables(msg);
            });
            
       subscriber_measurements = create_subscription<nimble_interfaces::msg::Measurements>(
            "measurements", 10,
            [this](const nimble_interfaces::msg::Measurements msg) {
                
                call_back_measurements(msg);
            });  
            
                   
        
        // Create a publishers
        publisher_stepTarget = create_publisher<nimble_interfaces::msg::TherapyRequirements>("step_target", 10);
        publisher_cartTarget = create_publisher<nimble_interfaces::msg::CartesianTrajectory>("cartesian_target", 10);
        publisher_cartState = create_publisher<nimble_interfaces::msg::CartesianTrajectory>("cartesian_state", 10);
        
        //Create wall timer to publish periodically (eliminar si no se usa)
        timer_ = this->create_wall_timer(1000ms, std::bind(&KinematicModelNode::timer_callback, this)); 
    }

private:
    //Instancias	
    SharedData	shared_data_;    //estructura de datos
    //Subscribers	
    rclcpp::Subscription<trajectory_msgs::msg::JointTrajectory>::SharedPtr subscriber_joints_target;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_joints_state;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_state_cables;
    rclcpp::Subscription<nimble_interfaces::msg::Measurements>::SharedPtr subscriber_measurements;
    //Publishers
    rclcpp::Publisher<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr publisher_cartTarget;
    rclcpp::Publisher<nimble_interfaces::msg::CartesianTrajectory>::SharedPtr publisher_cartState;
    rclcpp::Publisher<nimble_interfaces::msg::TherapyRequirements>::SharedPtr publisher_stepTarget;
    rclcpp::TimerBase::SharedPtr timer_; //timer (eliminar si no se usa)
    
    
    //Callbacks, funciones asociadas a la recepcion de cada topic	        
    void call_back_joints_target(const trajectory_msgs::msg::JointTrajectory & joint_target_msg) 
    {
        shared_data_.joints_target = joint_target_msg;  //almacenamiento del mensaje en la estructura de datos
        processData();  //llamada a la funcion de procesamiento
        
    }
    
    void call_back_joints_state(const sensor_msgs::msg::JointState & joint_state_msg) 
    {
        shared_data_.joints_state = joint_state_msg;
        processData();
    }
    
    void call_back_state_cables(const sensor_msgs::msg::JointState & joint_state_cables_msg) 
    {
        shared_data_.cables_state = joint_state_cables_msg;
        processData();
    }
    void call_back_measurements(const nimble_interfaces::msg::Measurements & measurements_msg) 
    {
        shared_data_.measurements = measurements_msg;
        processData();
    }
    
    
    void processData() {
        // Perform your logic using the shared_data_
 	//En este caso hay que diferenciar el calculo de las cartesianas para tray ideal (todos los puntos)
 	//y para la trayectoria actual, hacer un pushback y reiniciar en algun momento
 	
         //Publicacion
     	 auto cables_state_msg = sensor_msgs::msg::JointState(); //declarar mensaje con el tipo necesario
      	 //cables_state_msg=.......;  //Rellenar con la información correspondiente
         //cables_state_msg.header.stamp=now();  //header con el momento de publicacion
    	 //publisher_cables_state->publish(cables_state_msg); //publicar
    	 
    }
    
        // Callback ejecutado cada cierto tiempo (eliminar si no se usa)
      void timer_callback()
  {
 
    
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

