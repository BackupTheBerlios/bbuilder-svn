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
@author Alex Letkemann
*/
class BB_ToolMove : public BB_AbstractTool
{
public:
    BB_ToolMove();

    ~BB_ToolMove();

    virtual void click(QMouseEvent* me);
    virtual void move(QMouseEvent* me, bool overX, bool overY);
    virtual void release(QMouseEvent* me);
    virtual void setSelectionVector( QVector<BB_DrawObject*>* selectionVector );
    virtual void deleteSelection();
	virtual void selectAll();
protected:
    //     QVector<BB_DrawObject*> m_Selection;
    /**Punkt mit dem ausgeglichen wird*/
    BB_Point * comparePoint;
    BB_Point   m_Point2;
    BB_Point   m_Point1;
    BB_Rect    m_Rect;
    C2dVector  m_ClickPos;
	/** Wenn select = true, dann heisst es, dieser toll wird als ein Auswahl-Viereck arbeiten<br>
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
    void bringToLine(BB_Point *point);
};

#endif
