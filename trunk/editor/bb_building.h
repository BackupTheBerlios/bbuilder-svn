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
#ifndef BB_BUILDING_H
#define BB_BUILDING_H

#include <QVector>
#include <QtGui>
#include <QListWidgetItem>

#include "bb_fileobject.h"
#include "bb_level.h"
#include "bb_point.h"

#include "bb_doccomponent.h"

/**
 * Klasse stellt ein Gebäude dar.<br>
 * Das Gebäude kann mehrere Etagen haben, die im Vektor m_Levels gespeichert werden.<br>
 * @author Alex Letkemann
 */
class BB_Building : public BB_DocComponent
{
    public:
        /**
         * Konstruktor
         * @param path Verzeichnis, in dem gespeichert wird 
         * @param fileName  Dateiname, unter welchem gepeichert wird
         * @param name Gebäudename
         * @author Alex Letkemann
         */
        BB_Building( const QDir& path, const QString &fileName, const QString &name = QString( "" ) );


        /**
         * Destruktor
		 * @author Alex Letkemann
         */
        virtual ~BB_Building();

        /**
         * Rüft ein Dialog auf, mit welchem einige Eigenschaften des Gebäudes geändert werden können. 
         * @param parent Fenster, welches Blockiert wird, solange der Dialog offen ist.
         * @return Ergebnis des Dialoges
		 * @author Alex Letkemann
         */
        virtual int keyBoardEdit( QWidget* parent );

        /**
         * Schreibt das Gebäude in Form von XML in den übergebenen Stream 'out'.
         * @param out Stream, in welchen geschrieben wird.
         * @return Erfolg des Schreibens
		 * @author Alex Letkemann
         */
        virtual bool write( QTextStream &out );

        /**
         * \fn BB_Object::getClassName()
         */
        virtual const QString getClassName();


        /**
         * Löscht alle Dateien des Gebäudes
		 * @author Alex Letkemann
         */
        void remove();

        /**
         * Fügt die übergebene Etage dem Gebäude hinzu.
         * @param level Etage, die dem Gebäude hinzugefügt werden soll.
		 * @author Alex Letkemann
         */
        void addLevel( BB_Level* level );

        /**
         * Gibt den Vektor mit allen Etagen zurück.
         * @return Vektor mit allen Etagen.
		 * @author Alex Letkemann
         */
        QVector<BB_Level*>* getLevels();

        /**
         * Entfernt die übergebene Etage aus dem Gebäude.
         * @param level Etage, die aus dem gebäude entfernt werden soll.
		 * @author Alex Letkemann
         */
        void removeLevel( BB_Level* level );

        /**
         * Gibt die Etage nach ihrem Index zurück.
         * @param index Index der Etage.
         * @return Pointer auf die Etage, falls diese Existiert sonst NULL.
		 * @author Alex Letkemann
         */
        BB_Level* getLevel( int index );

        /**
         * Gibt die Anzahl der Etagen im Gebäude zurück.
         * @return Anzahl der Etagen im Gebäude.
		 * @author Alex Letkemann
         */
        int getLevelCount();

        /**
         * Gibt die Höhe des Gebäudes zurück.
         * @return Höhe des Gebäudes.
		 * @author Alex Letkemann
         */
        virtual double getHeight() const;

        /**
         * Erzeugt die 3D Ansicht des Gebäudes.<br>
         * Die 3D Ansicht wird komplett aus Dreiecken erzeugt. Die Erzeugten Dreiecke werden an den üergeben Vektor 'triangles' angehängt.
         * @param triangles Vektor, an den die Dreiecke angehängt werden.
         * @param vector Vektor zur Positionierung des Gebäudes.
         * @param rotation Rotation des Gebäudes in der Y-Achse
         * @param scale Skalierung des Gebäudes
         * @param height Hier keine Funktion
		 * @author Alex Letkemann
         */
        virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );


    protected:
        /** Vektor mit Pointern auf die Etagen des Gebäudes */
        QVector<BB_Level*> m_Levels;

};

#endif
