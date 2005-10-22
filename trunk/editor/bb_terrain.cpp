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
#include "bb_xgenerator.h"

BB_Terrain::BB_Terrain()
	: BB_FileObject(QDir("sdf"),QString("sdfs"))	/// @todo
{
	//TODO nur test ...
	m_FileName = "test";
}


BB_Terrain::~BB_Terrain()
{
}




/*!
    \fn BB_Terrain::generateXElement(QIODevice *device, int depth)
 */
QString BB_Terrain::generateXElement(QTextStream &stream, int depth)
{
	stream << BB_XGenerator::indent(depth) << "<bb_terrain>\n";
	stream << BB_XGenerator::indent(depth + 1) << m_FileName << "\n";
	stream << BB_XGenerator::indent(depth) << "</bb_terrain>\n";
	return QString("");
}


/*!
    \fn BB_Terrain::write(QIODevice *device)
 */
bool BB_Terrain::write(QIODevice *device)
{
    /// @todo implement me
}
