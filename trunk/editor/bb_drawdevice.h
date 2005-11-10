//
// C++ Interface: bb_drawdevice
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DRAWDEVICE_H
#define BB_DRAWDEVICE_H

#include "bb_drawobject.h"

/**
 * @author Alex Letkemann
 */
class BB_DrawDevice{
public:
    BB_DrawDevice();

    virtual ~BB_DrawDevice();
    virtual QVector<BB_DrawObject*>* getDrawObjects();

protected:
    QVector<BB_DrawObject*> m_DrawObjects;
};

#endif
