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

BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget *parent )
        : QWidget( parent )
{
	if( parentTool == NULL )
	{
		qDebug( "ERROR: BB_AbstractToolWidget::BB_AbstractToolWidget( NULL, .. ): Null-Pointer erhalten." );
		exit(1);
	}
	m_ParentTool = parentTool;
}


BB_AbstractToolWidget::~BB_AbstractToolWidget()
{}




/**
 *   \fn BB_AbstractToolWidget::updateWidget()
 */
void BB_AbstractToolWidget::updateWidget()
{
    /// @todo implement me
}


/*!
    \fn BB_AbstractToolWidget::setSelection( QVector< BB_DrawObject* >* vector )
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


/*!
    \fn BB_AbstractToolWidget::clearToolWidget()
 */
void BB_AbstractToolWidget::clearToolWidget()
{
    /// @todo implement me
}


/*!
    \fn BB_AbstractToolWidget::setWidgetEnabled( bool value )
 */
void BB_AbstractToolWidget::setWidgetEnabled( bool value )
{
    /// @todo implement me
}
