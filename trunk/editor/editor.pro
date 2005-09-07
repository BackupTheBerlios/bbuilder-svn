# Diese Datei wurde mit dem qmake-Manager von KDevelop erstellt. 
# ------------------------------------------- 
# Unterverzeichnis relativ zum Projektverzeichnis: ./editor
# Das Target ist eine Anwendung:  editor.e

FORMS += buildingEdit.ui 
IDLS += buildingEdit.ui 
HEADERS += bb_abstracttool.h \
           bb_building.h \
           bb_data.h \
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
           bb_toollinenew.h 
SOURCES += bb_abstracttool.cpp \
           bb_building.cpp \
           bb_data.cpp \
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
           bb_toollinenew.cpp 
buildingEdit.ui.target = buildingEdit.ui
buildingEdit.ui.commands = $$IDL_COMPILER
TARGET = editor.e
DESTDIR = ../bin
CONFIG += release \
warn_on
TEMPLATE = app
