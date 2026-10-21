# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_franka_desk_api_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED franka_desk_api_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(franka_desk_api_FOUND FALSE)
  elseif(NOT franka_desk_api_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(franka_desk_api_FOUND FALSE)
  endif()
  return()
endif()
set(_franka_desk_api_CONFIG_INCLUDED TRUE)

# output package information
if(NOT franka_desk_api_FIND_QUIETLY)
  message(STATUS "Found franka_desk_api: 3.6.0 (${franka_desk_api_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'franka_desk_api' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT franka_desk_api_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(franka_desk_api_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${franka_desk_api_DIR}/${_extra}")
endforeach()
