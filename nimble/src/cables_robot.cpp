#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"


using namespace std::chrono_literals;


//Estructura compartida para almacenar datos al recibir cada topic
struct SharedData {

    sensor_msgs::msg::JointState pelvis_SP;	
 };
 
 
//Nodo
class CableRobotNode : public rclcpp::Node
{
public:
    CableRobotNode() : Node("cables_robot")
    {	
    
    	//Possible internal parameters
        this->declare_parameter("param1", 1);
    	this->declare_parameter("param2", 2);
    	
        // Create a subscribers 
        subscriber_pelvisSP = create_subscription<sensor_msgs::msg::JointState>(
            "pelvis_SP", 10,
            [this](const sensor_msgs::msg::JointState msg) {
                // Callback function 
                call_back_pelvisSP(msg);
            });
                        
        // Create a publisher
        publisher_cables_state = create_publisher<sensor_msgs::msg::JointState>("cables_state", 10);
        
        //Create wall timer to publish periodically (eliminar si no se usa)
        timer_ = this->create_wall_timer(1000ms, std::bind(&CableRobotNode::timer_callback, this)); 
        
    }

private:

    //Instancias	
    SharedData	shared_data_;    //estructura de datos
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_pelvisSP; //susbcriptores
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_cables_state; //publishers
    rclcpp::TimerBase::SharedPtr timer_; //timer (eliminar si no se usa)
      
    //Callbacks, funciones asociadas a la recepcion de cada topic	
    void call_back_pelvisSP(const sensor_msgs::msg::JointState & pelvisSP_msg) 
    {
        shared_data_.pelvis_SP = pelvisSP_msg;  //almacenamiento del mensaje en la estructura de datos
        processData();  //llamada a la funcion de procesamiento
        
    }
    
    //Funcion para procesamiento
       void processData(){
       	 
    }
    
    // Callback ejecutado cada cierto tiempo (eliminar si no se usa)
      void timer_callback()
  {
  
         //Publicacion
     	 auto cables_state_msg = sensor_msgs::msg::JointState(); //declarar mensaje con el tipo necesario
      	 //cables_state_msg=.......;  //Rellenar con la información correspondiente
         //cables_state_msg.header.stamp=now();  //header con el momento de publicacion
    	 //publisher_cables_state->publish(cables_state_msg); //publicar
    
  }         
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CableRobotNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

