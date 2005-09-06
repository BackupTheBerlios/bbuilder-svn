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
	m_Terrain = new BB_Terrain();
	m_Buildings = NULL;
	m_Buildings = new QVector<BB_Building*>();
	m_Levels = new QVector<BB_Level> ();	
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
	return m_Buildings;
}


QVector< BB_Level>* BB_Doc::getLevels()
{
    return m_Levels;
}


BB_Terrain* BB_Doc::getTerrain()
{
    return m_Terrain;
}
