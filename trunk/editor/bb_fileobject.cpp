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
BB_FileObject::BB_FileObject(const QDir &path, const QString &filename, QString name): BB_Object(name)
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
void BB_FileObject::save()
{
    /// @todo implement me
}
