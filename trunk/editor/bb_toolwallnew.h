//
// C++ Interface: bb_toolwallnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLWALLNEW_H
#define BB_TOOLWALLNEW_H

#include <bb_toollinenew.h>

/**
 * Werkzeug zur Erstellung von Wänden.
 * Eine Wand wird durch Verbinden von zwei Knotenpunkten erstellt.
 * Dazu muss der erste Punkt angeclickt werden und mit gedrückter Maustaste 
 * bis zum zweiten Punkt gezogen werden. Befindet sich der Mauszeiger über dem zweiten Knotenpunkt, 
 * kann die Maustaste losgelassen werden und zwischen den beiden Knotenpunkten wird eine Wand ersellt.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolWallNew : public BB_ToolLineNew
{
public:
    /**
     * Konstruktor. Erstellt ein neues Wand-Werkzeug.
     * @param parent Parent-Fenster
     * @author Alex Letkemann
     */
    BB_ToolWallNew(QWidget* parent = 0);

	/**
	 * Destructor
	 */
    ~BB_ToolWallNew();

	/**
	 * @fn BB_AbstractTool::getToolWidget()
	 */
    virtual BB_AbstractToolWidget* getToolWidget();

protected:
    /**
     * Erstellt eine Wand zwischen den beiden angegebenen Punkten und gibt diese zurück.
     * @param p1 Punkt 1
     * @param p2 Punkt 2
     * @return Neue Wand
     */
    virtual BB_Line* createNewLine(BB_Point* p1, BB_Point* p2);
	
	
    /**
     * Sucht und gibt die zuerst gefundene Wand an der angegebenen Position zurück.
	 * Falls keine Wand an der angegebenen Position existiert, wird NULL zurückgegeben.
     * @param pos Position, an der gescuht werden soll.
     * @return Wand oder NULL
     */
    virtual BB_Line* getClickedLine(C2dVector& pos);

};

#endif
