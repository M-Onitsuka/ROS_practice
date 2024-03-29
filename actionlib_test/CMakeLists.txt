cmake_minimum_required(VERSION 2.8.3)
project(actionlib_test)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  roscpp
  roseus
  rospy
  std_msgs
  )

find_package(Boost REQUIRED COMPONENTS
  system
  )

add_action_files(
  DIRECTORY action
  FILES
  Fibonacci.action
)

generate_messages(
  DEPENDENCIES
  actionlib_msgs
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  actionlib
  actionlib_msgs
  roscpp
  roseus
  rospy
  std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(fibonacci_server src/fibonacci_server.cpp)
add_executable(fibonacci_client src/fibonacci_client.cpp)

target_link_libraries(fibonacci_server
  ${catkin_LIBRARIES}
)

target_link_libraries(fibonacci_client
  ${catkin_LIBRARIES}
)

add_dependencies(
  fibonacci_server
  ${actionlib_test_EXPORTED_TARGETS}
  )
