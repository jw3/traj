TARGET = autocombo
TEMPLATE = app

QT += core \
    gui
    
HEADERS += AutoCombo.h
SOURCES += AutoCombo.cpp \
    main.cpp
    

DESTDIR = ../build
MOC_DIR = $$DESTDIR/_$$TARGET
UI_DIR = $$DESTDIR/_$$TARGET
RCC_DIR = $$DESTDIR/_$$TARGET
OBJECTS_DIR = $$DESTDIR/_$$TARGET

CONFIG += qt debug uitools

QMAKE_CXXFLAGS += -std=c++0x