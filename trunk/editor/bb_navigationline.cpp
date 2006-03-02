//
// C++ Implementation: bb_navigationline
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_navigationline.h"


/**
 * Konstruktor.<br/>
 * Erstellt eine Navigationslinie zwischen den zwei übergebenen Navigationspunkten
 * @author Alex Letkemann
 */
BB_NavigationLine::BB_NavigationLine( BB_Point* p1, BB_Point* p2 )
        : BB_Line( p1, p2 )
{
	m_Pen.setColor( Qt::blue );
	m_Brush.setColor( Qt::blue );
}

/**
 * Destruktor 
 */
BB_NavigationLine::~BB_NavigationLine()
{}




/**
 * @fn BB_Object::getClassName()
 */
const QString BB_NavigationLine::getClassName()
{
    return QString( "BB_NavigationLine" );
}
