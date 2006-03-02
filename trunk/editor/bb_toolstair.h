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
#ifndef BB_TOOLSTAIR_H
#define BB_TOOLSTAIR_H

#include "bb_abstracttool.h"
#include "bb_stair.h"

/**
Eine Klasse zum erstellen von Treppen.<br>
Um eine Treppe zu erstellen Braucht man zwei Pointer auf Puntke<br>
Abgeleitet von BB_AbstractTool
	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ToolStair : public BB_AbstractTool
{
    public:
        /**
        Standart Konstruktor
        @param parent Zeiger auf ein Widget zu dem dieser Tool gehört
        @see BB_AbstractTool
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        BB_ToolStair( QWidget* parent );
        /**
        Destruktor
        */
        ~BB_ToolStair();
        /**
         * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @author Alex Letkemann
         */
        virtual void click( QMouseEvent* me );
        /**
         * Die Methode wird aufgerufen, wenn die Maus bei beliebiger gedrückter Maustaste bewegt wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @param overX Gibt an, ob der Mauszeiger horizontal außerhalb der Arbeitsfläche ist (true).
         * @param overY Gibt an, ob der Mauszeiger vertikal außerhalb der Arbeitsfläche ist (true).
         * @author Alex Letkemann
         */
        virtual void move( QMouseEvent* me, bool overX, bool overY );
        /**
         * Wird aufgerufen, wenn eine Maustaste los gelassen wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @author Alex	Letkemann
         */
        virtual void release( QMouseEvent* me );
        /**
         * Gibt das Eigenschftsfenster des Tools zurück.
         * @return Eigenschftsfenster des Tools.
         * @author Alex Letkemann
         */
        BB_AbstractToolWidget* getToolWidget();
    protected:
        /** Zeiger auf zu erstellende Treppe*/
        BB_Stair * m_Stair;
        /** Obere linke Position von Treppe*/
        BB_Point m_Point1;
        /** Untere rechte Position von Treppe*/
        BB_Point m_Point2;
        /**
        Dieser Rechteck symbolisiert die Treppe in zu zeichenden Fenster<br>
        Die Größe von recheck wird durch m_Point1 und m_Point2 bestimmt
        */
        BB_Rect m_Rect;
        /** Letzte Position von Mausklick*/
        C2dVector m_ClickPos;

};

#endif
