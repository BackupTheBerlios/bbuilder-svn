//
// C++ Implementation: bb_toolnavigationpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolnavigationpointnew.h"
#include <bb_widgettoolnavigationpointnew.h>

BB_ToolNavigationPointNew::BB_ToolNavigationPointNew()
 : BB_ToolPointNew()
{
}


BB_ToolNavigationPointNew::~BB_ToolNavigationPointNew()
{
}




/*!
    \fn BB_ToolNavigationPointNew::createNewPoint( C2dVector& pos )
 */
BB_Point* BB_ToolNavigationPointNew::createNewPoint( C2dVector& pos )
{
	return new BB_NavigationPoint( pos );
}


/*!
    \fn BB_ToolNavigationPointNew::getClickedPoint( C2dVector& pos )
 */
BB_Point* BB_ToolNavigationPointNew::getClickedPoint( C2dVector& pos )
{
	return (BB_Point *) getClickedObject( pos, typeid( BB_NavigationPoint ) );
}


/*!
    \fn BB_ToolNavigationPointNew::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolNavigationPointNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = new BB_WidgetToolNavigationPointNew( this );
	}
	
	return m_ToolWidget;
}
