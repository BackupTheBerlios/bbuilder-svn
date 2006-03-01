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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_CONFIG_H
#define BB_CONFIG_H

#include <QtGui>
#include <QtXml>

/**
 * Konfiguration
 * Diese Klasse enthällt alle Einstellungen des Editors, die persistent gespeicher werden.
 * @author Alex Letkemann 
 */
class BB_Config{
public:
	
    /**
     * Konstruktor
     */
    BB_Config();

    /**
     * Destruktor
     */
    ~BB_Config();

	/**
	 * Setzt den Pfad auf das zuletzt geöffnete Projekt
	 * @param path Pfad auf das zuletzt geöffnete Projekt
	 * @author Alex Letkemann
	 */
	void setCurrentProjectPath(const QString& path);
	

	/**
	 * Gibt den Pfad des zuletzt geöffneten Projektes zurück.
	 * @return Pfad des zuletzt geöffneten Projektes
	 * @author Alex Letkemann
	 */
	QString getCurrentProjectPath() const;
	
    /**
	 * Speichert alle Konfigurations-Einstellungen in die Datei bb.conf im conf Ordner
     * @return Erfolg des Speicherns
     */
    bool save();
	
    /**
	 * Lädt alle Konfigurations-Einstellungen aus der Datei bb.conf im conf Ordner
	 * Falls die Datei nicht gefunden wird, wird eine Neue erstellt.
     * @return Erfolg des Öffnens
     */
    bool open();
	

protected:
	/** Verzeichnis des letzten Projektes*/
    QString m_CurrentProjectPath;
};

#endif
