# CMake generated Testfile for 
# Source directory: /home/nick/franka_ros2_ws/src/franka_gazebo/franka_gazebo_hardware
# Build directory: /home/nick/franka_ros2_ws/build/franka_gazebo_hardware
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(gravity_compensation_model_test "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/nick/franka_ros2_ws/build/franka_gazebo_hardware/test_results/franka_gazebo_hardware/gravity_compensation_model_test.gtest.xml" "--package-name" "franka_gazebo_hardware" "--output-file" "/home/nick/franka_ros2_ws/build/franka_gazebo_hardware/ament_cmake_gmock/gravity_compensation_model_test.txt" "--command" "/home/nick/franka_ros2_ws/build/franka_gazebo_hardware/gravity_compensation_model_test" "--gtest_output=xml:/home/nick/franka_ros2_ws/build/franka_gazebo_hardware/test_results/franka_gazebo_hardware/gravity_compensation_model_test.gtest.xml")
set_tests_properties(gravity_compensation_model_test PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/nick/franka_ros2_ws/build/franka_gazebo_hardware/gravity_compensation_model_test" TIMEOUT "60" WORKING_DIRECTORY "/home/nick/franka_ros2_ws/build/franka_gazebo_hardware" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock_test.cmake;98;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;90;ament_add_gmock_test;/home/nick/franka_ros2_ws/src/franka_gazebo/franka_gazebo_hardware/CMakeLists.txt;111;ament_add_gmock;/home/nick/franka_ros2_ws/src/franka_gazebo/franka_gazebo_hardware/CMakeLists.txt;0;")
subdirs("gmock")
subdirs("gtest")
