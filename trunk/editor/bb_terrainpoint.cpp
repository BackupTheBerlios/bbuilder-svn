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
