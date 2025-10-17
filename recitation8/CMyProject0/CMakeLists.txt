cmake_minimum_required(VERSION 3.12)
project(CMyProject0 VERSION 1.0.0)
# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(say-hello STATIC hello.cpp)

# Specify the include directories (optional, here ommited because the headers are in the same folder)
# target_include_directories(say-hello PUBLIC ${CMAKE_SOURCE_DIR})

# Add an executable
add_executable(output main.cpp)

# Link the executable with the library
target_link_libraries(output PRIVATE say-hello)