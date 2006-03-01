//
// C++ Interface: bb_map
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_MAP_H
#define BB_MAP_H

#include <QPixmap>
#include <QDir>

/**
 * Die Map ist der Hintergrund der in die Arbeitsfläche gestellt wird.
 * Die Klasse steuert das Laden und das Zoomen der Map.
 * @author Alex Letkemann
 */
class BB_Map
{
    public:

        /**
         * Konstruktor
         */
        BB_Map();


        /**
         * Destruktor
         * @return 
         */
        virtual ~BB_Map();

        /**
         * Setzt des Bild der Map
         * @param map Das neue Bild der Map
         */
        void setMap( const QPixmap& map );

        /**
         * Gibt das Bild der Map zurück
         * @return Bild der Map
         */
        QPixmap& getMap();

        /**
         * Setzt den Zoomfaktor der Map
        * @param z Zoomfaktor der Map
         */
        void setZoom( double z );

        /**
         * Gibt den Zoomfaktor der Map zurück
        * @return Zoomfaktor der Map
         */
        double getZoom() const;


        /**
         * Setzt den Dateinamen der Map
         * @param filename Dateiname der Map
         */
        void setMapFileName( const QString& filename );

        /**
         * Gibt den Dateinamen der Map zurück
         * @return Dateiname der Map
         */
        QString getMapFileName() const;

        /**
         * Lädt die Bilddatei aus dem Verzeichnis 'path'.
         * @param path Verzeichnis, aus dem die Bilddatei (m_MapFileName) geladen wird.
         * @return True, wenn die Bilddatei erfolgreich geladen werden konnte, sonst False
         */
        bool loadMap( QDir& path );
    protected:

        /** Das Bilde der Map */
        QPixmap m_Map;

        /** Zoomfaktor der Map */
        double m_Zoom;

        /** Dateiname der Map */
        QString m_MapFileName;
    protected:

        /**
         * Wird aufgerufen, wenn sich die Map geändert hat, bzw. wenn die Map geladen wurde. 
         */
        virtual void mapChanged();
};

#endif
