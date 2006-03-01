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
#include <bb_tab.h>
#include <iostream>

#include <QtOpenGL>

using namespace std;


/**
 * Konstruktor 
 */
BB_Doc::BB_Doc()
// Bei der Initialisierung hat das Projekt noch keinen Path und keinen Dateiname,
// deswegen wird ein leerer Path und ein leerer Dateiname übergeben.
// Es werden temporäre Daten von BB_FileObject erzeugt.
// Die echten Daten werden mit open() oder createNew() erzeugt.
        : BB_FileObject( QDir(), QString(), QString( "bb_doc" ) )
{
    m_Terrain = NULL;
    m_Handler = new BB_XDocHandler( this );
    m_CollisionVector = NULL;

}


/**
 * Destruktor
 */
BB_Doc::~BB_Doc()
{}



/**
 * Gibt einen Pointer auf einen Vector mit allen Gebäuden zurück
 * @return Pointer auf einen Vektor mit allen Gebäuden
 * @author Alex Letkemann
 */
QVector< BB_Building*>* BB_Doc::getBuildings()
{
    return & m_Buildings;
}


/**
 * Liefert einen Vector mit allen Levels
 * @return Vector mit allen Levels
 * @author Alex Letkemann
 */
QVector<BB_Level*>* BB_Doc::getLevels()
{
    return & m_Levels;
}


/**
 * Liefert einen Pointer auf das Terrain
 * @return Pointer auf das Terrain
 * @author Alex Letkemann
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
    if ( m_Terrain != NULL )
    {
        delete m_Terrain;
        m_Terrain = NULL;
    }

    BB_DocComponent* object;

    /* Alle Etagen löschen */
    for ( int i = m_Levels.count() - 1 ; i >= 0 ; i-- )
    {
        object = m_Levels.at( i );
        m_Levels.remove( i );
        if ( object != NULL )
        {
            delete object;
            object = NULL;
        }
    }

    m_Levels.clear();
    /* Alle Gebäude löschen */
    for ( int i = m_Buildings.count() - 1 ; i >= 0 ; i-- )
    {
        object = m_Buildings.at( i );
        if ( object != NULL )
        {
            delete object;
            object = NULL;

        }
        m_Buildings.remove( i );
    }
    //     cout << "m_Buildings.clear(); count: " << m_Buildings.count() << endl;
    m_Buildings.clear();





    BB_Object::m_Counter = 0;

    documentChanged();

    return true;
}


/**
 * Öffnet und lädt das Projekt 'fileName'.
 * @return Falls Projekt geladen wurde True, sonst False.
 * @author Alex Letkemann
 */
bool BB_Doc::open( QString fileName )
{
    /* Dokument leeren */
    clear();

    if ( &fileName != NULL )
    {

        QDir dir( fileName );
        m_ProjectFile = dir.dirName();

        dir.cdUp();
        m_ProjectPath = dir;



        m_FileName = m_ProjectFile;
        m_FilePath = m_ProjectPath;


        /* Projektdatei auslesen */
        if ( !BB_FileObject::open() )
        {
            return false;
        }

		setPRO_DIR( m_ProjectPath.path() );
		
        if ( m_Terrain != NULL )
        {
            m_Terrain->open();
        }
        else
        {
            QString newTerrainName( "terrain.xml" );
            m_Terrain = newTerrain( m_ProjectPath, newTerrainName );
        }

        for ( int i = 0; i < m_Buildings.count(); i++ )
        {
            m_Buildings.at( i ) ->open();
        }

        m_Terrain->resolveBuildingIds( this );

        for ( int i = 0; i < m_Levels.count(); i++ )
        {
            m_Levels.at( i ) ->open();
        }


        BB_Object::m_Counter = m_MaxId;
    }
    else
    {
        cout << "BB_Doc::open(): ungültigen Dateinamen erhalten" << endl;
        return false;
    }

    documentChanged();
    
    return true;
}


/**
 * Schliesst das gelade Projekt
 * @author Alex Letkemann
 */
bool BB_Doc::close()
{
    m_ProjectFile = "";
    m_ProjectPath = QDir( "" );
    setPRO_DIR( "" );
    return clear();
}


/**
 * Erzeugt ein neues Projekt im Verzeichnis 'path'.
 * Im angegebenen Verzeichnis werden weitere Unterverzeichnise angelegt und die Projektdatei erzeugt.
 * @param name Name des Proketes
 * @param desc Beschreibung des Projektes
 * @param path Pfad, wo der neuen Projekt angelegt wird.
 * @return Erfolg des Anlegens
 * @author Alex Letkemann
 */
