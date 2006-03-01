//
// C++ Implementation: bb_map
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_map.h"

#include <iostream>

using namespace std;

/**
 * Konstruktor
 */
BB_Map::BB_Map()
{
    m_Zoom = 1;
    m_MapFileName = "";
}


/**
 * Destruktor
 */
BB_Map::~BB_Map()
{}



/**
 * Gibt das Bild der Map zurück
 * @return Bild der Map
 * @author Alex Letkemann
 */
QPixmap& BB_Map::getMap()
{
    return m_Map;
}

/**
 * Setzt des Bild der Map
 * @param map Das neue Bild der Map
 * @author Alex Letkemann
 */
void BB_Map::setMap( const QPixmap& map )
{
   
	if( &map != NULL)
	{
		m_Map = map;
		mapChanged();
	}
   
}


/**
 * Gibt den Zoomfaktor der Map zurück
 * @return Zoomfaktor der Map
 * @author Alex Letkemann
 */
double BB_Map::getZoom() const
{
    return m_Zoom;
}


/**
 * Setzt den Zoomfaktor der Map
 * @param z Zoomfaktor der Map
 * @author Alex Letkemann
 */
void BB_Map::setZoom( double theValue )
{
    m_Zoom = theValue;
}

/**
 * Gibt den Dateinamen der Map zurück
 * @return Dateiname der Map
 * @author Alex Letkemann
 */
QString BB_Map::getMapFileName() const
{
    return m_MapFileName;
}

/**
 * Setzt den Dateinamen der Map
 * @param filename Dateiname der Map
 * @author Alex Letkemann
 */
void BB_Map::setMapFileName( const QString& name )
{
    if ( &name != NULL && !name.isEmpty() )
    {
        m_MapFileName = name;
    }
    else
    {
        cout << "BB_Map::setMapFileName(..): Ungültigen Dateinamen erhalten" << endl;
    }
}

/**
 * Lädt die Bilddatei aus dem Verzeichnis 'path'.
 * @param path Verzeichnis, aus dem die Bilddatei (m_MapFileName) geladen wird.
 * @return True, wenn die Bilddatei erfolgreich geladen werden konnte, sonst False
 * @author Alex Letkemann
 */
bool BB_Map::loadMap( QDir& path )
{
    bool exit;

    if ( !m_MapFileName.isEmpty() )
    {
        QImage img;
        exit = img.load( path.path() + QDir::separator() + m_MapFileName, "PNG" );
        if ( exit )
        {
            m_Map = QPixmap::fromImage( img );
			mapChanged();
        }
    }
    else
    {
        exit = false;
    }

	
    return exit;
}


/**
 * Wird aufgerufen, wenn sich die Map geändert hat, bzw. wenn die Map geladen wurde. 
 * @author Alex Letkemann
 */
void BB_Map::mapChanged()
{
	/* Virtuelle Methode: Hier keine implementierung */
}
