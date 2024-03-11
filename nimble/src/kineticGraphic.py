import rclpy
from nimble_interfaces.msg import CartesianFullTrajectory
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def callback(msg):
    # Extract left_malleolus points from the received message
    left_malleolus_points = msg.left_malleolus

    # Extract x, y, z coordinates
    x = [point.x for point in left_malleolus_points]
    y = [point.y for point in left_malleolus_points]
    z = [point.z for point in left_malleolus_points]

    # Plot the points in 3D
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(x, y, z, c='r', marker='o')

    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')

    plt.show()

def main(args=None):
    rclpy.init(args=args)

    node = rclpy.create_node('plot_left_malleolus')

    # Create a subscriber for the 'cartesian_full_target' topic using the 'CartesianFullTrajectory' message type
    subscriber = node.create_subscription(CartesianFullTrajectory, 'cartesian_full_target', callback, 10)

    print("Waiting for CartesianFullTrajectory messages. Press Ctrl+C to exit.")

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("Exiting.")

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
