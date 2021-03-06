//
// C++ Implementation: bb_widgettoolselect
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolselect.h"
#include <bb_toolmove.h>

/**
 * Konstruktor
 */
BB_WidgetToolSelect::BB_WidgetToolSelect( BB_ToolMove* parentTool )
        : BB_AbstractToolWidget(parentTool)
{

    m_Selection = NULL;

    m_Ui.setupUi( this );

	m_Ui.lineEdit_ObjectName->setText( "" );
	m_Ui.lineEdit_ObjectName->setEnabled( false );

	m_Ui.textEdit_ObjectDesc->setPlainText( "" );
	m_Ui.textEdit_ObjectDesc->setEnabled( false );
	
    connect( m_Ui.lineEdit_ObjectName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
	connect( m_Ui.textEdit_ObjectDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );
	connect( m_Ui.button_Delete, SIGNAL( released() ), this, SLOT( slotDeleteSelection() ) );
	connect( m_Ui.button_SelectAll, SIGNAL( released() ), this, SLOT( slotSelectAll() ) );
}


/**
 * Destruktor
 */
BB_WidgetToolSelect::~BB_WidgetToolSelect()
{}




/**
 * Wird aufgerufen, wenn das Bearbeiten des Namen beendet wurde.
 */
void BB_WidgetToolSelect::slotNameFinished()
{
	if( m_Selection != NULL && m_Selection->count() == 1  )
	{
		m_Selection->at(0)->setName( m_Ui.lineEdit_ObjectName->text() );
	}
}


/**
 * Wird aufgerufen, wenn das Bearbeiten der Beschreibung beendet wurde.
 */
void BB_WidgetToolSelect::slotDescFinished()
{
	if( m_Selection != NULL && m_Selection->count() == 1 )
	{
		m_Selection->at(0)->setDescription( m_Ui.textEdit_ObjectDesc->toPlainText() );
	}
}



/**
 * Aktualisiert das Fenster.
 */
void BB_WidgetToolSelect::updateWidget()
{
    if ( m_Selection != NULL )
    {
        m_Ui.label_ObjectsCount->setText( QString::number( m_Selection->count() ) );

        if ( m_Selection->count() != 1 )
        {
            m_Ui.lineEdit_ObjectName->setText( "" );
            m_Ui.lineEdit_ObjectName->setEnabled( false );

            m_Ui.textEdit_ObjectDesc->setPlainText( "" );
            m_Ui.textEdit_ObjectDesc->setEnabled( false );
        }
        else
        {
            m_Ui.lineEdit_ObjectName->setText( m_Selection->at( 0 ) ->getName() );
            m_Ui.lineEdit_ObjectName->setEnabled( true );

            m_Ui.textEdit_ObjectDesc->setPlainText( m_Selection->at( 0 ) ->getDescription() );
            m_Ui.textEdit_ObjectDesc->setEnabled( true );
        }
    }
}

/**
 * Wird aufgerufen, wenn die Taste 'Löschen' betätigt wurde.
 * Löscht alle selectierten Objekte
 */
void BB_WidgetToolSelect::slotDeleteSelection()
{
	m_ParentTool->deleteSelection();
	updateWidget();
}


/**
 * Selektiert alle Objekte auf der Arbeisfläche.
 * @author Alex Letkemann
 */
void BB_WidgetToolSelect::slotSelectAll()
{
	((BB_ToolMove*)(m_ParentTool))->selectAll();
	updateWidget();
}
