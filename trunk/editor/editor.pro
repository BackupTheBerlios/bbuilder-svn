# Diese Datei wurde mit dem qmake-Manager von KDevelop erstellt. 
# ------------------------------------------- 
# Unterverzeichnis relativ zum Projektverzeichnis: ./editor
# Das Target ist eine Anwendung:  editor.e

FORMS += buildingEdit.ui \
         projectNew.ui \
         fileOptions.ui \
         terrainEdit.ui 
IDLS += terrainEdit.ui 
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
           bb_xbuildinghandler.h \
           bb_rect.h \
           bb_toolselect.h \
           bb_propertywidget.h \
           bb_globals.h \
           bb_map.h \
           bb_dlgbuildingedit.h \
           bb_dlgterrainedit.h \
           bb_drawdevice.h \
           bb_doccomponent.h \
           bb_xterrainhandler.h \
           bb_dlgwalledit.h \
           bb_dlgwalleditarea.h \
           bb_triangle.h \
           bb_tooltrianglenew.h 
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
           bb_xbuildinghandler.cpp \
           bb_rect.cpp \
           bb_toolselect.cpp \
           bb_propertywidget.cpp \
           bb_globals.cpp \
           bb_map.cpp \
           bb_dlgbuildingedit.cpp \
           bb_dlgterrainedit.cpp \
           bb_drawdevice.cpp \
           bb_doccomponent.cpp \
           bb_xterrainhandler.cpp \
           bb_dlgwalledit.cpp \
           bb_dlgwalleditarea.cpp \
           bb_triangle.cpp \
           bb_tooltrianglenew.cpp 
TARGET = editor.e
DESTDIR = ../bin
CONFIG += debug \
warn_on
TEMPLATE = app
QT += xml
