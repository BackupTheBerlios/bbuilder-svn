//
// C++ Implementation: bb_abstracttoolwidget
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <bb_abstracttoolwidget.h>
#include <bb_abstracttool.h>

/**
 * Kontrucktor
 * @param parentTool Das Tool, wessen Fenster dies hier ist.
 * @param parent Fenster in welchem dieses Fenster dargestellt wird.
 * @author Alex Letkemann
 */
BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget *parent )
        : QWidget( parent )
{
	if( parentTool == NULL )
	{
		qDebug( "ERROR: BB_AbstractToolWidget::BB_AbstractToolWidget( NULL, .. ): Null-Pointer erhalten." );
		exit(1);
	}
	m_Selection = NULL;
	m_ParentTool = parentTool;
}

/**
 * Destruktor
 * @author Alex Letkemann
 */
BB_AbstractToolWidget::~BB_AbstractToolWidget()
{}




/**
 * Aktualisiert das Fenster
 * @author Alex Letkemann
 */
void BB_AbstractToolWidget::updateWidget()
{
	/* Hier keine Implemetirung */
}


/**
 * Setzt den Selektionsvektor
 * @param vector Selektionsvektor
 * @author Alex Letkemann
 */
void BB_AbstractToolWidget::setSelection( QVector< BB_DrawObject* >* vector )
{
	if( vector != NULL )
	{
		m_Selection = vector;
		setWidgetEnabled( true );
		updateWidget();
	}
	else
	{
		setWidgetEnabled( false );
		qDebug( "Selektions-Vektor wurde nicht gesetzt: NULL-Pointer erhalten" );
	}
}


/**
 * Leert das Fnester, bzw setzt die Default-Werte.
 * @author Alex Letkemann
 */
void BB_AbstractToolWidget::clearToolWidget()
{
	/* Hier keine Implemetirung */
}


/**
 * Aktiviert oder Deaktiviert das Fenster.
 * @param value True Akviert, False Deaktiviert
 * @author Alex Letkemann
 */
void BB_AbstractToolWidget::setWidgetEnabled( bool value )
{
	/* Hier keine Implemetirung */
}
