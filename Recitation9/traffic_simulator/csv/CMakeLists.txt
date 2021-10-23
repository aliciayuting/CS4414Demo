cmake_minimum_required(VERSION 3.0.0)

add_library(
  csv_reader
  SHARED
  csv_reader.hpp csv_reader.cpp
)

target_include_directories(
  csv_reader
  PUBLIC
  ${traffic_simulator_SOURCE_DIR}
)
