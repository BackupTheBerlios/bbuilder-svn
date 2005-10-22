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

#include <QVector>
#include <QDir>

#include "bb_fileobject.h"

#include "bb_terrain.h"
#include "bb_building.h"
#include "bb_level.h"

/**
@author Alex Letkemann
*/
class BB_Doc : public BB_FileObject {
public:
    BB_Doc();

    virtual ~BB_Doc();
	
	virtual BB_Terrain* BB_Doc::getTerrain();
	virtual QVector<BB_Building*>* getBuildings();
	virtual QVector<BB_Level*>* getLevels();
	virtual bool open(QString &fileName);
    virtual bool close();
	virtual bool createNew(QDir &path);
    virtual bool write(QIODevice*)
;

protected:
	
	BB_Terrain *m_Terrain;	
	QVector<BB_Building*> m_Buildings;
    QVector<BB_Level*> m_Levels;
	QDir m_ProjectPath;
	QString m_ProjectFile;
	
	virtual bool clear();
	
};

#endif
