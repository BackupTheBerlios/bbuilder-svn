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
#ifndef BB_DOC_H
#define BB_DOC_H

#include <QWidget>
#include <QVector>
#include <QDir>

#include "bb_fileobject.h"

#include "bb_terrain.h"
#include "bb_building.h"
#include "bb_level.h"

#include "bb_xdochandler.h"
#include <c3dtriangle.h>
#include "3dmath.h"
class BB_Tab;

/**
@author Alex Letkemann
*/
class BB_Doc : public BB_FileObject
{
    public:
		/**
		 * Konstruktor 
		 */
        BB_Doc();

		/**
		 * Destruktor 
		 */
        ~BB_Doc();
        /**
         * Liefert einen Pointer auf das Terrain
         * @return Pointer auf das Terrain
         * @author Alex Letkemann
         */
        BB_Terrain* BB_Doc::getTerrain();
		
		/**
		 * Gibt einen Pointer auf einen Vector mit allen Gebäuden zurück
		 * @return Pointer auf einen Vektor mit allen Gebäuden
		 * @author Alex Letkemann
		 */
        QVector<BB_Building*>* getBuildings();
		
		/**
		 * Liefert einen Vector mit allen Levels
		 * @return Vector mit allen Levels
		 * @author Alex Letkemann
		 */
        QVector<BB_Level*>* getLevels();
		
		/**
		 * Öffnet und lädt das Projekt 'fileName'.
		 * @return Falls Projekt geladen wurde True, sonst False.
		 * @author Alex Letkemann
		 */
        bool open( QString fileName );
		
		/**
		 * Schliesst das gelade Projekt
		 * @author Alex Letkemann
		 */
        bool close();
		
		/**
		 * Erzeugt ein neues Projekt im Verzeichnis 'path'.
		 * Im angegebenen Verzeichnis werden weitere Unterverzeichnise angelegt und die Projektdatei erzeugt.
		 * @param name Name des Proketes
		 * @param desc Beschreibung des Projektes
		 * @param path Pfad, wo der neuen Projekt angelegt wird.
		 * @return Erfolg des Anlegens
		 * @author Alex Letkemann
		 */
        bool createNew( const QString &name, const QString &desc, const QDir &path );
		
		/**
		 * Schreibt die Projektdatei in den übergeben Stream 'out
		 * @param out Stream, in den Geschrieben werden soll.
		 * @return Erfolg des Schreibens
		 * @author Alex Letkemann
		 */
        bool write( QTextStream &out );
		
		/**
		 * Startet einen Dialog zum Erstellen eines neuen Gebäudes.
		 * Nach dem Erstellen des Gebäudes, wird dieses zurückgegeben.
		 * @param parent Fenster, welches blockiert werden soll, solange der Dialog aktiv ist.
		 * @return Das neue Gebäude. Falls Gebäude nicht erstellt werden konnte, wird NULL zurückgegeben.
		 * @author Alex Letkemann
		 */
        BB_Building* newBuilding( QWidget * parent );
		
        /**
		 * Startet einen Dialog zum Erstellen einer neuen Etage.<br>
		 * Die Etage wird dem übergebenen Gebäude hinzugefügt.<br>
		 * Nach dem Erstellen der Etage, wird diese zurückgegeben.
		 * @param building Gebäude, welchem die Etage hinzugefügt werden soll.
		 * @param parent Fenster, welches blockiert werden soll, solange der Dialog aktiv ist.
		 * @return Die neue Etage. Falls die Etage nicht erstellt werden konnte, wird NULL zurückgegeben.
		 * @author Alex Letkemann
	     */
        BB_Level* newLevel( BB_Building* building, QWidget * parent );
		
		/**
		 * Reserviert ein leeres Gebäude im angegebenen Verzeichnis und Dateinamen.<br />
		 * Die Datei muss an der stelle bereits existieren, damit diese geladen werden kann.<br />
		 * @param path Existierender Pfad
		 * @param fileName Existierende Datei
		 * @return Pointer auf das reservierte Gebäude.
		 * @author Alex Letkemann
		 */
        BB_Building* newBuilding( QDir& path, QString& fileName );
		
		/**
		 * Reserviert eine leere Etage im angegebenen Verzeichnis und Dateinamen.<br />
		 * Die Datei muss an der stelle bereits existieren, damit diese geladen werden kann.<br />
		 * @param building Gebäude, zu dem die Etage gehört.
		 * @param path Existierender Pfad
		 * @param fileName Existierende Datei
		 * @return Pointer auf die reservierte Etage.
		 * @author Alex Letkemann
		 */
        BB_Level* newLevel( BB_Building* building, QDir& path, QString& fileName );
		
