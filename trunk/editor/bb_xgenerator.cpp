//
// C++ Implementation: bb_xgenerator
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xgenerator.h"

/** Konstrucktor */
BB_XGenerator::BB_XGenerator()
{
}


/** Destrucktor */
BB_XGenerator::~BB_XGenerator()
{
}




/**
 * Ersetzt alle Zeichen, die in einem XML-Attribut nicht vorkommen dürfen, durch Referenzen.
 * Es wird ein neuer String erzeugt, der übergebene String dient als Datenquelle.
 * @param str String mit zu ersetzenden Zeichen
 * @return Neuer String mit ersetzten Zeichen
 * @author Alex Letkemann
 * @date 19.05.2005
 */
QString BB_XGenerator::escapedAttribute(const QString &str)
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
 * @date 19.05.2005
 */
QString BB_XGenerator::escapedText(const QString &str)
{
	QString result = str;
	result.replace("&", "&amp;");
	result.replace("<", "&lt;");
	result.replace(">", "&gt;");
	return result;
}


/**
 * Erzeugt einen String der Länge 'depth * 4' gefüllt mit Leerzeichen, und gibt diesen zurück.
 * @param depth Anzahl der Leerzeichen
 * @return String mit 'depth' Leerzeiche
 * @author Alex Letkemann
 * @date 19.05.2005
 */
QString BB_XGenerator::indent(int depth)
{
	const int IndentSize = 4;
	return QString(IndentSize * depth, ' ');
}


/**
 * Schreibt die XML-Daten auf das übergebene QIODevice.
 * @param device Das QIODevice, auf welches geschrieben werden soll.
 * @return False im Fehlerfall sonst True
 */
bool BB_XGenerator::write(QIODevice *device)
{
	return true;
}
