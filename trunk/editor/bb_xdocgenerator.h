//
// C++ Interface: bb_xdocgenerator
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef BB_XDOCGENERATOR_H
#define BB_XDOCGENERATOR_H


#include "bb_xgenerator.h"
#include "bb_doc.h"

/**
@author Alex Letkemann
*/
class BB_XDocGenerator : public BB_XGenerator{
public:
    BB_XDocGenerator(BB_Doc * doc);

    virtual ~BB_XDocGenerator();

protected:
    BB_Doc* m_Doc;
};

#endif
