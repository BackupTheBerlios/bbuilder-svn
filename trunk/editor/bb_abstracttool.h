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
#include "bb_tab.h"

/**
@author Alex Letkemann
*/
class BB_AbstractTool{
public:
	BB_AbstractTool();

    virtual ~BB_AbstractTool();

/* Edit: Alex
 * Minimierung  der Aufrufparameter!	
 *     virtual void move(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer) = 0;
 *     virtual void release(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer) = 0;
 *     virtual void click(QMouseEvent* me, QVector<BB_DrawObject*>* objects,BB_Tab * tabCreator, BB_Transformer* transformer) = 0;
 */
	virtual void move(QMouseEvent* me, bool overX, bool overY) = 0;
	virtual void release(QMouseEvent* me) = 0;
	virtual void click(QMouseEvent* me) = 0;
	
    virtual bool remove(BB_DrawObject * delObject);

	void setObjects(QVector< BB_DrawObject * >* vector);
	QVector< BB_DrawObject * >* getObjects() const;

	void setTransformer(BB_Transformer* transformer);
	BB_Transformer* getTransformer() const;
	
	void setSelectionVector(QVector<BB_DrawObject*>* selectionVector);
	QVector<BB_DrawObject*>* getSelectionVector() const;

	void setToolObjects(QVector< BB_DrawObject * >* theValue);
	

	QVector< BB_DrawObject * >* getToolObjects() const;
    void clearSelection();
	
	


protected:
	C2dVector m_LastLogicMouseClick;
	C2dVector m_pLogic;
	QPoint m_pScreen;
	QWidget * parentWidget;
	
	/** Vektor mit Objekten, die bearbeitet werden sollen. */
    QVector<BB_DrawObject*>* m_Objects;
	
	QVector<BB_DrawObject*>* m_Selection;
	
	/** Transformer, der bei der Bearbeitung verwendet wird. */
    BB_Transformer* m_Transformer;
    QVector<BB_DrawObject*>* m_ToolObjects;
};

#endif
