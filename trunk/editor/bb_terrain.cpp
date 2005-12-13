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
#include "bb_terrain.h"
#include "bb_dlgterrainedit.h"

#include <QObject>

#include "bb_point.h"
#include "bb_triangle.h"

#include <iostream>
#include "bb_xterrainhandler.h"

using namespace std;

const QString BB_Terrain::s_ClassName = "BB_Terrain";

BB_Terrain::BB_Terrain(const QDir& path, const QString &fileName, const QString &name)
	: BB_DocComponent(path, fileName, name)
{
	m_Handler = new BB_XTerrainHandler(this);
}


/**
 * Destrucktor
 */
BB_Terrain::~BB_Terrain()
{
}




/*!
    \fn virtual void BB_Terrain::generateXElement(QIODevice *device, int depth)
 */
void BB_Terrain::generateXElement(QTextStream &out, int depth)
{
	out << BB::indent(depth) << "<bb_terrain>" << BB::escapedText(getFileName()) << "</bb_terrain>\n";
}


/*!
   \fn BB_FileObject::write(QTextStream &out);
 */
bool BB_Terrain::write(QTextStream &out)
{
	int depth = 1;
	
	QVector<BB_Point*> points;
 	QVector<BB_Triangle*> triangles; 
	
	BB_Object* object;
	
	for(int i = 0; i < m_DrawObjects.count(); i++)
	{
		object = m_DrawObjects.at(i);
		
		if(typeid(*object) == typeid(BB_Point))
		{
			points.append((BB_Point*)object);
		} 
		else if (typeid(*object) == typeid(BB_Triangle))
		{
			triangles.append((BB_Triangle*)object);
		}
		else
		{
			qDebug() << "Unbekanntes Objekt gefunden: " << typeid(*object).name() << endl;
		}
	}
	
	
	
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
			<< "<!DOCTYPE bb_terrain>\n"
			<< "<bb_terrain version=\"1.0\">\n";
	BB_Object::generateXElement(out, depth);
	out << BB::indent(depth) << "<mapfile>" << m_MapFileName << "</mapfile>\n";
	
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
	
		if(triangles.count())
		{
			out << BB::indent(depth) << "<triangles>\n";
			
			for(int i = 0; i < triangles.count(); i++)
			{
				triangles.at(i)->generateXElement(out,depth + 1);
			}
			
			out << BB::indent(depth) << "</triangles>\n";
		}
		else
		{
			out << BB::indent(depth) << "<triangles />\n";
		}
	
	out << "</bb_terrain>\n";
	return true;
}


/*!
    \fn BB_Terrain::keyBoardEdit(QWidget* parent)
 */
int BB_Terrain::keyBoardEdit(QWidget* parent)
{
	QImage image;
	
	int result;
	bool exit = false;

	BB_DlgTerrainEdit dlg(parent);
	
	dlg.setName(getName());
	dlg.setDescription(getDescription());
	
	QString planFile(m_FilePath.path() + QDir::separator() + m_MapFileName);
	dlg.setPlanFile( planFile );
	
	do
	{
	
		result = dlg.exec();
		/* Falls Abbrechen gedrückt wurde: raus. */
		if(result == QDialog::Rejected)
		{
			return false;
		}
		
		if(dlg.getName().isEmpty())
		{
			QMessageBox::critical(NULL,"Fehler",QString::fromUtf8("Sie müssen einen Namen für das Gelände angeben."));
		}
		else if(!image.load(dlg.getPlanFile()))
		{
			QMessageBox::critical(NULL,"Fehler",QString::fromUtf8("Sie müssen eine gültige Bilddatei als Plan angeben."));
		}
		else
		{
			/* Falls alles gut ist */
			exit = 1;
		}
			
	} while(result != QDialog::Rejected && !exit);
	
	setName(dlg.getName());
	setDescription(dlg.getDescription());
	
	m_MapFileName.sprintf("%08d.png",getObjectNr());
	
	image.save(m_FilePath.path() + QDir::separator() + m_MapFileName,"PNG");
	
	setMap(QPixmap::fromImage(image));
	
	parent->update();
	getListWidgetItem()->setText(getName());
	return result;
}


/**
 * Führt die open() Funktion von BB_FileObject aus und
 * läd zusätztlich die Map Datei des Geländes.
 */
bool BB_Terrain::open()
{
	bool exit;

	if(BB_FileObject::open())
	{
		exit = loadMap(m_FilePath);
	}
	else
	{
		exit = false;
	}

	return exit;
}
