# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target franka_msgs::franka_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${franka_msgs_TARGETS}.
if(franka_msgs_TARGETS AND NOT TARGET franka_msgs::franka_msgs)
  add_library(franka_msgs::franka_msgs INTERFACE IMPORTED)
  set_target_properties(franka_msgs::franka_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${franka_msgs_TARGETS}")
endif()
