project(opencv_save)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIR})

add_executable(opencv_save opencv_save.cpp)
target_link_libraries(opencv_save ${OpenCV_LIBRARIES})