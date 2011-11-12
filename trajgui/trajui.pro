TEMPLATE = app

QT += core \
    gui \
    sql
    
HEADERS += TrajTableModel.h \
	TrajFrame.h \
	TrajTableView.h \
	ValidationFields.h
	
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

DESTDIR = ./build
TARGET = trajgui
MOC_DIR = $$DESTDIR
UI_DIR = $$DESTDIR
RCC_DIR = $$DESTDIR
OBJECTS_DIR = $$DESTDIR

CONFIG += qt debug uitools

QMAKE_CXXFLAGS += -std=c++0x