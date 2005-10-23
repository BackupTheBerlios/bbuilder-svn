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

#include "bb_object.h"

#include <QIODevice>
#include <QDir>
#include <QTextStream>
#include <QListWidgetItem>

/**
@author Alex Letkemann
*/
class BB_FileObject : public BB_Object
{
public:
	BB_FileObject(const QDir &path, const QString &filename, const QString &name = QString(""));

    virtual	~BB_FileObject();
    bool save();

	QString getFileName() const;

	QDir getFilePath() const;

	void setFileName(const QString& theValue);

	void setFilePath(const QDir& theValue);
    virtual const QString getClassName();
	virtual QListWidgetItem* getListWidgetItem();
    virtual void setName(const QString& name);
	
	

protected:
	/** Gibt an, ob das Objekt modifiziert wurde */
    bool m_Modified;
	
	/** Dateiname */
    QString m_FileName;
	
	/** Pfad zur Datei im Dateisystem */
    QDir m_FilePath;
	
	QListWidgetItem* m_ListWidgetItem;
protected:
	virtual bool write(QTextStream &out)  = 0;

};

#endif
