cmake_minimum_required(VERSION 3.12)
project(CMyProject0 VERSION 1.0.0)
# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the shared library (Defalt is STATIC)
add_library(say-hello SHARED src/hello.cpp)

# Specify the include directories 
# so that hello.hpp is accessible to targets that link against this library.
target_include_directories(say-hello PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Add the executable target
add_executable(my_app src/main.cpp)

# Link the shared library to the executable
target_link_libraries(my_app PRIVATE say-hello)