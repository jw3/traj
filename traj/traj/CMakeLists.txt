project(traj2)
cmake_minimum_required(VERSION 2.8)


message("building Traj lib")

add_library(traj-atmos TrajAtmosphere.cpp)
add_library(traj-bc TrajBC.cpp)
add_library(traj-traj Trajectory.cpp)
add_library(traj-range TrajRangeData.cpp)
add_library(traj-vectors TrajVector.cpp)