bool BB_Doc::createNew( const QString &name, const QString &desc, const QDir &path )
{

    if ( &name == NULL || name.isEmpty() || &desc == NULL || &path == NULL )
    {
        return false;
    }

    QDir tmpPath;

    setName( name );
    setDescription( desc );

    m_ProjectFile = path.dirName() + ".glbb";
    m_ProjectPath = path.path();

    m_FilePath = m_ProjectPath;
    m_FileName = m_ProjectFile;


    m_ProjectPath.mkdir( "terrain" );
    m_ProjectPath.mkdir( "buildings" );
    m_ProjectPath.mkdir( "levels" );
    m_ProjectPath.mkdir( "textures" );

    tmpPath = m_ProjectPath;
    tmpPath.cd( "terrain" );

    QString s = "terrain.xml";

    /* neues Gelände erzeugen */
    newTerrain( tmpPath, s );
    m_Terrain->setName( "Terrain" );



    save();
    documentChanged();
	setPRO_DIR( m_ProjectPath.path() );
    return true;
}


/**
 * Schreibt die Projektdatei in den übergeben Stream 'out
 * @param out Stream, in den Geschrieben werden soll.
 * @return Erfolg des Schreibens
 * @author Alex Letkemann
 */
bool BB_Doc::write( QTextStream &out )
{
    m_MaxId = BB_Object::m_Counter;
    int depth = 1;

    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    << "<!DOCTYPE bb_doc>\n"
    << "<bb_doc version=\"1.0\">\n";

    BB_Object::generateXElement( out, depth );
    out << BB::indent( depth ) << "<properties max_id=\"" << m_MaxId << "\" />" << endl;
    if ( getTerrain() != NULL )
    {
        m_Terrain->generateXElement( out, depth );
    }

    if ( m_Buildings.count() == 0 )
    {
        out << BB::indent( depth ) << "<buildings />\n";
    }
    else
    {
        out << BB::indent( depth ) << "<buildings>\n";

        for ( int i = 0; i < m_Buildings.count(); i++ )
        {
            m_Buildings.at( i ) ->generateXElement( out, depth + 1 );
        }

        out << BB::indent( depth ) << "</buildings>\n";
    }

    if ( m_Levels.count() == 0 )
    {
        out << BB::indent( depth ) << "<levels />\n";
    }
    else
    {
        out << BB::indent( depth ) << "<levels>\n";

        for ( int i = 0; i < m_Levels.count(); i++ )
        {
            m_Levels.at( i ) ->generateXElement( out, depth + 1 );
        }

        out << BB::indent( depth ) << "</levels>\n";
    }

    out << "</bb_doc>\n";

    return true;
}



/**
 * Startet einen Dialog zum Erstellen eines neuen Gebäudes.
 * Nach dem Erstellen des Gebäudes, wird dieses zurückgegeben.
 * @param parent Fenster, welches blockiert werden soll, solange der Dialog aktiv ist.
 * @return Das neue Gebäude. Falls Gebäude nicht erstellt werden konnte, wird NULL zurückgegeben.
 * @author Alex Letkemann
 */
BB_Building* BB_Doc::newBuilding( QWidget * parent )
{
    QString fileName;
    QDir path = m_ProjectPath;
    path.cd( "buildings" );

    BB_Building* building = new BB_Building( path, "tempFile" );

    if ( building->keyBoardEdit( parent ) == QDialog::Accepted )
    {
        building->setFileName( fileName.sprintf( "%08d.xml", building->getObjectNr() ) );
        building->save();
        m_Buildings.append( building );

        save();
        documentChanged();
    }
    else
    {
        delete building;
        building = NULL;
    }

    return building;
}


/**
 * Startet einen Dialog zum Erstellen einer neuen Etage.
 * Nach dem Erstellen der Etage, wird diese zurückgegeben.
 * @param parent Fenster, welches blockiert werden soll, solange der Dialog aktiv ist.
 * @return Die neue Etage. Falls die Etage nicht erstellt werden konnte, wird NULL zurückgegeben.
 * @author Alex Letkemann
 */
