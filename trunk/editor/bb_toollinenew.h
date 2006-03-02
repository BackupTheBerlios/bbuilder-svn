/***************************************************************************
*   Copyright (C) 2005 by Vacesav Ustinov                                 *
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
***************************************************************************/
#ifndef BB_TOOLLINENEW_H
#define BB_TOOLLINENEW_H

#include "bb_abstracttool.h"
#include "bb_wall.h"

/**
Ein Basis-Klass für BB_ToolWallNew und BB_ToolNavigationLineNew
Ein Werkzeug zum Erstellen von Linien und Wänden 
@author Vacesav Ustinov, Alex Letkemann (Änderungen)
*/
class BB_ToolLineNew : public BB_AbstractTool
{
    public:
        /**
        Standart Konstruktor
        @param parent Zeiger auf ein Widget zu dem dieser Tool gehört
        @see BB_AbstractTool
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        BB_ToolLineNew( QWidget *parent );
        /**
        Destruktor
        */
        ~BB_ToolLineNew();
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
        /**
         * Gibt das Eigenschftsfenster des Tools zurück.
         * @return Eigenschftsfenster des Tools.
         * @author Alex Letkemann
         */
        virtual BB_AbstractToolWidget* getToolWidget();
    protected:

        /** Ein Hilfs-Objekt von Typ BB_Line zum Schieben von Linien*/
        BB_Line * m_Tmp_Line;
        /** Ein Hilfs-Objekt von Typ BB_Point. wird Benötigt beim Ersellen von eien neue Linie*/
        BB_Point m_MovePoint;

    protected:
        /**
        Gibt zeiger auf ein Punkt, auf den man geklickt hat.<br>
        Gibt es Zwei Punkte auf gleiche Position, 
        dann wird nur der erster in Vector m_Objects von BB_AbstractTool stehende Punkt zurückgeliefert<br>
        Falss es keine Punkte auf gesuchte Position gibts, wird ein Null-Pointer zurückgegeben
        @param pos gesuchte logische Position
        @return Zeiger auf ein Punkt, der auf gesuchte Position liegt oder NULL
        @author Vacesav Ustinov
        */
        virtual BB_Point* getClickedPoint( C2dVector& pos );
        /**
        Liefert Zeiger auf frisch erzeugte Linie zurück
        @param p1 Zeiger auf ein Punkt, wird als Position 1 implementiert
        @param p2 Zeiger auf ein Punkt, wird als Position 2 implementiert
        @author Vacesav Ustinov
        */
        virtual BB_Line* createNewLine( BB_Point* p1, BB_Point* p2 );
        /**
        Gibt Zeiger auf eine Linie, auf die man geklickt hat.<br>
        Gibt es zwei Linie auf gleiche Position, 
        dann wird nur die erste in Vector m_Objects von BB_AbstractTool stehende Linie zurückgeliefert<br>
        Falss es keine Punkte auf gesuchte Position gibts, wird ein Null-Pointer zurückgegeben
        @param pos gesuchte logische Position
        @return Zeiger auf eine Linie, die auf gesuchte Position liegt oder NULL
        @author Vacesav Ustinov
        */
        virtual BB_Line* getClickedLine( C2dVector& pos );
};

#endif
