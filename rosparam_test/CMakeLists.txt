cmake_minimum_required(VERSION 2.8.3)
project(rosparam_test)

## Compile as C++11, supported in ROS Kinetic and newer
FILE(READ "config/my_compile_option" contents)
list(GET contents 0 output_content)
message(${output_content})
add_compile_options(-std=c++11 ${output_content})

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
#  yaml-cpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(YAMC yaml-cpp REQUIRED)

catkin_package()

message("catkin_INCLUDE_DIRS:${catkin_INCLUDE_DIRS}")
message("catkin_LIBRARIES:${catkin_LIBRARIES}")
# message("yamc_INCLUDE_DIRS:${yamc_INCLUDE_DIRS}")
# message("yamc_LIBRARIES:${yamc_LIBRARIES}")
# message("yamc_LIBRARIES:${yamc_LIBRARY_DIRS}")
# message("yaml-cpp_LIBRARIES:${yaml-cpp_LIBRARIES}")

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/my_node.cpp)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  #yaml-cpp
  ${YAMC_LIBRARIES}
)
