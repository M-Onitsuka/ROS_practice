#include <iostream>
#include <vector>
#include <string>
#include <ros/ros.h>
#include <yaml-cpp/yaml.h>

class TestClass{
private:
  std::string config_address;
  std::vector<int> my_param_v;
  double my_param;
  YAML::Node conf;
  ros::NodeHandle nh;
public:
  TestClass() : nh("~")
  {
    // ros::param::get("~config_address", config_address);
    nh.getParam("config_address", config_address);
    std::cout << "hello" << std::endl;
    std::cout << config_address << std::endl;
    // nh.param("hoge", my_param, 0.0);
    // nh.param("hoge_v", my_param_v, std::vector<int>(3,0));
    conf = YAML::LoadFile(config_address);
    my_param = conf["my_param"].as<double>();
    my_param_v = conf["my_param_v"].as<std::vector<int> >();
  }

  void Show(){
    std::cout << my_param << std::endl;
    for(auto itr=my_param_v.begin();itr!=my_param_v.end();itr++){
      std::cout << *itr << " ";
    }
    std::cout << std::endl;
  }
};
