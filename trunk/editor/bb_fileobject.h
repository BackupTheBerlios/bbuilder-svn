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
#include <QXmlDefaultHandler>

/**
@author Alex Letkemann
*/
class BB_FileObject : public BB_Object
{
public:
	BB_FileObject(const QDir &path, const QString &filename, const QString &name = QString(""));

    virtual	~BB_FileObject();
    virtual bool save();
    virtual bool open();
	
	QString getFileName() const;

	QDir getFilePath() const;

	void setFileName(const QString& theValue);

	void setFilePath(const QDir& theValue);
    virtual const QString getClassName();
	virtual QListWidgetItem* getListWidgetItem();
    virtual void setName(const QString& name);
	virtual bool read(QXmlDefaultHandler &handler, QIODevice * dev);
    virtual QString getErrorString() const;
    virtual void setModified( bool value );
	
	

protected:
	/** Gibt an, ob das Objekt modifiziert wurde */
    bool m_Modified;
	
	/** Dateiname */
    QString m_FileName;
	
	/** Pfad zur Datei im Dateisystem */
    QDir m_FilePath;
	
	QListWidgetItem* m_ListWidgetItem;
    QXmlDefaultHandler* m_Handler;
    QString m_ErrorString;
protected:
	/** Schreibt die Datei in den Stream out */ 
	virtual bool write(QTextStream &out)  = 0;


};

#endif
