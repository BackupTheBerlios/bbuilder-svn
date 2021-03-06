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
#include "bb_toolmove.h"
#include <iostream>
#include <math.h>
#include <bb_widgettoolselect.h>

using namespace std;

/**
Standart Konstruktor
@param parent Zeiger auf ein Widget zu dem dieser Tool gehört
@see BB_AbstractTool
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
BB_ToolMove::BB_ToolMove( QWidget * parent )
        : BB_AbstractTool( parent )
{




    m_ComparePoint = NULL;
    m_Rect.setPos1( &m_Point1 );
    m_Rect.setPos2( &m_Point2 );

    QPen pen;
    QColor p( 255, 221, 118, 210 );
    pen.setBrush( p );

    m_Rect.setPen( pen );

    QColor b( 255, 221, 118, 150 );
    m_Rect.setBrush( b );

    m_select = true;

    m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolMove.png" );
}

/**
Destruktor
*/

BB_ToolMove::~BB_ToolMove()
{}


// void BB_ToolMove::click(QMouseEvent* me)
// {
//     if(m_Objects != NULL && me != NULL && m_Transformer != NULL)
//     {
//       /**wenn ein Object selektiert wurde, wird dieser desectiert*/
//         if(m_Selection->count() == 1)
//         {
//             for(int i = 0; i < m_Selection->count(); i++)
//             {
//                 m_Selection->at(i)->setSelected(false);
//             }
//             m_Selection->clear();
//         }
//
//         BB_DrawObject *object;
//
//
//         m_pScreen = me->pos();
//         m_Transformer->screenToLogical(m_pLogic,m_pScreen);
//         m_LastLogicMouseClick = m_pLogic;
//
//         if(m_Selection->count() == 0)
//         {
//             for(int i = 0; i < m_Objects->count(); i++)
//             {
//                 object = m_Objects->at(i);
//                 //--------zur presentation
//                 if (object->getClassName() == "BB_Point")
//                     ((BB_Point *)object)->setScale(m_Transformer->getScale());
//                 //---------ende-----------
//                 if(object->isHit(m_pLogic))
//                 {
//                     //punkt loeschen
//                     if (me->button () ==  Qt::RightButton && object->getClassName() == "BB_Point")
//                     {
//                         BB_AbstractTool::remove
//                             (object);
//                         //((BB_Point *)object)->deleteLines(m_Objects);
//                         ((BB_Point *)object)->deleteLinkedObjects(m_Objects);
//                         delete object;
//                         return;
//                     }
//                     //Punkten ausrichten
//                     if (me->button() == Qt::MidButton && object->getClassName() == "BB_Point")
//                     {
//                         bringToLine((BB_Point *)object);
//                         //if(tabCreator != NULL)
//                         // tabCreator->createProperties(((BB_Point *)object)->getItemModel());
//                     }
//                     m_Selection->append(object);
//                 }
//             }
//         }
//     }
// }

/**
 * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
 * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
 * @author Alex Letkemann
 */

