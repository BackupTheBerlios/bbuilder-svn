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
@author Alex Letkemann
*/
class BB_Map
{
    public:
        BB_Map();
        ~BB_Map();
        void setMap( const QPixmap& theValue );
        QPixmap& getMap();
        void setZoom( double theValue );
        double getZoom() const;
        void setMapFileName( const QString& theValue );
        QString getMapFileName() const;
        bool loadMap( QDir& path );
    protected:
        QPixmap m_Map;
        double m_Zoom;
        QString m_MapFileName;
};

#endif
