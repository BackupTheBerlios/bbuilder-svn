//
// C++ Implementation: bb_drawdevice
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_drawdevice.h"
#include "bb_point.h"

#include <iostream>

using namespace std;

BB_DrawDevice::BB_DrawDevice()
{}


/**
 * Destrucktor
 * Löscht alle Objekte, die noch im DrawDevice sind.
 */
BB_DrawDevice::~BB_DrawDevice()
{

    BB_DrawObject * object;

    /* Alle Punkte löschen.
    * Vorher werden alle Objekte gelöscht, 
    * die vom jeweiligen Punkt abhängig sind.
    */
    for ( int i = m_DrawObjects.count() - 1; i >= 0 ; i-- )
    {
        if ( typeid( *( m_DrawObjects.at( i ) ) ) == typeid( BB_Point ) )
        {
            object = m_DrawObjects.at( i );
            m_DrawObjects.remove( i );

            ( ( BB_Point* ) object ) -> deleteLinkedObjects( &m_DrawObjects );
            delete object;
        }
    }


    if ( m_DrawObjects.count() > 0 )
    {

        ///@todo Auf qDebug umstellen
        cout << "BB_Terrain::~BB_Terrain(): Nicht alle Objekte konnten gelöscht werden" << endl;
    }

    m_DrawObjects.clear();
}




/**
 * Gibt einen Pointer auf den Vektor mit allen Objekten zurück
 * @return Vektor mit allen Objekten
 * @author Alex Letkemann
 * @date 10.11.2005
 */
QVector<BB_DrawObject*>* BB_DrawDevice::getDrawObjects()
{
    return & m_DrawObjects;
}
