//
// C++ Interface: bb_xterrainhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XTERRAINHANDLER_H
#define BB_XTERRAINHANDLER_H

#include <bb_xhandler.h>

#include "bb_drawobject.h"


class BB_Terrain;

/**
SAX-XML-Handler für BB_Terrain

@author Alex Letkemann
*/
class BB_XTerrainHandler : public BB_XHandler
{
public:
	BB_XTerrainHandler( BB_Terrain * terrain );

    ~BB_XTerrainHandler();
    virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);
    virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);

protected:
    BB_DrawObject* m_Object;
    BB_Terrain* m_Terrain;
    
	bool m_XTerrainTag;
	bool m_XScale;
};

#endif
