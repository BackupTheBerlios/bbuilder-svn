//
// C++ Implementation: bb_widgettoolscale
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolscale.h"
#include <bb.h>
#include <QMessageBox>


/**
 * Konstruktor. Erstellt ein neues Werkzeugfenster für das Maßstab-Werkzeug.
 * @param parentTool Maßstab-Werkzeug
 * @param parent Parent-Wenster, in dem dieses Fenster plaziert wird.
 * @author Alex Letkemann
 */
BB_WidgetToolScale::BB_WidgetToolScale( BB_AbstractTool* parentTool, QWidget* parent )
        : BB_AbstractToolWidget(parentTool, parent)
{
    m_Ui.setupUi( this );
    m_Ui.real->setValidator( BB::validNumeric );

    m_RealScale = NULL;
	
	
	connect(m_Ui.real, SIGNAL(editingFinished()), this, SLOT(slotRealFinished()));
}

/**
 * Desruktor
 */
BB_WidgetToolScale::~BB_WidgetToolScale()
{}


/**
 * Setzt den logischen Maßstab.
 * @param value Logischer Maßstab.
 */
void BB_WidgetToolScale::setLogicalScale( double value )
{
    m_Ui.logical->setText( QString::number( value ) );
}


/**
 * Setzt den Pointer auf den reelen Maßstab.
 * @param real Pointer auf den reelen Maßstab.
 * @author Alex Letkemann
 */
void BB_WidgetToolScale::setRealScale( double *real )
{
    if ( real != NULL )
    {
        m_RealScale = real;
        m_Ui.real->setText( QString::number( *real ) );
    }
}


/**
 * Wird aufgerufen, wenn das Bearbeiten des reelen Maßstabes beendet wurde.
 * Ändert den reelen Maßstab des DocComponentes.
 * @author Alex Letkemann
 */
void BB_WidgetToolScale::slotRealFinished()
{
	if ( m_RealScale != NULL )
	{
		bool ok;
		double tmp;

		tmp = QString( m_Ui.real->text() ).toDouble( &ok );

		if ( ok )
		{
			*m_RealScale = tmp;
		}
		else
		{
			m_Ui.real->setText( QString::number( *m_RealScale ) );
			QMessageBox::critical(this,
								  "Fehler",
								  QString::fromUtf8("Fehler bei der Eingabe.\nBitte überprüfen Sie ihre Eingabe"));
			
			
		}
	}
}

