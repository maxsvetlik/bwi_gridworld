project(grid)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_library(grid SHARED src/grid.cpp)
 
