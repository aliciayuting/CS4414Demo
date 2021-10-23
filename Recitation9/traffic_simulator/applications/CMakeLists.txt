cmake_minimum_required(VERSION 3.0.0)

add_executable(
  simulator 
  event.hpp event.cpp
  simulator.cpp
)

target_link_libraries(
  simulator
  LINK_PRIVATE
  csv_reader
  controller
)

add_executable(
  iconmaker
  iconmaker.cpp
)

target_link_libraries(
  iconmaker
  LINK_PRIVATE
  pngwriter
)
