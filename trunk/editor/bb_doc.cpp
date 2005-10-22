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
#include "bb_doc.h"

#include <iostream>
#include "bb_xdocgenerator.h"

using namespace std;

BB_Doc::BB_Doc()
	: QObject()
{
	m_Terrain = NULL;
	m_ProjectPath = NULL;
}


BB_Doc::~BB_Doc()
{
}



/**
 * Gibt einen Pointer auf einen Vector mit allen Gebäuden zurück
 * @return Pointer auf einen Vektor mit allen Gebäuden
 */
QVector< BB_Building*>* BB_Doc::getBuildings()
{
	return &m_Buildings;
}


QVector<BB_Level*>* BB_Doc::getLevels()
{
    return &m_Levels;
}


BB_Terrain* BB_Doc::getTerrain()
{
    return m_Terrain;
}


/**
 * Löscht den Inhalt des Dokumentes
 */
bool BB_Doc::clear()
{

	if(m_Terrain != NULL)
	{
		delete m_Terrain;
		m_Terrain = NULL;
	}
	
	BB_Object* object;
	
	for(int i = 0; i < m_Buildings.count(); i++)
	{
		object = m_Buildings.at(i);
		m_Buildings.remove(i);
		
		delete object;
		object = NULL;
	}
	
	
	for(int i = 0; i < m_Levels.count(); i++)
	{
		object = m_Levels.at(i);
		m_Levels.remove(i);
		delete object;
		object = NULL;
		
	}
	
	return true;
}


/*!
    \fn BB_Doc::open(QDir &dir)
 */
bool BB_Doc::open(QString &fileName)
{
	/* Dokument leeren */
	clear();
	
	if(fileName != NULL )
	{
		
		QDir dir(fileName);
		m_ProjectFile = dir.dirName();
		
		dir.cdUp();
		m_ProjectPath = dir;
		
	}
	else 
	{
		cout << "BB_Doc::open(): ungültigen Dateinamen erhalten" << endl;
		return false;
	}
	
	cout << "m_ProjectPath: " << m_ProjectPath.path().toStdString() << endl;
	cout << "m_ProjectFile: " << m_ProjectFile.toStdString() << endl;
	
	return true;
}


/*!
    \fn BB_Doc::save()
 */
bool BB_Doc::save()
{
    /// @todo implement me

	return true;
}


/*!
    \fn BB_Doc::close()
 */
bool BB_Doc::close()
{
	m_ProjectFile = "";
	m_ProjectPath = QDir("");
	
	return clear();
}


/*!
    \fn BB_Doc::new(QDir &path)
 */
bool BB_Doc::createNew(QDir &path)
{

	if(&path == NULL)
	{
		return false;
	}
	
	m_ProjectFile = path.dirName();
	m_ProjectPath = path.path();
	
	QString fileName = path.path() + QDir::separator() + path.dirName() + ".glbb";
	QFile file(fileName);
	
	if(!file.open(QFile::WriteOnly | QFile::Text))
	{
		file.close();
		return false;
	}
	

	
	
	
	path.mkdir("terrain");
	path.mkdir("buildings");
	path.mkdir("levels");
	path.mkdir("textures");
	
	m_Terrain = new BB_Terrain();
	
	BB_XDocGenerator docGenerator(this);
	
	if(!docGenerator.write(&file))
	{
		file.close();
		return false;
	}
	
	file.close();
	return true;
}
