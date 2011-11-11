TEMPLATE = app

QT += core \
    gui \
    sql
    
HEADERS += TrajTableModel.h \
	TrajFrame.h \
	TrajTableView.h
	
SOURCES += TrajTableModel.cpp \
	TrajFrame.cpp \
	TrajTableView.cpp \
    main.cpp
    
RESOURCES += rc.qrc

LIBS += -L../traj/Debug \
    -ltraj \
    -L../trajdb/Debug \
    -ltrajdb \
    -L../trajdb/lib
    
INCLUDEPATH += ../traj \
    ../trajdb
    
FORMS = TrajFrame.ui

TARGET = trajgui
MOC_DIR = ./build
OBJECTS_DIR = ./build
DESTDIR = ./build

CONFIG += qt debug uitools

QMAKE_CXXFLAGS += -std=c++0x