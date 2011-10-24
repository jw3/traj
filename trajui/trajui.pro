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
FORMS += trajectoryui.ui
RESOURCES += rc.qrc
LIBS += -L../traj/Debug \
    -ltraj \
    -L../trajdb/Debug \
    -ltrajdb \
    -L../trajdb/lib \
    -lsqlite3
INCLUDEPATH += ../traj \
    ../trajdb
