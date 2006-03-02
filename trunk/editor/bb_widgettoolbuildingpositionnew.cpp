//
// C++ Implementation: bb_widgettoolbuildingpositionnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolbuildingpositionnew.h"
#include <bb_buildingposition.h>
#include <bb_abstracttool.h>
#include <bb_toolbuildingpositionnew.h>


/**
 * Konstruktor.<br />
 * Erstellt ein neues Fenster für das Gebäudepositionierungs-Werkzeug.
 * @param doc Dockument, welches das Gelände und die Gebäude enthält.
 * @param parentTool Gebäudepositionierungs-Werkzeug.
 * @param parent Parent-Fenster, in den das neue Fenster angelegt wird.
 * @author Alex Letkemann
 */
BB_WidgetToolBuildingPositionNew::BB_WidgetToolBuildingPositionNew( BB_Doc* doc, BB_AbstractTool* parentTool, QWidget* parent ) : 						BB_AbstractToolWidget( parentTool, parent )
{
    if ( doc == NULL )
    {
        qDebug( "BB_WidgetToolBuildingPositionNew kann nicht ohne BB_Doc initialisiert werden" );
        exit( 1 );
    }

    m_Doc = doc;
    m_Ui.setupUi( this );

    m_BPos = NULL;
    m_Building = NULL;

    connect( m_Ui.lineEdit_X, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );
    connect( m_Ui.lineEdit_Y, SIGNAL( editingFinished() ), this, SLOT( slotPosFinished() ) );

    connect( m_Ui.lineEdit_Height, SIGNAL( editingFinished() ), this, SLOT( slotHeightFinished() ) );
    connect( m_Ui.doubleSpinBox_Rotation, SIGNAL( valueChanged( double ) ), this, SLOT ( slotRotationChanged( double ) ) );
    connect( m_Ui.lineEdit_Name, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_Desc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );
    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );
    connect( m_Ui.listWidget_Buildings, SIGNAL( currentRowChanged( int ) ), this , SLOT( slotBuildingChanged( int ) ) );

}


/**
 * Destruktor
 */
BB_WidgetToolBuildingPositionNew::~BB_WidgetToolBuildingPositionNew()
{}


/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::clearToolWidget()
{
    m_Ui.lineEdit_Name->clear();
    m_Ui.textEdit_Desc->clear();
    m_Ui.lineEdit_X->clear();
    m_Ui.lineEdit_Y->clear();
    m_Ui.lineEdit_Height->clear();
    m_Ui.doubleSpinBox_Rotation->setValue( 0.0 );
    m_Ui.listWidget_Buildings->clear();
}

/**
 * Aktiviert oder Deaktiviert das Fenster.<br />
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_Name->setEnabled( value );
    m_Ui.textEdit_Desc->setEnabled( value );
    m_Ui.lineEdit_X->setEnabled( value );
    m_Ui.lineEdit_Y->setEnabled( value );
    m_Ui.lineEdit_Height->setEnabled( value );
    m_Ui.doubleSpinBox_Rotation->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}

/**
 * Aktualisiert das Eigenschaftsfenster
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::updateWidget()
{
    m_Ui.listWidget_Buildings->clear();
    for ( int i = 0; i < m_Doc->getBuildings() ->count(); i++ )
    {
        m_Ui.listWidget_Buildings->addItem( QString( m_Doc->getBuildings() ->at( i ) ->getName() ) );
    }

    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_BuildingPosition ) )
    {
        BB_BuildingPosition * bPos = NULL;

        bPos = ( BB_BuildingPosition* ) ( m_Selection->at( 0 ) );

        m_Ui.lineEdit_Name->setText( bPos->getName() );
        m_Ui.textEdit_Desc->setPlainText( bPos->getDescription() );
        m_Ui.lineEdit_X->setText( QString::number( bPos->getPos().x() ) );
        m_Ui.lineEdit_Y->setText( QString::number( bPos->getPos().y() ) );
        m_Ui.lineEdit_Height->setText( QString::number( bPos->getHeight() ) );
        m_Ui.doubleSpinBox_Rotation->setValue( bPos->getRotation() );





        setWidgetEnabled( true );
    }
    else
    {

        setWidgetEnabled( false );
    }
}

/**
 * Löscht die Selektion
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::slotDescFinished()
{
    m_BPos = ( ( BB_BuildingPosition* ) ( m_Selection->at( 0 ) ) );
    m_BPos->setDescription( m_Ui.textEdit_Desc->toPlainText() );
}


/**
 * Wird aufgerufen, wenn die Höhenposition des Gebäudes geändert wurde.
 * Änder die Höhenposition des Gebäudes.
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::slotHeightFinished()
{
    m_BPos = ( ( BB_BuildingPosition* ) ( m_Selection->at( 0 ) ) );

    bool ok;
    double height;

    height = QString( m_Ui.lineEdit_Height->text() ).toDouble( &ok );

    if ( ok )
    {
        ( ( BB_TerrainPoint* ) ( m_BPos ) ) ->setHeight( height );
    }
}

/**
 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
 * Speichert den neuen Namen im Objekt.
 * @author Alex Letkemann 
 */
void BB_WidgetToolBuildingPositionNew::slotNameFinished()
{
    m_BPos = ( ( BB_BuildingPosition* ) ( m_Selection->at( 0 ) ) );
    m_BPos->setName( m_Ui.lineEdit_Name->text() );
}


/**
 * Wird aufgerufen, wenn die Position des Gebäudes im Fenster geändert wird.
 * Ändert die Position des Gebäudes.
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::slotPosFinished()
{
    m_BPos = ( ( BB_BuildingPosition* ) ( m_Selection->at( 0 ) ) );
    C2dVector v = m_BPos->getPos();
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

    m_BPos->setPos( v );

    m_ParentTool->documentChanged();
}



/**
 * Wird aufgerufen, wenn die Rotationswinkel des Gebäudes im Fenster geändert wird.
 * Ändert den Rotationswinkel des Gebäudes.
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::slotRotationChanged( double value )
{
    m_BPos = ( ( BB_BuildingPosition* ) ( m_Selection->at( 0 ) ) );
    m_BPos->setRotation( value );

    // Workframe aktualisieren
    m_ParentTool->documentChanged();
}


/**
 * Wird aufgerufen, wenn ein Gebäudes zur Plazierung ausgewählt wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolBuildingPositionNew::slotBuildingChanged( int index )
{
    if ( index != -1 )
    {
        ( ( BB_ToolBuildingPositionNew* ) ( m_ParentTool ) ) ->setBuilding( m_Doc->getBuilding( index ) );
    }
}
