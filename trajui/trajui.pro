TEMPLATE = app
TARGET = trajui
QT += core \
    gui \
    sql
HEADERS += trajectoryui.h
SOURCES += main.cpp \
    trajectoryui.cpp
FORMS += trajectoryui.ui
RESOURCES += 
LIBS += -L../traj/Debug -ltraj
INCLUDEPATH += ../traj
