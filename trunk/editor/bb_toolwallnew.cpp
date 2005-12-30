//
// C++ Implementation: bb_toolwallnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolwallnew.h"
#include <bb_wall.h>
#include <bb_widgettoolwallnew.h>

BB_ToolWallNew::BB_ToolWallNew( QWidget* parent ) : BB_ToolLineNew( parent )
{}


BB_ToolWallNew::~BB_ToolWallNew()
{}


BB_AbstractToolWidget* BB_ToolWallNew::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolWallNew( this );
    }

    return m_ToolWidget;
}

BB_Line* BB_ToolWallNew::createNewLine( BB_Point* p1, BB_Point* p2 )
{
    return ( BB_Line* ) new BB_Wall( p1, p2 );
}

BB_Line* BB_ToolWallNew::getClickedLine( C2dVector& pos )
{
    return ( BB_Line * ) getClickedObject( pos, typeid( BB_Wall ) );
}

