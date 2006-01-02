//
// C++ Implementation: bb_widgettoollinenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoollinenew.h"

#include <bb_point.h>
#include <bb_line.h>

BB_WidgetToolLineNew::BB_WidgetToolLineNew( BB_AbstractTool* parentTool , QWidget *parent )
        : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );

    connect( m_Ui.lineEdit_LineName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_LineDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );

    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );

    setWidgetEnabled( false );

}


BB_WidgetToolLineNew::~BB_WidgetToolLineNew()
{}


void BB_WidgetToolLineNew::slotNameFinished()
{
	if ( m_Selection != NULL && m_Selection->count() == 1 )
	{
		m_Tmp_DrawObject = m_Selection->at( 0 );
		m_Tmp_DrawObject->setName( m_Ui.lineEdit_LineName->text() );
	}
}

void BB_WidgetToolLineNew::slotDescFinished()
{
	if ( m_Selection != NULL && m_Selection->count() == 1 )
	{
		m_Tmp_DrawObject = m_Selection->at( 0 );
		m_Tmp_DrawObject->setDescription( m_Ui.textEdit_LineDesc->toPlainText() );
	}
}

void BB_WidgetToolLineNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


void BB_WidgetToolLineNew::updateWidget()
{
    BB_Line * tmpLine;

    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_Line ) )
    {
        tmpLine = ( BB_Line* ) m_Selection->at( 0 );

        m_Ui.lineEdit_LineName->setText( tmpLine->getName() );
        m_Ui.textEdit_LineDesc->setPlainText( tmpLine->getDescription() );

        m_Tmp_DrawObject = tmpLine->getPos1();
        if ( m_Tmp_DrawObject != NULL )
        {
            m_Ui.label_Pos1->setText( m_Tmp_DrawObject->getName() + " (" + QString::number( m_Tmp_DrawObject->getObjectNr() ) + ")" );
        }

        m_Tmp_DrawObject = tmpLine->getPos2();
        if ( m_Tmp_DrawObject != NULL )
        {
            m_Ui.label_Pos2->setText( m_Tmp_DrawObject->getName() + " (" + QString::number( m_Tmp_DrawObject->getObjectNr() ) + ")" );
        }

        setWidgetEnabled( true );
    }
    else
    {
        clearToolWidget();
        setWidgetEnabled( false );
    }

}

void BB_WidgetToolLineNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_LineName->setEnabled( value );
    m_Ui.textEdit_LineDesc->setEnabled( value );

    m_Ui.pushButton_Delete->setEnabled( value );
}

void BB_WidgetToolLineNew::clearToolWidget()
{
    m_Ui.lineEdit_LineName->clear();
    m_Ui.textEdit_LineDesc->clear();
    m_Ui.label_Pos1->clear();
    m_Ui.label_Pos2->clear();
}

