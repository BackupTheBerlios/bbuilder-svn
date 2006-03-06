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
#ifndef BB_LEVEL_H
#define BB_LEVEL_H

#include "bb_doccomponent.h"

class BB_Building;

/**
 * Stellt eine Etage dar.<br>
 * Die Etage kennt das Gebäude zu welchem sie gehört und besitzt eine Höhe.
 * @author Alex Letkemann
 */
class BB_Level : public BB_DocComponent
{
    public:
        /**
         * Konstrucktor<br>
        * Erstellt eine neue Etage
         * @param building Gebäude, welchem die Etage zugeteilt wird.
         * @param path Pfad zur Datei
         * @param fileName Dateiname
         * @param name Etagen-Name
        * @author Alex Letkemann
         */
        BB_Level( BB_Building* building, const QDir& path, const QString &fileName, const QString &name = QString( "" ) );

        /**
         * Destruktor
         */
        virtual ~BB_Level();

        /**
         * Erstellt den 'bb_level' XML-Element
         * @param out Stream, in den geschrieben werden soll-.
         * @param depth Eirückung
        * @author Alex Letkemann
         */
        virtual void generateXElement( QTextStream &out, int depth );

        /**
         * \fn write( QTextStream &out )
         */
        virtual bool write( QTextStream &out );


        /**
        * Gibt den Klassennamen zurück
        * @return Klassenname
        */
        virtual const QString getClassName();


        /**
         * Setzt die Höhe der Etage
         * @param Value Höhe der Etage
        * @author Alex Letkemann
         */
        void setHeight( double Value );

        /**
         * Gibt die Höhe zurück
         * @return Höhe der Etage
        * @author Alex Letkemann
         */
        virtual double getHeight() const;

        /**
         * Gibt das Gebäude zurück, welchem die Etage zugehört.
         * @return Gebäude
        * @author Alex Letkemann
         */
        BB_Building* getBuilding();
        /**
         * Gibt die Länge der Pixel in Metern zurück
         * @param pixel Pixel
         * @return Meter
         * @author Vaceslav Ustinov
         */
        double getMeterPerPixel( double pixel );
/**
 * Gibt die Länge der Meter in Pixeln zurück
 * @param meter Meter
 * @return Pixel
 * @author Vaceslav Ustinov
 */
double getPixelPerMeter( double meter );


        /**
        * \fn keyBoardEdit( QWidget* parent )
         */
        virtual int keyBoardEdit( QWidget* parent );


        /**
         * Erzeugt das 3D-Model der Etage.
        * Das Model wird komplett aus Dreiecken erstellt, welche an den übergebene Vektor 'triangles' angehängt wird.
         * @param triangles Vektor, an den die Dreiecke angehängt werden.
         * @param vector Positionvektor
         * @param rotation Rotation der Etage in Grad
         * @param scale Maßstab
         * @param height Höhe eines Meters in Pixel
         */
        virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );
    protected:
        /** Hohe der Etage in Meter */
        double m_Height;

        /** Gebäude, dem die Etage gehört */
        BB_Building* m_Building;
};

#endif
