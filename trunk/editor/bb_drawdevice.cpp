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

BB_DrawDevice::BB_DrawDevice()
{
}


/**
 * Destrucktor
 * Löscht alle Objekte
 */
BB_DrawDevice::~BB_DrawDevice()
{
	BB_DrawObject* object;
	
	for(int i = 0; i < m_DrawObjects.count(); i++)
	{
		object = m_DrawObjects.at(i);
		if(object != NULL)
		{
			delete object;
		}
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
	return &m_DrawObjects;
}
