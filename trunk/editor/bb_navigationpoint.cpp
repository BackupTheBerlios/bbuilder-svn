//
// C++ Implementation: bb_navigationpoint
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_navigationpoint.h"

BB_NavigationPoint::BB_NavigationPoint(C2dVector p): BB_Point(p)
{
	m_Indexed = false;
}


BB_NavigationPoint::~BB_NavigationPoint()
{
}




bool BB_NavigationPoint::getIndexed() const
{
    return m_Indexed;
}


void BB_NavigationPoint::setIndexed( bool value )
{
    m_Indexed = value;
}
