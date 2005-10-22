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


#include "bb_line.h"
#include "bb_wall.h"

#include <iostream>

using namespace std;

BB_Building::BB_Building(const QDir& path, const QString &fileName, const QString &name)
	: BB_FileObject(path,fileName,name)
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


/*!
    \fn BB_Building::write(QIODevice *device)
 */
bool BB_Building::write(QTextStream &out)
{
	int depth = 1;
	
 	QVector<BB_Point*> points;
 	QVector<BB_Wall*> walls; 
	
	BB_Object* object;
	
	for(int i = 0; i < m_DrawObject->count(); i++)
	{
		object = m_DrawObject->at(i);
		
		if(typeid(*object) == typeid(BB_Point))
		{
			points.append((BB_Point*)object);
		} 
		else if (typeid(*object) == typeid(BB_Wall))
		{
			walls.append((BB_Wall*)object);
		}
		else
		{
			cout << "Unbekanntes Objekt gefunden" << endl;
		}
	}
	
	
	
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
			<< "<!DOCTYPE bb_building>\n"
			<< "<bb_building version=\"1.0\">\n";
	BB_Object::generateXElement(out, depth);
	
	if(points.count())
	{
		out << BB::indent(depth) << "<points>\n";
		
		for(int i = 0; i < points.count(); i++)
		{
			points.at(i)->generateXElement(out,depth + 1);
		}
		
		out << BB::indent(depth) << "</points>\n";
	}
	else
	{
		out << "<points />";
	}
	
	out << "</bb_building>\n";
	return true;
}


/*!
    \fn BB_Building::generateXElement(QTextStream &out, int depth)
 */
void BB_Building::generateXElement(QTextStream &out, int depth)
{
	out << BB::indent(depth) << "<bb_building>" << BB::escapedText(getFileName()) << "</bb_building>\n";
}


/*!
    \fn BB_Building::getClassName()
 */
const QString BB_Building::getClassName()
{
	return QString("BB_Building");
}
