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
#ifndef BB_WINDOW_H
#define BB_WINDOW_H

#include <bb_constructionelement.h>

/**
Implementierung von Fenster
 
	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_Window : public BB_ConstructionElement
{
    public:
        /**
        Konstuktor mit Parameter
        @param C2dVector
        */
		BB_Window( C2dVector v1, C2dVector v2);
        ~BB_Window();
        /**
        Abgeleitete Funktion zum Zeichnen von einem Fenster
        @param BB_Transformer
        @param QPainter von QT
        */
//         virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
		void generateXElement( QTextStream &out, int depth );
};

#endif
