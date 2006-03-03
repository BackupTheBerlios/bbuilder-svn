//
// C++ Implementation: bb_widgettoolterraintrianglenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolterraintrianglenew.h"
#include <bb_globals.h>
#include <bb_abstracttool.h>
#include <bb_terraintriangle.h>

/**
 * Konstruktor. Erstellt ein neues Fenster für das Geländeflächen-Erstellungs-Werkzeug.
 * @param parentTool Geländeflächen-Erstellungs-Werkzeug.
 * @param parent Parent-Fenster, in dem das neue Fenster positioniert wird.
 * @return 
 */
BB_WidgetToolTerrainTriangleNew::BB_WidgetToolTerrainTriangleNew( BB_AbstractTool* parentTool, QWidget* parent ) : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );

    connect( m_Ui.lineEdit_Name, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_Desc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );
    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );
    connect( m_Ui.lineEdit_Texture, SIGNAL( editingFinished() ), this, SLOT( slotTextureFinished() ) );
    connect( m_Ui.toolButton_TextureSearch, SIGNAL( pressed() ), this, SLOT( slotTextureSearch() ) );

}


/**
 * Destruktor
 */
BB_WidgetToolTerrainTriangleNew::~BB_WidgetToolTerrainTriangleNew()
{}

/**
 * Lädt die Default-Werte in das Werkzeugfenster.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainTriangleNew::clearToolWidget()
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
void BB_WidgetToolTerrainTriangleNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_Name->setEnabled( value );
    m_Ui.textEdit_Desc->setEnabled( value );
    m_Ui.pushButton_Delete->setEnabled( value );
}

/**
 * Aktualisiert das Eigenschaftsfenster
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainTriangleNew::updateWidget()
{
    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_TerrainTriangle ) )
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
void BB_WidgetToolTerrainTriangleNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/**
 * Wird aufgerufen, wenn die Beschreibung geändert wird.
 * Ändert die Beschreibung.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainTriangleNew::slotDescFinished()
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
void BB_WidgetToolTerrainTriangleNew::slotNameFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setName( m_Ui.lineEdit_Name->text() );
        m_ParentTool->documentChanged();
    }
}


/**
 * Wird aufgerufen, wenn die Bearbeitung des Textur-Dateinamen abgeschlossen ist.
 * Ändert den Text-Dateinamen der Fläche.
 * @author Alex Letkemann 
 */
void BB_WidgetToolTerrainTriangleNew::slotTextureFinished()
{

    QFileInfo fileInfo( m_Ui.lineEdit_Texture->text() );
    QString fileName;


    if ( fileInfo.exists() )
    {
        fileName = fileInfo.fileName();

		QString newFile = PRO_TEXTURES_DIR() + SEPARATOR() + fileName;
        if ( !QFile::exists( newFile ) )
        {
			QFile::copy( fileInfo.absoluteFilePath(), newFile );
        }

        if ( m_Selection != NULL && m_Selection->count() == 1 )
        {
// 			qDebug() << fileName;
            m_Tmp_DrawObject = m_Selection->at( 0 );
			m_Tmp_DrawObject->setTextureFileName( fileInfo.fileName() );
        }
		
		m_Ui.lineEdit_Texture->setText( fileInfo.fileName() );
    }


}


/**
 * Ruft einen Datei-Dialog auf, mit dem man eine Bilddatei als Textur auswählen kann.
 * @author Alex Letkemann
 */
void BB_WidgetToolTerrainTriangleNew::slotTextureSearch()
{
    QString filename;
    filename = QFileDialog::getOpenFileName( this,
               QString::fromUtf8( "Öffnen" ),
               PRO_TEXTURES_DIR(),
               "Images (*.png *.bmp *.jpg)" );
    if ( !filename.isEmpty() )
    {

		m_Ui.lineEdit_Texture->setText( filename );
		
    }

    slotTextureFinished();
}


/**
 * Gibt den Textur-Dateinamen zurück.
 * @return Textur-Dateiname
 * @author Alex Letkemann
 */
QString BB_WidgetToolTerrainTriangleNew::getTextureFileName()
{
	return m_Ui.lineEdit_Texture->text();
}
