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

BB_WidgetToolScale::BB_WidgetToolScale( BB_AbstractTool* parentTool, QWidget* parent )
        : BB_AbstractToolWidget(parentTool, parent)
{
    m_Ui.setupUi( this );
    m_Ui.real->setValidator( BB::validNumeric );

    m_RealScale = NULL;
	
	
	connect(m_Ui.real, SIGNAL(editingFinished()), this, SLOT(slotRealFinished()));
}


BB_WidgetToolScale::~BB_WidgetToolScale()
{}


/**
 * Setzt den logischen Maß
 */
void BB_WidgetToolScale::setLogicalScale( double value )
{
    m_Ui.logical->setText( QString::number( value ) );
}


/**
 * Setzt den Pointer auf den Reelen Maß
 * @param real Pointer auf den Reelen Maß
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
 * Wird aufgeruffen, wenn im 'real'-LineEdit die Taste 'Enter' gedrückt wird 
 * oder das LineEdit den Fokus verliert.
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

