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

#include <QPainter>
#include "bb_dlgwalleditpreview.h"
#include "bb_transformer.h"

BB_DlgWallEditPreview::BB_DlgWallEditPreview( BB_Wall * wall, BB_DocComponent * docComponent, QWidget * parent , Qt::WFlags f )
        : QLabel( parent, f )
{
    initilize( wall, docComponent );
}

void BB_DlgWallEditPreview::initilize( BB_Wall * wall, BB_DocComponent * docComponent )
{

    /**
    * Transformer um die Bildschirm-Koordinaten auszurechnen.
    * Hier braucht man keinen speziellen Transformer von der WorkArea oder WorkFrame.
    * die ist eine selbstaendige "Programm"
    * Bmerkung: die OffSet in Hauptprogramm muss auf 0,0 stehen!!!
    */
    BB_Transformer transformer;
    QPoint p1;
    QPoint p2;

    transformer.logicalToScreen( p1, wall->getPos1() ->getPos() );
    transformer.logicalToScreen( p2, wall->getPos2() ->getPos() );

    m_rect.setTopLeft( p1 );
    m_rect.setBottomRight( p2 );
    m_rect = m_rect.normalized();
    int optimale_hohe = 50;
    if ( m_rect.height() < optimale_hohe )
    {
        int old_height = m_rect.height();
        int differenz = optimale_hohe - old_height;
        m_rect.setHeight( optimale_hohe );
        m_rect.moveTop( m_rect.top() - ( differenz / 2 ) );
    }
    int optimale_breite = 50;
    if ( m_rect.width() < optimale_breite )
    {
        int old_width = m_rect.width();
        int differenz = optimale_breite - old_width;;
        m_rect.setWidth( optimale_breite );
        m_rect.moveLeft( m_rect.left() - ( differenz / 2 ) );
    }


    QMatrix m;
    m.rotate( wall->getWinkel() );

    QPixmap ausschnitt = docComponent->getMap().copy( m_rect ).transformed( m );

    if ( ausschnitt.height() > optimale_hohe )
    {
        QRect rect_optimize;
        //Standart einstellungen
        rect_optimize.setX( 0 );
        rect_optimize.setY( 0 );
        rect_optimize.setHeight( 50 );
        rect_optimize.setWidth( ausschnitt.width() );


        int differenz = ausschnitt.height() - optimale_hohe;
        rect_optimize.moveTop( differenz / 2 );

        rect_optimize = rect_optimize.normalized();

        ausschnitt = ausschnitt.copy( rect_optimize );
    }

    //     	setPixmap( docComponent->getMap());
    setPixmap( ausschnitt );
}


BB_DlgWallEditPreview::~BB_DlgWallEditPreview()
{}

void BB_DlgWallEditPreview::paintEvent ( QPaintEvent * pe )
{
    QLabel::paintEvent( pe );
    QPainter painter;
    painter.begin( this );
    painter.end();
}

