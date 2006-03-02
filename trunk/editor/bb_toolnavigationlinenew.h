//
// C++ Interface: bb_toolnavigationlinenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLNAVIGATIONLINENEW_H
#define BB_TOOLNAVIGATIONLINENEW_H

#include <bb_toollinenew.h>

/**
 * Werkzeug zur Erstellung von Navigationslinien.
 * Eine Navigationslinie wird durch Verbinden von zwei Navagationskonten erstellt.
 * Dazu muss der erste Navigationsknoten angeclickt werden und mit gedrückter Maustaste 
 * bis zum zweiten Navigationsknoten gezogen werden. Befindet sich der Mauszeiger über dem zweiten Navigationsknoten, 
 * kann die Maustaste losgelassen werden und zwischen den beiden Navigationsknoten wird eine Navigationslinie ersellt.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolNavigationLineNew : public BB_ToolLineNew
{
public:
    /**
     * Erstellt ein neues Navigationslinien-Werkzeug
     * @param parent Parent-Fenster
     * @author Alex Letkemann 
     */
    BB_ToolNavigationLineNew(QWidget* parent);

    /**
     * Destruktor
     */
    ~BB_ToolNavigationLineNew();

	
    /**
     * Erstellt eine neue Linie zwischen den beiden, übergebenen Punkten p1 und p2 und gibt diese zurück.
     * @param p1 Punkt 1
     * @param p2 Punkt 2
     * @return Erstellte Navigationslinie.
	 * @author Alex Letkemann
     */
    virtual BB_Line* createNewLine(BB_Point* p1, BB_Point* p2);
	
	
    /**
     * Such und gibt die zuerst gefundene Linie an der übergebenen Position zurück.
	 * Falls keine Linie an der übergebenen Position existiert, wird NULL zurückgegeben.
     * @param pos Position an der gesucht werden soll.
     * @return Linie oder NULL
	 * @author Alex Letkemann
     */
    virtual BB_Line* getClickedLine(C2dVector& pos);
	
    /**
     * Sucht und gibt den zuerst gefundenen Punkt an der übergebenen Position zurück.
	 * Wird kein Punkt an der angegebenen Position gefudnen, so wird NULL zurückgegeben.
     * @param pos Position, an der gesucht werden soll.
     * @return Punkt oder NULL
	 * @author Alex Letkemann
     */
    virtual BB_Point* getClickedPoint(C2dVector& pos);

};

#endif