		/**
		 * Reserviert ein leeres Gelände im angegebenen Verzeichnis und Dateinamen.<br />
		 * Die Datei muss an der stelle bereits existieren, damit diese geladen werden kann.<br />
		 * @param path Existierender Pfad
		 * @param fileName Existierende Datei
		 * @return Pointer auf das reservierte Gelände.
		 * @author Alex Letkemann
		 */
        BB_Terrain* newTerrain( QDir& path, QString& fileName );
		
		/**
		 * Löscht das Gebäude, welches das QListWidgetItem item hat.
		 * @param item QListWidgetItem des Gebäudes
		 * @return True, falls das Gebäude erfolgreich gelöscht wurde, sonst false.
		 * @author Alex Letkemann
		 */
        bool deleteBuilding( QListWidgetItem* item );
		
        /**
		 * Gibt das Gebäude mit dem angegebenen QListWidgetItem zurück.
		 * @param item QListWidgetItem
		 * @return Gebäude, falls ein solches Existiert, sonst NULL.
		 * @author Alex Letkemann
         */
        BB_Building* getBuilding( QListWidgetItem* item );
		
		/**
		 * Fügt einen Tab als Beobachter hinzu.
		 * @param tab Tab, welches als Beobachter hinzugefügt werden soll.
		 * @author Alex Letkemann
		 */
        void addObserver( BB_Tab *tab );
		
		/**
		 * Gibt das Gebäude mit dem übergebenen Index zurück.
		 * Falls kein Gebäude mit dem angegebenen Index existiert, wird NULL zurückgegeben.
		 * @param index Gebäude-Index
		 * @return Gebäude mit dem übergebenen Index oder NULL. 
		 */
        BB_Building* getBuilding( int index );
		
		/**
		 * Löscht die angegebene Etage
		 * @param level Etage, welche gelöscht werden soll.
		 * @return Erfolg des Löschens. True, falls die Etage gelöscht werden konnte sonst false.
		 */
        bool deleteLevel( BB_Level* level );
        
		/**
		 * Löscht alle Etagen des angegebenen Gebäudes.
		 * @param building Gebäude, wessen etage gelöscht werden sollen.
		 * @author Alex Letkemann
		 */
		void deleteLevels( BB_Building* building );
		
		/**
		 * Gibt das Gebäude mit der angegeben Objekt-ID zurück.
		 * Falls kein Gebäude mit solcher ID existiert wird NULL zurückgegeben.
		 * @param objectId Objekt-ID des Gebäudes
		 * @return Gebäude oder NULL.
		 * @author Alex Letkemann
		 */
        BB_Building* getBuildingById( int objectId );
        
		/**
		 * Zeichnet das Gesamt-3D-Model.
		 * @author Alex Letkemann
		 */
		void showGl();
		
		/**
		 * Erzeugt alle 3D-Objekte.
		 * @author Alex Letkemann
		 */
        void createGlObjects();
		
		/**
		 * Gibt den Kollisionvektor zurück.
		 * @return Kollisionvektor
		 * @author Vacelav Ustinov
		 */
        CVector3 * getCollisionVector();
		
		/**
		 * Gibt den Vektor mit allen 3D-Dreiecken zurück.
		 * @return Vektor mit allen 3D-Dreiecken
		 * @author Vacelav Ustinov
		 */
        QVector<C3dTriangle> & getTriangles();
    protected:
		
		/**
	     * Ruft die documentChanged()-Funktion der Beobachter auf.
	     * @author Alex Letkemann
		 */
        void documentChanged();

        /**
         * Löscht den Inhalt des Dokumentes
         * @return Liefert 'false' im Fehlerfall zurück, sonst 'true'.
         * @author Alex Letkemann
         * @date 22.10.2005
         */
        bool clear();
    protected:

		/** Gelände */
        BB_Terrain *m_Terrain;
		
		/** Gebäude-Vektor */
        QVector<BB_Building*> m_Buildings;
		
		/** Etagen-Vektor */
        QVector<BB_Level*> m_Levels;
		
		/** Pfad zum Projekt */
        QDir m_ProjectPath;
		
		/** Projektdateiname */
        QString m_ProjectFile;
		
		/** Liste der Beobachter */
        QList<BB_Tab*> m_Observer;
		
		/** Maximale Objekt-ID */
        int m_MaxId;
		
		/** Vektor der 3D-Dreiecke */
        QVector<C3dTriangle> m_Triangles;
		
		/** Kollisionsvektor */
        CVector3 * m_CollisionVector;



		/* Freund-Klasse zum laden der XML-Projektdatei */
        friend class BB_XDocHandler;

};

#endif
