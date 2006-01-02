//
// C++ Implementation: bb
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb.h"


QRegExp BB::regExpAlphanumeric = QRegExp("[A-Za-z][A-Za-z0-9\\s._]+");
QRegExp BB::regExpNumeric = QRegExp("[0-9.]+");


QRegExpValidator* BB::validAlphanumeric = new QRegExpValidator( regExpAlphanumeric, NULL );
QRegExpValidator* BB::validNumeric = new QRegExpValidator( regExpNumeric, NULL );


/** Konstruktor */
BB::BB()
{
}


/** Destruktor */
BB::~BB()
{
}




/**
 * Erzeugt einen String der Länge 'depth * 4' gefüllt mit Leerzeichen, und gibt diesen zurück.
 * @param depth Anzahl der Leerzeichen
 * @return String mit 'depth' Leerzeiche
 * @author Alex Letkemann
 */
QString BB::indent(int depth)
{
	const int IndentSize = 4;
	return QString(IndentSize * depth, ' ');
}


/**
 * Ersetzt alle Zeichen, die in einem XML-Attribut nicht vorkommen dürfen, durch Referenzen.
 * Es wird ein neuer String erzeugt, der übergebene String dient als Datenquelle.
 * @param str String mit zu ersetzenden Zeichen
 * @return Neuer String mit ersetzten Zeichen
 * @author Alex Letkemann
 */
QString BB::escapedAttribute(const QString &str)
{
	QString result = escapedText(str);
	result.replace("\"", "&quot;");
	result.prepend("\"");
	result.append("\"");
	return result; 
}


/**
 * Ersetzt alle Zeichen, die in einem XML-Text nicht vorkommen dürfen, durch Referenzen.
 * Es wird ein neuer String erzeugt, der übergebene String dient als Datenquelle.
 * @param str String mit zu ersetzenden Zeichen
 * @return Neuer String mit ersetzten Zeichen
 * @author Alex Letkemann
 */
QString BB::escapedText(const QString &str)
{
	QString result = str;
	result.replace("&", "&amp;");
	result.replace("<", "&lt;");
	result.replace(">", "&gt;");
	result.replace(QString::fromUtf8("Ä"), "&Auml;");
	result.replace(QString::fromUtf8("Ö"), "&Ouml;");
	result.replace(QString::fromUtf8("Ü"), "&Uuml;");
	result.replace(QString::fromUtf8("ä"), "&auml;");
	result.replace(QString::fromUtf8("ö"), "&ouml;");
	result.replace(QString::fromUtf8("ü"), "&uuml;");
	result.replace(QString::fromUtf8("ß"), "&szlig;");
	return result;
}

