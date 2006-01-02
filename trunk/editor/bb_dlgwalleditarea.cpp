/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   v.ustinov@web.de                                                      *
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
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#include "bb_dlgwalleditarea.h"
#include "bb_dlgwalledit.h"
#include "bb_level.h"
#include "bb_window.h"
#include <iostream>
#include <QPainter>

using namespace std;

BB_DlgWallEditArea::BB_DlgWallEditArea( BB_Wall * wall, BB_DocComponent * docComponent, QWidget * parent, Qt::WFlags f )
        : QLabel( parent, f )
{
    //zum testen, feste hoehe von 3,2 meter
    double hohe_meter = 3.2;
    double laenge_pixel = wall->getLength();
    double laenge_meter = docComponent->getMeterPerPixel( laenge_pixel );
    m_height = hohe_meter;
    m_lenght = laenge_meter;
    double m_verhaeltniss = m_lenght / m_height;
    m_Wall = wall;
    setFixedSize ( 400 * m_verhaeltniss, 400 );
    m_Tool = NULL;
    m_DrawObjects = NULL;
    m_DrawObjects = wall->getObjects();

    m_Selection = new QVector<BB_DrawObject *>;
    m_ToolObjects = new QVector<BB_DrawObject *>;
    // 	setMinimumSize ( 400 * m_verhaeltniss, 400);
}


BB_DlgWallEditArea::~BB_DlgWallEditArea()
{
	delete m_Selection;
	delete m_ToolObjects;
}


void BB_DlgWallEditArea::paintEvent ( QPaintEvent * pe )
{
    QLabel::paintEvent( pe );
    QPainter painter( this );
    painter.drawRect( 0, 0, width() - 1, height() - 1 );
    if ( m_DrawObjects != NULL )
    {
        BB_DrawObject * tmpElement;
        for ( int i = 0; i < m_DrawObjects->count(); i++ )
        {
            tmpElement = m_DrawObjects->at( i );
            tmpElement->show( m_transformer, painter );
        }
    }
    else
    {
        qDebug( "m_DrawObjects ist nicht initialisiert: in BB_DlgWallEditArea" );
    }

    for ( int i = 0;i < m_ToolObjects->count() ;i++ )
    {
        m_ToolObjects->at( i ) ->show( m_transformer, painter );
    }

}

void BB_DlgWallEditArea::resizeEvent ( QResizeEvent * re )
{}


/**
 * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
 */
void BB_DlgWallEditArea::mousePressEvent ( QMouseEvent * me )
{
    if ( m_Tool != NULL )
    {
        m_Tool->click( me );
        // 		update();
    }
    else
    {
        cout << "Kein Tool ausgewählt" << endl;
    }
}

/**
 * Wird aufgerufen, wenn eine Maustaste losgelassen wird.
 */
void BB_DlgWallEditArea::mouseReleaseEvent( QMouseEvent* me )
{
    if ( m_Tool != NULL )
    {
        m_Tool->release( me );
        update();
    }
    else
    {
        cout << "Kein Tool ausgewählt" << endl;
    }

    /* Mouseevent weiterleiten, damit das BB_TabXXXXX es mitkriegt */
    QLabel::mouseReleaseEvent( me );
}


/**
 * Wird aufgerufen, wenn die Maus mit einer gedrückten Maustaste bewegt wird.
 */
void BB_DlgWallEditArea::mouseMoveEvent( QMouseEvent* me )
{

    if ( m_Tool != NULL )
    {
        bool overX, overY;
        overX = ( me->pos().x() < 0 || me->pos().x() > width() );
        overY = ( me->pos().y() < 0 || me->pos().y() > height() );

        m_Tool->move( me, overX, overY );
        update();
    }
    else
    {
        qDebug() << "Kein Tool ausgewählt" << endl;
    }
}

void BB_DlgWallEditArea::setTool( BB_AbstractTool * tool )
{
    if ( tool != NULL )
    {
        if ( m_Tool != NULL )
        {
            m_Tool->reset();
        }

        for ( int i = 0; i < m_DrawObjects->count(); i++ )
        {
            m_DrawObjects->at( i ) ->setSelected( false );
        }

        m_Tool = tool;
        if ( typeid( * tool ) == typeid( BB_ToolMove ) )
        {
            m_Tool->setObjects( m_Wall->getPoints() );
            for ( int i = 0; i < m_DrawObjects->count(); i++ )
            {
                m_DrawObjects->at( i ) ->setSelected( true );
            }
        }
        m_Tool->setSelectionVector( m_Selection );
        m_Tool->setToolObjects( m_ToolObjects );
        m_Tool->setTransformer( &m_transformer );
        //         m_Tool->setTransformer( &m_Transformer );
        // 		m_Tool->setObjects(m_DrawObjects);
        //         m_Tool->setToolObjects( &m_ToolObjects );
        //         m_Tool->setSelectionVector( m_Selection );
        //         m_Tool->setDocComponent( m_Component );
    }
    else
    {
        QMessageBox::critical ( this, "Fehler (BB_WorkFrame)", "Fehler beim setzten des Tools.\nNULL-Pointer erhalten", QMessageBox::Ok, QMessageBox::NoButton );
    }
    update();
}
