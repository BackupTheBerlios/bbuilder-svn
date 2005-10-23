//
// C++ Implementation: bb_xdochandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xdochandler.h"
#include "bb_doc.h"


#include <iostream>

using namespace std;


BB_XDocHandler::BB_XDocHandler(BB_Doc* doc)
	: BB_XHandler()
{
	if(doc != NULL)
	{
		m_Doc = doc;
	}
	
	m_XDocTag = false;
}


BB_XDocHandler::~BB_XDocHandler()
{
}



bool BB_XDocHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
{
// 	return QXmlDefaultHandler::startElement(namespaceURI, localName, qName, atts);
	
// 	cout << "event: " << namespaceURI.toStdString() << " | " << localName.toStdString() << " | " << qName.toStdString() << endl;
	
	if (!m_XDocTag && qName != "bb_doc") {
		m_ErrorStr = QObject::tr("Dies ist keine glbb Datei");
// 		cout << m_ErrorStr.toStdString() << endl; 
		return false;
	}

	if (qName == "bb_doc") {
		QString version = atts.value("version");
		if (!version.isEmpty() && version != "1.0") {
			m_ErrorStr = QObject::tr("Die ist keine glbb Datei der Version 1.0.");
			return false;
		}
		m_XDocTag = true;		
	} 
	else if(qName == "bb_terrain")
	{
		m_Path = m_Doc->getFilePath();
		m_Path.cd("terrain");
	}
	else if(qName == "buildings")
	{
		m_Path = m_Doc->getFilePath();
		m_Path.cd("buildings");
	}
	else if(qName == "levels")
	{
		m_Path = m_Doc->getFilePath();
		m_Path.cd("levels");
	}
	
	m_CurrentText.clear();

	return true;
}



bool BB_XDocHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
{
	if (qName == "name") {
		m_Doc->setName(m_CurrentText);
		
	} 
	else if (qName == "description")
	{
		m_Doc->setDescription(m_CurrentText);
		
	}
	else if(qName == "bb_terrain")
	{
		if(m_Doc->getTerrain() == NULL)
		{
			m_Doc->newTerrain(m_Path, m_CurrentText);
		}
		else
		{
			m_Doc->getTerrain()->setFileName(m_CurrentText);
			m_Doc->getTerrain()->setFilePath(m_Path);
		}
	}
	else if(qName == "bb_building")
	{
		m_Doc->newBuilding(m_Path, m_CurrentText);
	}
	else if(qName == "bb_level")
	{
		m_Doc->newLevel(m_Path, m_CurrentText);
	}
		
	
	
	
	return true;

}
