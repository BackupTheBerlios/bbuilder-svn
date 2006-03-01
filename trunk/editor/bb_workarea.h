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
#ifndef BB_WORKAREA_H
#define BB_WORKAREA_H

#include <QScrollArea>
#include "bb_workframe.h"
#include "bb_tab.h"

#include "bb_drawdevice.h"

/**
 * Die Klasse stellt einen Arbeitsbereich, welcher die eigedliche Arbeitsfläche enthält.<br />
 * Die Arbeitsfläche ist mit Scrollbalken versehen und kann somit größer sein als der Arbeitsbereich.<br />
 * Hintergrund der Arbeitsfläche wird zusammen mit dem DocComponent geändert.
 * @author Alex Letkemann
 */
class BB_WorkArea : public QScrollArea
{
        Q_OBJECT
    public:
		
		/**
		 * Konstruktor
		 * Erzeugt einen scrollbaren Arbeitbereich.
		 * @param selectVector Selektions-Vektor
		 * @param parent Eltern-Fenster
		 */
        BB_WorkArea( QVector<BB_DrawObject*>* selectVector, QWidget *parent = 0 );

		/**
		 * Destruktor
		 */
        ~BB_WorkArea();
		
		/**
		 * Zoom um den übergeben Faktor.
		 * @param factor Zoomfaktor, um den gezoomt werden soll.
		 * @author Alex Letkemann
		 */
        void zoom( double faktor );
		
		/**
		 * Gibt das Tool zurück, welches im Workframe verwendet wird.
		 * @return Das Tool, welches im Workframe benutzt wird.
		 * @author Alex Letkemann
		 */
        BB_AbstractTool* getTool();
		
		/**
		 * Setzt das Tool des Workframes auf <i>tool</i>.
		 * @param tool Tool, welches im Workframe benutzt werden soll.
		 * @author Alex Letkemann
		 */
        void setTool( BB_AbstractTool* tool );
		
		/**
		 * Setzt den Zoom auf den übergebenen Zoomfaktor
		 * @param zoom Zoomfaktor
		 * @author Alex Letkemann
		 */
        void setZoomFaktor( double zoom );
        
		/**
		 * Gibt das Komponent zurück, welches gerade bearbeitet wird.
		 * Falls kein Komponent eingestellt ist wird NULL zurückgegeben
		 * @return Das aktuelle DocComponent
		 * @author Alex Letkemann
		 */
		BB_DocComponent* getDocComponent();
		
		/**
		 * Setzt das DocComponent, welches bearbeitet werden soll.
		 * Falls NULL übergeben wird, wird der Arbeitbereich deaktiviert.
		 * @param component DocComponent, welches bearbeitet werden soll.
		 * @author Alex Letkemann
		 */
        void setDocComponent( BB_DocComponent* component );
		
		/**
		 * Gibt den Zoomfaktor zurück
		 * @return Zoomfaktor
		 * @author Alex Letkemann
		 */
    	double getZoom();
    protected:
		
		/** Arbeitfläche */
        BB_WorkFrame *m_WorkFrame;
		
		/** Hintergrund der Arbeitsfläche */
        BB_Map* m_Map;
};

#endif
