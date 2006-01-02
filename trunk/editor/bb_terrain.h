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
#ifndef BB_TERRAIN_H
#define BB_TERRAIN_H

#include "bb_doccomponent.h"

#include <QTextStream>

/**
@author Alex Letkemann
*/
class BB_Terrain : public BB_DocComponent
{
public:
	BB_Terrain(const QDir& path, const QString &fileName, const QString &name = QString(""));

    virtual ~BB_Terrain();
	virtual void generateXElement(QTextStream &out, int depth);
	
	/** @see virtual bool BB_FileObject::write(QTextStream &out) */
	virtual bool write(QTextStream &out);
	virtual int keyBoardEdit(QWidget* parent);
    virtual bool open();
    virtual const QString getClassName();
	
private:
	static const QString s_ClassName;

};

#endif
