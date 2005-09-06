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
#include "bb_building.h"
#include "ui_buildingEdit.h"



BB_Building::BB_Building()
	: BB_Object()
{
	m_DrawObject = new QVector<BB_DrawObject*>();
}


/**
 * Destrucktor 
 */
BB_Building::~BB_Building()
{
	for(int i = 0; i < m_DrawObject->count(); i++)
	{
		delete m_DrawObject->at(i);
	}
	
	delete m_DrawObject;
}




/*!
    \fn BB_Building::keyBoardEdit(QWidget* parent)
 */
int BB_Building::keyBoardEdit(QWidget* parent)
{
	int result;
	QDialog dialog(parent);
	Ui_BuildingEditDialog dlg;
	
	dlg.setupUi(&dialog);
	
	dlg.lineEditName->setText(getName());
	dlg.lineEditDesc->setText(getDescription());
	
	
	
	result = dialog.exec();
	
	setName(dlg.lineEditName->text());
	setDescription(dlg.lineEditDesc->text());
	
	return result;
}


/**
 * Gibt einen Pointer auf einen Vektor mit den DrawObjects des Gebäudes zurück
 * @return Pointer auf einen Vektor mit den DrawObjects des Gebäudes
 */
QVector<BB_DrawObject*>* BB_Building::getDrawObjects()
{
	return m_DrawObject;
}
