cmake_minimum_required(VERSION 3.12)
project(MyProject VERSION 1.0.0)

add_library(
    say-hello  SHARED
    hello.hpp
    hello.cpp
)

add_executable(output main.cpp)

target_link_libraries(output PRIVATE say-hello)