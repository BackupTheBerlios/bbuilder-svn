//
// C++ Implementation: bb_doccomponent
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_doccomponent.h"

BB_DocComponent::BB_DocComponent(const QDir& path, const QString &fileName, const QString &name)
 : BB_FileObject(path,fileName,name), BB_Map(), BB_DrawDevice()
{
}


BB_DocComponent::~BB_DocComponent()
{
}


/**
 * Führt die open() Funktion von BB_FileObject aus und
 * läd zusätztlich die Map Datei des Gebäudes.
 */
bool BB_DocComponent::open()
{
	return (BB_FileObject::open() && loadMap(m_FilePath));
}

