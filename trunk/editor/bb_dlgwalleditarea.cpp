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
#include <iostream>
#include <QPainter>

using namespace std;

BB_DlgWallEditArea::BB_DlgWallEditArea( BB_Wall * wall, BB_DocComponent * docComponent, QWidget * parent, Qt::WFlags f )
        : QLabel( parent, f )
{
	//zum testen, feste hoehe von 3,2 meter
	double hohe_meter = 3.2;
    double laenge_pixel = wall->getLength();
	double laenge_meter = docComponent->getMeterPerPixel( laenge_pixel);
	m_height = hohe_meter;
	m_lenght = laenge_meter;
	double m_verhaeltniss = m_lenght / m_height;
	setFixedSize ( 400 * m_verhaeltniss, 400);
// 	setMinimumSize ( 400 * m_verhaeltniss, 400);
}


BB_DlgWallEditArea::~BB_DlgWallEditArea()
{}


void BB_DlgWallEditArea::paintEvent ( QPaintEvent * pe )
{
    QLabel::paintEvent( pe );
    QPainter painter( this );
	painter.drawRect(0,0,width()-1, height()-1);
}

void BB_DlgWallEditArea::resizeEvent ( QResizeEvent * re){
}
