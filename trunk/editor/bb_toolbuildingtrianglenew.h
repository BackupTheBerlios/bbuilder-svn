//
// C++ Interface: bb_toolbuildingtrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLBUILDINGTRIANGLENEW_H
#define BB_TOOLBUILDINGTRIANGLENEW_H

#include <bb_tooltrianglenew.h>

/**
 * Werkzeug zur Markieren von Dächern und Gründen von Gebäuden.<br />
 * Die Gesamte Fläche wird aus mehreren Dreiecken zusamengesetzt.<br />
 * Ein Dreieck lässt sich druch anclicken von drei verschiedenen Knoten auf der Arbeitsfläche erstellen.
 * 
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolBuildingTriangleNew : public BB_ToolTriangleNew
{
public:
	/**
	 * Konstruktor
	 */
    BB_ToolBuildingTriangleNew(QWidget* parent);

	/**
	 * Destruktor
	 */
    ~BB_ToolBuildingTriangleNew();

protected:
	
    /**
     * Erzeugt ein neues Dreieck und gibt dieses zurück.
     * @return Neues Dreieck.
     */
    virtual BB_Triangle* createNewSurface();

};

#endif
