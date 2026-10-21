# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target franka_spine_msgs::franka_spine_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${franka_spine_msgs_TARGETS}.
if(franka_spine_msgs_TARGETS AND NOT TARGET franka_spine_msgs::franka_spine_msgs)
  add_library(franka_spine_msgs::franka_spine_msgs INTERFACE IMPORTED)
  set_target_properties(franka_spine_msgs::franka_spine_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${franka_spine_msgs_TARGETS}")
endif()
