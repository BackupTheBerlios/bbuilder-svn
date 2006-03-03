//
// C++ Implementation: bb_globals
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//


/**
 * Datei enthält alle globalen Variablen und Funktionen.
 * BIN_DIR(): Pfad zum Verzeichnis wo die  ausführbare Datei liegt.
 * MAIN_DIR(): Pfad zu Hauptverzeichnis des Programms.
 * IMG_DIR(): Pfad, in welchem alle Grafiken des Programms untergebracht sind.
 * CONF_DIR(): Pfad zum Konfiguraionsordner des Programms.
 * SEPARATOR(): Separator des Dateisystems des Aktuellen Betriebssystems.
 * Die Pfade werden mit der Funktion setDirs(..) gesetzt und sind danach global erreichbar.
 * @author Alex Letkemann
 * @date 27.10.2005
 */

#include <QtCore>
#include <iostream>

#include "bb_globals.h"

using namespace std;

/**
Verzeichnis von binäre Files liegen
*/
QString bin_dir;
/**
Hauptverzeichniss. Hier liegt das Programm selb und dazu nötige Dateien (conf, image)
*/
QString main_dir;
/**
Verzeichnis wo die Bilder liegen
*/
QString img_dir;
/**
verzeichniss mit Konfigurationsfile
*/
QString conf_dir;
/**
Platformabhängige Separator
*/
QString separator;
/**
Verzeichnis von aktuellen Projekt
*/
QString pro_dir;

/**
Gibt Projektverzeichnis zurück
*/
QString PRO_DIR()
{
    return pro_dir;
}
/**
Gibt aktuelle Verzeichnis mit XML-Files von Gebäuden zurück
*/
QString PRO_BUILDINGS_DIR()
{
    return pro_dir + SEPARATOR() + "buildings";
}
/**
Gibt aktuelle Verzeichnis mit XML-Files von Etagen zurück
*/
QString PRO_LEVELS_DIR()
{
    return pro_dir + SEPARATOR() + "levels";
}
/**
Gibt aktuelle Verzeichnis mit XML-File von Gelände zurück
*/
QString PRO_TERRAINS_DIR()
{
    return pro_dir + SEPARATOR() + "terrain";
}
/**
Gibt aktuelle Verzeichnis mit Texturen zurück
*/
QString PRO_TEXTURES_DIR()
{
    return pro_dir + SEPARATOR() + "textures";
}
/**
Setzt aktuelle Projekverzeichnis fest
*/
void setPRO_DIR( QString s )
{
    pro_dir = s;
}
/**
Setzt aktuelle binäre-Verzeichnis fest
*/
QString BIN_DIR()
{
    return bin_dir;
}
/**
Setzt aktuelle Programm-Verzeichnis fest
*/
QString MAIN_DIR()
{
    return main_dir;
}
/**
Setzt aktuelle Image-Verzeichnis fest
*/
QString IMG_DIR()
{
    return img_dir;
}
/**
Setzt aktuelle Verzeichnis mit Konfiguration-dateien fest
*/
QString CONF_DIR()
{
    return conf_dir;
}
/**
Gibt platformabhängige Separator zurück
*/
QString SEPARATOR()
{
    return separator;
}

/**
 * Setzt die Pfade des Programms.
 * @param argv0 Parameter-Array des Programms
 */
void setDirs( char * argv0 )
{
    QFileInfo binaryFile( argv0 );
    QDir dir( binaryFile.dir() );


    separator = QDir::separator();

    dir.makeAbsolute();
    bin_dir = dir.path();

    dir.cdUp();
    main_dir = dir.path();

    if ( !dir.cd( "img" ) )
    {
        dir.mkdir( "img" );
        dir.cd( "img" );
    }
    img_dir = dir.path();

    dir.cdUp();
    if ( !dir.cd( "conf" ) )
    {
        dir.mkdir( "conf" );
        dir.cd( "conf" );
    }

    conf_dir = dir.path();


    cout << "MAIN_DIR: " << main_dir.toStdString() << endl;
    cout << "BIN_DIR: " << bin_dir.toStdString() << endl;
    cout << "CONF_DIR: " << conf_dir.toStdString() << endl;
    cout << "IMG_DIR: " << img_dir.toStdString() << endl;


}