void BB_ToolMove::click( QMouseEvent* me )
{
    //wenn die noetigen objekte nicht da sind, sofort abbrechen
    if ( m_Objects == NULL | me == NULL | m_Transformer == NULL )
    {
        qDebug( "BB_ToolMove::click()->Nicht alle objecte sind da!!!! m_Objects: %p \tme: %p\tm_Transformer: %p", m_Objects, me, m_Transformer );
        return ;
    }
    //Behandlung von linke Maustaste
    if ( me->button() == Qt::LeftButton )
    {
        BB_DrawObject * object;

        m_pScreen = me->pos();
        m_Transformer->screenToLogical( m_pLogic, m_pScreen );
        m_LastLogicMouseClick = m_pLogic;

        //beim ersten click markieren und verschiebne
        for ( int i = 0;i < m_Objects->count() ;i++ )
        {
            object = m_Objects->at( i );
            if ( object == NULL )
                cout << "NULL pointer auf Object in bb_toolmove::click" << endl;
            //--------zur presentation
            ///@todo das muss irgentwie anders geloest werden
            if ( object->getClassName() == "BB_Point" )
                ( ( BB_Point * ) object ) ->setScale( m_Transformer->getScale() );
            //---------ende-----------
            if ( object->isHit( m_pLogic ) && !object->isSelected() )
            {
                //Ausrichtung. Die Objecte werden mit Shift Taste selectiert
                if ( me->modifiers () != Qt::ShiftModifier )
                {
                    clearSelection();
                }
                m_select = false;
                selectObject( object );
                qDebug( "Keine Objeckte sind selectiert, ein neues wurde selektiert" );
                if ( m_ToolWidget != NULL )
                {
                    m_ToolWidget->updateWidget();
                }
                return ;
            }
        }

        for ( int i = 0; i < m_Selection->count(); i++ )
        {
            object = m_Selection->at( i );
            //--------zur presentation
            ///@todo das muss irgentwie anders geloest werden
            if ( object->getClassName() == "BB_Point" )
                ( ( BB_Point * ) object ) ->setScale( m_Transformer->getScale() );
            //---------ende-----------
            if ( object->isHit( m_pLogic ) )
            {
                m_select = false;
                object->setSelected( true );
                qDebug( "es wurde auf einem Selektiertem Objekt gecklickt" );
                return ;
            }
        }
        //clearSelection();
        m_ClickPos = m_pLogic;

        m_Point1.setX( me->x() );
        m_Point1.setY( me->y() );

        m_Point2.setX( me->x() );
        m_Point2.setY( me->y() );

        if ( m_ToolObjects != NULL )
        {
            m_ToolObjects->append( &m_Rect );
        }
    }
}

//alte funktion von BB_ToolMove::move()
// void BB_ToolMove::move( QMouseEvent* me, bool overX, bool overY )
// {
//
//     if ( m_Objects != NULL && me != NULL && m_Transformer != NULL )
//     {
//
//         for ( int i = 0; i < m_Selection->count(); i++ )
//         {
//             C2dVector moveTmp;
//             m_Transformer->screenToLogical( m_pLogic, me->pos() );
//             moveTmp.setX( m_pLogic.x() - m_LastLogicMouseClick.x() );
//             moveTmp.setY( m_pLogic.y() - m_LastLogicMouseClick.y() );
//
//             if ( overX )
//             {
//                 moveTmp.setX( 0 );
//             }
//
//             if ( overY )
//             {
//                 moveTmp.setY( 0 );
//             }
//
//             m_Selection->at( i ) ->moveBy( moveTmp );
//         }
//
//         m_Transformer->screenToLogical( m_LastLogicMouseClick, me->pos() );
//     }
// }

/**
 * Die Methode wird aufgerufen, wenn die Maus bei beliebiger gedrückter Maustaste bewegt wird.
 * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
 * @param overX Gibt an, ob der Mauszeiger horizontal außerhalb der Arbeitsfläche ist (true).
 * @param overY Gibt an, ob der Mauszeiger vertikal außerhalb der Arbeitsfläche ist (true).
 * @author Alex Letkemann
 */

