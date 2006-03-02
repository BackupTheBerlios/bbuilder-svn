/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann   *
 *   alex@letkemann.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 ***************************************************************************/
#ifndef BB_TOOLZOOM_H
#define BB_TOOLZOOM_H

#include <bb_abstracttool.h>
#include <bb_workarea.h>
#include <bb_widgettoolzoom.h>

/**
 * Vergrößerungs-Werkzeug.
 * Das Werkzeug zoomt das Hintergrundbild der Arbeitsfläche und Scalliert die Positionen aller Objekte auf der Arbeitsfläche.
 * Mit der linken Maustaste wird die Arbeitsfläche um 25% vergrößert.
 * Die mittlere Maustaste setzt die Arbeitsfläche zurück auf die Originalgröße.
 * Mir der rechten Maustaste wird die Arbeitsfläche um 25% verkleinert.
 * @author Alex Letkemann
 */
class BB_ToolZoom : public BB_AbstractTool
{
public:
	
	
	/**
	 * Konstruktor. Erzeugt ein neues Zoomwerkzeug für die angegebene Arbeitsfläche. 
     * @param area Arbeitsfläche, mit der geareitet Wird.
	 * @param paret Parent-Fenster
	 * @author Alex Letkemann
	 */
	BB_ToolZoom(BB_WorkArea* area, QWidget* paret);

	/**
	 * Destruktor
	 */
    ~BB_ToolZoom();

	/**
	 * Mit der linken Maustaste wird die Arbeitsfläche um 25% vergrößert.
	 * Die mittlere Maustaste setzt die Arbeitsfläche zurück auf die Originalgröße.
	 * Mir der rechten Maustaste wird die Arbeitsfläche um 25% verkleinert.
	 */
    virtual void click(QMouseEvent* me);
    
	/**
	 * @fn BB_AbstractTool::( BB_DocComponent* component )
	 * Setzt zusätzlich den Zoomfaktor der Arbeitsfläche.
	 * @author Alex Letkemann
	 */
	virtual void setDocComponent( BB_DocComponent* component );
    
	/**
	 * @fn BB_AbstractTool::getToolWidget() 
	 */
	virtual BB_AbstractToolWidget* getToolWidget();

protected:
	
	/* Arbeitsfläche */
    BB_WorkArea* m_WorkArea;
};

#endif
