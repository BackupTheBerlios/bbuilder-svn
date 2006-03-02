//
// C++ Implementation: bb_widgettoolnavigationpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolnavigationpointnew.h"
#include "bb_navigationpoint.h"
#include "bb_abstracttool.h"


/**
 * Konstruktor. Erstellt ein neues Werkzeugfenster für das Navigations-Knoten Werkzeug.
 * @param parentTool Navigations-Knoten Werkzeug
 * @param parent Parent-Fenster, in dem diese Fenster positionier wird.
 */
BB_WidgetToolNavigationPointNew::BB_WidgetToolNavigationPointNew( BB_AbstractTool* parentTool, QWidget* parent ) : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );

    connect( m_Ui.lineEdit_Name, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_Desc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );
    connect( m_Ui.lineEdit_X, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );
    connect( m_Ui.lineEdit_Y, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );
    connect( m_Ui.checkBox_Index, SIGNAL( stateChanged ( int ) ), this, SLOT( slotIndexChanged( int ) ) );
    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );
}


/**
 * Destruktor
 */
BB_WidgetToolNavigationPointNew::~BB_WidgetToolNavigationPointNew()
{}

/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::clearToolWidget()
{

    m_Ui.lineEdit_Name->clear();

    m_Ui.textEdit_Desc->blockSignals( true );
    m_Ui.textEdit_Desc->clear();
    m_Ui.textEdit_Desc->blockSignals( false );

    m_Ui.lineEdit_X->clear();
    m_Ui.lineEdit_Y->clear();

	m_Ui.checkBox_Index->setCheckState( Qt::Unchecked );
}

/**
 * Aktiviert oder Deaktiviert das Fenster.<br />
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_Name->setEnabled( value );
    m_Ui.textEdit_Desc->setEnabled( value );
    m_Ui.lineEdit_X->setEnabled( value );
    m_Ui.lineEdit_Y->setEnabled( value );
    m_Ui.checkBox_Index->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}


/**
 * Aktualisiert das Fenster
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::updateWidget()
{

    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_NavigationPoint ) )
    {
        BB_NavigationPoint * tmpPoint = ( ( BB_NavigationPoint* ) ( m_Selection->at( 0 ) ) );

        m_Ui.lineEdit_Name->setText( tmpPoint->getName() );
        m_Ui.textEdit_Desc->blockSignals( true );
        m_Ui.textEdit_Desc->setPlainText( tmpPoint->getDescription() );
        m_Ui.textEdit_Desc->blockSignals( false );

		m_Ui.lineEdit_X->setText( QString::number(tmpPoint->getPos().x()) );
		m_Ui.lineEdit_Y->setText( QString::number(tmpPoint->getPos().y()) );

		if(tmpPoint->getIndexed())
		{
			m_Ui.checkBox_Index->setChecked( Qt::Checked );
		}
		else
		{
			m_Ui.checkBox_Index->setChecked( Qt::Unchecked );
		}

        setWidgetEnabled( true );

    }
    else
    {
        clearToolWidget();
        setWidgetEnabled( false );
    }
}



/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::slotDescFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setDescription( m_Ui.textEdit_Desc->toPlainText() );
        m_ParentTool->documentChanged();
    }
}


/**
 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
 * Speichert den neuen Namen im Objekt.
 * @author Alex Letkemann 
 */
void BB_WidgetToolNavigationPointNew::slotNameFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setName( m_Ui.lineEdit_Name->text() );
        m_ParentTool->documentChanged();
    }
}


/**
 * Wird aufgerufen, wenn die Position des Knotens im Fenster geändert wird.
 * Ändert die Position des Knotens.
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::slotPosFinished()
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
 * Markiert den asugewählten Knoten als Indiziert oder als nicht Indiziert.
 * @param index True: Indiziert, False: nicht Indiziert.
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::slotIndexChanged( int index )
{
    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_NavigationPoint ) )
    {
        BB_NavigationPoint * tmpPoint =  ( BB_NavigationPoint* )  m_Selection->at( 0 );
		tmpPoint->setIndexed( index );
	}
}


/**
 * Löscht die Selektion
 * @author Alex Letkemann
 */
void BB_WidgetToolNavigationPointNew::slotDelete()
{
	m_ParentTool->deleteSelection();
}

