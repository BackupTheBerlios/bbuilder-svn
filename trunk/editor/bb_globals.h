//
// C++ Interface: bb_globals
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef BB_GLOBALS_H
#define BB_GLOBALS_H

#include <QString>

/**
Setzt aktuelle binäre-Verzeichnis fest
*/
QString BIN_DIR();
/**
Setzt aktuelle Programm-Verzeichnis fest
*/
QString MAIN_DIR();
/**
Setzt aktuelle Image-Verzeichnis fest
*/
QString IMG_DIR();
/**
Setzt aktuelle Verzeichnis mit Konfiguration-dateien fest
*/
QString CONF_DIR();
/**
Gibt platformabhängige Separator zurück
*/
QString SEPARATOR();
/**
Gibt Projektverzeichnis zurück
*/
QString PRO_DIR();
/**
Gibt aktuelle Verzeichnis mit XML-Files von Gebäuden zurück
*/
QString PRO_BUILDINGS_DIR();
/**
Gibt aktuelle Verzeichnis mit XML-Files von Etagen zurück
*/
QString PRO_LEVELS_DIR();
/**
Gibt aktuelle Verzeichnis mit XML-File von Gelände zurück
*/
QString PRO_TERRAINS_DIR();
/**
Gibt aktuelle Verzeichnis mit Texturen zurück
*/
QString PRO_TEXTURES_DIR();
/**
Setzt aktuelle Projekverzeichnis fest
*/
void setPRO_DIR( QString s );
/**
 * Setzt die Pfade des Programms.
 * @param argv0 Parameter-Array des Programms
 */
void setDirs( char *argv0 );

#endif
