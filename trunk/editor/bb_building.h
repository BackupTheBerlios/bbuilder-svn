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

#include "bb_drawobject.h"
#include "bb_map.h"

/**
@author Alex Letkemann
*/
class BB_Building : public BB_FileObject,  public BB_Map {
public:
	BB_Building(const QDir& path, const QString &fileName, const QString &name = QString(""));

    virtual ~BB_Building();
    int keyBoardEdit(QWidget* parent);
    QVector<BB_DrawObject*>* getDrawObjects();
	virtual bool write(QTextStream &out);
    virtual void generateXElement(QTextStream &out, int depth);
    virtual const QString getClassName();
    virtual bool open();
    void remove();
    virtual QListWidgetItem* getListWidgetItem();
    

protected:
    QVector<BB_Level>* m_Levels;
    QVector<BB_DrawObject*>* m_DrawObject;
    QListWidgetItem* m_ListWidgetItem;
    
};

#endif
