//
// C++ Interface: bb_fileobject
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_FILEOBJECT_H
#define BB_FILEOBJECT_H

#include <bb_object.h>
#include <QIODevice>
#include <QDir>

/**
@author Alex Letkemann
*/
class BB_FileObject : public BB_Object
{
public:
	BB_FileObject(const QDir &path, const QString &filename, QString name = "");

    virtual	~BB_FileObject();
    void save();

protected:
	/** Gibt an, ob das Objekt modifiziert wurde */
    bool m_Modified;
	
	/** Dateiname */
    QString m_FileName;
	
	/** Pfad zur Datei im Dateisystem */
    QDir m_FilePath;
protected:
    virtual bool write(QIODevice *device)  = 0;
};

#endif
