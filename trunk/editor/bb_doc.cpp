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
#include "bb_xdochandler.h"

#include <iostream>

using namespace std;

BB_Doc::BB_Doc()
		// Bei der Initialisierung hat das Projekt noch keinen Path und keinen Dateiname,
		// deswegen wird ein leerer Path und ein leerer Dateiname übergeben.
		// Es werden temporäre Daten von BB_FileObject erzeugt.
		// Die echten Daten werden mit open() oder createNew() erzeugt.
	:	BB_FileObject(QDir(),QString(),QString("bb_doc"))
{
	m_Terrain = NULL;
 	m_Handler = new BB_XDocHandler(this);

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


/**
 * Liefert einen Vector mit allen Levels
 * @return Vector mit allen Levels
 */
QVector<BB_Level*>* BB_Doc::getLevels()
{
    return &m_Levels;
}


/**
 * Liefert einen Pointer auf das Terrain
 * @return Pointer auf das Terrain
 */
BB_Terrain* BB_Doc::getTerrain()
{
    return m_Terrain;
}


/**
 * Löscht den Inhalt des Dokumentes
 * @return Liefert 'false' im Fehlerfall zurück, sonst 'true'.
 * @author Alex Letkemann
 * @date 22.10.2005
 */
bool BB_Doc::clear()
{

	/* Terrain löschen */
	if(m_Terrain != NULL)
	{
		delete m_Terrain;
		m_Terrain = NULL;
	}
	
	BB_DocComponent* object;
	
	/* Alle Gebäude löschen */
	for(int i = m_Buildings.count() - 1 ; i >= 0 ; i--)
	{
		object = m_Buildings.at(i);
		if(object != NULL)
		{
			delete object;
			object = NULL;
			
		}
		m_Buildings.remove(i);
	}
	m_Buildings.clear();
	
	
	/* Alle Etagen löschen */
	for(int i = m_Levels.count() - 1 ; i >= 0 ; i--)
	{
		object = m_Levels.at(i);
		m_Levels.remove(i);
		if(object != NULL)
		{
			delete object;
			object = NULL;
		}
	}
	m_Levels.clear();
	
	
	BB_Object::m_Counter = 0;
	
	return true;
}


/*!
    \fn BB_Doc::open(QDir &dir)
 */
bool BB_Doc::open(QString fileName)
{
	/* Dokument leeren */
	clear();
	
	if(&fileName != NULL )
	{
		
		QDir dir(fileName);
		m_ProjectFile = dir.dirName();
		
		dir.cdUp();
		m_ProjectPath = dir;
		
		
		
		m_FileName = m_ProjectFile;
		m_FilePath = m_ProjectPath;
		
		
		/* Projektdatei auslesen */
		if(!BB_FileObject::open())
		{
			return false;
		}
		
		m_Terrain->open();
		
		for(int i = 0; i < m_Buildings.count(); i++)
		{
			m_Buildings.at(i)->open();
		}
		
// 		for(int i = 0; i < m_Levels.count(); i++)
// 		{
// 			m_Levels.at(i)->open();
// 		}
		
	}
	else 
	{
		cout << "BB_Doc::open(): ungültigen Dateinamen erhalten" << endl;
		return false;
	}
	
// 	cout << "m_ProjectPath: " << m_ProjectPath.path().toStdString() << endl;
// 	cout << "m_ProjectFile: " << m_ProjectFile.toStdString() << endl;
	
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
bool BB_Doc::createNew(const QString &name, const QString &desc, const QDir &path)
{

	if(&name == NULL || name.isEmpty() || &desc == NULL || &path == NULL)
	{
		return false;
	}
	
	QDir tmpPath;
	
	setName(name);
	setDescription(desc);
	
	m_ProjectFile = path.dirName() + ".glbb";
	m_ProjectPath = path.path();
	
	m_FilePath = m_ProjectPath;
	m_FileName = m_ProjectFile;
	
	
	m_ProjectPath.mkdir("terrain");
	m_ProjectPath.mkdir("buildings");
	m_ProjectPath.mkdir("levels");
	m_ProjectPath.mkdir("textures");
	
	tmpPath = m_ProjectPath;
	tmpPath.cd("terrain");
	
	QString s = "terrain.xml";
	
	/* neues Gelände erzeugen */
	newTerrain(tmpPath, s);
	m_Terrain->setName("Terrain");
	
	
	
	save();
	return true;
}


/**
 * 
 */
bool BB_Doc::write(QTextStream &out)
{
	int depth = 1;
	
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
			<< "<!DOCTYPE bb_doc>\n"
			<< "<bb_doc version=\"1.0\">\n";

	BB_Object::generateXElement(out,depth);
	
	if(getTerrain() != NULL)
	{
		m_Terrain->generateXElement(out, depth);
	}
	
	if(m_Buildings.count() == 0)
	{
		out << BB::indent(depth) << "<buildings />\n";
	}
	else
	{
		out << BB::indent(depth) << "<buildings>\n";
		
		for(int i = 0; i < m_Buildings.count(); i++)
		{
			m_Buildings.at(i)->generateXElement(out, depth + 1);
		}
		
		out << BB::indent(depth) << "</buildings>\n";
	}
	
	if(m_Levels.count() == 0)
	{
		out << BB::indent(depth) << "<levels />\n";
	}
	else
	{
		out << BB::indent(depth) << "<levels>\n";
		
		for(int i = 0; i < m_Levels.count(); i++)
		{
			m_Levels.at(i)->generateXElement(out, depth + 1);
		}
		
		out << BB::indent(depth) << "</levels>\n";
	}
	
	out << "</bb_doc>\n";

	return true;
}


/*!
    \fn BB_Doc::newBuilding()
 */
BB_Building* BB_Doc::newBuilding(QWidget * parent)
{
	QString fileName;
	QDir path = m_ProjectPath;
	path.cd("buildings");
	
	BB_Building* building = new BB_Building(path,"tempFile");
	
	if(building->keyBoardEdit(parent) == QDialog::Accepted)
	{
		building->setFileName(fileName.sprintf("%08d.xml",building->getObjectNr()));
		building->save();
		m_Buildings.append(building);
		
		save();
	}
	else
	{
		delete building;
		building = NULL;
	}
	
	return building;
}


/*!
    \fn BB_Doc::newLevel()
 */
BB_Level* BB_Doc::newLevel(QWidget * parent)
{
// 	QString fileName;
// 	QDir path = m_ProjectPath;
// 	path.cd("levels");
// 	
// 	BB_Level* level = new BB_Level(path,"tempFile");
// 	
// 	if(level->keyBoardEdit(parent) == QDialog::Accepted)
// 	{
// 		level->setFileName(fileName.sprintf("%08d.xml",level->getObjectNr()));
// 		level->save();
// 		m_Levels.append(level);
// 		save();
// 	}
// 	else
// 	{
// 		delete level;
// 		level = NULL;
// 	}
// 	
// 	return level;
	return NULL;
}


/*!
    \fn BB_Doc::newBuilding(QDir& path, QString& fileName)
 */
BB_Building* BB_Doc::newBuilding(QDir& path, QString& fileName)
{
	BB_Building* building = new BB_Building(path,fileName);
	m_Buildings.append(building);
		
	return building;
}


/*!
    \fn BB_Doc::newLevel(QDir& path, QString& fileName)
 */
BB_Level* BB_Doc::newLevel(QDir& path, QString& fileName)
{
	BB_Level* level = new BB_Level(path,fileName);
	m_Levels.append(level);
		
	return level;
}


/*!
    \fn BB_Doc::newTerrain(QDir& path, QString& fileName)
 */
BB_Terrain* BB_Doc::newTerrain(QDir& path, QString& fileName)
{
	m_Terrain = new BB_Terrain(path,fileName,"Terrain");
	return m_Terrain;
}


/*!
    \fn BB_Doc::getBuilding(QListWidgetItem* item)
 */
BB_Building* BB_Doc::getBuilding(QListWidgetItem* item)
{
	if(&m_Buildings != NULL)
	{
		BB_Building* building;
		
		for(int i = 0; i < m_Buildings.count(); i++)
		{
			building = m_Buildings.at(i);
			if(building != NULL && building->getListWidgetItem() == item)
			{
				return building;
			}
		}
	}
	
	return NULL;
}


/**
 * Löscht das Gebäude, welches das QListWidgetItem item hat.
 * @param item QListWidgetItem des Gebäudes
 * @return True, falls das Gebäude erfolgreich gelöscht wurde, sonst false.
 */
bool BB_Doc::deleteBuilding(QListWidgetItem* item)
{
	if( item != NULL )
	{
		BB_Building* building;
		
		for( int i = m_Buildings.count() - 1 ; i >= 0 ; i-- )
		{
			building = m_Buildings.at( i );
			if( item == building->getListWidgetItem() )
			{
				m_Buildings.remove( i );
				delete building;
				return true;
			}
		}
	}
	
	return false;
}
