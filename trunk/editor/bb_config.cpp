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
#include "bb_globals.h"

#include <iostream>


using namespace std;

/**
 * Konstruktor
 */
BB_Config::BB_Config()
{
    m_CurrentProjectPath = "";
}

/**
 * Destruktor
 */
BB_Config::~BB_Config()
{}



/**
 * Gibt den Pfad des zuletzt geöffneten Projektes zurück.
 * @return Pfad des zuletzt geöffneten Projektes
 * @author Alex Letkemann
 */
QString BB_Config::getCurrentProjectPath() const
{
    return m_CurrentProjectPath;
}


/**
 * Setzt den Pfad auf das zuletzt geöffnete Projekt
 * @param path Pfad auf das zuletzt geöffnete Projekt
 * @author Alex Letkemann
 */
void BB_Config::setCurrentProjectPath( const QString& path )
{
    m_CurrentProjectPath = path;
}


/**
 * Speichert alle Konfigurations-Einstellungen in die Datei bb.conf im conf Ordner
 * @return Erfolg des Speicherns
 */
bool BB_Config::save()
{
    QFile file( CONF_DIR() + SEPARATOR() + "bb.conf" );

    if ( !file.open( QFile::WriteOnly | QFile::Text ) )
    {
        return false;
    }

    QTextStream Stream( &file );

    QDomDocument xmlDoc( "BB_Config" );
    QDomElement root( xmlDoc.createElement( "BB_Config_Root" ) );
    xmlDoc.appendChild( root );

    /* Aktuelles Projekt-Verzeichnis speichern */
    QDomElement currentProjectElement( xmlDoc.createElement( "CurrentProject" ) );
    QDomText currentProjectDoc( xmlDoc.createTextNode( m_CurrentProjectPath ) );
    root.appendChild( currentProjectElement );
    currentProjectElement.appendChild( currentProjectDoc );


    Stream << xmlDoc.toString() << endl;
    file.close();

    return true;
}


/**
 * Lädt alle Konfigurations-Einstellungen aus der Datei bb.conf im conf Ordner
 * Falls die Datei nicht gefunden wird, wird eine Neue erstellt.
 * @return Erfolg des Öffnens
 */
bool BB_Config::open()
{

    QFile file( CONF_DIR() + SEPARATOR() + "bb.conf" );
    if ( !file.exists() )
    {
        cout << "Konfigurationsdatei nicht gefunden,\n\
        beim Beenden des Programms wird eine\n\
        neue Konfigurationsdatei erstellt" << endl;
        return false;
    }

    file.open( QFile::ReadOnly | QFile::Text );

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument domDocument;

    if ( !domDocument.setContent( &file, true, &errorStr, &errorLine,
                                  &errorColumn ) )
    {
        QMessageBox::information( NULL, "BB_Config",
                                  QString( "Parse error at line %1, column %2:\n%3" )
                                  .arg( errorLine )
                                  .arg( errorColumn )
                                  .arg( errorStr ) );

        return false;
    }

    QDomDocumentType docType = domDocument.doctype();

    QDomElement root = domDocument.documentElement();
    if ( docType.name() != "BB_Config" || root.tagName() != "BB_Config_Root" )
    {
        cout << "Ungültige Konfigurationsdatei gefunden" << endl;
        return false;
    }

    QDomElement child = root.firstChildElement( "CurrentProject" );
    if ( !child.isNull() )
    {
        m_CurrentProjectPath = child.text();
        QFileInfo infoFile( m_CurrentProjectPath );
        setPRO_DIR( infoFile.path() );
    }

    return true;

}
