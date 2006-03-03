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
#ifndef BB_WORKFRAME_H
#define BB_WORKFRAME_H

#include <QtGui>
#include "bb_abstracttool.h"
#include "bb_drawobject.h"
#include "bb_transformer.h"
#include "bb_tab.h"

/**
 * Die Arbeitsfläche. In diesem Fenster wird der Hintergrund und alle Objekte gezeichnet.
 * Die Arbeitsfläche kenn einen Selektionsvektor, der die Objekte (z.B. Selektionsmaske) der Tools enthält.
 * Von hier werden auch die ganzen Clicks und die Bewegungen der Maus verarbeitet oder weiter an die Werkzeuge geleitet.
 * Zeichen Reihenfolge:<br>
 * 1. Alle Objekte aus dem DrawObjects-Vektor, die KEINE Punkte sind<br>
 * 2. Alle Punkte<br>
 * 3. Die ToolObjekte<br>
 * Jedes Objekt, das Gezeichnet wird, liegt oberhalb der bereits gezeichneten Objekte.
 * @author Alex Letkemann
 */
class BB_WorkFrame : public QLabel
{
    public:
        /**
         * Konstruktor. Erzeugt eine neue Arbeitsfläche.
         * @param selectVector Selektionsvektor, der verwendet werden soll.
         * @param parent Fenster, in dem dieses Fenster plaziert wird.
         * @param f Qt-Window-Flags
		 * @author Alex Letkemann
         */
        BB_WorkFrame( QVector<BB_DrawObject*>* selectVector, QWidget * parent = 0, Qt::WFlags f = 0 );

		/**
		 * Destruktor
		 */
        ~BB_WorkFrame();
		
		/**
		 * Setzt den Zoomfaktor
		 * @param faktor Zoomfaktor
		 * @author Alex Letkemann
		 */
        void setZoomFaktor( double faktor );

		/**
		 * Gibt das aktuelle Werkzeug zurück, welches zur Zeit verwendet wird.
		 * @return Aktuelles Werkzeug
		 * @author Alex Letkemann
		 */
        BB_AbstractTool* getTool();
		
		
        /**
         * Setzt das Werkzeug, welches verwendet werden soll.
		 * @param tool Werkzeug, welches verwendet werden soll
		 * @author Alex Letkemann
         */
        void setTool( BB_AbstractTool* tool );

        /**
         * Setzt das Dokument-Kompenent, welches bearbeitet werden soll.
		 * @param theValue Dokument-Kompenent, welches bearbeitet werden soll
		 * @author Alex Letkemann
         */
        void setDocComponent( BB_DocComponent* theValue );

        /**
         * Gibt das Dokument-Kompenent zurück, welche zur Zeit bearbeitet wird.
		 * @return Dokument-Kompenent, welche zur Zeit bearbeitet wird.
         */
        BB_DocComponent* getDocComponent() const;

		/**
		 * Wird aufgerufen, wenn das Dokument-Kompenent geändert wird.
		 * Aktualisiert die Arbeitsfläche.
		 * @author Alex Letkemann
		 */
		virtual void documentChanged();


    protected:
		
        /**
         * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
		 * Leitet den Event an das eingestellte Werkzeug.
         * @param me QMouseEvent
		 * @author Alex Letkemann
         */
        virtual void mousePressEvent ( QMouseEvent * me );
		
		
        /**
		 * Wird aufgerufen, wenn eine Maustaste losgelassen wird.
		 * Leitet den Event an das eingestellte Werkzeug.
		 * @param me QMouseEvent
		 * @author Alex Letkemann
		 */
        virtual void mouseReleaseEvent ( QMouseEvent* me );
		
		/**
		 * Zeichnet den Hintergrund und alle Objekte (Wenn die Arbeitsfläche aktiviert ist).
         * Zeichen Reihenfolge:
		 * 1. Alle Objekte aus dem DrawObjects-Vektor, die KEINE Punkte sind
		 * 2. Alle Punkte
		 * 3. Die ToolObjekte
		 * Jedes Objekt, das Gezeichnet wird, liegt oberhalb der bereits gezeichneten Objekte.
		 * @author Alex Letkemann
		 * @date 12.12.2005
		 */
        virtual void paintEvent ( QPaintEvent * pe );
		
        /**
         * Wird aufgerufen, wen die Maus mit gedrückter Maustaste bewegt wird.
		 * Leitet den Event an das eingestellte Werkzeug
		 * @param me QMouseEvent
		 * @author Alex Letkemann
         */
        virtual void mouseMoveEvent ( QMouseEvent* me );
		
        /**
		 * Zeichnet einen blauen Kreutz am logischen Koordinatenursprung
		 * @param painter Painter, mit dem gezeichnet wird
		 * @author Alex Letkemann
		 * @date 13.09.2005
		 */
        void drawCenter( QPainter &painter );
        
    protected:
		/** Werkzeug, welches eingestellt ist */
        BB_AbstractTool* m_Tool;
		
		/** Selektionsvektor, mit dem gearbeitet wird */
        QVector<BB_DrawObject*>* m_Selection;
		
		/** Transformer, der die Umrechnungen durchführt */
		BB_Transformer m_Transformer;
		
        /** Hilfsobjekte, die von den Tools erzeugt werden und gezeichnet werden müssen. */
        QVector<BB_DrawObject*> m_ToolObjects;
		
        /** Kompenent, mit welchem gearbeitet wird */
        BB_DocComponent* m_Component;
        
		/** Objekt-Vektor enthält alle Objekte des Dokument-Kompenentes, die gezeichnet werden. */
		QVector<BB_DrawObject*>* m_DrawObjects;
};

#endif
