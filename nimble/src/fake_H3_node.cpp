#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <random>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"



using namespace std::chrono_literals;

//Estructura compartida para almacenar datos al recibir cada topic
struct SharedData {

    sensor_msgs::msg::JointState joints_SP;
};

//Nodo
class FakeH3Node : public rclcpp::Node
{
public:
    FakeH3Node() : Node("fake_H3_node")
    {	
    	//Possible internal parameters
        this->declare_parameter("param", 1);
    	this->declare_parameter("param2", 2);
    	
        // Create a subscribers 
        subscriber_jointsSP = create_subscription<sensor_msgs::msg::JointState>(
            "joints_SP", 10,
            [this](const sensor_msgs::msg::JointState msg) {
                // Callback function
                call_back_jointsSP(msg);
            });
                    
        // Create a publishers
        publisher_joints_state = create_publisher<sensor_msgs::msg::JointState>("joints_state", 10);
        
        
    }

private:
    //Instancias
    SharedData	shared_data_;    //estructura de datos
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_jointsSP; //susbcriptores
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_joints_state; //publishers
       
    //Callbacks, funciones asociadas a la recepcion de cada topic        
        
    void call_back_jointsSP(const sensor_msgs::msg::JointState & joints_SP_msg)
    {
	shared_data_.joints_SP = joints_SP_msg;
         //Publicacion
        auto joints_state_msg = sensor_msgs::msg::JointState();  //declarar mensaje con el tipo necesario
        
      	for (size_t i = 0; i < shared_data_.joints_SP.position.size(); ++i) {
            // Create a JointState message
            joints_state_msg.header.stamp=now();
            joints_state_msg.name = {"hipR","kneeR", "ankleR", "hipL", "kneeL", "ankleL"};
            std::random_device rd;
    	    std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(-1.0, 1.0);
            double random_number = dis(gen);

            joints_state_msg.position.push_back(shared_data_.joints_SP.position[i]+random_number);
                       
        } 
    	publisher_joints_state->publish(joints_state_msg);  //publicar
        
    }
     
      
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FakeH3Node>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

