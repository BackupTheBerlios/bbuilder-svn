//
// C++ Interface: bb_terrainpoint
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TERRAINPOINT_H
#define BB_TERRAINPOINT_H

#include <bb_point.h>

/**
 * Gel&auml;ndepunkt.
 * Der Gel&auml;ndepunkt esitzt neben den Eigenschaften des normalen Punktes
 * noch zus&auml;tzlich eine Eigenschaft, die die H&ouml;he des Punktes beschreibt.
 * Damit ist es m&ouml;glich den Punkt im dreidimensionalen Raum zu plazieren.
 * Die H&ouml;he des Punktes wird in Metern angegeben.
 *	@author Alex Letkemann <alex@letkemann.de>
 **/
class BB_TerrainPoint : public BB_Point
{
public:
	/**
	 * Konstruktor.
	 * Erzeugt einen neuen GeländePunkt an der Position 'pos' in der H&ouml;he 0m. 
	 * @param pos Position an der der Punkt erstellt wird
	 * @author Alex Letkemann
	 */
	BB_TerrainPoint( C2dVector& pos );

	/**
	 * Destruktor
	 * @author Alex Letkemann
	 */
    ~BB_TerrainPoint();
	
	/**
	 * Setzt die H&ouml;he des Punktes.
	 * @param value H&oumlhe des Punktes in Metern.
	 * @author Alex Letkemann
	 */
	void setHeight( double value );
	
	/**
	 * Gibt die H&ouml;he des Punktes in Metern zur&uuml;ck.
	 * @return H&ouml;he des Punktes in Metern.
	 * @author Alex Letkemann
	 */
	double getHeight() const;
    virtual const QString getClassName();
	

protected:
	/** H&ouml;he des Punktes */
    double m_Height;
};

#endif
