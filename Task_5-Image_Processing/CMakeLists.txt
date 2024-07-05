cmake_minimum_required(VERSION 3.5)
project(Task_5-Image_Processing)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Task_5-Image_Processing main.cpp)
target_link_libraries(Task_5-Image_Processing ${OpenCV_LIBS})