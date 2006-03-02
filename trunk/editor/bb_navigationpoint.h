//
// C++ Interface: bb_navigationpoint
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_NAVIGATIONPOINT_H
#define BB_NAVIGATIONPOINT_H

#include <bb_point.h>

/**
 * Navigationspunkt.<br />
 * Ein Navigationspunkt kann Indizierte werden, oder auch nicht.
 * Indizierte Navigationspunkte sind die Stellen, die man im Menu des Renderers auswählen kann und sich dahin leiten lassen kann.
 * Die nicht Indizierten Punkte tauchen im Menu nicht auf, sie dienen nur als Zwischenpunkte auf der Route.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_NavigationPoint : public BB_Point
{
public:
	/**
	 * Konstruktor 
	 */
    BB_NavigationPoint(C2dVector p);

	/**
	 * Destruktor
	 */
    ~BB_NavigationPoint();

	/**
	 * Setzt den Indizierungsstatus
	 * @param value True: Indiziert, False: nicht Indiziert
	 * @author Alex Letkemann
	 */
	void setIndexed( bool value );
	
	/**
	 * Gibt den Indizierungsstatus zurück.
	 * @return Indizierungsstatus
	 * @author Alex Letkemann
	 */
	bool getIndexed() const;
	
	/**
	 * @fn BB_Object::getClassName()
	 */
    virtual const QString getClassName();
	

protected:
	/** Indizierungsstatus */
    bool m_Indexed;
};

#endif
