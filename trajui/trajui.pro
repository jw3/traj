TEMPLATE = app
TARGET = trajui
QT += core \
    gui \
    sql
HEADERS += tablemodel.h \
    trajectoryui.h
SOURCES += tablemodel.cpp \
    main.cpp \
    trajectoryui.cpp
FORMS += tablemodel.ui \
    trajectoryui.ui
RESOURCES += 
LIBS += -L../traj/Debug -ltraj
INCLUDEPATH += ../traj
