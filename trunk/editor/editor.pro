# Diese Datei wurde mit dem qmake-Manager von KDevelop erstellt. 
# ------------------------------------------- 
# Unterordner relativ zum Projektordner: ./editor
# Das Target ist eine Anwendung:  editor.e

FORMS += buildingEdit.ui \
         projectNew.ui \
         fileOptions.ui 
IDLS += fileOptions.ui 
HEADERS += bb_abstracttool.h \
           bb_building.h \
           bb_doc.h \
           bb_drawobject.h \
           bb_level.h \
           bb_mainwindow.h \
           bb_object.h \
           bb_point.h \
           bb_tabbuilding.h \
           bb_tab.h \
           bb_tablevel.h \
           bb_tabterrain.h \
           bb_terrain.h \
           bb_toolmove.h \
           bb_toolpointnew.h \
           bb_toolzoom.h \
           bb_transformer.h \
           bb_workarea.h \
           bb_workframe.h \
           bb_line.h \
           bb_config.h \
           bb_toollinenew.h \
           bb_dlgprojectnew.h \
           bb_wall.h \
           bb_dwpoint.h \
           c2dvector.h \
           bb_fileobject.h \
           bb.h \
           bb_xdochandler.h \
           bb_xhandler.h \
           bb_xbuildinghandler.h 
SOURCES += bb_abstracttool.cpp \
           bb_building.cpp \
           bb_doc.cpp \
           bb_drawobject.cpp \
           bb_level.cpp \
           bb_mainwindow.cpp \
           bb_object.cpp \
           bb_point.cpp \
           bb_tabbuilding.cpp \
           bb_tab.cpp \
           bb_tablevel.cpp \
           bb_tabterrain.cpp \
           bb_terrain.cpp \
           bb_toolmove.cpp \
           bb_toolpointnew.cpp \
           bb_toolzoom.cpp \
           bb_transformer.cpp \
           bb_workarea.cpp \
           bb_workframe.cpp \
           main.cpp \
           bb_line.cpp \
           bb_config.cpp \
           bb_toollinenew.cpp \
           bb_dlgprojectnew.cpp \
           bb_wall.cpp \
           bb_dwpoint.cpp \
           c2dvector.cpp \
           bb_fileobject.cpp \
           bb.cpp \
           bb_xdochandler.cpp \
           bb_xhandler.cpp \
           bb_xbuildinghandler.cpp 
TARGET = editor.e
DESTDIR = ../bin
CONFIG += release \
warn_on
TEMPLATE = app
QT += xml
