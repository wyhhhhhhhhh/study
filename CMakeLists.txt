cmake_minimum_required( VERSION 2.8)
project(biaoding)

# set( CMAKE_CXX_FLAGS "-std=c++11 -03")
find_package(OpenCV)
include_directories(${OpenCV})

add_executable(main src/main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
