/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                             *
*   v.ustinov@web.de                                                                                   *
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
#include "bb_toollinenew.h"

#include <iostream>
#include <bb_point.h>

#include <bb_workarea.h>
#include <bb_widgettoollinenew.h>


///@todo m_Tmp_Line auf m_TmpWall umstellen

using namespace std;



BB_ToolLineNew::BB_ToolLineNew( QWidget *parent )
        : BB_AbstractTool(parent)
{

	m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolWall.png" );
//     m_movedPoint = NULL;
}


BB_ToolLineNew::~BB_ToolLineNew()
{}


void BB_ToolLineNew::click( QMouseEvent* me )
{
    if ( m_Objects != NULL && me != NULL && m_Transformer != NULL )
    {
        m_pScreen = me->pos();
        m_Transformer->screenToLogical( m_pLogic, m_pScreen );

        m_LastLogicMouseClick = m_pLogic;
        m_MovePoint.setPos( m_pLogic );

        clearSelection();

        BB_Line* line = getClickedLine( m_pLogic );

        if ( line != NULL )
        {

			selectObject( line );


            m_Tmp_Line = NULL;
        }
        else
        {
            BB_Point* point = getClickedPoint( m_pLogic );
            if ( point != NULL )
            {
                m_Tmp_Line = createNewLine( point, &m_MovePoint );
                m_ToolObjects->append( m_Tmp_Line );
            }
            else
            {
                m_Tmp_Line = NULL;
            }
            // EDIT: Alex Letkemann
            // Andere Implementierung
            //         BB_DrawObject * object;
            //
            //         for ( int i = 0; i < m_Objects->count(); i++ )
            //         {
            //             object = m_Objects->at( i );
            //             //--------zur presentation
            //             /// @todo bitte bessere implementierung von Scale Funktion
            //             if ( object->getClassName() == "BB_Point" )
            //                 ( ( BB_Point * ) object ) ->setScale( m_Transformer->getScale() );
            //             //---------ende-----------
            //             if ( object->isHit( m_pLogic ) && ( object->getClassName() == "BB_Point" ) )
            //             {
            //                 C2dVector fromhitobject = ( ( BB_Point* ) object ) ->getPos();
            //                 cout << "New Line : Point :" << fromhitobject.x() << endl;
            //                 BB_Point *tmpPoint = new BB_Point( m_pLogic );	///@todo tmpPoint wird nicht aus dem Speicher entfernt
            //                 m_movedPoint = tmpPoint;
            //                 BB_Wall *wall = new BB_Wall( ( BB_Point* ) object, tmpPoint );
            //                 m_Tmp_Line = wall;
            //                 m_Objects->append( wall );
            //                 m_LastLogicMouseClick = m_pLogic;
            //                 return ;
            //             }
            //             /// @todo zum testen, nach implementation bitte loeschen.
            //             if ( object->isHit( m_pLogic ) && ( object->getClassName() == "BB_Wall" ) )
            //             {
            //                 ( ( BB_Wall * ) object ) ->editDlg( getDocComponent() );
            //                 return ;
            //             }
            //         }
        }

        updateWidget();
    }
}

void BB_ToolLineNew::move( QMouseEvent* me, bool overX, bool overY )
{
    if ( m_Objects != NULL &&
            me != NULL &&
            m_Transformer != NULL &&
            !overX &&
            !overY )
    {

        C2dVector moveTmp;
        m_Transformer->screenToLogical( m_pLogic, me->pos() );
        moveTmp.setX( m_pLogic.x() - m_LastLogicMouseClick.x() );
        moveTmp.setY( m_pLogic.y() - m_LastLogicMouseClick.y() );

        //                  cout << "m_LastLogicMouseClick.x:" << m_LastLogicMouseClick.x();
        //                  cout << "m_LastLogicMouseClick.y:" << m_LastLogicMouseClick.y()<<endl;
        //
        //                  cout << "m_pLogic.x:" << m_pLogic.x();
        //                  cout << "m_pLogic.y:" << m_pLogic.y()<<endl;
        //
        //                  cout << "moveTmp.x:" << moveTmp.x();
        //                  cout << "moveTmp.y:" << moveTmp.y()<<endl;

        //         m_movedPoint->moveBy( moveTmp );

        m_MovePoint.moveBy( moveTmp );
        m_LastLogicMouseClick = m_pLogic;
    }
}

void BB_ToolLineNew::release( QMouseEvent* me )
{
    if ( m_Objects != NULL && me != NULL && m_Transformer != NULL )
    {

        if ( m_Tmp_Line != NULL )
        {
            m_pScreen = me->pos();
            m_Transformer->screenToLogical( m_pLogic, m_pScreen );

            BB_Point* point = getClickedPoint( m_pLogic );

            if ( point != NULL && m_Tmp_Line->setPos2( point ) )
            {
                m_Objects->append( m_Tmp_Line );
                m_MovePoint.removeLinkedObject( m_Tmp_Line );

                clearSelection();
                m_Tmp_Line->setSelected( true );
                m_Selection->append( m_Tmp_Line );
            }
            else
            {
                m_MovePoint.removeLinkedObject( m_Tmp_Line );
                delete m_Tmp_Line;
            }

            m_Tmp_Line = NULL;
            m_ToolObjects->clear();
            updateWidget();
        }

        // 		EDIT: Alex Letkemann
        // 		Andere Implementierung
        //
        //
        //
        //         BB_DrawObject * object;
        //
        //         m_pScreen = me->pos();
        //         m_Transformer->screenToLogical( m_pLogic, m_pScreen );
        //
        //         for ( int i = 0; i < m_Objects->count(); i++ )
        //         {
        //
        //             object = m_Objects->at( i );
        //
        //             if ( object->isHit( m_pLogic ) && ( object->getClassName() == "BB_Point" ) )
        //             {
        //
        //                 C2dVector fromhitobject = ( ( BB_Point* ) object ) ->getPos();
        //                 cout << "Old Line : Point :" << fromhitobject.x() << endl;
        //
        //                 if ( !m_Tmp_Line->setPos2( ( BB_Point* ) object ) )
        //                 {
        //                     //                     delete m_Tmp_Line;
        //                 }
        //                 m_Tmp_Line = NULL;
        //                 //delete m_movedPoint;
        //                 m_movedPoint = NULL;
        //                 return ;
        //             }
        //         }
        //
        //         deleteObject( m_Tmp_Line );
        //         m_Tmp_Line = NULL;
        //         m_movedPoint = NULL;
    }
}



/*!
    \fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolLineNew::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolLineNew( this );
    }

    return m_ToolWidget;
}


/*!
    \fn BB_ToolLineNew::getClickedPoint( C2dVector& pos )
 */
BB_Point* BB_ToolLineNew::getClickedPoint( C2dVector& pos )
{
    return ( BB_Point* ) getClickedObject( pos, typeid( BB_Point ) );
}


/*!
    \fn BB_ToolLineNew::createNewLine( BB_Point* p1, BB_Point* p2 )
 */
BB_Line* BB_ToolLineNew::createNewLine( BB_Point* p1, BB_Point* p2 )
{
    return new BB_Line( p1, p2 );
}


/*!
    \fn BB_ToolLineNew::getClickedLine()
 */
BB_Line* BB_ToolLineNew::getClickedLine( C2dVector& pos )
{
    return ( BB_Line* ) getClickedObject( pos, typeid( BB_Line ) );
}
