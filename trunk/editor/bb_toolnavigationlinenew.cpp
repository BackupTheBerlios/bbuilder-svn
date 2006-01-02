//
// C++ Implementation: bb_toolnavigationlinenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolnavigationlinenew.h"
#include <bb_navigationline.h>

BB_ToolNavigationLineNew::BB_ToolNavigationLineNew(QWidget* parent): BB_ToolLineNew(parent)
{
}


BB_ToolNavigationLineNew::~BB_ToolNavigationLineNew()
{
}


BB_Line* BB_ToolNavigationLineNew::createNewLine(BB_Point* p1, BB_Point* p2)
{
	return (BB_Line*) new BB_NavigationLine(p1, p2);
}

BB_Line* BB_ToolNavigationLineNew::getClickedLine(C2dVector& pos)
{
	return (BB_Line*) getClickedObject( pos, typeid( BB_NavigationLine ) );
}

BB_Point* BB_ToolNavigationLineNew::getClickedPoint(C2dVector& pos)
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_NavigationPoint ));
}

