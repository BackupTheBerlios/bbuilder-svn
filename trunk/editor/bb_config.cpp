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
#include "bb_config.h"



BB_Config::BB_Config()
{
}


BB_Config::~BB_Config()
{
}



/**
 * Gibt den Path zum aktuellen Projekt zuruck
 * @return Verzeichnis des aktuellen Projektes
 */
QString BB_Config::getCurrentProjectPath() const
{
    return m_CurrentProjectPath;
}


/**
 * Setzt das Verzeichnis des aktuellen Projektes auf <i>path</i>
 * @param path Das Verzeichnis des neuen, aktuellen Projektes
 */
void BB_Config::setCurrentProjectPath(const QString& path)
{
    m_CurrentProjectPath = path;
}


/**
 * Speichert alle Konfigurations-Einstellungen in die Datei bb.conf im conf Ordner
 */
bool BB_Config::save()
{
	QFile file("../conf/bb.conf");
	if(!file.open(QFile::WriteOnly | QFile::Text))
	{
		return false;
	}
	
	QTextStream Stream(&file);
	
	QDomDocument xmlDoc("BB_Config");
	QDomElement root = xmlDoc.createElement("BB_Config_Root");
	xmlDoc.appendChild(root);
	root.setAttribute("Version",2);
	
	
		
	Stream << xmlDoc.toString() << endl;
	file.close();
	
	return true;
}


/**
 * Lädt alle Konfigurations-Einstellungen aus der Datei bb.conf im conf Ordner
 * Falls die Datei nicht gefunden wird, wird eine Neue erstellt.
 */
bool BB_Config::open()
{
    /// @todo implement me
}
