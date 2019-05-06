cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Num.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  AddTwoInts.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

## The catkin_package macro generates cmake config files for your package
catkin_package(
  CATKIN_DEPENDS
  roscpp
  rospy
  std_msgs
  message_runtime
)

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(hello src/hello.cpp)
add_executable(talker src/talker.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(hello ${catkin_LIBRARIES})
target_link_libraries(talker ${catkin_LIBRARIES})
