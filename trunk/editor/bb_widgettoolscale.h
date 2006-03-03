//
// C++ Interface: bb_widgettoolscale
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLSCALE_H
#define BB_WIDGETTOOLSCALE_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetScale.h>

/**
 * Tool-Fenster für das ToolScale.
 * Das Fenster ermöglich es den reelen Maßstab einzugeben.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolScale : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:

		/**
		 * Konstruktor. Erstellt ein neues Werkzeugfenster für das Maßstab-Werkzeug.
		 * @param parentTool Maßstab-Werkzeug
		 * @param parent Parent-Wenster, in dem dieses Fenster plaziert wird.
		 * @author Alex Letkemann
		 */
		BB_WidgetToolScale( BB_AbstractTool* parentTool, QWidget* parent = 0  );

		/**
		 * Destruktor
		 */
        ~BB_WidgetToolScale();
		
		/**
		 * Setzt den logischen Maßstab.
		 * @param value Logischer Maßstab.
		 */
        void setLogicalScale( double value );
		
		/**
		 * Setzt den Pointer auf den reelen Maßstab.
		 * @param real Pointer auf den reelen Maßstab.
		 * @author Alex Letkemann
		 */
        void setRealScale( double *real );


    protected:
		/** Form */
        Ui::WidgetToolScale m_Ui;
		
		/** Pointer auf den reelen Maßstab */
        double* m_RealScale;
		
    private slots:
		
        /**
         * Wird aufgerufen, wenn das Bearbeiten des reelen Maßstabes beendet wurde.
		 * Ändert den reelen Maßstab des DocComponentes.
		 * @author Alex Letkemann
         */
        void slotRealFinished();
};

#endif
