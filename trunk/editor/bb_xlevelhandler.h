//
// C++ Interface: bb_xlevelhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XLEVELHANDLER_H
#define BB_XLEVELHANDLER_H

#include <bb_xhandler.h>
#include <bb_level.h>
#include <bb_drawobject.h>
#include <bb_wall.h>
#include <bb_navigationpoint.h>

/**
XML-Handler für das Einlesen von BB_Level-XML-Dateien

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_XLevelHandler : public BB_XHandler
{
public:
    BB_XLevelHandler( BB_Level* level );

    ~BB_XLevelHandler();

    virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);
    virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);

protected:
    BB_Level* m_Level;
    BB_DrawObject* m_Object;
    int m_ScalePointIndex;
    bool m_XLevelTag;
	bool m_XScale;
	QVector<BB_DrawObject*>* m_DrawObjects;
};

#endif
