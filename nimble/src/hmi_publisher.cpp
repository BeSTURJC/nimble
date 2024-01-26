#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"

using namespace std::chrono_literals;

//Nodo
class HmiPublisher : public rclcpp::Node
{
public:
  HmiPublisher()
  : Node("hmi_publisher"), count_(0)
  {
    publisher_measur_ = this->create_publisher<nimble_interfaces::msg::Measurements>("measurements", 10);
    publisher_th_req_ = this->create_publisher<nimble_interfaces::msg::TherapyRequirements>("therapy_requirements", 10);
    
    //Declaracion de parámetros por defecto
    this->declare_parameter("height", 1.8);
    this->declare_parameter("femur", 0.45);
    this->declare_parameter("tibia", 0.4);
    this->declare_parameter("foot", 0.28); 
    this->declare_parameter("speed", 1.0);
    this->declare_parameter("step_length", 0.8);
    this->declare_parameter("step_height", 0.1); 
    timer_ = this->create_wall_timer(1000ms, std::bind(&HmiPublisher::timer_callback, this));
  }

private:
//Instancias
  
  rclcpp::TimerBase::SharedPtr timer_; //timer
  rclcpp::Publisher<nimble_interfaces::msg::Measurements>::SharedPtr publisher_measur_; //publishers
  rclcpp::Publisher<nimble_interfaces::msg::TherapyRequirements>::SharedPtr publisher_th_req_;
  size_t count_;


  //Callback periodico
  void timer_callback()
  {
  
    //Declaracion mensajes
    auto meas_msg = nimble_interfaces::msg::Measurements();
    auto th_req_msg = nimble_interfaces::msg::TherapyRequirements();
    
    //Relleno con parámetros (estos pueden modificarse por comandos o en el .launch)
    double height_dbl = this->get_parameter("height").as_double();
    float height = static_cast<float>(height_dbl);                                   
    meas_msg.height = height;
    double femur_dbl = this->get_parameter("femur").as_double();
    float femur = static_cast<float>(femur_dbl);                                   
    meas_msg.femur = femur;
    double tibia_dbl = this->get_parameter("tibia").as_double();
    float tibia = static_cast<float>(tibia_dbl);                                   
    meas_msg.tibia = tibia;
    double foot_dbl = this->get_parameter("foot").as_double();
    float foot = static_cast<float>(foot_dbl);                                   
    meas_msg.foot = foot;  
                                                           
    //RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: '" << message.femur << "'"); 
    meas_msg.header.stamp=now();   
    publisher_measur_->publish(meas_msg); //publicar measurements
    
    double speed_dbl = this->get_parameter("speed").as_double();
    float speed = static_cast<float>(speed_dbl);                                   
    th_req_msg.speed = speed;
    double step_length_dbl = this->get_parameter("step_length").as_double();
    float step_length = static_cast<float>(step_length_dbl);                                   
    th_req_msg.step_length = step_length;
    double step_height_dbl = this->get_parameter("step_height").as_double();
    float step_height = static_cast<float>(step_height_dbl);                                   
    th_req_msg.step_height = step_height;
    th_req_msg.header.stamp=now(); 
    publisher_th_req_->publish(th_req_msg); //publicar therapy_requirements
    
  }

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HmiPublisher>());
  rclcpp::shutdown();
  return 0;
}
