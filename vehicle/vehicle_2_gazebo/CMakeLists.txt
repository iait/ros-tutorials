cmake_minimum_required(VERSION 2.8.3)
project(vehicle_2_gazebo)

## Package
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)

catkin_package()

## Build
include_directories(
  ${catkin_INCLUDE_DIRS}
)
