#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_publish_node");
  ros::NodeHandle n;

  geometry_msgs::Twist cmd_vel;
  ros::Publisher publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    //cmd_vel.linear.x = 10;
    //cmd_vel.angular.z = 10;
    
    cmd_vel.linear.x = 2.0;
    cmd_vel.angular.z = 0.0;
    publisher_cmd_vel.publish(cmd_vel);
    ros::Duration(2.0).sleep();

    cmd_vel.linear.x = 0.0;
    cmd_vel.angular.z = 1.5;
    publisher_cmd_vel.publish(cmd_vel);
    ros::Duration(1.6).sleep();

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}