void BB_ToolMove::move( QMouseEvent* me, bool overX, bool overY )
{
    //wenn die noetigen objekte nicht da sind, sofort abbrechen
    if ( m_Objects == NULL | me == NULL | m_Transformer == NULL )
    {
        qDebug( "BB_ToolMove::click()->Nicht alle objecte sind da!!!! m_Objects: %p \tme: %p\tm_Transformer: %p", m_Objects, me, m_Transformer );
        return ;
    }
    //Behandlung von Linke-maustaste
    if ( me->buttons() == Qt::LeftButton )
    {
        //wenn Slected-mode ausgewaehlt, dann einfach viereck weiter schieben
        if ( m_select )
        {
            m_Point2.setX( me->x() );
            m_Point2.setY( me->y() );
        }
        //sonst alle punkte verschieben
        else
        {
            for ( int i = 0; i < m_Selection->count(); i++ )
            {
                C2dVector moveTmp;
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
        }
    }
}


//alte funktion von BB_ToolMove::release()
// void BB_ToolMove::release( QMouseEvent* me )
// {
//     /* Übergebene Variablen, die nicht verwendet werden */
//     me->ignore();
//     //     if (m_ComparePoint != NULL){
//     //       m_ComparePoint->setSelected(false);
//     //       m_ComparePoint = NULL;
//     //     }
// }

/**
 * Wird aufgerufen, wenn eine Maustaste los gelassen wird.
 * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
 * @author Alex	Letkemann
 */

void BB_ToolMove::release( QMouseEvent* me )
{
    //wenn release nach einer Verschiebung ausgefuert wurde,
    //dann einfach return ohne Aenderungen
    if ( !m_select )
    {
        m_select = true;
        documentChanged();
        return ;
    }
    //wenn die noetigen objekte nicht da sind, sofort abbrechen
    if ( m_Objects == NULL | me == NULL | m_Transformer == NULL )
    {
        qDebug( "BB_ToolMove::click()->Nicht alle objecte sind da!!!! m_Objects: %p \tme: %p\tm_Transformer: %p", m_Objects, me, m_Transformer );
        m_ToolWidget->updateWidget();
        return ;
    }
    //Behandlung nur von Linke-Maustaste
    if ( me->button() == Qt::LeftButton )
    {
        BB_DrawObject * object;

        //alle Objekte desektieren
        clearSelection();

        m_pScreen = me->pos();
        m_Transformer->screenToLogical( m_pLogic, m_pScreen );

        //Wenn die Position von Click und release kleiner als 10 dann werden max. ein Object ausgewaehlt
        //         if ( m_ClickPos.getAbstand( m_pLogic ) < 10 )
        if ( m_ClickPos.getAbstand( m_pLogic ) < 10 / m_Transformer->getScale() )
        {
            for ( int i = 0; i < m_Objects->count(); i++ )
            {
                object = m_Objects->at( i );
                if ( object->isHit( m_pLogic ) )
                {
                    selectObject( object );
                    //max 1 Object, also Abbrechen
                    break;
                }
            }
        }
        //Auswahlviereck
        else
        {
            QRectF rect( m_ClickPos.x(),
                         m_ClickPos.y(),
                         ( m_pLogic.x() - m_ClickPos.x() ),
                         ( m_pLogic.y() - m_ClickPos.y() ) );

            for ( int i = 0; i < m_Objects->count(); i++ )
            {
                object = m_Objects->at( i );
                if ( object->isHit( rect ) )
                {
                    selectObject( object );
                }
            }
        }
        if ( m_ToolObjects != NULL )
        {
            m_ToolObjects->clear();
        }
    }
    //wieder in Auswahl-Modus wechseln
    m_select = true;
    updateWidget();
}

/**
Selektiert alle Objekte in Vector m_Obejcts<br>
So können alle Objekte Verschoben oder gelösch werden
@author Vaceslav Ustinov <v.ustinov@web.de>
*/

void BB_ToolMove::selectAll()
{
    if ( m_Selection != NULL && m_Component != NULL )
    {
        m_Selection->clear();

        BB_DrawObject* object;

        for ( int i = 0; i < m_Component->getDrawObjects() ->count() ; i++ )
        {
            object = m_Component->getDrawObjects() ->at( i );
            selectObject( object );
        }

    }

    documentChanged();
}


/**
 * Gibt das Eigenschftsfenster des Tools zurück.
 * @return Eigenschftsfenster des Tools.
 * @author Alex Letkemann
 */
BB_AbstractToolWidget* BB_ToolMove::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolSelect( this );
    }

    return m_ToolWidget;
}
