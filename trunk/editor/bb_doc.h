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
class BB_Tab;

/**
@author Alex Letkemann
*/
class BB_Doc : public BB_FileObject
{
    public:
        BB_Doc();

        ~BB_Doc();

        BB_Terrain* BB_Doc::getTerrain();
        QVector<BB_Building*>* getBuildings();
        QVector<BB_Level*>* getLevels();
        bool open( QString fileName );
        bool close();
        bool createNew( const QString &name, const QString &desc, const QDir &path );
        bool write( QTextStream &out );
        BB_Building* newBuilding( QWidget * parent );
        BB_Level* newLevel( BB_Building* building, QWidget * parent );
        BB_Building* newBuilding( QDir& path, QString& fileName );
        BB_Level* newLevel( BB_Building* building, QDir& path, QString& fileName );
        BB_Terrain* newTerrain( QDir& path, QString& fileName );
        bool deleteBuilding( QListWidgetItem* item );
        BB_Building* getBuilding( QListWidgetItem* item );
        void addObserver( BB_Tab *tab );
        BB_Building* getBuilding( int index );
        bool deleteLevel( BB_Level* level );
        void deleteLevels( BB_Building* building );
        BB_Building* getBuildingById( int objectId );
        void showGl();
    void createGlObjects();
    protected:
        void documentChanged();

    protected:

        BB_Terrain *m_Terrain;
        QVector<BB_Building*> m_Buildings;
        QVector<BB_Level*> m_Levels;
        QDir m_ProjectPath;
        QString m_ProjectFile;
        QList<BB_Tab*> m_Observer;
        int m_MaxId;
    QVector<C3dTriangle> m_Triangles;

        bool clear();



        friend class BB_XDocHandler;

};

#endif
