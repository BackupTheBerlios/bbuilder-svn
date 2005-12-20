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
#ifndef BB_DLGWALLEDITPREVIEW_H
#define BB_DLGWALLEDITPREVIEW_H

#include <QLabel>
#include "bb_wall.h"

/**
	Dies ist ein kleines Fenster(Preview-window) in Dialog beim bearbeiten von einer Wand
 
	@author Vaceslav Ustinov <v.ustinov@web.de>
	@date 2005-12-19
*/
class BB_DlgWallEditPreview : public QLabel
{
    public:
        /**
        * Standart Konstruktor
        * @param BB_Wall * Zeiger auf ein Wand zu dem dieser Dialog geh&ouml;rt
        * @param BB_DocComponent * Zeiger auf DocComponent (bzw  @link BB_DocComponent @endlink )
        */
        BB_DlgWallEditPreview( BB_Wall * wall, BB_DocComponent * docComponent, QWidget * parent = 0, Qt::WFlags f = 0 );
        ~BB_DlgWallEditPreview();
    protected:
        /**
        * Rutine zum initiliasieren aller wichtigen einstellungen
        * es ist eine private Funktion und es wird nur im Konstruktor aufgerufen
        * @author Vaceslav Ustinov
        * @date 2005-12-20
        */
        void initilize( BB_Wall * wall, BB_DocComponent * docComponent );
        /**
        *&Uuml;berladene Funktion. @see QLabel::paintEvent();
         */
        void paintEvent ( QPaintEvent * pe );
    private:
        QRect m_rect;

};

#endif
