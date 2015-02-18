project(experiment)

cmake_minimum_required(VERSION 2.8.1)
cmake_policy(SET CMP0015 NEW)

set (GRID_LOCATION ../grid)
set (AGENT_LOCATION ../agent)

include_directories(${GRID_LOCATION}/include ${AGENT_LOCATION}/include)
link_directories(${GRID_LOCATION}/build ${AGENT_LOCATION}/build)

add_executable(experiment src/run_sim.cpp)
target_link_libraries(experiment grid agent)
