//
// C++ Implementation: bb_fileobject
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_fileobject.h"

#include <QMessageBox>
#include <iostream>

#include "bb_object.h"

using namespace std;

/**
 * Konstruktor. Erzeugt ein neues FileObjekt.
 * Falls einer der Parameter 'path' oder 'filename' NULL oder leer ist, wird der Path der Datei auf das
 * Aktuelle TEMP-Verzeichnis des Betriebsystems gesetzt und der Dateiname wird auf den Objektnamen
 * mit der Endung '.tmp' gesetzt.
 * @param path Verzeichnis-Pfad zur Datei
 * @param filename Dateiname
 * @param name Name des Objektes (Falls leer erzeugt BB_Object einen Namen).
 * @author Alex Letkemann
 * @date 30.10.2005
 */
BB_FileObject::BB_FileObject( const QDir &path, const QString &filename, const QString &name ) : BB_Object( name )
{
    if ( &path != NULL || &filename != NULL || filename.isEmpty() )
    {
        m_FilePath = path;
        m_FileName = filename;
    }
    else
    {
        m_FilePath = QDir::temp();
        m_FileName = getName() + ".tmp";
    }


    m_ListWidgetItem = NULL;
    m_Handler = NULL;

    setModified( true );
}


/** Destruktor */
BB_FileObject::~BB_FileObject()
{
	if( m_ListWidgetItem != NULL )
	{
		delete m_ListWidgetItem;
		m_ListWidgetItem = NULL;
	}
}




/**
 * Prüft, ob die Datei geschrieben werden kann.
 * Erzeugt die Datei und ruft die 'write'-Funktion auf.
 * @author Alex Letkemann
 * @date 30.10.2005
 */
bool BB_FileObject::save()
{
    QFile file( m_FilePath.path() + QDir::separator() + m_FileName );

    if ( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        QMessageBox::critical( NULL, "Fehler", QString::fromUtf8( "Datei konnte nicht geöffnet werden: \n" ) + file.fileName() );
        file.close();
        return false;
    }

    QTextStream Stream;
    Stream.setDevice( &file );
    Stream.setCodec( "UTF-8" );

    if ( !write( Stream ) )
    {
        QMessageBox::critical( NULL, "Fehler", QString::fromUtf8( "Fehler beim Schreiben in Datei: \n" ) + file.fileName() );
        file.close();
        return false;
    }

    setModified( false );
    file.close();
    return true;
}


QString BB_FileObject::getFileName() const
{
    return m_FileName;
}


QDir BB_FileObject::getFilePath() const
{
    return m_FilePath;
}


void BB_FileObject::setFileName( const QString& theValue )
{
    m_FileName = theValue;
}


void BB_FileObject::setFilePath( const QDir& theValue )
{
    m_FilePath = theValue;
}


/**
 * Gibt den Namen der Klasse zurück.
 * @return Klassenname
 */
const QString BB_FileObject::getClassName()
{
    return QString( "BB_FileObject" );
}


/**
 * Gibt ein QListWidgetItem zurück, welches in einer QListWidget verwendet werden kann.
 * Der Text des QListWidgetItems entspricht dem Namen des Objektes.
 * Falls das QListWidgetItem noch nicht erzeugt wurde, wird es hier erzeugt und zurückgegeben.
 * @author Alex Letkemann
 * @date 23.10.2005
 */
QListWidgetItem* BB_FileObject::getListWidgetItem()
{
    if ( m_ListWidgetItem == NULL )
    {
        m_ListWidgetItem = new QListWidgetItem( getName() );
    }

    return m_ListWidgetItem;
}



/**
 * Überladene Funktion des BB_Object.
 * Ruft die Funktion des BB_Object auf und ersetzt den Text im QListWidgetItem 
 * (falls dieses Initialisiert ist) durch den neuen Namen.
 * @param name Neuer Objektname
 * @author Alex Letkemann
 * @date 23.10.2005
 */
void BB_FileObject::setName( const QString& name )
{
    BB_Object::setName( name );
    if ( m_ListWidgetItem != NULL )
    {
        m_ListWidgetItem->setText( getName() );
    }
}


/**
 * Liest die Datei eine.
 * @return false im Fehlerfall sonst true
 * @author Alex Letkemann
 * @date 30.10.2005
 */
bool BB_FileObject::open()
{
    if ( m_Handler != NULL )
    {
        QFile file( m_FilePath.path() + QDir::separator() + m_FileName );

        if ( !file.exists() || !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            m_ErrorString = "Datei konnte nicht geöffnet werden: " + file.fileName();
            return false;
        }


        if ( !read( *m_Handler, &file ) )
        {
            m_ErrorString = "Fehler beim Parsen der Datei: " + file.fileName();
            file.close();
            return false;
        }

        setModified( false );
        file.close();
        return true;
    }
    else
    {
        m_ErrorString = "Für '" + getClassName() + "' ist kein Handler definiert!";
    }

    return false;
}


/**
 * Liest das Device <i>dev</i> aus und Parst es mit dem übergebenen XML-Handler.
 * @param handler Handler, mit dem die Datei geparst werden soll.
 * @param dev Device, welches ausgelesen werden soll.
 * @return false im Fehlerfall sonst true;
 * @author Alex Letkemann
 */
bool BB_FileObject::read( QXmlDefaultHandler &handler, QIODevice * dev )
{
    QXmlSimpleReader reader;
    reader.setContentHandler( &handler );
    reader.setErrorHandler( &handler );

    QXmlInputSource xmlInputSource( dev );

    return reader.parse( xmlInputSource );
}


/**
 * Gibt den Errorstring zurück.
 * @return Errorstring
 */
QString BB_FileObject::getErrorString() const
{
    return m_ErrorString;
}


/*!
    \fn BB_FileObject::setModified( bool value )
 */
void BB_FileObject::setModified( bool value )
{
    m_Modified = value;

    if ( m_Modified )
    {
        // 		getListWidgetItem() ->setTextColor( Qt::white );
        getListWidgetItem() ->setText( getName() + "*" );
    }
    else
    {
        // 		getListWidgetItem() ->setTextColor( Qt::black );
        getListWidgetItem() ->setText( getName() );
    }
}
