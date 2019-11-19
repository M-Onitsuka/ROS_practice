#include <rosparam_test/my_library.h>

int main(int argc,char **argv){
  ros::init(argc, argv, "rosparam_test");
  TestClass tc;
  while(ros::ok()){
    std::cout << FOO << std::endl;
    tc.Show();
    ros::spinOnce();
  }
  return 0;
}
