/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
***************************************************************************/
#include "bb_toolpointnew.h"
#include <bb_widgettoolpointnew.h>

#include <iostream>

using namespace std;

/**
 * Konstruktor.
 * Erstellt ein neues Werkzeug zur Erstellung von Punkten
 * @author Alex Letkemann
 */
BB_ToolPointNew::BB_ToolPointNew(QWidget * parent)
        : BB_AbstractTool(parent)
{
	m_Point = NULL;
	m_Icon = QIcon ( IMG_DIR() + SEPARATOR() + "toolPoint.png" );
	m_Selection = NULL;
}

/**
 * Destruktor
 */
BB_ToolPointNew::~BB_ToolPointNew()
{}


/**
 * Pr&uuml;ft, ob ein Punkt angeclickt wurde und selektiert diesen.
 * Wenn kein Punkt angeclickt wurde, wird ein neuer erzeigt und dieser selectiert.
 * @param me MouseClickEvent
 * @author Alex Letkemann, Vaceslav Ustinov
 * @date 27.12.2005
 */
void BB_ToolPointNew::click( QMouseEvent* me )
{

    if ( m_Objects != NULL && me != NULL )
    {
        m_Transformer->screenToLogical( m_LastLogicMouseClick, me->pos() );
//         clearSelection();

        m_pScreen = me->pos();
        m_Transformer->screenToLogical( m_pLogic, m_pScreen );

        // Prüfen, ob ein bereits vorhandener Punkt angeclickt wurde
		m_Point = getClickedPoint( m_pLogic );

        // falls kein Punkt abgeclickt wurde, wird ein neuer Punkt erzeugt
        if ( m_Point == NULL )
        {
			m_Point = createNewPoint( m_pLogic );
			if( m_Point != NULL )
			{
            	m_Objects->append( m_Point );
			}
        }

		if ( me->modifiers () != Qt::ShiftModifier )
		{
			clearSelection();
		}

		if( m_Point != NULL )
		{
			selectObject( m_Point );
		}
        updateWidget();
    }
}




/**
 * Bewegt den selektierten Punkt.
 * @param me MouseMoveEvent
 * @param overX Gibt an wenn der Maus-Zeiger horizontal außerhalb des Workframes ist.
 * @param overY Gibt an wenn der Maus-Zeiger vertikal außerhalb des Workframes ist.
 */
void BB_ToolPointNew::move( QMouseEvent* me, bool overX, bool overY )
{
    //wenn die noetigen objekte nicht da sind, sofort abbrechen
    if ( m_Objects == NULL && me == NULL && m_Transformer == NULL )
    {
        qDebug( "BB_ToolMove::click()->Nicht alle objecte sind da!!!! m_Objects: %p \tme: %p\tm_Transformer: %p", m_Objects, me, m_Transformer );
        return ;
    }

    C2dVector moveTmp;
    for ( int i = 0; i < m_Selection->count(); i++ )
    {

        m_Transformer->screenToLogical( m_pLogic, me->pos() );
        moveTmp.setX( m_pLogic.x() - m_LastLogicMouseClick.x() );
        moveTmp.setY( m_pLogic.y() - m_LastLogicMouseClick.y() );
        //Uberpruefung, damit die punkte nicht auserrand geschoben werden
        ///@todo Funktioniert falsch!!!
        if ( overX )
        {
            moveTmp.setX( 0 );
        }
        if ( overY )
        {
            moveTmp.setY( 0 );
        }
        m_Selection->at( i ) ->moveBy( moveTmp );
    }
    //letzte mausposition merken
    m_Transformer->screenToLogical( m_LastLogicMouseClick, me->pos() );
	updateWidget();
}


/**
 * Wird aufgerufen, wenn die Maustaste losgelassen wird.
 * @param me MausReleaseEvent
 */
void BB_ToolPointNew::release( QMouseEvent* me )
{
    me->ignore();
    m_Point = NULL;
}


/*!
    \fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolPointNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = new BB_WidgetToolPointNew( this );
	}
	
	return m_ToolWidget;
}


/**
 * Die Funktion such nach einem Punkt an der Position 'pos'.
 * Wird ein Punkt an der angegebenen Position gefunden, wird der 
 * Zeiger des Punktes zur&uumlckgegeben. Falls nicht wird NULL zurückgegeben.
 * @param pos Position an der nach dem Punkt gesucht wird
 * @return Zeiger auf den gefundenen Punkt.
 */
BB_Point* BB_ToolPointNew::getClickedPoint( C2dVector& pos )
{
	BB_Point * point = ( BB_Point * ) getClickedObject( pos, typeid( BB_Point ) );
	return point;
}


/**
 * Die Funktion erzeugt einen neuen Punkt an der Position 'pos' und gibt den Zeiger
 * auf den neuen Punkt zur&uuml;ck
 * @param pos Position, an der der neue Punkt erzeugt wird.
 * @return Zeiger auf den neuen Punkt
 */
BB_Point* BB_ToolPointNew::createNewPoint( C2dVector& pos )
{
	// neunen Punkt erzeugen und zurückgeben
	return new BB_Point( pos );
}
