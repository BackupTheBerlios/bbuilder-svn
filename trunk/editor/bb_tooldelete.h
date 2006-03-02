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
#ifndef BB_TOOLDELETE_H
#define BB_TOOLDELETE_H

#include <bb_abstracttool.h>

/**
Werkzeug zum Löschen von Objekten<br>
Beim Click auf ein Objekt z.B Tür, Fenster etc wird dieser gelöscht
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ToolDelete : public BB_AbstractTool
{
    public:
        /**
        Standart Konstruktor
        @param parent Zeiger auf ein Widget zu dem dieser Tool gehört
        @see BB_AbstractTool
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        BB_ToolDelete( QWidget * parent );
        /**
        Destruktor
        */
        ~BB_ToolDelete();
        /**
         * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @author Vaceslav Ustinov
         */
        virtual void click( QMouseEvent* me );

};

#endif
