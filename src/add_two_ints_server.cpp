#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"

bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res)
{
  res.sum = (0.5) * sqrt( pow( (req.d * req.b) - (req.g * req.b) - (req.a * req.e) + (req.g * req.e) + (req.a * req.h) - (req.d * req.h),2)
                        + pow( (req.d * req.c) - (req.g * req.c) - (req.a * req.f) + (req.g * req.f) + (req.a * req.i) - (req.d * req.i),2)
                        + pow( (req.e * req.c) - (req.h * req.c) - (req.b * req.f) + (req.h * req.f) + (req.b * req.i) - (req.e * req.i),2)
                    );
  ROS_INFO("request: ax=%ld, ay=%ld, az=%ld, bx=%ld, by=%ld, bz=%ld, cx=%ld, cy=%ld, cz=%ld",
            (long int)req.a, (long int)req.b, (long int)req.c, (long int)req.d, (long int)req.e, (long int)req.f, (long int)req.g, (long int)req.h, (long int)req.i
          );
  ROS_INFO("sending back response: [%.2f]", (float)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}