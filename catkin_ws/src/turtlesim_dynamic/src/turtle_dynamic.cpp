#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "turtlesim_dynamic/turtledynamicConfig.h"
#include <geometry_msgs/Twist.h>

ros::Publisher publisher_cmd_vel;
double linear_velocity;
double angular_velocity;

void DynamicReconfigureCallback(turtlesim_dynamic::turtledynamicConfig &config, uint32_t level)
{
  ROS_INFO("Dynamic Param Double : %f", config.parametaLinearX);
  ROS_INFO("Dynamic Param Double : %f", config.parametaAngularZ);
  linear_velocity=config.parametaLinearX;
  angular_velocity=config.parametaAngularZ;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_dynamic_node");
  ros::NodeHandle n;

  geometry_msgs::Twist cmd_vel;
  ros::Publisher publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(60);

  dynamic_reconfigure::Server<turtlesim_dynamic::turtledynamicConfig> server;
  dynamic_reconfigure::Server<turtlesim_dynamic::turtledynamicConfig>::CallbackType f;

  f = boost::bind(&DynamicReconfigureCallback, _1, _2);
  server.setCallback(f);

  cmd_vel.linear.x = 1.0;
  cmd_vel.angular.z = 1.0;
  while (ros::ok())
  {
    cmd_vel.linear.x = linear_velocity;
    cmd_vel.angular.z = angular_velocity;
    publisher_cmd_vel.publish(cmd_vel);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;

}
