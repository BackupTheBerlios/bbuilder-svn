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
 * BB_DrawDevice enthält alle Objekte, die auf der Arbeitoberfläche gezeichnet werden 
 * und ist vor allem für die saubere Abräuming der Objekte zuständig.<br>
 * Per Offset können alle Objekte verschoben werden.
 * @author Alex Letkemann
 */
class BB_DrawDevice{
public:
    /**
     * Konstruktor
     */
    BB_DrawDevice();

    /**
	 * Destruktor
	 * Löscht alle Objekte, die noch im DrawDevice sind.
	 * @author Alex Letkemann
	 * @date 23.11.2005
	 */
	virtual ~BB_DrawDevice();
	
	
    /**
     * Gibt den Pointer auf einen Vektor mit allen Objekten zurück 
	 * @return Pointer auf einen Vektor mit allen Objekten
	 * @author Alex Letkemann
     */
    virtual QVector<BB_DrawObject*>* getDrawObjects();

	
	/**
	 * Setzt den Offset
	 * @param value Offset
	 * @author Alex Letkemann
	 */
	void setOffset( const C2dVector& value );
	

	/**
	 * Gibt den Offset zurück
	 * @return Offset
	 */
	const C2dVector& getOffset() const;
	

protected:
	/** Vektor, der alle Objekte enthält */
    QVector<BB_DrawObject*> m_DrawObjects;
	
	/** Offset */
    C2dVector m_Offset;
};

#endif