BB_Level* BB_Doc::newLevel( BB_Building* building, QWidget * parent )
{
    // 	Eine Etage kann nur mit einem Gebäude erzeugt werden
    if ( building == NULL )
    {
        return NULL;
    }

    QString fileName;
    QDir path = m_ProjectPath;
    path.cd( "levels" );

    BB_Level* level = new BB_Level( building , path, "tempFile" );

    if ( level->keyBoardEdit( parent ) == QDialog::Accepted )
    {
        level->setFileName( fileName.sprintf( "%08d.xml", level->getObjectNr() ) );
        level->save();
        m_Levels.append( level );

        save();
        documentChanged();
    }
    else
    {
        if ( level != NULL )
        {
            delete level;
            level = NULL;
        }
    }

    return level;
}



/**
 * Reserviert ein leeres Gebäude im angegebenen Verzeichnis und Dateinamen.<br />
 * Die Datei muss an der stelle bereits existieren, damit diese geladen werden kann.<br />
 * @param path Existierender Pfad
 * @param fileName Existierende Datei
 * @return Pointer auf das reservierte Gebäude.
 * @author Alex Letkemann
 */
BB_Building* BB_Doc::newBuilding( QDir& path, QString& fileName )
{
    BB_Building * building = new BB_Building( path, fileName );
    m_Buildings.append( building );
    documentChanged();
    return building;
}


/**
 * Reserviert eine leere Etage im angegebenen Verzeichnis und Dateinamen.<br />
 * Die Datei muss an der stelle bereits existieren, damit diese geladen werden kann.<br />
 * @param building Gebäude, zu dem die Etage gehört.
 * @param path Existierender Pfad
 * @param fileName Existierende Datei
 * @return Pointer auf die reservierte Etage.
 * @author Alex Letkemann
 */
BB_Level* BB_Doc::newLevel( BB_Building* building, QDir& path, QString& fileName )
{
    BB_Level * level = new BB_Level( building, path, fileName );
    m_Levels.append( level );
    documentChanged();
    return level;
}


/**
 * Reserviert ein leeres Gelände im angegebenen Verzeichnis und Dateinamen.<br />
 * Die Datei muss an der stelle bereits existieren, damit diese geladen werden kann.<br />
 * @param path Existierender Pfad
 * @param fileName Existierende Datei
 * @return Pointer auf das reservierte Gelände.
 * @author Alex Letkemann
 */
BB_Terrain* BB_Doc::newTerrain( QDir& path, QString& fileName )
{
    m_Terrain = new BB_Terrain( path, fileName, "Terrain" );
    documentChanged();
    return m_Terrain;
}



/**
 * Gibt das Gebäude mit dem angegebenen QListWidgetItem zurück.
 * @param item QListWidgetItem
 * @return Gebäude, falls ein solches Existiert, sonst NULL.
 * @author Alex Letkemann
 */
