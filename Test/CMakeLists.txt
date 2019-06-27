cmake_minimum_required(VERSION 3.9)
project(Test)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

add_executable(Test main.cpp)
target_link_libraries(Test ${OpenCV_LIBS})
