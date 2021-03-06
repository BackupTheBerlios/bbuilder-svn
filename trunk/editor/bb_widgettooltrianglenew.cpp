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

/**
 * Konstruktor. Erzeugt ein neues Fenster für das Flächenerstellungs-Werkzeug.
 * @param parentTool Flächenerstellungs-Werkzeug.
 * @param parent Parent-Fenster, in dem dieses Fenster plaziert wird.
 * @author Alex Letkemann
 */
BB_WidgetToolTriangleNew::BB_WidgetToolTriangleNew( BB_AbstractTool* parentTool, QWidget* parent ) : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );

    connect( m_Ui.lineEdit_Name, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );

    // ACHTUNG: Für QTextEdit-Objekte müssen die Signale geblockt werden, wenn man ein clear() oder setXXXText() macht
    // sonst entsteht eine Endlosschleife, da das Signal textChanged() dabei gesendet wird.
    connect( m_Ui.textEdit_Desc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );
    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );
}

/**
 * Destruktor
 */
BB_WidgetToolTriangleNew::~BB_WidgetToolTriangleNew()
{}

/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolTriangleNew::clearToolWidget()
{
    m_Ui.lineEdit_Name->clear();
    m_Ui.textEdit_Desc->blockSignals( true );
    m_Ui.textEdit_Desc->clear();
    m_Ui.textEdit_Desc->blockSignals( false );
}

/**
 * Aktiviert oder Deaktiviert das Fenster.<br>
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_WidgetToolTriangleNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_Name->setEnabled( value );
    m_Ui.textEdit_Desc->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}

/**
 * Aktualisiert das Fenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolTriangleNew::updateWidget()
{

    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            dynamic_cast<BB_Triangle*>( m_Selection->at( 0 ) ) )
    {

        BB_Triangle * tmpTriangle = ( ( BB_Triangle* ) ( m_Selection->at( 0 ) ) );
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
void BB_WidgetToolTriangleNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/**
 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
 * Speichert den neuen Namen im Objekt.
 * @author Alex Letkemann 
 */
void BB_WidgetToolTriangleNew::slotNameFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setName( m_Ui.lineEdit_Name->text() );
        m_ParentTool->documentChanged();
    }
}


/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * @author Alex Letkemann
 */
void BB_WidgetToolTriangleNew::slotDescFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setDescription( m_Ui.textEdit_Desc->toPlainText() );
        m_ParentTool->documentChanged();
    }
}
