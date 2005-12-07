//
// C++ Implementation: bb_xterrainhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xterrainhandler.h"
#include "bb_terrain.h"

#include "bb_point.h"

#include <iostream>

using namespace std;
BB_XTerrainHandler::BB_XTerrainHandler( BB_Terrain * terrain )
 : BB_XHandler()
{
	if(terrain != NULL)
	{
		m_Terrain = terrain;
	}
	
	m_Object = NULL;
	
}


BB_XTerrainHandler::~BB_XTerrainHandler()
{
}




/*!
    \fn BB_XTerrainHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
 */
bool BB_XTerrainHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
{
// 	return QXmlDefaultHandler::startElement(namespaceURI, localName, qName, atts);
	
// 	cout << "event: " << namespaceURI.toStdString() << " | " << localName.toStdString() << " | " << qName.toStdString() << endl;
	
// 	cout << "<" << qName.toStdString() << ">" << endl;
	
	if (!m_XTerrainTag && qName != "bb_terrain") {
		m_ErrorStr = QObject::tr("Dies ist keine gültige bb_terrain Datei");
// 		cout << m_ErrorStr.toStdString() << endl; 
		return false;
	}

	if (qName == "bb_terrain") {
		QString version = atts.value("version");
		if (!version.isEmpty() && version != "1.0") {
			m_ErrorStr = QObject::tr("Die ist keine bb_terrain Datei der Version 1.0.");
			return false;
		}
		m_XTerrainTag = true;		
	} 
	else if(qName == "bb_point")
	{
		bool ok;
		QString tmp;
		
		int x,y,id;
		
		tmp = atts.value("id");
		id = tmp.toInt(&ok);
		
		tmp = atts.value("x");
		x = tmp.toInt(&ok);
		
		tmp = atts.value("y");
		y = tmp.toInt(&ok);
		
		
		m_Object = new BB_Point();
		((BB_Point*)m_Object)->setX(x);
		((BB_Point*)m_Object)->setY(y);
		
		m_Object->m_ObjectNr = id;
		m_Object->setSelected(false);
		m_Terrain->getDrawObjects()->append(m_Object);

	}
	m_CurrentText.clear();

	return true;
}


/*!
    \fn BB_XTerrainHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
 */
bool BB_XTerrainHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
{
// 	cout << "</" << qName.toStdString() << ">" << endl;
	if(m_Object == NULL)
	{
		if (qName == "name") {
			m_Terrain->setName(m_CurrentText);
			
		} 
		else if (qName == "description")
		{
			m_Terrain->setDescription(m_CurrentText);
			
		}
		else if(qName == "mapfile")
		{
			m_Terrain->setMapFileName(m_CurrentText);
		}
	}
	else
	{
		if (qName == "name") {
			m_Object->setName(m_CurrentText);
			
		} 
		else if (qName == "description")
		{
			m_Object->setDescription(m_CurrentText);
			
		}
	}
	
	
	if(qName == "bb_point")
	{
		m_Object = NULL;
	}


	return true;
}
