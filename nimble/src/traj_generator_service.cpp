#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <boost/tokenizer.hpp>


#include "rclcpp/rclcpp.hpp"
#include "nimble_interfaces/msg/measurements.hpp"
#include "nimble_interfaces/msg/therapy_requirements.hpp"
#include "nimble_interfaces/srv/traj_generator_service.hpp"

#include <memory>

void generate_trajectory(const std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService::Request> request,
          std::shared_ptr<nimble_interfaces::srv::TrajGeneratorService::Response>      response)
{   float femur=request->measurements.femur;
    float speed=request->therapy_requirements.speed;	
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request");
                
                
    std::string csv_file_path = "file.csv";            
    std::ifstream file(csv_file_path);
    std::cout << "Attempting to open file: " << csv_file_path << std::endl;


    // Check if the file is opened successfully
    if (!file.is_open()) {
            RCLCPP_ERROR(rclcpp::get_logger("joint_trajectory_publisher"), "Error opening the file.");
    throw std::runtime_error("Error opening the file.");
        }
        
        // Create a JointTrajectory message
        auto joint_trajectory = std::make_shared<trajectory_msgs::msg::JointTrajectory>();

        // Initialize JointTrajectory message
        //trajectory_msgs::msg::JointTrajectory joint_trajectory;
        joint_trajectory->joint_names = {"hipR","kneeR", "ankleR", "hipL", "kneeL", "ankleL", "pelvisList", "pelvisTilt", "hipR_abd", "hipL_abd"};

        // Read and process each line of the CSV file
        std::string line;
        while (std::getline(file, line)) {
            // Use a boost tokenizer to split the line into tokens
            boost::tokenizer<boost::escaped_list_separator<char>> tokens(line);
            
            trajectory_msgs::msg::JointTrajectoryPoint point;
            point.positions.reserve(10);

            // Process the tokens and convert to double
            for (const auto& token : tokens) {
                point.positions.push_back(std::stod(token));
            }

            // Add the point to the trajectory
            joint_trajectory->points.push_back(point);
        }

        // Close the file
        file.close();
        
    response->joints_trajectory = *joint_trajectory;                 
  
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("traj_generator_service");

  rclcpp::Service<nimble_interfaces::srv::TrajGeneratorService>::SharedPtr service =
    node->create_service<nimble_interfaces::srv::TrajGeneratorService>("traj_generator_service", &generate_trajectory);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Trajectory Generator Service: Ready.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}

