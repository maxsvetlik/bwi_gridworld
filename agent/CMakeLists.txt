project(agent)

set (GRID_LOCATION /home/matish/programmi/bwi_gridworld/grid/)

cmake_minimum_required(VERSION 2.6)

include_directories(${GRID_LOCATION}/include)

add_library(agent SHARED src/Agent.cpp)
 
 
