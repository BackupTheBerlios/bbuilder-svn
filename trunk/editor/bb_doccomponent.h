//
// C++ Interface: bb_doccomponent
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DOCCOMPONENT_H
#define BB_DOCCOMPONENT_H

#include <bb_fileobject.h>
#include <bb_map.h>
#include <bb_drawdevice.h>

/**
@author Alex Letkemann
*/
class BB_DocComponent : public BB_FileObject, public BB_Map, public BB_DrawDevice
{
public:
	BB_DocComponent(const QDir& path, const QString &fileName, const QString &name);

    ~BB_DocComponent();

};

#endif
