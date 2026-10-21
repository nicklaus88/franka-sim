#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gz_ros2_control::gz_ros2_control-system" for configuration "Release"
set_property(TARGET gz_ros2_control::gz_ros2_control-system APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gz_ros2_control::gz_ros2_control-system PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgz_ros2_control-system.so"
  IMPORTED_SONAME_RELEASE "libgz_ros2_control-system.so"
  )

list(APPEND _cmake_import_check_targets gz_ros2_control::gz_ros2_control-system )
list(APPEND _cmake_import_check_files_for_gz_ros2_control::gz_ros2_control-system "${_IMPORT_PREFIX}/lib/libgz_ros2_control-system.so" )

# Import target "gz_ros2_control::gz_hardware_plugins" for configuration "Release"
set_property(TARGET gz_ros2_control::gz_hardware_plugins APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gz_ros2_control::gz_hardware_plugins PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgz_hardware_plugins.so"
  IMPORTED_SONAME_RELEASE "libgz_hardware_plugins.so"
  )

list(APPEND _cmake_import_check_targets gz_ros2_control::gz_hardware_plugins )
list(APPEND _cmake_import_check_files_for_gz_ros2_control::gz_hardware_plugins "${_IMPORT_PREFIX}/lib/libgz_hardware_plugins.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
