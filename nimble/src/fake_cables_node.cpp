#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <random>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "nimble_interfaces/msg/joints_trajectory.hpp"



using namespace std::chrono_literals;



//Nodo
class FakeCablesNode : public rclcpp::Node
{
public:
    FakeCablesNode() : Node("fake_cables_node")
    {	
    	//Possible internal parameters
        this->declare_parameter("param", 1);
    	this->declare_parameter("param2", 2);
    	
        // Create a subscribers 
        subscriber_joints_target = create_subscription<nimble_interfaces::msg::JointsTrajectory>(
            "joints_target", 10,
            [this](const nimble_interfaces::msg::JointsTrajectory msg) {
                // Callback function
                call_back_joints_target(msg);
            });
                    
        // Create a publishers
        publisher_cables_state = create_publisher<sensor_msgs::msg::JointState>("cables_state", 10);
        
        
    }

private:
    //Instancias
    rclcpp::Subscription<nimble_interfaces::msg::JointsTrajectory>::SharedPtr subscriber_joints_target; //susbcriptores
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_cables_state; //publishers
       
    //Callbacks, funciones asociadas a la recepcion de cada topic        
        
    void call_back_joints_target(const nimble_interfaces::msg::JointsTrajectory & joints_target_msg)
    {
	    //Publicacion estado pelvis list
        
        auto cablesSP_msg = sensor_msgs::msg::JointState();  //declarar mensaje con el tipo necesario
      	 //jointsSP_msg=.......;   //Rellenar con la información correspondiente
         //jointsSP_msg.header.stamp=now();   //header con el momento de publicacion
    	 //publisher_jointsSP->publish(jointsSP_msg);  //publicar
        cablesSP_msg.header.stamp=now();
        cablesSP_msg.name = {"pelvisList"};
        std::random_device rd;
    	    std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(-3.0, 3.0);
            double random_number = dis(gen);
        cablesSP_msg.position.push_back(joints_target_msg.trajectory.points[0].positions[6]);//+random_number);
        //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Cont Point: %s, AnkleX:%f",last_exoPositions.contactPoint.name.c_str(),exoPositions_movilBase.refSystems.rightToe(0));
        //cablesSP_msg.position[0]=joints_target_msg.trajectory.points[0].positions[6];
    	publisher_cables_state->publish(cablesSP_msg); 
    	        
    }
     
      
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FakeCablesNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

