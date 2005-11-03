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
 ***************************************************************************/
#include "bb_abstracttool.h"
#include "bb_tab.h"

#include <iostream>

using namespace std;

BB_AbstractTool::BB_AbstractTool()
{
	m_Transformer = NULL;
	m_Objects = NULL;
	m_Action = NULL;
	
}

BB_AbstractTool::~BB_AbstractTool()
{
}

bool BB_AbstractTool::remove(BB_DrawObject * delObject)
{
	if(m_Objects != NULL && delObject != NULL)
	{
	BB_DrawObject * tmpObject;
	int objectPosition;
	objectPosition = -1;
	for (int i=0; i<m_Objects->count(); i++)
	{
		tmpObject = m_Objects->at(i);
		if (tmpObject == delObject)
		{
			objectPosition = i;
			
			// TODO Objekt wird nicht aus dem Speicher gelöscht!
		}
	}
	cout << objectPosition <<endl;
	m_Objects->remove(objectPosition);
	
	if(objectPosition == -1) 
		return false;
	else
		return true;
	}
	else
	{
		return false;
	}
}



/**
 * Gibt den Vector zurück, der z.Z. bearbeitet wird.
 * @return Vector, der bearbeitet wird.
 */
QVector< BB_DrawObject * >* BB_AbstractTool::getObjects() const
{
    return m_Objects;
}


/**
 * Setzt den Pointer auf den Vector, welcher bearbeitet werden soll.
 * @param vector Vector, der bearbeitet werden soll.
 */
void BB_AbstractTool::setObjects(QVector< BB_DrawObject * >* vector)
{
	m_Objects = vector;
}


/**
 * Gibt den Transformer zurück, der bei der Bearbeitung verwendet wird.
 * @return Transformer, der bei der Bearbeitung verwendet wird.
 */
BB_Transformer* BB_AbstractTool::getTransformer() const
{
    return m_Transformer;
}


/**
 * Setzt den Transformer, der bei der Bearbeitung verwendet werden soll.
 * @param transformer Transformer, der bei der bearbeitung verwendet werden soll.
 */
void BB_AbstractTool::setTransformer(BB_Transformer* transformer)
{
	m_Transformer = transformer;
}


QVector<BB_DrawObject*>* BB_AbstractTool::getSelectionVector() const
{
	return m_Selection;
}



void BB_AbstractTool::setSelectionVector(QVector<BB_DrawObject*>* selectionVector)
{
	if(selectionVector != NULL)
	{
		m_Selection = selectionVector;
	}
	else
	{
		cout << "BB_AbstractTool::setSelectionVector(): Übergebener Pointer ist NULL\n Auswahl-Vektor wurde nicht gesetzt." <<  endl;
	}
}


QVector< BB_DrawObject * >* BB_AbstractTool::getToolObjects() const
{
    return m_ToolObjects;
}


void BB_AbstractTool::setToolObjects(QVector< BB_DrawObject * >* theValue)
{
    m_ToolObjects = theValue;
}


/**
 * Hebt die Selektion alle Objekte, die im SelectionVector liegen, auf.
 */
void BB_AbstractTool::clearSelection()
{

	for(int i = 0; i < m_Selection->count(); i++)
	{
		m_Selection->at(i)->setSelected(false);
	}
	
	m_Selection->clear();
}


QAction* BB_AbstractTool::getAction()
{
	return m_Action;
}


void BB_AbstractTool::setAction(QAction* action)
{
	if(action != NULL)
	{
		m_Action = action;
	}
	else
	{
		cout << "BB_AbstractTool::setAction(): NULL-Pointer erhalten" << endl;
	}
}
