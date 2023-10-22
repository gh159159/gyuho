#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "multi_node");
  ros::NodeHandle n;

  ros::Rate loop_rate(60);

  for(int i=2; i<=9; ++i){
        for(int j=1; j<=9; ++j){
            int data = i*j;
            ROS_INFO("%d * %d = %d", i, j, data);
        }
  }

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
