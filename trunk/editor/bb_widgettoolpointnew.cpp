//
// C++ Implementation: bb_widgettoolpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <bb_widgettoolpointnew.h>
#include <bb.h>
#include <bb_point.h>
#include <bb_abstracttool.h>

#include <iostream>
using namespace std;


BB_WidgetToolPointNew::BB_WidgetToolPointNew( BB_AbstractTool* parentTool , QWidget *parent )
        : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );

    // 	m_Ui.lineEdit_X->setValidator( BB::validNumeric );
    // 	m_Ui.lineEdit_Y->setValidator( BB::validNumeric );

    connect( m_Ui.lineEdit_X, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );
    connect( m_Ui.lineEdit_Y, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );

    connect( m_Ui.lineEdit_PointName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_PointDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );

    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );

}


BB_WidgetToolPointNew::~BB_WidgetToolPointNew()
{}


/*!
    \fn BB_WidgetToolPointNew::slotPosFinished()
 */
void BB_WidgetToolPointNew::slotPosFinished()
{
    commitPos();
}


/**
 * Speichert die Beschreibung
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::commitDesc()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Point->setDescription( m_Ui.textEdit_PointDesc->toPlainText() );
}


/**
 * Speichert den Namen
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::commitName()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Point->setName( m_Ui.lineEdit_PointName->text() );
}


/**
 * Prüft und speihert die eingegebene Position
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::commitPos()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Vector = m_Tmp_Point->getPos();
    double x, y;
    bool ok;

    x = QString( m_Ui.lineEdit_X->text() ).toDouble( &ok );
    if ( ok )
    {
        m_Tmp_Vector.setX( x );
    }

    y = QString( m_Ui.lineEdit_Y->text() ).toDouble( &ok );
    if ( ok )
    {
        m_Tmp_Vector.setY( y );
    }

    m_Tmp_Point->setPos( m_Tmp_Vector );

    m_ParentTool->documentChanged();
}


/*!
    \fn BB_WidgetToolPointNew::slotDelete()
 */
void BB_WidgetToolPointNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/*!
    \fn BB_WidgetToolPointNew::slotDescFinished()
 */
void BB_WidgetToolPointNew::slotDescFinished()
{
    commitDesc();
}


/*!
    \fn BB_WidgetToolPointNew::slotNameFinished()
 */
void BB_WidgetToolPointNew::slotNameFinished()
{
    commitName();
}


/*!
    \fn BB_AbstractToolWidget::updateWidget()
 */
void BB_WidgetToolPointNew::updateWidget()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_Point = ( ( BB_Point * ) ( m_Selection->at( 0 ) ) );
        m_Tmp_Vector = m_Tmp_Point->getPos();

        m_Ui.lineEdit_X->setText( QString::number( m_Tmp_Vector.x() ) );
        m_Ui.lineEdit_Y->setText( QString::number( m_Tmp_Vector.y() ) );

        m_Ui.lineEdit_PointName->setText( m_Tmp_Point->getName() );
        m_Ui.textEdit_PointDesc->setPlainText( m_Tmp_Point->getDescription() );

        setWidgetEnabled( true );


    }
    else
    {
        clearWidget();
        setWidgetEnabled( false );
    }
}


/*!
    \fn BB_AbstractToolWidget::clearWidget()
 */
void BB_WidgetToolPointNew::clearWidget()
{
    m_Ui.lineEdit_PointName->clear();
    // 	m_Ui.textEdit_PointDesc->clear();

    m_Ui.lineEdit_X->clear();
    m_Ui.lineEdit_Y->clear();
}


/*!
    \fn BB_AbstractToolWidget::setWidgetEnabled( bool value )
 */
void BB_WidgetToolPointNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_X->setEnabled( value );
    m_Ui.lineEdit_Y->setEnabled( value );
    m_Ui.lineEdit_PointName->setEnabled( value );
    m_Ui.textEdit_PointDesc->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}
