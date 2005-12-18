//
// C++ Interface: bb_xbuildinghandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XBUILDINGHANDLER_H
#define BB_XBUILDINGHANDLER_H

#include "bb_xhandler.h"
#include "bb_drawobject.h"

#include "bb_point.h"
#include "bb_wall.h"

class BB_Building;

/**
@author Alex Letkemann
*/
class BB_XBuildingHandler : public BB_XHandler
{
public:
    BB_XBuildingHandler(BB_Building* building);

    ~BB_XBuildingHandler();
	
	virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);
	virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);
    

protected:
    BB_Building* m_Building;
	bool m_XBuildingTag;
	bool m_XScale;
	
	BB_DrawObject *m_Object;
	int m_ScalePointIndex;
	
    QVector<BB_DrawObject*>* m_DrawObjects;
};

#endif
