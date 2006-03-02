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

/**
 * Konstruktor. Erstellt ein neues Wand-Werkzeug.
 * @param parent Parent-Fenster
 * @author Alex Letkemann
 */
BB_ToolWallNew::BB_ToolWallNew( QWidget* parent ) : BB_ToolLineNew( parent )
{}

/**
 * Destructor
 */
BB_ToolWallNew::~BB_ToolWallNew()
{}

/**
 * @fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolWallNew::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolWallNew( this );
    }

    return m_ToolWidget;
}

/**
 * Erstellt eine Wand zwischen den beiden angegebenen Punkten und gibt diese zurück.
 * @param p1 Punkt 1
 * @param p2 Punkt 2
 * @return Neue Wand
 */
BB_Line* BB_ToolWallNew::createNewLine( BB_Point* p1, BB_Point* p2 )
{
    return ( BB_Line* ) new BB_Wall( p1, p2 );
}

/**
 * Sucht und gibt die zuerst gefundene Wand an der angegebenen Position zurück.
 * Falls keine Wand an der angegebenen Position existiert, wird NULL zurückgegeben.
 * @param pos Position, an der gescuht werden soll.
 * @return Wand oder NULL
 */
BB_Line* BB_ToolWallNew::getClickedLine( C2dVector& pos )
{
    return ( BB_Line * ) getClickedObject( pos, typeid( BB_Wall ) );
}

