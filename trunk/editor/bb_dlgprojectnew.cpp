/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
***************************************************************************/
#include "bb_dlgprojectnew.h"

#include <iostream>
#include <QtGui>
#include <bb.h>
using namespace std;

/** Konstruktor */
BB_DlgProjectNew::BB_DlgProjectNew( QWidget * parent, Qt::WFlags f )
        : QDialog( parent, f )
{

    m_Dlg.setupUi( this );

    m_Dlg.lineEditProjectName->setValidator( BB::validAlphanumeric );

    m_ProjectPath = QDir::homePath();
    m_Dlg.lineEditProjectPath->setText( m_ProjectPath );
    checkDir();

    connect( m_Dlg.buttonShowDir,
             SIGNAL( clicked() ),
             this,
             SLOT( slotShowDir() ) );

    connect( m_Dlg.lineEditProjectName,
             SIGNAL( textChanged( const QString& ) ),
             this,
             SLOT( slotNameChanged( const QString& ) ) );

    connect( m_Dlg.lineEditProjectPath,
             SIGNAL( textChanged( const QString& ) ),
             this,
             SLOT( slotPathChanged( const QString& ) ) );

    connect( m_Dlg.textEditProjectDesc,
             SIGNAL( textChanged() ),
             this,
             SLOT( slotDescChanged() ) );

}

/** Destruktor */
BB_DlgProjectNew::~BB_DlgProjectNew()
{}




/** Wird aufgerufen, wenn der 'Suchen'-Button gedrückt wird */
void BB_DlgProjectNew::slotShowDir()
{
    cout << "ShowDir" << endl;
    QFileDialog fileDialog( this );
    fileDialog.setAcceptMode( QFileDialog::AcceptSave );
    fileDialog.setDirectory( QDir::home() );
    fileDialog.setFileMode( QFileDialog::DirectoryOnly );
    fileDialog.setViewMode( QFileDialog::List );


    if ( fileDialog.exec() )
    {
        m_Dlg.lineEditProjectPath->setText( fileDialog.selectedFiles().at( 0 ) );
    }


}


/** Wird aufgerufen, wenn das Verzeichnis geändert wird */
void BB_DlgProjectNew::slotPathChanged( const QString & text )
{
    m_ProjectPath = text;
    checkDir();
}


/** Wird aufgerufen, wenn der Name geändert wird */
void BB_DlgProjectNew::slotNameChanged( const QString & text )
{
    m_ProjectName = text;
    m_ProjectDir = text.toLower().remove( QRegExp( "\\W" ) );
    checkDir();
}



/**
 * Prüft ob, der angegebene Pfad für das neue Projekt gültig ist,
 * schaltet den OK Button ein bzw. aus und
 * Setzt schreibt ein "Ungültig" hinter dem Pfad im Anzeigelabel im Dialog.
 * @author Alex Letkemann
 * @date 17.09.2005
 */
void BB_DlgProjectNew::checkDir()
{
    m_Dir = m_ProjectPath;
    QDir fullPath( m_ProjectPath + "/" + m_ProjectDir );

    bool fullPathExists = fullPath.exists();

    if ( m_Dir.exists() && m_ProjectDir != "" && !fullPathExists )
    {
        m_Dlg.okButton->setEnabled( true );
        m_Dlg.lineEditFinalPath->setText( m_Dir.path()
                                          + "/"
                                          + m_ProjectDir );
    }
    else
    {
        m_Dlg.okButton->setEnabled( false );
        m_Dlg.lineEditFinalPath->setText( m_Dir.path()
                                          + "/"
                                          + m_ProjectDir );

        if ( fullPathExists && m_ProjectDir != "" )
        {
            m_Dlg.lineEditFinalPath->setText( m_Dlg.lineEditFinalPath->text()
                                              + QString::fromUtf8( " ( existiert bereits )" ) );
        }
        else
        {
            m_Dlg.lineEditFinalPath->setText( m_Dlg.lineEditFinalPath->text()
                                              + QString::fromUtf8( " ( ungültig )" ) );
        }

    }
}

/** Gibt den Projekt-Verzeichnis-Namen zurück */
QString BB_DlgProjectNew::getProjectDir() const
{
    return m_ProjectDir;
}

/** Gibt den Pfad zum Projekt-Verzeichnis zurück */
QDir BB_DlgProjectNew::getProjectPath() const
{
    return m_Dir;
}



/** Wird aufgerufen, wenn die Beschreibung geändert wird */
void BB_DlgProjectNew::slotDescChanged()
{
    m_ProjectDescription = m_Dlg.textEditProjectDesc->toPlainText();
}

/** Gibt den Projektnamen zurück */
QString BB_DlgProjectNew::getProjectName() const
{
    return m_ProjectName;
}

/** Gibt die Projektbeschreibung zurück */
QString BB_DlgProjectNew::getProjectDescription() const
{
    return m_ProjectDescription;
}
