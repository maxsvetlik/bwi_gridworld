project(experiment)

set (GRID_LOCATION /home/matish/programmi/bwi_gridworld/grid/)
set (AGENT_LOCATION /home/matish/programmi/bwi_gridworld/agent/)

cmake_minimum_required(VERSION 2.6)

include_directories(${GRID_LOCATION}/include ${AGENT_LOCATION}/include)
link_directories(${GRID_LOCATION}/build ${AGENT_LOCATION}/build)

add_executable(experiment src/run_sim.cpp)
target_link_libraries(experiment grid agent)
 
 
