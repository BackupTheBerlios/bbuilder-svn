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


/**
 * Konstruktor. Erzeugt ein neues Werkzeugfenster für das Punkt-Erstellungs-Werkzeug.
 * @param parentTool Punkt-Erstellungs-Werkzeug.
 * @param parent Parent-Fenster in dem dieses Fenster plaziert wird.
 * @author Alex Letkemann
 */
BB_WidgetToolPointNew::BB_WidgetToolPointNew( BB_AbstractTool* parentTool , QWidget *parent )
        : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );

    connect( m_Ui.lineEdit_X, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );
    connect( m_Ui.lineEdit_Y, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );

    connect( m_Ui.lineEdit_PointName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_PointDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );

    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );
	connect( m_Ui.pushButton_ToLine_H, SIGNAL( released() ), this, SLOT( slotToLine_H() ) );
	connect( m_Ui.pushButton_ToLine_V, SIGNAL( released() ), this, SLOT( slotToLine_V() ) );

}

/**
 * Destruktor 
 */
BB_WidgetToolPointNew::~BB_WidgetToolPointNew()
{}


/**
 * Wird aufgerufen, wenn die Position des Punktes im Fenster geändert wird.
 * Ändert die Position des Punktes.
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::slotPosFinished()
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




/**
 * Löscht die Selektion
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::slotDescFinished()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Point->setDescription( m_Ui.textEdit_PointDesc->toPlainText() );
}


/**
 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
 * Speichert den neuen Namen im Objekt.
 * @author Alex Letkemann 
 */
void BB_WidgetToolPointNew::slotNameFinished()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Point->setName( m_Ui.lineEdit_PointName->text() );
}


/**
 * Aktualisiert das Eigenschaftsfenster
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::updateWidget()
{
	
    if ( m_Selection != NULL &&
            m_Selection->count() >= 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_Point ) )
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
        clearToolWidget();
        setWidgetEnabled( false );
    }
}


/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::clearToolWidget()
{
    m_Ui.lineEdit_PointName->clear();

    m_Ui.lineEdit_X->clear();
    m_Ui.lineEdit_Y->clear();
}


/**
 * Aktiviert oder Deaktiviert das Fenster.<br>
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_WidgetToolPointNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_X->setEnabled( value );
    m_Ui.lineEdit_Y->setEnabled( value );
    m_Ui.lineEdit_PointName->setEnabled( value );
    m_Ui.textEdit_PointDesc->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
	m_Ui.pushButton_ToLine_H->setEnabled( value );
	m_Ui.pushButton_ToLine_V->setEnabled( value );
}

void BB_WidgetToolPointNew::slotToLine_H()
{
    if ( m_Selection != NULL )
    {
        if ( m_Selection->count() > 1 )
        {
            m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
            for ( int i = 1;i < m_Selection->count() ;i++ )
            {
                if ( typeid( *( m_Selection->at( i ) ) ) == typeid( BB_Point ) )
                {
                    ( ( BB_Point * ) m_Selection->at( i ) ) ->bringToLineHorizontal( m_Tmp_Point );
                }
            }
        }
		m_ParentTool->documentChanged();
    }
}

void BB_WidgetToolPointNew::slotToLine_V()
{
	if ( m_Selection != NULL )
	{
		if ( m_Selection->count() > 1 )
		{
			m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
			for ( int i = 1;i < m_Selection->count() ;i++ )
			{
				if ( typeid( *( m_Selection->at( i ) ) ) == typeid( BB_Point ) )
				{
					( ( BB_Point * ) m_Selection->at( i ) ) ->bringToLineVertikal( m_Tmp_Point );
				}
			}
		}
		m_ParentTool->documentChanged();
	}
}
