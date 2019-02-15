//#include "ros/ros.h"
//#include "std_msgs/String.h"
//#include <my_serial_node/Point3D.h>
//#include <my_serial_node/Quaternion.h>
//#include <my_serial_node/Sonar.h>
//#include <my_serial_node/Surround.h>

///**
// * This tutorial demonstrates simple receipt of messages over the ROS system.
// */
//void chatterCallback(const my_serial_node::Surround::ConstPtr& msg)
//{
//  for (int i =0; i < 12; i++) {
//    ROS_INFO("I heard: [%f]", msg->sonar[i].range);
//  }
//}

//int main(int argc, char **argv)
//{
//  ros::init(argc, argv, "listener");

//  ros::NodeHandle n;

//  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

//  ros::spin();

//  return 0;
//}


#include "ros/ros.h"
#include "std_msgs/String.h"
#include <my_serial_node/Point3D.h>
#include <my_serial_node/Quaternion.h>
#include <my_serial_node/Sonar.h>
#include <my_serial_node/Surround.h>

void chatterCallback(const my_serial_node::Surround::ConstPtr& msg)
{
  for (int i = 0; i < 12; i++) {  
    ROS_INFO("I heard sonar[%d] range: [%f]", i, msg->sonar[i].range);
    ROS_INFO("I heard sonar[%d] x: [%f]", i, msg->sonar[i].translation.x);
    ROS_INFO("I heard sonar[%d] y: [%f]", i, msg->sonar[i].translation.y);
    ROS_INFO("I heard sonar[%d] z: [%f]", i, msg->sonar[i].translation.z);
    ROS_INFO("I heard sonar[%d] qx: [%f]", i, msg->sonar[i].rotation.qx);
    ROS_INFO("I heard sonar[%d] qy: [%f]", i, msg->sonar[i].rotation.qy);
    ROS_INFO("I heard sonar[%d] qz: [%f]", i, msg->sonar[i].rotation.qz);
    ROS_INFO("I heard sonar[%d] qw: [%f]", i, msg->sonar[i].rotation.qw);
  }
  ROS_INFO("I heard the time is [%f] ms", msg->time);
}
int main(int argc, char **argv){
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/ab/sensor/ultrasonic_radar", 1000, chatterCallback);
  ros::spin();
  return 0;
}
