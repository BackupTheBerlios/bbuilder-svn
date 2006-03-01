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
#ifndef BB_TOOLWINDOWNEW_H
#define BB_TOOLWINDOWNEW_H

#include "bb_abstracttool.h"

/**
* Werkzeug zum Erstellen von neuen Fenstern
* @author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ToolWindowNew : public BB_AbstractTool
{
    public:
        /**
        Standart Konstruktor
        @param parent Zeiger auf ein Widget zu dem dieser Tool gehört
        @see BB_AbstractTool
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        BB_ToolWindowNew( QWidget *parent );
        /**
        Destruktor
        */
        ~BB_ToolWindowNew();
        /**
        Ein Erreignis, wird aufgerufen wenn mann auf eine Mauste-Taste druckt
        @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        virtual void click( QMouseEvent* me );
        /**
        Die Methode wird aufgerufen, wenn die Maus bei beliebiger gedrückter Maustaste bewegt wird.
        @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        virtual void move( QMouseEvent* me, bool overX, bool overY );
        /**
        Wird aufgerufen, wenn eine Maustaste los gelassen wird.
        @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        virtual void release( QMouseEvent* me );

};

#endif
