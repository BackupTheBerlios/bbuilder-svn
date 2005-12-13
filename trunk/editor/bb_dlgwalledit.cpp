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
#include <QtGui>

BB_DlgWallEdit::BB_DlgWallEdit( BB_Map * map, QWidget * parent, Qt::WFlags f )
        : QDialog( parent, f )
{
    setWindowTitle ( tr( "Eigenschaften von einer Wand" ) );
	m_CentralWidget = new BB_DlgWallEditArea(map);
    m_CentralWidget->setPixmap( map->getMap());
    initilize();
}


BB_DlgWallEdit::~BB_DlgWallEdit()
{}

void BB_DlgWallEdit::initilize()
{
    QScrollArea * scroll = new QScrollArea();
    scroll->setWidget( m_CentralWidget );
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget( scroll );
    setLayout( layout );
}

