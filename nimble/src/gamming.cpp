#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "nimble_interfaces/msg/frame_state.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"

using namespace std::chrono_literals;

//Estructura compartida para almacenar datos al recibir cada topic
struct SharedData {

    nimble_interfaces::msg::FrameState frame_state;
    nimble_interfaces::msg::TherapyRequirements step_target;
};

//Nodo
class GammingNode : public rclcpp::Node
{
public:
    GammingNode() : Node("gamming")
    {	
    	//Possible internal parameters
        this->declare_parameter("param1", 1);
    	this->declare_parameter("param2", 2);
    	
        // Create a subscribers 
        subscriber_frameState = create_subscription<nimble_interfaces::msg::FrameState>(
            "frame_state", 10,
            [this](const nimble_interfaces::msg::FrameState msg) {
                // Callback function 
                call_back_frame_state(msg);
            });
                        
        subscriber_stepTarget = create_subscription<nimble_interfaces::msg::TherapyRequirements>(
            "step_target", 10,
            [this](const nimble_interfaces::msg::TherapyRequirements msg) {
                // Callback function 
                call_back_step_target(msg);
            });
            
        //Create wall timer to run periodically (eliminar si no se usa)
        timer_ = this->create_wall_timer(1000ms, std::bind(&GammingNode::timer_callback, this)); 
        
    }

private:

    //Instancias
    SharedData	shared_data_;     //estructura de datos
    rclcpp::Subscription<nimble_interfaces::msg::TherapyRequirements>::SharedPtr subscriber_stepTarget; //susbcriptores
    rclcpp::Subscription<nimble_interfaces::msg::FrameState>::SharedPtr subscriber_frameState;
    rclcpp::TimerBase::SharedPtr timer_; //timer (eliminar si no se usa)
   
    //Callbacks, funciones asociadas a la recepcion de cada topic	       
    void call_back_frame_state(const nimble_interfaces::msg::FrameState & frame_state_msg) 
    {
        shared_data_.frame_state = frame_state_msg;  //almacenamiento del mensaje en la estructura de datos
        processData();  //llamada a la funcion de procesamiento
        
    }
    
    void call_back_step_target(const nimble_interfaces::msg::TherapyRequirements & step_target_msg) 
    {
        
        shared_data_.step_target = step_target_msg;
        processData();
    }
    
    //Funcion para procesamiento    
    void processData() {
        // Perform your logic using the shared_data_
        // ...
    }
  
      // Callback ejecutado cada cierto tiempo (eliminar si no se usa)
      void timer_callback()
  {
  
        
    
  }             
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GammingNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

