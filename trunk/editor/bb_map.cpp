//
// C++ Implementation: bb_map
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_map.h"

#include <iostream>

using namespace std;

BB_Map::BB_Map()
{
	m_Zoom = 1;
	m_MapFileName = "";
}


BB_Map::~BB_Map()
{
}




/**
 * 
 * @return 
 */
QPixmap& BB_Map::getMap()
{
    return m_Map;
}


/**
 * 
 * @param map 
 */
void BB_Map::setMap(const QPixmap& map)
{
    m_Map = map;
}


double BB_Map::getZoom() const
{
    return m_Zoom;
}


void BB_Map::setZoom(double theValue)
{
    m_Zoom = theValue;
}


QString BB_Map::getMapFileName() const
{
    return m_MapFileName;
}


void BB_Map::setMapFileName(const QString& name)
{
	if(&name != NULL && !name.isEmpty())
	{
    	m_MapFileName = name;
	}
	else
	{
		cout << "BB_Map::setMapFileName(..): Ungültigen Dateinamen erhalten" << endl;
	}
}


/*!
    \fn BB_Map::load()
 */
bool BB_Map::loadMap(QDir& path)
{
	bool exit;
	
	if(!m_MapFileName.isEmpty())
	{
		QImage img;
		exit = img.load(path.path() + QDir::separator() + m_MapFileName,"PNG");
		if(exit)
		{
			m_Map = QPixmap::fromImage(img);
		}
	}
	else
	{
		exit = false;
	}
	
	return exit;
}
