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
#include "bb_terrain.h"

const QString BB_Terrain::s_ClassName = "BB_Terrain";

BB_Terrain::BB_Terrain(const QDir& path, const QString &fileName, const QString &name)
	: BB_FileObject(path, fileName, name)
{

}


BB_Terrain::~BB_Terrain()
{
}




/*!
    \fn BB_Terrain::generateXElement(QIODevice *device, int depth)
 */
void BB_Terrain::generateXElement(QTextStream &out, int depth)
{
	out << BB::indent(depth) << "<bb_terrain>" << BB::escapedText(getFileName()) << "</bb_terrain>\n";
}


/*!
    \fn BB_Terrain::write(QIODevice *device)
 */
bool BB_Terrain::write(QTextStream &out)
{
    /// @todo implement me
	return true;
}
