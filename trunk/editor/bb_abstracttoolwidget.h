//
// C++ Interface: bb_abstracttoolwidget
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_ABSTRACTTOOLWIDGET_H
#define BB_ABSTRACTTOOLWIDGET_H

#include <QWidget>
#include <bb_drawobject.h>

class BB_AbstractTool;

/**
 * Basisklasse für alle Tool-Fenster.<br>
 * Enthält alle Methoden, die ein Eingenschaftsfenser haben muss.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_AbstractToolWidget : public QWidget
{
        Q_OBJECT
    public:
		
        /**
         * Kontrucktor
         * @param parentTool Das Tool, wessen Fenster dies hier ist.
         * @param parent Fenster in welchem dieses Fenster dargestellt wird.
		 * @author Alex Letkemann
         */
        BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget *parent = 0 );

        /**
         * Destruktor
		 * @author Alex Letkemann
         */
        virtual ~BB_AbstractToolWidget();

        /**
         * Aktualisiert das Fenster
		 * @author Alex Letkemann
         */
        virtual void updateWidget();
        
		/**
		 * Setzt den Selektionsvektor
		 * @param vector Selektionsvektor
		 * @author Alex Letkemann
		 */
		virtual void setSelection( QVector< BB_DrawObject* >* vector );
		
        /**
         * Leert das Fnester, bzw setzt die Default-Werte.
		 * @author Alex Letkemann
         */
        virtual void clearToolWidget();
		
		
        /**
         * Aktiviert oder Deaktiviert das Fenster.
         * @param value True Akviert, False Deaktiviert
		 * @author Alex Letkemann
         */
        virtual void setWidgetEnabled( bool value );

        
    protected:
		/** Tool */
        BB_AbstractTool *m_ParentTool;
        
		/** Hilfsvariable */
		BB_DrawObject* m_Tmp_DrawObject;
		
		/** Selektionsvektor */
		QVector< BB_DrawObject* >* m_Selection;
};

#endif
