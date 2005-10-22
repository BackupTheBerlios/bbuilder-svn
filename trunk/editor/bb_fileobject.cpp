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


using namespace std;

/**
 * Konstrucktor. Erzeugt ein neues FileObjekt.
 * Falls einer der Parameter 'path' oder 'filename' NULL oder leer ist, wird der Path der Datei auf das
 * Aktuelle TEMP-Verzeichnis des Betriebsystems gesetzt und der Dateiname wird auf den Objektnamen
 * mit der Endung '.tmp' gesetzt.
 * @param path Verzeichnis-Pfad zur Datei
 * @param filename Dateiname
 * @param name Name des Objektes (Falls leer erzeugt BB_Object einen Namen).
 * @author Alex Letkemann
 * @date 22.10.2005
 */
BB_FileObject::BB_FileObject(const QDir &path, const QString &filename, const QString &name): BB_Object(name)
{
	if(&path != NULL || &filename != NULL || filename.isEmpty())
	{
		m_FilePath = path;
		m_FileName = filename;
	}
	else
	{
		m_FilePath = QDir::temp();
		m_FileName = getName() + ".tmp";
	}
}


/** Destrucktor */
BB_FileObject::~BB_FileObject()
{
}




/**
 * Prüft, ob die Datei geschrieben werden kann.
 * Erzeugt die Datei und ruft die 'write'-Funktion auf.
 * @author Alex Letkemann
 * @date 22.10.2005
 */
bool BB_FileObject::save()
{
	QFile file(m_FilePath.path() + QDir::separator() + m_FileName);

	if(!file.open(QIODevice::WriteOnly))
	{
		QMessageBox::critical(NULL,"Fehler", QString::fromUtf8("Datei konnte nicht geöffnet werden: \n") + file.fileName());
		file.close();
		return false;
	}
	
	QTextStream Stream;
	Stream.setDevice(&file);
	Stream.setCodec("UTF-8");
	
	if(!write(Stream))
	{
		QMessageBox::critical(NULL,"Fehler", QString::fromUtf8("Fehler beim Schreiben in Datei: \n") + file.fileName());
		file.close();
		return false;
	}
	
	
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


void BB_FileObject::setFileName(const QString& theValue)
{
    m_FileName = theValue;
}


void BB_FileObject::setFilePath(const QDir& theValue)
{
    m_FilePath = theValue;
}


/*!
    \fn BB_FileObject::getClassName()
 */
const QString BB_FileObject::getClassName()
{
	return QString("BB_FileObject");
}
