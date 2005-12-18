//
// C++ Interface: bb_drawdevice
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DRAWDEVICE_H
#define BB_DRAWDEVICE_H

#include "bb_drawobject.h"

/**
 * @author Alex Letkemann
 */
class BB_DrawDevice{
public:
    /**
     * Konstruktor
     */
    BB_DrawDevice();

    /**
	 * Destrucktor
	 * Löscht alle Objekte, die noch im DrawDevice sind.
	 * @author Alex Letkemann
	 * @date 23.11.2005
	 */
	virtual ~BB_DrawDevice();
	
	
    /**
     * Gibt den Pointer auf einen Vektor mit allen Objekten zurück 
	 * @return Pointer auf einen Vektor mit allen Objekten
     */
    virtual QVector<BB_DrawObject*>* getDrawObjects();

protected:
	/** Vektor, der alle Objekte enthält */
    QVector<BB_DrawObject*> m_DrawObjects;
};

#endif
