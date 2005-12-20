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
#ifndef BB_DLGWALLEDITAREA_H
#define BB_DLGWALLEDITAREA_H 
//QT includes
#include <QLabel> 
//Local Includes
#include "bb_map.h"
#include "bb_wall.h"
#include "bb_doccomponent.h"

/**
Cetral Widget in BB_DlgWallEdit,
wird von QLabel abgeleitet.
Dieses Widget dient zum Edittieren einer Wand
 
@author Vaceslav Ustinov
*/
class BB_DlgWallEditArea : public QLabel
{
    public:
        BB_DlgWallEditArea( BB_Wall * wall, BB_DocComponent * docComponent, QWidget * parent = 0, Qt::WFlags f = 0 );
        ~BB_DlgWallEditArea();
    protected:
        BB_Map * m_currentMap;
        /**
        * hohe und  breite in meter
        */
        double m_height;
        double m_lenght;
        double m_verhaeltniss;
    private:
        void paintEvent ( QPaintEvent * );
        void resizeEvent ( QResizeEvent * );
};

#endif
