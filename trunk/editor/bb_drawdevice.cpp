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

/**
 * Konstruktor
 */
BB_DrawDevice::BB_DrawDevice()
{}


/**
 * Destruktor
 * Löscht alle Objekte, die noch im DrawDevice sind.
 * @author Alex Letkemann
 * @date 23.11.2005
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


    m_DrawObjects.clear();
}

/**
 * Gibt den Pointer auf einen Vektor mit allen Objekten zurück 
 * @return Pointer auf einen Vektor mit allen Objekten
 * @author Alex Letkemann
 */
QVector<BB_DrawObject*>* BB_DrawDevice::getDrawObjects()
{
    return & m_DrawObjects;
}

/**
 * Gibt den Offset zurück
 * @return Offset
 */
const C2dVector& BB_DrawDevice::getOffset() const
{
    return m_Offset;
}

/**
 * Setzt den Offset
 * @param value Offset
 * @author Alex Letkemann
 */
void BB_DrawDevice::setOffset( const C2dVector& value )
{
    m_Offset = value;
}
