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
#include "bb_dlgwalledit.h"
#include "bb_level.h"
#include <iostream>
#include <QtGui>

using namespace std;

BB_DlgWallEdit::BB_DlgWallEdit( BB_Wall * wall, BB_DocComponent * docComponent , QWidget * parent, Qt::WFlags f )
        : QDialog( parent, f )
{
    setWindowTitle ( tr( "Eigenschaften von einer Wand" ) );
    m_level = docComponent;
    m_wall = wall;
	m_CentralWidget = new BB_DlgWallEditArea( wall, docComponent );
	m_PreviewWidget = new BB_DlgWallEditPreview( wall, docComponent );

    initilize();
}


BB_DlgWallEdit::~BB_DlgWallEdit()
{}

void BB_DlgWallEdit::initilize()
{
    QScrollArea * scroll = new QScrollArea();
    scroll->setWidget( m_CentralWidget );
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( scroll );
    layout->addWidget( m_PreviewWidget );
    setLayout( layout );
    // 	setFixedHeight(500);
}

void BB_DlgWallEdit::paintEvent ( QPaintEvent * pe )
{
    m_CentralWidget->repaint();
}
void BB_DlgWallEdit::resizeEvent ( QResizeEvent * re )
{
    m_CentralWidget->update();
}



BB_DocComponent* BB_DlgWallEdit::getLevel() const
{
    return m_level;
}


void BB_DlgWallEdit::setLevel( BB_DocComponent* Value )
{
    m_level = Value;
}


BB_Wall* BB_DlgWallEdit::getWall() const
{
    return m_wall;
}


void BB_DlgWallEdit::setWall( BB_Wall* Value )
{
    m_wall = Value;
}
