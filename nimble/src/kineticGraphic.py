import rclpy
from trajectory_msgs.msg import JointTrajectory
from nimble_interfaces.msg import CartesianFullTrajectory
import matplotlib.pyplot as plt

LABELS = ["hipR", "kneeR", "ankleR", "hipL", "kneeL", "ankleL", "a", "b", "b", "f", "f"]

def joint_trajectory_callback(msg):
    for j in range(len(msg.points[1].positions)):
        color = 'C' + str(j)
        joint_positions = [point.positions[j] for point in msg.points]
        plt.plot(range(len(msg.points)), joint_positions, color=color, label=LABELS[j])

    # X and Y axis labels
    plt.xlabel('Iteration Number')
    plt.ylabel('Joint Positions')

    # Add a legend
    plt.legend()

    # Display each iteration separately
    plt.show()

def cartesian_callback(msg):
    joint_positions = [point.x for point in msg.left_knee]

    plt.plot(joint_positions, label=f'Joint')
    plt.show()

def main(args=None):
    rclpy.init(args=args)

    node = rclpy.create_node('plot_joint_trajectory')

    # Create a subscriber for the 'joint_trajectory' topic using the 'JointTrajectory' message type
    #subscriber = node.create_subscription(JointTrajectory, 'joints_target', joint_trajectory_callback, 10)
    subscriber = node.create_subscription(CartesianFullTrajectory, 'cartesian_full_target', cartesian_callback, 10)

    print("Waiting for JointTrajectory messages. Press Ctrl+C to exit.")

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("Exiting.")

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
