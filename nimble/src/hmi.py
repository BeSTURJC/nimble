#!/bin/python3

import rclpy
from rclpy.node import Node
from nimble_interfaces.msg import Measurements, TherapyRequirements
from std_msgs.msg import Header
import threading
import time
from nimble_interfaces.msg import CartesianFullTrajectory

from hmi_web.flask_class import FlaskApp

class HmiPublisher(Node):

    def __init__(self):
        super().__init__('hmi_publisher')
        self.publisher_measur_ = self.create_publisher(Measurements, 'measurements', 10)
        self.publisher_th_req_ = self.create_publisher(TherapyRequirements, 'therapy_requirements', 10)

        subTopic = 'cartesian_full_target' #** Shows the full trajectory
        # subTopic = 'cartesian_state' #** Shows the actual position of the exo 
        self.create_subscription(CartesianFullTrajectory, subTopic, self.cartesian_callback, 10)

        # TODO: The cartesian_state probably have a buffer, if the buffer is implemented, get only the last element

        # TODO: Clean the parameters if the HMI is confirmed
        self.yamlNamespace = 'hmi'
        self.declare_parameters(
            namespace=self.yamlNamespace,
            parameters=[
                ('height', 1.8),
                ('femur', 0.3371),
                ('tibia', 0.3495),
                ('distance_to_heel', 0.0),
                ('distance_to_toe', 0.1065),
                ('height_ankle', 0.0705),
                ('depth_pelvis', 0.0),
                ('width_pelvis', 0.4367),
                ('min_assist_level', 10),
                ('max_assist_level', 50),
                ('speed', 1.0),
                ('step_length', 0.8),
                ('step_height', 0.1)
            ]
        )
        self.timer_ = self.create_timer(1.0, self.publisher_callback)

        # Runs the flask app
        self.webHmi = FlaskApp()
        self.flask_thread = threading.Thread(target=self.run_flask)
        self.flask_thread.start()

    def cartesian_callback(self, msg):
       
       #! This is the first trial, it follows the created route
       for i, position in enumerate(msg.left_knee):

        data1 = self.webHmi.set_articulation_positions( 'exo1', 100,
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

        data2 = self.webHmi.set_articulation_positions( 'exo2', 115,
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

        self.webHmi.data = {**data1, **data2}
        
        time.sleep(0.1)

    # Runs the Flask app
    def run_flask(self):
        self.webHmi.run()

    # Publish measurements and therapy requirements 
    def publisher_callback(self):
        meas_msg = Measurements()
        th_req_msg = TherapyRequirements()

        meas_msg.height = self.get_parameter(self.yamlNamespace + '.height').get_parameter_value().double_value
        meas_msg.femur = self.get_parameter('hmi.femur').get_parameter_value().double_value
        meas_msg.tibia = self.get_parameter('hmi.tibia').get_parameter_value().double_value
        meas_msg.distance_to_heel = self.get_parameter('hmi.distance_to_heel').get_parameter_value().double_value
        meas_msg.distance_to_toe = self.get_parameter('hmi.distance_to_toe').get_parameter_value().double_value
        meas_msg.height_ankle = self.get_parameter('hmi.height_ankle').get_parameter_value().double_value
        meas_msg.depth_pelvis = self.get_parameter('hmi.depth_pelvis').get_parameter_value().double_value
        meas_msg.width_pelvis = self.get_parameter('hmi.width_pelvis').get_parameter_value().double_value
        meas_msg.header = Header()
        meas_msg.header.stamp = self.get_clock().now().to_msg()

        self.publisher_measur_.publish(meas_msg)

        th_req_msg.min_assist_level = self.get_parameter('hmi.min_assist_level').get_parameter_value().integer_value
        th_req_msg.max_assist_level = self.get_parameter('hmi.max_assist_level').get_parameter_value().integer_value
        
        #meas_msg.height = self.get_parameter('speed').get_parameter_value().double_value
        #th_req_msg.step_length = self.get_parameter('step_length').get_parameter_value().double_value
        #th_req_msg.step_height = self.get_parameter('step_height').get_parameter_value().double_value
        th_req_msg.speed = float(self.webHmi.speed)
        th_req_msg.step_length = float(self.webHmi.step_length)
        th_req_msg.step_height = float(self.webHmi.step_height)
        
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
