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
#include "QMessageBox"

#include <iostream>


using namespace std;


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

/**
 * Wird aufgeruffen, wenn während des Parsens ein Fehler auftritt.
 * Dier Fehler wird im std::cout ausgegeben
 */
bool BB_XHandler::fatalError(const QXmlParseException& exception)
{
	
	QString errorString = QObject::tr("Parse error at line %1, column %2:\n%3")
									.arg(exception.lineNumber())
									.arg(exception.columnNumber())
									.arg(exception.message());
	cout << "XML-Fehler: " << errorString.toStdString() << endl;
	return false;
}
