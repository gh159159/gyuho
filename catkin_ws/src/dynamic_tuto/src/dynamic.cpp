#include <ros/ros.h>
#include "dynamic_reconfigure/server.h"
#include "dynamic_tuto/TutorialConfig.h"

void DynamicReconfigureCallback(dynamic_tuto::TutorialConfig &config, uint32_t level)
{
  ROS_INFO("Dynamic Param Int : %d", config.param_int);
  ROS_INFO("Dynamic Param Double : %f", config.param_double);
  ROS_INFO("Dynamic Param String : %s", config.param_string.c_str());
  if(config.param_bool == true) ROS_INFO("Dynamic Param Bool : true");
  else if (config.param_bool != true) ROS_INFO("Dynamic Param Bool : false");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "dynamic_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  dynamic_reconfigure::Server<dynamic_tuto::TutorialConfig> server;
  dynamic_reconfigure::Server<dynamic_tuto::TutorialConfig>::CallbackType f;

  f = boost::bind(&DynamicReconfigureCallback, _1, _2);
  server.setCallback(f);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;

}
