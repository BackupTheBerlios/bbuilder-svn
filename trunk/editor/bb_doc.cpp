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

using namespace std;

BB_Doc::BB_Doc()
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
void BB_Doc::clear()
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
		delete object;
		m_Buildings.remove(i);
	}
	
	
	for(int i = 0; i < m_Levels.count(); i++)
	{
		object = m_Levels.at(i);
		delete object;
		m_Levels.remove(i);
	}
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

	return false;
}
