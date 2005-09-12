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

#include <bb_abstracttool.h>

/**
@author Alex Letkemann
*/
class BB_ToolMove : public BB_AbstractTool
{
public:
    BB_ToolMove();

    ~BB_ToolMove();

    virtual void click(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer);
    virtual void move(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer);
    virtual void release(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer);

protected:
    QVector<BB_DrawObject*> m_Selection;
};

#endif
