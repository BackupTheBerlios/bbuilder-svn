//
// C++ Interface: bb_xhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XHANDLER_H
#define BB_XHANDLER_H

#include <QXmlDefaultHandler>

/**
@author Alex Letkemann
*/
class BB_XHandler : public QXmlDefaultHandler
{
public:
    BB_XHandler();

    ~BB_XHandler();

	virtual bool characters(const QString& ch);
	virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName) = 0;
	virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts) = 0;
    virtual bool fatalError(const QXmlParseException& exception);

protected:
    QString m_CurrentText;
	QString m_ErrorStr;
};

#endif
