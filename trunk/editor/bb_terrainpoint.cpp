//
// C++ Implementation: bb_terrainpoint
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_terrainpoint.h"

BB_TerrainPoint::BB_TerrainPoint( )
	: BB_Point( )
{
	m_Height = 0.0;
}

BB_TerrainPoint::BB_TerrainPoint( C2dVector& pos )
 : BB_Point( pos )
{
	m_Height = 0.0;
}


BB_TerrainPoint::~BB_TerrainPoint()
{
}




double BB_TerrainPoint::getHeight() const
{
    return m_Height; 
}


void BB_TerrainPoint::setHeight( double value )
{
    m_Height = value;
}


/*!
    \fn BB_TerrainPoint::getClassName()
 */
const QString BB_TerrainPoint::getClassName()
{
	return QString( "BB_TerrainPoint" );
}


/*!
    \fn BB_TerrainPoint::generateXElement( QTextStream &out, int depth )
 */
void BB_TerrainPoint::generateXElement( QTextStream &out, int depth )
{
	out << BB::indent( depth ) << "<bb_terrainpoint id=\"" << getObjectNr() 
			<< "\" x=\"" << getX() 
			<< "\" y=\"" << getY() 
			<< "\" h=\"" << m_Height
			<< "\">\n";
	BB_Object::generateXElement( out, depth + 1 );
	out << BB::indent( depth ) << "</bb_terrainpoint>\n";
}
