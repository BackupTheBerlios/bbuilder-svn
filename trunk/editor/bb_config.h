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
#ifndef BB_CONFIG_H
#define BB_CONFIG_H

#include <QtGui>
#include <QtXml>

/**
@author Alex Letkemann
*/
class BB_Config{
public:
    BB_Config();

    ~BB_Config();

	void setCurrentProjectPath(const QString& path);
	

	QString getCurrentProjectPath() const;
    bool save();
    bool open();
	

protected:
    QString m_CurrentProjectPath;
};

#endif
