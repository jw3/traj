#############################################################################
# Makefile for building: build/trajgui
# Generated by qmake (2.01a) (Qt 4.7.4) on: Wed Sep 26 12:15:48 2012
# Project:  trajui.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile trajui.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -std=c++0x -g -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtUiTools -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I../traj -I../trajdb -Ibuild -Ibuild
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -L../traj/Debug -ltraj -L../trajdb/Debug -ltrajdb -L../trajdb/lib -lQtXml -lQtGui -lQtCore -lQtUiTools -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = TrajTableModel.cpp \
		TrajFrame.cpp \
		TrajTableView.cpp \
		TrajBulletTreeModel.cpp \
		main.cpp build/moc_TrajTableModel.cpp \
		build/moc_TrajFrame.cpp \
		build/moc_TrajTableView.cpp \
		build/moc_ValidationFields.cpp \
		build/moc_TrajBulletTreeModel.cpp \
		build/qrc_rc.cpp
OBJECTS       = build/TrajTableModel.o \
		build/TrajFrame.o \
		build/TrajTableView.o \
		build/TrajBulletTreeModel.o \
		build/main.o \
		build/moc_TrajTableModel.o \
		build/moc_TrajFrame.o \
		build/moc_TrajTableView.o \
		build/moc_ValidationFields.o \
		build/moc_TrajBulletTreeModel.o \
		build/qrc_rc.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/uitools.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		trajui.pro
QMAKE_TARGET  = trajgui
DESTDIR       = build/
TARGET        = build/trajgui

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_TrajFrame.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) build/ || $(MKDIR) build/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: trajui.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/uitools.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/i386-linux-gnu/libQtXml.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl \
		/usr/lib/i386-linux-gnu/libQtUiTools.prl
	$(QMAKE) -o Makefile trajui.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/uitools.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/i386-linux-gnu/libQtXml.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
/usr/lib/i386-linux-gnu/libQtUiTools.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile trajui.pro

dist: 
	@$(CHK_DIR_EXISTS) build/trajgui1.0.0 || $(MKDIR) build/trajgui1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/trajgui1.0.0/ && $(COPY_FILE) --parents TrajTableModel.h TrajFrame.h TrajTableView.h ValidationFields.h TrajBulletTreeModel.h TreeNodes.h build/trajgui1.0.0/ && $(COPY_FILE) --parents rc.qrc build/trajgui1.0.0/ && $(COPY_FILE) --parents TrajTableModel.cpp TrajFrame.cpp TrajTableView.cpp TrajBulletTreeModel.cpp main.cpp build/trajgui1.0.0/ && $(COPY_FILE) --parents TrajFrame.ui build/trajgui1.0.0/ && (cd `dirname build/trajgui1.0.0` && $(TAR) trajgui1.0.0.tar trajgui1.0.0 && $(COMPRESS) trajgui1.0.0.tar) && $(MOVE) `dirname build/trajgui1.0.0`/trajgui1.0.0.tar.gz . && $(DEL_FILE) -r build/trajgui1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_TrajTableModel.cpp build/moc_TrajFrame.cpp build/moc_TrajTableView.cpp build/moc_ValidationFields.cpp build/moc_TrajBulletTreeModel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_TrajTableModel.cpp build/moc_TrajFrame.cpp build/moc_TrajTableView.cpp build/moc_ValidationFields.cpp build/moc_TrajBulletTreeModel.cpp
build/moc_TrajTableModel.cpp: TrajTableModel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) TrajTableModel.h -o build/moc_TrajTableModel.cpp

build/moc_TrajFrame.cpp: build/ui_TrajFrame.h \
		TrajBulletTreeModel.h \
		TreeNodes.h \
		ITreeNode.h \
		TrajFrame.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) TrajFrame.h -o build/moc_TrajFrame.cpp

build/moc_TrajTableView.cpp: TrajTableView.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) TrajTableView.h -o build/moc_TrajTableView.cpp

build/moc_ValidationFields.cpp: ValidationFields.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ValidationFields.h -o build/moc_ValidationFields.cpp

build/moc_TrajBulletTreeModel.cpp: TreeNodes.h \
		ITreeNode.h \
		TrajBulletTreeModel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) TrajBulletTreeModel.h -o build/moc_TrajBulletTreeModel.cpp

compiler_rcc_make_all: build/qrc_rc.cpp
compiler_rcc_clean:
	-$(DEL_FILE) build/qrc_rc.cpp
build/qrc_rc.cpp: rc.qrc \
		resources/reload.png \
		resources/save.png \
		resources/cancel.png
	/usr/bin/rcc -name rc rc.qrc -o build/qrc_rc.cpp

compiler_image_collection_make_all: build/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) build/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_TrajFrame.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_TrajFrame.h
build/ui_TrajFrame.h: TrajFrame.ui \
		TrajTableView.h \
		ValidationFields.h \
		ValidationFields.h
	/usr/bin/uic-qt4 TrajFrame.ui -o build/ui_TrajFrame.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/TrajTableModel.o: TrajTableModel.cpp TrajTableModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/TrajTableModel.o TrajTableModel.cpp

build/TrajFrame.o: TrajFrame.cpp TrajFrame.h \
		build/ui_TrajFrame.h \
		TrajBulletTreeModel.h \
		TreeNodes.h \
		ITreeNode.h \
		ValidationFields.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/TrajFrame.o TrajFrame.cpp

build/TrajTableView.o: TrajTableView.cpp TrajTableView.h \
		TrajTableModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/TrajTableView.o TrajTableView.cpp

build/TrajBulletTreeModel.o: TrajBulletTreeModel.cpp TrajBulletTreeModel.h \
		TreeNodes.h \
		ITreeNode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/TrajBulletTreeModel.o TrajBulletTreeModel.cpp

build/main.o: main.cpp TrajFrame.h \
		build/ui_TrajFrame.h \
		TrajBulletTreeModel.h \
		TreeNodes.h \
		ITreeNode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o main.cpp

build/moc_TrajTableModel.o: build/moc_TrajTableModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_TrajTableModel.o build/moc_TrajTableModel.cpp

build/moc_TrajFrame.o: build/moc_TrajFrame.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_TrajFrame.o build/moc_TrajFrame.cpp

build/moc_TrajTableView.o: build/moc_TrajTableView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_TrajTableView.o build/moc_TrajTableView.cpp

build/moc_ValidationFields.o: build/moc_ValidationFields.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_ValidationFields.o build/moc_ValidationFields.cpp

build/moc_TrajBulletTreeModel.o: build/moc_TrajBulletTreeModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_TrajBulletTreeModel.o build/moc_TrajBulletTreeModel.cpp

build/qrc_rc.o: build/qrc_rc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_rc.o build/qrc_rc.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

