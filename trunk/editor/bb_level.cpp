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
***************************************************************************/
#include "bb_level.h"
#include "bb_building.h"


BB_Level::BB_Level( BB_Building* building, const QDir& path, const QString &fileName, const QString &name )
        : BB_DocComponent( path, fileName, name )
{
	if( building == NULL )
	{
		qDebug( "BB_Level kann nicht ohne building initialisiert werden." );
		exit(1);
	}
	
	m_Building = building;
	m_Building->addLevel(this);
	
    //Standart Hoehe
	m_height = 3.0;
}


BB_Level::~BB_Level()
{
	m_Building->removeLevel(this);
}




/*!
    \fn BB_Level::generateXElement(QTextStream &out, int depth)
 */
void BB_Level::generateXElement( QTextStream &out, int depth )
{
    out << BB::indent( depth ) << "<bb_level>" << BB::escapedText( getFileName() ) << "</bb_level>\n";
}


/*!
    \fn BB_Level::write(QTextStream &out)
 */
bool BB_Level::write( QTextStream &out )
{
    /// @todo implement me
    return false;
}


/*!
    \fn BB_Object::getClassName()
 */
const QString BB_Level::getClassName()
{
    return QString( "BB_Level" );
}


double BB_Level::getHeight() const
{
    return m_height;
}

void BB_Level::setHeight( double Value )
{
    m_height = Value;
}


/*!
    \fn BB_Level::getBuilding()
 */
BB_Building* BB_Level::getBuilding()
{
	return m_Building;
}
