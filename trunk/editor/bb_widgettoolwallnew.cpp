//
// C++ Implementation: bb_widgettoolwallnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolwallnew.h"
#include <bb_wall.h>
#include <bb_abstracttool.h>

/**
 * Konstruktor. Erstellt ein neues Wand-Erstellungs-Werkzeug.
 * @param parentTool Wand-Erstellungs-Werkzeug
 * @param parent Parent-Fenster, in den dieses Fenster plaziert wird.
 * @author Alex Letkemann
 */
BB_WidgetToolWallNew::BB_WidgetToolWallNew( BB_AbstractTool* parentTool, QWidget* parent ) : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );


    connect( m_Ui.lineEdit_WallName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
	
	// ACHTUNG: Für QTextEdit-Objekte müssen die Signale geblockt werden, wenn man ein clear() oder setXXXText() macht
	// sonst entsteht eine Endlosschleife, da das Signal textChanged() dabei gesendet wird.
    connect( m_Ui.textEdit_WallDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );

    connect( m_Ui.pushButton_Swap, SIGNAL( released() ), this, SLOT( slotSwap() ) );
    connect( m_Ui.pushButton_Edit, SIGNAL( released() ), this, SLOT( slotEdit() ) );
    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );

    setWidgetEnabled( false );
}


/**
 * Destruktor
 */
BB_WidgetToolWallNew::~BB_WidgetToolWallNew()
{}


/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::clearToolWidget()
{
    m_Ui.lineEdit_WallName->clear();
	
	m_Ui.textEdit_WallDesc->blockSignals(true);
    m_Ui.textEdit_WallDesc->clear();
	m_Ui.textEdit_WallDesc->blockSignals(false);
	
    m_Ui.label_Pos1->clear();
    m_Ui.label_Pos2->clear();
}


/**
 * Aktiviert oder Deaktiviert das Fenster.<br />
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_WallName->setEnabled( value );
    m_Ui.textEdit_WallDesc->setEnabled( value );

    m_Ui.pushButton_Delete->setEnabled( value );
    m_Ui.pushButton_Edit->setEnabled( value );
    m_Ui.pushButton_Swap->setEnabled( value );
}

/**
 * Aktualisiert das Fenster
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::updateWidget()
{
	
    BB_Wall * tmpWall;

    if ( m_Selection != NULL &&
            m_Selection->count() >= 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_Wall ) )
    {
        tmpWall = ( BB_Wall* ) m_Selection->at( 0 );

        m_Ui.lineEdit_WallName->setText( tmpWall->getName() );
		m_Ui.textEdit_WallDesc->blockSignals(true);
        m_Ui.textEdit_WallDesc->setPlainText( tmpWall->getDescription() );
		m_Ui.textEdit_WallDesc->blockSignals(false);
        m_Tmp_DrawObject = tmpWall->getPos1();
        if ( m_Tmp_DrawObject != NULL )
        {
            m_Ui.label_Pos1->setText( m_Tmp_DrawObject->getName() + " (" + QString::number( m_Tmp_DrawObject->getObjectNr() ) + ")" );
        }

        m_Tmp_DrawObject = tmpWall->getPos2();
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



/**
 * Löscht die Selektion
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::slotDescFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setDescription( m_Ui.textEdit_WallDesc->toPlainText() );
        m_ParentTool->documentChanged();
    }
}


/**
 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
 * Speichert den neuen Namen im Objekt.
 * @author Alex Letkemann 
 */
void BB_WidgetToolWallNew::slotNameFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setName( m_Ui.lineEdit_WallName->text() );
        m_ParentTool->documentChanged();
    }
}


/**
 * Änder die Richtung der Wand.
 * Dadurch wird die sichtbare Seite der Wand ungedreht.
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::slotSwap()
{
//     BB_Wall * wall = ( BB_Wall * ) m_Selection->at( 0 );
//     wall->swap();

	for( int i=0;i<m_Selection->count() ;i++ ){
		if (typeid(*(m_Selection->at(i)))==typeid(BB_Wall)){
			((BB_Wall*)m_Selection->at(i))->swap();
		}
	}

    m_ParentTool->documentChanged();
}


/**
 * Startet ein weiteres Dialog, in dem die sichtbare Seite der Wand bearbeitet werden kann.
 * @author Alex Letkemann
 */
void BB_WidgetToolWallNew::slotEdit()
{
    BB_Wall * wall = ( BB_Wall * ) m_Selection->at( 0 );
    wall->editDlg( m_ParentTool->getDocComponent() );
}
