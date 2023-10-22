#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtle_control_node");
  ros::NodeHandle n;

  // 읽기를 위한 파라미터 변수 초기화
  double linear_x, angular_z;

  n.param("linear_x", linear_x, 1.0);
  n.param("angular_z", angular_z, 1.0);

  // Publisher 초기화
  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    geometry_msgs::Twist cmd_vel;
    cmd_vel.linear.x = 10;
    cmd_vel.angular.z = 10;

    cmd_vel_pub.publish(cmd_vel);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

