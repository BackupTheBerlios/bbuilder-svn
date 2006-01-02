//
// C++ Implementation: bb_widgettooltrianglenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettooltrianglenew.h"
#include <bb_triangle.h>
#include <bb_abstracttool.h>

BB_WidgetToolTriangleNew::BB_WidgetToolTriangleNew( BB_AbstractTool* parentTool, QWidget* parent ) : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );
}


BB_WidgetToolTriangleNew::~BB_WidgetToolTriangleNew()
{}


void BB_WidgetToolTriangleNew::clearToolWidget()
{
    m_Ui.lineEdit_Name->clear();
    m_Ui.textEdit_Desc->blockSignals( true );
    m_Ui.textEdit_Desc->clear();
    m_Ui.textEdit_Desc->blockSignals( false );
}

void BB_WidgetToolTriangleNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_Name->setEnabled( value );
    m_Ui.textEdit_Desc->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}

void BB_WidgetToolTriangleNew::updateWidget()
{
    if ( m_Selection == NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_Triangle ) )
    {
		BB_Triangle *tmpTriangle = (( BB_Triangle* )( m_Selection->at(0)));
		BB_DrawObject* tmp_DrawObject = NULL;
		
		m_Ui.lineEdit_Name->setText( tmpTriangle->getName() );
		
		m_Ui.textEdit_Desc->blockSignals( true );
		m_Ui.textEdit_Desc->setPlainText( tmpTriangle->getDescription() );
		m_Ui.textEdit_Desc->blockSignals( false );
		
		tmp_DrawObject = tmpTriangle->getPos1();
		if ( tmp_DrawObject != NULL )
		{
			m_Ui.label_Pos1->setText( tmp_DrawObject->getName() + " (" + QString::number( tmp_DrawObject->getObjectNr() ) + ")" );
		}

		tmp_DrawObject = tmpTriangle->getPos2();
		if ( tmp_DrawObject != NULL )
		{
			m_Ui.label_Pos2->setText( tmp_DrawObject->getName() + " (" + QString::number( tmp_DrawObject->getObjectNr() ) + ")" );
		}
		
		tmp_DrawObject = tmpTriangle->getPos3();
		if ( tmp_DrawObject != NULL )
		{
			m_Ui.label_Pos3->setText( tmp_DrawObject->getName() + " (" + QString::number( tmp_DrawObject->getObjectNr() ) + ")" );
		}
		
		setWidgetEnabled(true);
		
	}
	else
	{
		clearToolWidget();
		setWidgetEnabled( false );
	}
}



/*!
    \fn BB_WidgetToolTriangleNew::slotDelete()
 */
void BB_WidgetToolTriangleNew::slotDelete()
{
		m_ParentTool->deleteSelection();
}
