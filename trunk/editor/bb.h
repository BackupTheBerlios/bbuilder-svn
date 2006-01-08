//
// C++ Interface: bb
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_H
#define BB_H

#include <QString>
#include <QRegExp>
#include <QRegExpValidator>

/**
 * BB ist eine rein statische Klassen und enthällt eine Sammlung kleinerer statischer Hilfsfunktionen.
 * @author Alex Letkemann
 */
class BB
{
    public:
        BB();

        ~BB();
		
		/**
		 * Erzeugt einen String der Länge 'depth * 4' gefüllt mit Leerzeichen, und gibt diesen zurück.
		 * @param depth Anzahl der Leerzeichen
		 * @return String mit 'depth' Leerzeiche
		 * @author Alex Letkemann
		 */
        static QString indent( int depth );
		
		/**
		 * Ersetzt alle Zeichen, die in einem XML-Attribut nicht vorkommen dürfen, durch Referenzen.
		 * Es wird ein neuer String erzeugt, der übergebene String dient als Datenquelle.
		 * @param str String mit zu ersetzenden Zeichen
		 * @return Neuer String mit ersetzten Zeichen
		 * @author Alex Letkemann
		 */
        static QString escapedAttribute( const QString &str );
		
		/**
		 * Ersetzt alle Zeichen, die in einem XML-Text nicht vorkommen dürfen, durch Referenzen.
		 * Es wird ein neuer String erzeugt, der übergebene String dient als Datenquelle.
		 * @param str String mit zu ersetzenden Zeichen
		 * @return Neuer String mit ersetzten Zeichen
		 * @author Alex Letkemann
		 */
        static QString escapedText( const QString &str );
		
		/** Regulärer Ausdruck für alphanummerische Eingaben */
		static QRegExp regExpAlphanumeric;
		
		/** Regulärer Ausdruck für nummerische Eingaben */
		static QRegExp regExpNumeric;
		
		/** Validator für Alphanummerische Eingaben */
        static QRegExpValidator *validAlphanumeric;
		
		/** Validator für Nummerische Eingaben */
		static QRegExpValidator *validNumeric;
	/** compare funktion fuer qsort*/
	int compare (const void * a, const void * b);

};

#endif
