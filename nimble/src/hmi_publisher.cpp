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
    
    //Declaracion de parámetros con valores por defecto
    //Measurements
    this->declare_parameter("height", 1.8);
    this->declare_parameter("femur", 0.45);
    this->declare_parameter("tibia", 0.4);
    this->declare_parameter("distance_to_heel", 0.10);
    this->declare_parameter("distance_to_toe", 0.2);
    this->declare_parameter("height_ankle", 0.10);
    this->declare_parameter("depth_pelvis", 0.10);
    this->declare_parameter("width_pelvis", 0.4);
    //Therapy requirements 
    this->declare_parameter("min_assist_level", 10);
    this->declare_parameter("max_assist_level", 50);
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
    
    double distance_to_heel_dbl = this->get_parameter("distance_to_heel").as_double();
    float distance_to_heel = static_cast<float>(distance_to_heel_dbl);                                   
    meas_msg.distance_to_heel = distance_to_heel; 
    
    double distance_to_toe_dbl = this->get_parameter("distance_to_toe").as_double();
    float distance_to_toe = static_cast<float>(distance_to_toe_dbl);                                   
    meas_msg.distance_to_toe = distance_to_toe;
    
    double height_ankle_dbl = this->get_parameter("height_ankle").as_double();
    float height_ankle = static_cast<float>(height_ankle_dbl);                                   
    meas_msg.height_ankle = height_ankle;
    
    double depth_pelvis_dbl = this->get_parameter("depth_pelvis").as_double();
    float depth_pelvis = static_cast<float>(depth_pelvis_dbl);                                   
    meas_msg.depth_pelvis = depth_pelvis;
    
    double width_pelvis_dbl = this->get_parameter("width_pelvis").as_double();
    float width_pelvis = static_cast<float>(width_pelvis_dbl);                                   
    meas_msg.width_pelvis = width_pelvis;    
                                                           
    //RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: '" << message.femur << "'"); 
    meas_msg.header.stamp=now();   
    publisher_measur_->publish(meas_msg); //publicar measurements
    
    int min_assist_level = this->get_parameter("min_assist_level").as_int();
    th_req_msg.min_assist_level = min_assist_level;
    
    int max_assist_level = this->get_parameter("max_assist_level").as_int();
    th_req_msg.max_assist_level = max_assist_level;
    
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
