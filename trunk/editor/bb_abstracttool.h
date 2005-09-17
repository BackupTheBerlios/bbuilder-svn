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
#ifndef BB_ABSTRACTTOOL_H
#define BB_ABSTRACTTOOL_H

#include <QtGui>

#include "bb_drawobject.h"
#include "bb_transformer.h"
#include "c2dvector.h"

/**
@author Alex Letkemann
*/
class BB_AbstractTool{
public:
	BB_AbstractTool();

    virtual ~BB_AbstractTool();
    virtual void move(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer) = 0;
    virtual void release(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer) = 0;
    virtual void click(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer) = 0;
    bool remove(QVector<BB_DrawObject*>* objects, BB_DrawObject * delObject);

protected:
	C2dVector m_LastLogicMouseClick;
	C2dVector m_pLogic;
	QPoint m_pScreen;
	QWidget * parentWidget;
};

#endif