BB_Building* BB_Doc::getBuilding( QListWidgetItem* item )
{
    if ( &m_Buildings != NULL )
    {
        BB_Building * building;

        for ( int i = 0; i < m_Buildings.count(); i++ )
        {
            building = m_Buildings.at( i );
            if ( building != NULL && building->getListWidgetItem() == item )
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
 * @author Alex Letkemann
 */
bool BB_Doc::deleteBuilding( QListWidgetItem* item )
{
    if ( item != NULL )
    {
        BB_Building * building;

        for ( int i = m_Buildings.count() - 1 ; i >= 0 ; i-- )
        {
            building = m_Buildings.at( i );
            if ( item == building->getListWidgetItem() )
            {
                m_Buildings.remove( i );
                deleteLevels( building );
                m_Terrain->buildingDeleted( building );
                delete building;
                documentChanged();
                return true;
            }
        }
    }

    return false;
}



/**
 * Fügt einen Tab als Beobachter hinzu.
 * @param tab Tab, welches als Beobachter hinzugefügt werden soll.
 * @author Alex Letkemann
 */
void BB_Doc::addObserver( BB_Tab *tab )
{
    if ( tab != NULL )
    {
        m_Observer.append( tab );
    }
}

/**
 * Ruft die documentChanged()-Funktion der Beobachter auf.
 * @author Alex Letkemann
 */
void BB_Doc::documentChanged()
{

    for ( int i = 0; i < m_Observer.count(); i++ )
    {
        m_Observer.at( i ) ->documentChanged();
    }
}



/**
 * Gibt das Gebäude mit dem übergebenen Index zurück.
 * Falls kein Gebäude mit dem angegebenen Index existiert, wird NULL zurückgegeben.
 * @param index Gebäude-Index
 * @return Gebäude mit dem übergebenen Index oder NULL. 
 */
BB_Building* BB_Doc::getBuilding( int index )
{
    if ( index < m_Buildings.count() && index >= 0 )
    {
        return m_Buildings.at( index );
    }

    return NULL;
}



/**
 * Löscht die angegebene Etage
 * @param level Etage, welche gelöscht werden soll.
 * @return Erfolg des Löschens. True, falls die Etage gelöscht werden konnte sonst false.
 * @author Alex Letkemann
 */
bool BB_Doc::deleteLevel( BB_Level* level )
{
    for ( int i = m_Levels.count() - 1; i >= 0; i-- )
    {
        if ( m_Levels.at( i ) == level )
        {
			level->getBuilding()->removeLevel( level );
			m_Levels.remove(i);
            delete level;
            documentChanged();
            return true;
        }
    }

    return false;
}



/**
 * Löscht alle Etagen des angegebenen Gebäudes.
 * @param building Gebäude, wessen etage gelöscht werden sollen.
 * @author Alex Letkemann
 */
void BB_Doc::deleteLevels( BB_Building* building )
{
    if ( building != NULL )
    {
        for ( int i = building->getLevelCount(); i >= 0; i-- )
        {
            deleteLevel( building->getLevel( i ) );
        }
    }
}



/**
 * Gibt das Gebäude mit der angegeben Objekt-ID zurück.
 * Falls kein Gebäude mit solcher ID existiert wird NULL zurückgegeben.
 * @param objectId Objekt-ID des Gebäudes
 * @return Gebäude oder NULL.
 * @author Alex Letkemann
 */
BB_Building* BB_Doc::getBuildingById( int objectId )
{
    for ( int i = 0; i < m_Buildings.count(); i++ )
    {
        if ( m_Buildings.at( i ) ->getObjectNr() == objectId )
        {
            return m_Buildings.at( i );
        }
    }

    return NULL;
}



/**
 * Zeichnet das Gesamt-3D-Model.
 * @author Alex Letkemann
 */
void BB_Doc::showGl()
{

    for ( int i = 0; i < m_Triangles.count(); i++ )
    {
        if ( m_Triangles.at( i ).getVisible() )
        {
            m_Triangles.at( i ).show();
        }

    }
}




void BB_Doc::createGlObjects()
{

    m_Triangles.clear();

    if ( m_CollisionVector != NULL )
    {
        delete [] m_CollisionVector;
    }

    double scale = 1.0;

    if ( m_Terrain != NULL )
    {
        m_Terrain->createGl( m_Triangles, scale );
    }

    m_CollisionVector = new CVector3[ m_Triangles.count() * 3 ];

    for ( int i = 0;i < m_Triangles.count() ;i++ )
    {
        if ( m_Triangles.at( i ).getCollision() )
        {
            m_CollisionVector[ i * 3 ].x = m_Triangles.at( i ).getV0().x();
            m_CollisionVector[ i * 3 ].y = m_Triangles.at( i ).getV0().y();
            m_CollisionVector[ i * 3 ].z = m_Triangles.at( i ).getV0().z();

            m_CollisionVector[ ( i * 3 ) + 1 ].x = m_Triangles.at( i ).getV1().x();
            m_CollisionVector[ ( i * 3 ) + 1 ].y = m_Triangles.at( i ).getV1().y();
            m_CollisionVector[ ( i * 3 ) + 1 ].z = m_Triangles.at( i ).getV1().z();

            m_CollisionVector[ ( i * 3 ) + 2 ].x = m_Triangles.at( i ).getV2().x();
            m_CollisionVector[ ( i * 3 ) + 2 ].y = m_Triangles.at( i ).getV2().y();
            m_CollisionVector[ ( i * 3 ) + 2 ].z = m_Triangles.at( i ).getV2().z();
        }
        else
        {
            cout << "keine collision" << endl;
        }
    }

}

/**
 * Gibt den Kollisionvektor zurück.
 * @return Kollisionvektor
 * @author Vacelav Ustinov
 */
CVector3 * BB_Doc::getCollisionVector()
{
    return m_CollisionVector;
}


/**
 * Gibt den Vektor mit allen 3D-Dreiecken zurück.
 * @return Vektor mit allen 3D-Dreiecken
 * @author Vacelav Ustinov
 */
QVector<C3dTriangle> & BB_Doc::getTriangles()
{
    return m_Triangles;
}
