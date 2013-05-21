project(traj2)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("building TrajDB")

add_library(trajdb-bulletdata BulletData.cpp)
add_library(trajdb-caliberdata CaliberData.cpp)
add_library(trajdb-mfgdata MfgData.cpp)
add_library(trajdb-db TrajDatabase.cpp)

add_library(sqlite3 sqlite3.c)
