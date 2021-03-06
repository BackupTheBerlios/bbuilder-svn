//
// C++ Interface: bb_doccomponent
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DOCCOMPONENT_H
#define BB_DOCCOMPONENT_H

#include <bb_fileobject.h>
#include <bb_map.h>
#include <bb_drawdevice.h>

#include <bb_point.h>

/**
 * Die Klasse vereinit mehrere Klassen und stellt die Basisklasse für die Komponenten des Projektes (Gelände, Gebäude, Etage).<br>
 * Klasse besteht aus drei Klassen:<br>
 * BB_FileObject:	Für das Speichern/Laden<br>
 * BB_Map: 			Hintergrundbild laden/speichern<br>
 * BB_DrawDevice:	Enthält die Geometriedaten<br>
 * <br>
 * Als weiteres behandelt die Klasse den Maßstab der Map.
 * Der Maßstab kann mittels der beiden Punkte m_ScalePoint_1 und m_ScalePoint_2 eingestellt werden.
 * Die Entfernung der Beiden Punkte wird mit der reelen Entfernung, die der User angeben kann, ins Verhältnis gesetzt.
 * @author Alex Letkemann
 */
class BB_DocComponent : public BB_FileObject, public BB_Map, public BB_DrawDevice
{
    public:
        /**
         * Konstruktor
         * @param path Verzeichnis, in dem gespeichert wird 
         * @param fileName  Dateiname, unter welchem gepeichert wird
         * @param name Objektname
         */
        BB_DocComponent( const QDir& path, const QString &fileName, const QString &name );

        /**
         * Destruktor
         */
        ~BB_DocComponent();

        /**
         * Führt die open() Funktion von BB_FileObject aus und
         * läd zusätztlich die Map Datei des Gebäudes.
         * @author Alex Letkemann
         * @date 13.12.2005
         */
        virtual bool open();

        /**
         * Gibt der Pointer auf den ersten Maßstab-Punkt zurück
        * @return Pointer auf den ersten Maßstab-Punkt
         */
        BB_Point* getScalePoint_1();


        /**
        * Gibt der Pointer auf den zweiten Maßstab-Punkt zurück
        * @return Pointer auf den zweite Maßstab-Punkt
         */
        BB_Point* getScalePoint_2();


        /**
         * Setzt den reelen Abstand zwischen den Maßstab-Punkten
         * @param value der reele Abstand zwischen den Maßstab-Punkten
         */
        void setScaleReal( double value );

        /**
         * Gibt den reelen Abstand zwischen den Maßstab-Punkten
         * @return der reele Abstand zwischen den Maßstab-Punkten
         */
        double getScaleReal() const;

        /**
         * Gibt den Pointer auf den reelen Maßstab.
         * @return Pointer auf den reelen Maßstab.
         */
        double* getScaleRealPointer();


        /**
         * Gibt die Länge der Pixel in Metern zurück
         * @param pixel Pixel
         * @return Meter
         */
        virtual double getMeterPerPixel( double pixel );


        /**
         * Gibt die Länge der Meter in Pixeln zurück
         * @param meter Meter
         * @return Pixel
         */
        virtual double getPixelPerMeter( double meter );


        /**
         * Startet einen Dialog zum Bearbeiten.
         * @param parent Fenster, welches blockert werden soll, solange der Dialog aktiv ist.
         * @return Rückgabewert des Dialoges
        * @author Alex Letkemann
         */
        virtual int keyBoardEdit( QWidget* parent );

        /**
         * Schreibt das XML-Element des DocComponentes in den angegeben Stream.
         * @param out Stream, in welchen geschrieben werden soll.
         * @param depth Einrückung.
         * @author Alex Letkemann
         */
        virtual void generateXElement( QTextStream &out, int depth );

        /**
         * Erzeugt das 3D-Model des Objektes.
         * @param triangles Vektor, an den die 3D-Dreiecke angehängt werden.
         * @param scale Maßstab
         * @author Alex Letkemann
         */
        virtual void createGl( QVector<C3dTriangle>& triangles, double scale );

        /**
         * Gibt die Höhe zurück.
         * @return Die Höhe
         * @author Alex Letkemann
         */
        virtual double getHeight() const;
    protected:

        /** Maßstab-Punkt */
        BB_Point * m_ScalePoint_1;
        /** Maßstab-Punkt */
        BB_Point * m_ScalePoint_2;

        /** Der reele Maßstab */
        double m_ScaleValue;
    protected:

        /**
            * Wird aufgerufen, wenn die Map sich ändert und setzt den Offset neu.
            * @author Alex Letkemann
         */
        virtual void mapChanged();

};

#endif
