project(traj2)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${traj2_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

include(MacroOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build.")


add_subdirectory(traj)
add_subdirectory(trajdb)
add_subdirectory(trajgui)



######## tidbits
# -- add all files of type to a list
# file(GLOB hellworld_SOURCES *.cpp)