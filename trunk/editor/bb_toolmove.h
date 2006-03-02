/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
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
#ifndef BB_TOOLMOVE_H
#define BB_TOOLMOVE_H

#include "bb_abstracttool.h"
#include "bb_point.h"
#include "bb_rect.h"

/**
Werkzeug zum Selektieren, Verschieben und Ausrichten von den Punkten
@author Alex Letkemann
*/
class BB_ToolMove : public BB_AbstractTool
{
    public:
        /**
        Standart Konstruktor
        @param parent Zeiger auf ein Widget zu dem dieser Tool gehört
        @see BB_AbstractTool
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        BB_ToolMove( QWidget * parent );
        /**
        Destruktor
        */
        ~BB_ToolMove();
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
        virtual BB_AbstractToolWidget* getToolWidget();
        /**
        Selektiert alle Objekte in Vector m_Obejcts<br>
        So können alle Objekte Verschoben oder gelösch werden
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        virtual void selectAll();
    protected:
        //     QVector<BB_DrawObject*> m_Selection;
        /**Punkt mit dem ausgeglichen wird*/
        BB_Point * m_ComparePoint;
        /** Hilfs-Punkt für meghrere Funktionen*/
        BB_Point m_Point2;
        /** Hilfs-Punkt für meghrere Funktionen*/
        BB_Point m_Point1;
        /** Auswahlrechteck, wird beium Selektieren benutzt*/
        BB_Rect m_Rect;
        /** Letzte Position von Mausklick*/
        C2dVector m_ClickPos;
        /**
        *Wenn select = true, dann heisst es, dieser toll wird als ein Auswahl-Viereck arbeiten<br>
        *Wenn select = false, dann heisst es, dieser toll wird die Punkten verschieben
        */
        bool m_select;
    private:
        /**
        Funktion zum Ausgleichen von zwei Punkten<br>
        Bei erstem klick(MausRAd) auf ein Punkt. wird deieser
        in comparepoint gespeichert.<br>
        Bei zweitem Klick werden die punkte verglichen und
        enweder senkrecht oder waagerecht ausgeglichen.
        @author Vaceslav Ustinov
        @param point zeiger auf einen BB_Point
        @date 22.10.2005
        */ 
        //     void bringToLine(BB_Point *point);

};

#endif
