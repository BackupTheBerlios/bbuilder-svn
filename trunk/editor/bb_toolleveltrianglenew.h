//
// C++ Interface: bb_toolleveltrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLLEVELTRIANGLENEW_H
#define BB_TOOLLEVELTRIANGLENEW_H

#include <bb_tooltrianglenew.h>

/**
 * Werkzeug zum markieren von Decken und Böden bei den Etagen.
 * Die Böden und Decken werden durch mehrere Dreiecke erstellt.
 * Ein Dreieck lässt sich durch anclicken von drei unterschiedlichen Knoten auf der Arbeitfläche erstellen.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolLevelTriangleNew : public BB_ToolTriangleNew
{
public:
	
	/**
	 * Konstriktor
	 */
    BB_ToolLevelTriangleNew(QWidget* parent);

	/**
	 * Destruktor
	 */
    ~BB_ToolLevelTriangleNew();

    /**
     * Erstellt ein neues Dreieck und gibt dieses zurück.
     * @return neues Dreieck
     */
    virtual BB_Triangle* createNewSurface();

};

#endif
