/***************************************************************************
 *   Copyright (C) 2005 by Vacesav Ustinov   						*
 *   v.ustinov@web.de   *
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

#include <bb_abstracttool.h>
#include "bb_line.h"
//#include "bb_drawobject.h"

/**
dokumentation

@author Vacesav Ustinov
*/
class BB_ToolLineNew : public BB_AbstractTool
{
public:
    BB_ToolLineNew();
    BB_ToolLineNew(QWidget *parent);

    ~BB_ToolLineNew();

    virtual void click(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer);
    virtual void move(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer);
    virtual void release(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer);
protected:
	BB_DrawObject * m_movedPoint;
	BB_Line * tmpLine;

};

#endif
