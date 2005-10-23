//
// C++ Implementation: bb_xhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xhandler.h"

BB_XHandler::BB_XHandler()
 : QXmlDefaultHandler()
{
}


BB_XHandler::~BB_XHandler()
{
}


bool BB_XHandler::characters(const QString& ch)
{
	m_CurrentText += ch;
	return true;
}

// bool BB_XHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
// {
//  
// }
// 
// bool BB_XHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
// {
// 
// }



/*!
    \fn BB_XHandler::fatalError(const QXmlParseException& exception)
 */
bool BB_XHandler::fatalError(const QXmlParseException& exception)
{
    /// @todo implement me
}
