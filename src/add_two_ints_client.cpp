#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 10)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  srv.request.c = atoll(argv[3]);
  srv.request.d = atoll(argv[4]);
  srv.request.e = atoll(argv[5]);
  srv.request.f = atoll(argv[6]);
  srv.request.g = atoll(argv[7]);
  srv.request.h = atoll(argv[8]);
  srv.request.i = atoll(argv[9]);
  if (client.call(srv))
  {
    ROS_INFO("l'aire du triaangle est de: %.2f", (float)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}