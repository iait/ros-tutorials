cmake_minimum_required(VERSION 2.8.3)
project(velodyne)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS roscpp std_msgs)

## Declare a C++ executable and libraries
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(velodyne_pub src/velodyne_pub.cpp)
target_link_libraries(velodyne_pub ${catkin_LIBRARIES})
