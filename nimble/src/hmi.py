#!/bin/python3

import rclpy
from rclpy.node import Node
from nimble_interfaces.msg import Measurements, TherapyRequirements
from std_msgs.msg import Header
import sys
import threading
import time
from nimble_interfaces.msg import CartesianFullTrajectory

import ament_index_python

# Package includes
package_path = ament_index_python.get_package_share_directory("nimble")
sys.path.append(package_path)

from include.hmi_web.flask_class import FlaskApp

class HmiPublisher(Node):

    def __init__(self):
        super().__init__('hmi_publisher')
        self.publisher_measur_ = self.create_publisher(Measurements, 'measurements', 10)
        self.publisher_th_req_ = self.create_publisher(TherapyRequirements, 'therapy_requirements', 10)
        self.create_subscription(CartesianFullTrajectory, 'cartesian_full_target', self.cartesian_callback, 10)

        self.declare_parameters(
            namespace='',
            parameters=[
                ('height', 1.8),
                ('femur', 0.3371),
                ('tibia', 0.3495),
                ('distance_to_heel', 0.0),
                ('distance_to_toe', 0.1065),
                ('height_ankle', 0.0705),
                ('depth_pelvis', 0.0),
                ('width_pelvis', 0.1367),
                ('min_assist_level', 10),
                ('max_assist_level', 50),
                ('speed', 1.0),
                ('step_length', 0.8),
                ('step_height', 0.1)
            ]
        )

        self.timer_ = self.create_timer(1.0, self.timer_callback)

        # Runs the flask app
        self.webHmi = FlaskApp()
        self.flask_thread = threading.Thread(target=self.run_flask)
        self.flask_thread.start()

    def cartesian_callback(self, msg):
       
       #! This is the first trial, it follows the created route
       for i, position in enumerate(msg.left_knee):

        self.webHmi.set_articulation_positions(
            msg.left_knee[i],
            msg.right_knee[i],
            msg.left_pelvis[i],
            msg.right_pelvis[i],
            msg.left_hip[i],
            msg.right_hip[i],
            msg.left_ankle[i],
            msg.right_ankle[i],
            msg.left_heel[i],
            msg.right_heel[i],
            msg.left_toe[i],
            msg.right_toe[i]
        )
        
        time.sleep(0.1)

    # Runs the Flask app
    def run_flask(self):
        self.webHmi.run()

    def timer_callback(self):
        meas_msg = Measurements()
        th_req_msg = TherapyRequirements()

        # meas_msg.height = self.get_parameter('height').get_parameter_value().double_value
        meas_msg.height = float(self.webHmi.height)
        # meas_msg.femur = self.get_parameter('femur').get_parameter_value().double_value
        meas_msg.femur = float(self.webHmi.femur)
        # meas_msg.tibia = self.get_parameter('tibia').get_parameter_value().double_value
        meas_msg.tibia = float(self.webHmi.tibia)

        meas_msg.distance_to_heel = self.get_parameter('distance_to_heel').get_parameter_value().double_value
        meas_msg.distance_to_toe = self.get_parameter('distance_to_toe').get_parameter_value().double_value
        meas_msg.height_ankle = self.get_parameter('height_ankle').get_parameter_value().double_value
        meas_msg.depth_pelvis = self.get_parameter('depth_pelvis').get_parameter_value().double_value
        meas_msg.width_pelvis = self.get_parameter('width_pelvis').get_parameter_value().double_value
        meas_msg.header = Header()
        meas_msg.header.stamp = self.get_clock().now().to_msg()

        self.publisher_measur_.publish(meas_msg)

        th_req_msg.min_assist_level = self.get_parameter('min_assist_level').get_parameter_value().integer_value
        th_req_msg.max_assist_level = self.get_parameter('max_assist_level').get_parameter_value().integer_value
        th_req_msg.speed = self.get_parameter('speed').get_parameter_value().double_value
        th_req_msg.step_length = self.get_parameter('step_length').get_parameter_value().double_value
        th_req_msg.step_height = self.get_parameter('step_height').get_parameter_value().double_value
        th_req_msg.header = Header()
        th_req_msg.header.stamp = self.get_clock().now().to_msg()

        self.publisher_th_req_.publish(th_req_msg)

def main(args=None):

    rclpy.init(args=args)
    hmi_publisher = HmiPublisher()
    rclpy.spin(hmi_publisher)

    hmi_publisher.flask_thread.join()
    hmi_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
