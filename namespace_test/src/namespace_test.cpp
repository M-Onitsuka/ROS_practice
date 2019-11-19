#include <iostream>
#include <string>

#include "ros/ros.h"
#include "std_msgs/String.h"

class TestListener{
private:
  std::string topic_name;
  std::string getdata;
  ros::Subscriber sub;
  ros::NodeHandle* nh;
public:
  TestListener(ros::NodeHandle* nh, std::string topic_name) : nh(nh), topic_name(topic_name)
  {
    sub = nh->subscribe(topic_name, 1000, &TestListener::Callback, this);
  }
  void Callback(const std_msgs::String::ConstPtr& msg){
    getdata = msg->data;
  }
  void Show(){
    if(!getdata.empty()){
      ROS_INFO("I get %s", getdata.c_str());
      getdata.clear();
    }
  }
};

int main(int argc, char **argv){
  ros::init(argc, argv, "namespace_test");
  ros::NodeHandle nh("");
  // std::string topic_name("input");
  std::string topic_name("/input");
  TestListener tl(&nh, topic_name);
  while(ros::ok()){
    tl.Show();
    ros::spinOnce();
  }
}
