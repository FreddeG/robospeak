#include "ros/ros.h"
#include "robospeak/sayString.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client");
  if (argc != 2) //put 2 for actual input
  {
    ROS_INFO("use: rosrun robospeak testSender.cpp 'message'");
    return 1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<robospeak::sayString>("say_string");
  robospeak::sayString srv;
  srv.request.str = argv[1];
  //srv.request.str = "test";
  //ROS_INFO("Recieved argv:%s\n", argv[1]);
  ROS_INFO("Recieved argv:%s\n", srv.request.str.c_str());

  if (client.call(srv))
  {
    ROS_INFO("Return: %s", srv.response.str.c_str());
  }
  else
  {
    //ROS_INFO()
    ROS_ERROR("Failed to call service sayString");
    return 1;
  }

  return 0;
}
