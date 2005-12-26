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
#ifndef BB_OBJECT_H
#define BB_OBJECT_H

#include <QTextStream>
#include <QString>
#include "bb.h"

/**
@author Alex Letkemann
*/
class BB_Object{
public:
//     BB_Object();
	
	BB_Object(QString name = "");

    virtual ~BB_Object();

	int BB_Object::getObjectNr() const;

	void BB_Object::setName(const QString& theValue);
	QString& BB_Object::getName();
	
	void BB_Object::setDescription(const QString& theValue);
	QString& BB_Object::getDescription();
	
	virtual void generateXElement(QTextStream &out, int depth);	
    virtual const QString getClassName();


private:
    static int m_Counter;
    int m_ObjectNr;
    QString m_Description;
    QString m_Name;
	bool m_AutoName;
	
	
	
private:
    void createName();
	
	friend class BB_XBuildingHandler;
	friend class BB_XTerrainHandler;
	friend class BB_Doc;

};

#endif
