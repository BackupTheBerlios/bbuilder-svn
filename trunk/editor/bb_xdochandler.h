//
// C++ Interface: bb_xdochandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XDOCHANDLER_H
#define BB_XDOCHANDLER_H

#include "bb_xhandler.h"
#include <QDir>

class BB_Doc;

/**
@author Alex Letkemann
*/
class BB_XDocHandler : public BB_XHandler
{
public:
    BB_XDocHandler(BB_Doc* doc);

    ~BB_XDocHandler();

	virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);
	virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);

protected:
    BB_Doc* m_Doc;
    bool m_XDocTag;
    QDir m_Path;
    int m_ObjectId;
	int m_BuidingNr;

};

#endif
