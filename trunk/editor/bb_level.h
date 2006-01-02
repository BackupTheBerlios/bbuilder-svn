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
#ifndef BB_LEVEL_H
#define BB_LEVEL_H

#include "bb_doccomponent.h"

class BB_Building;

/**
@author Alex Letkemann
*/
class BB_Level : public BB_DocComponent
{
    public:
        BB_Level( BB_Building* building, const QDir& path, const QString &fileName, const QString &name = QString( "" ) );

        virtual ~BB_Level();
        virtual void generateXElement( QTextStream &out, int depth );
        virtual bool write( QTextStream &out );
        virtual const QString getClassName();
		void setHeight( double Value );
		double getHeight() const;
    protected:
		/**
		Hohe von Etage in meter
		*/
		double m_height;
};

#endif
