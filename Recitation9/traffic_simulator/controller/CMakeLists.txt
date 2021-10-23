cmake_minimum_required(VERSION 3.0.0)

add_library(
  controller
  SHARED
  color.hpp
  traffic_controller.hpp traffic_controller.cpp
  traffic_light.hpp traffic_light.cpp
)

target_include_directories(
  controller
  PUBLIC
  ${traffic_simulator_SOURCE_DIR}
)
