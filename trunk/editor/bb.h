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

/**
 * BB ist eine rein statische Klassen und enthällt eine Sammlung kleinerer statischer Hilfsfunktionen.
 * @author Alex Letkemann
 * @date 21.10.2005
 */
class BB{
public:
    BB();

    ~BB();
    static QString indent(int depth);
	static QString escapedAttribute(const QString &str);
	static QString escapedText(const QString &str);

};

#endif
