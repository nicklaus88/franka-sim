# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_franka_vision_and_manipulation_kit_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED franka_vision_and_manipulation_kit_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(franka_vision_and_manipulation_kit_FOUND FALSE)
  elseif(NOT franka_vision_and_manipulation_kit_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(franka_vision_and_manipulation_kit_FOUND FALSE)
  endif()
  return()
endif()
set(_franka_vision_and_manipulation_kit_CONFIG_INCLUDED TRUE)

# output package information
if(NOT franka_vision_and_manipulation_kit_FIND_QUIETLY)
  message(STATUS "Found franka_vision_and_manipulation_kit: 3.6.0 (${franka_vision_and_manipulation_kit_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'franka_vision_and_manipulation_kit' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT franka_vision_and_manipulation_kit_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(franka_vision_and_manipulation_kit_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${franka_vision_and_manipulation_kit_DIR}/${_extra}")
endforeach()
