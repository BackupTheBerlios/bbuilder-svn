//
// C++ Implementation: bb_widgettoolterrainpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolterrainpointnew.h"
#include <bb_abstracttool.h>
#include <bb_terrainpoint.h>

/**
 * Konstruktor. Erstellt ein neues Fenster für das Geländepunkt-Erstellungs-Werkzeug.
 * @param parentTool Geländepunkt-Erstellungs-Werkzeug.
 * @param parent Parent-Fenster, in dem dieses Fenster plaziert wird.
 * @author Alex Letkemann
 */
BB_WidgetToolTerrainPointNew::BB_WidgetToolTerrainPointNew( BB_AbstractTool* parentTool, QWidget* parent ) 
	: BB_AbstractToolWidget( parentTool, parent )
{
    // 	m_Ui.checkBox_Index->setTristate( false );
    m_Ui.setupUi( this );

    connect( m_Ui.lineEdit_X, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );
    connect( m_Ui.lineEdit_Y, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );

    connect( m_Ui.lineEdit_Height, SIGNAL( editingFinished() ), this, SLOT( slotHeightFinished() ) );

    connect( m_Ui.lineEdit_PointName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_PointDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );

    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );

}

/**
 * Destructor
 */
BB_WidgetToolTerrainPointNew::~BB_WidgetToolTerrainPointNew()
{}

/**
 * Löscht die Selektion
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}

/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::slotDescFinished()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Point->setDescription( m_Ui.textEdit_PointDesc->toPlainText() );
}

/**
 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
 * Speichert den neuen Namen im Objekt.
 * @author Alex Letkemann 
 */
void BB_WidgetToolTerrainPointNew::slotNameFinished()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    m_Tmp_Point->setName( m_Ui.lineEdit_PointName->text() );
}


/**
 * Wird aufgerufen, wenn die Position des Punktes im Fenster geändert wurde.
 * Ändert die Position des Punktes.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::slotPosFinished()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );
    C2dVector v = m_Tmp_Point->getPos();
    double x, y;
    bool ok;

    x = QString( m_Ui.lineEdit_X->text() ).toDouble( &ok );
    if ( ok )
    {
        v.setX( x );
    }

    y = QString( m_Ui.lineEdit_Y->text() ).toDouble( &ok );
    if ( ok )
    {
        v.setY( y );
    }

    m_Tmp_Point->setPos( v );

    m_ParentTool->documentChanged();
}

/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::clearToolWidget()
{
    m_Ui.lineEdit_PointName->setText( "" );
    m_Ui.textEdit_PointDesc->setPlainText( "" );


    m_Ui.lineEdit_X->setText( "" );
    m_Ui.lineEdit_Y->setText( "" );
    m_Ui.lineEdit_Height->setText( "" );

}

/**
 * Aktiviert oder Deaktiviert das Fenster.<br>
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_PointName->setEnabled( value );
    m_Ui.lineEdit_X->setEnabled( value );
    m_Ui.lineEdit_Y->setEnabled( value );
    m_Ui.textEdit_PointDesc->setEnabled( value );
    m_Ui.lineEdit_Height->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}

/**
 * Aktualisiert das Eigenschaftsfenster
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::updateWidget()
{
    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_TerrainPoint ) )
    {
        m_Tmp_Point = ( BB_TerrainPoint * ) m_Selection->at( 0 );

        m_Ui.lineEdit_PointName->setText( m_Tmp_Point->getName() );
        m_Ui.textEdit_PointDesc->setPlainText( m_Tmp_Point->getDescription() );


        m_Ui.lineEdit_X->setText( QString::number( m_Tmp_Point->getPos().x() ) );
        m_Ui.lineEdit_Y->setText( QString::number( m_Tmp_Point->getPos().y() ) );

        m_Ui.lineEdit_Height->setText( QString::number( ( ( BB_TerrainPoint* ) ( m_Tmp_Point ) ) ->getHeight() ) );

        setWidgetEnabled( true );
    }
    else
    {
        setWidgetEnabled( false );
    }
}


/**
 * Wird aufgerufen, wenn die Bearbeitung der Höhenposition des Punktes abgeschlossen wurde.
 * Ändert die Höhenposition des Punktes.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainPointNew::slotHeightFinished()
{
    m_Tmp_Point = ( ( BB_Point* ) ( m_Selection->at( 0 ) ) );

    bool ok;
    double height;

    height = QString( m_Ui.lineEdit_Height->text() ).toDouble( &ok );

    if ( ok )
    {
        ( ( BB_TerrainPoint* ) ( m_Tmp_Point ) ) ->setHeight( height );
    }

    m_ParentTool->documentChanged();
}
