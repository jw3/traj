project(traj2)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("building Traj GUI")

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(traj2_HEADERS TrajBulletTreeModel.h TrajFrame.h TrajTableModel.h TrajTableView.h)

QT4_WRAP_CPP(traj2_HEADERS_MOC ${traj2_HEADERS})
QT4_WRAP_UI(traj2_FORMS_HEADERS TrajFrame.ui)
QT4_ADD_RESOURCES(traj2_RESOURCES_RCC rc.qrc)

ADD_EXECUTABLE(traj2 ${traj2_SOURCES} 
    ${traj2_HEADERS_MOC} 
    ${traj2_FORMS_HEADERS} 
    ${traj2_RESOURCES_RCC})

TARGET_LINK_LIBRARIES(traj2 ${QT_LIBRARIES})
