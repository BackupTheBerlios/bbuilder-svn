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
 * Diese Klasse stellt eine Datei dar. Die hat einen Dateinamen und einen Pfad, wo sie gespeichert wird.
 * Die Datei kann geladen und gespeichert werden. Zum laden wird ein XML-Handler benötigt, der die Datei interprätiert.
 * @author Alex Letkemann
 */
class BB_FileObject : public BB_Object
{
public:
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
	BB_FileObject(const QDir &path, const QString &filename, const QString &name = QString(""));

    virtual	~BB_FileObject();
	
	/**
	 * Prüft, ob die Datei geschrieben werden kann.
	 * Erzeugt die Datei und ruft die 'write'-Funktion auf.
	 * @author Alex Letkemann
	 * @date 30.10.2005
	 */
    virtual bool save();
	
	/**
	 * Liest die Datei eine.
	 * @return false im Fehlerfall sonst true
	 * @author Alex Letkemann
	 * @date 30.10.2005
	 */
    virtual bool open();
	
	/**
	 * Gibt den Dateinamen zurück.
	 * @return Dateiname
	 * @author Alex Letkemann
	 */
	QString getFileName() const;

	/**
	 * Gibt den Pfad zum Verzeichnis der Datei zurück.
	 * @return Pfad zum Verzeichnis der Datei.
	 * @author Alex Letkemann
	 */
	QDir getFilePath() const;

	
	/**
	 * Setzt den Dateiname
	 * @param theValue Datenname
	 */
	void setFileName(const QString& theValue);

	/**
	 * Setzt den Pfad zum Verzeichnis der Datei
	 * @param theValue Pfad zum Verzeichnis der Datei
	 */
	void setFilePath(const QDir& theValue);
	
    /**
     * Gibt den Klassennamen zurück.
     * @return Klassenname
     */
    virtual const QString getClassName();
	
	/**
	 * Gibt ein QListWidgetItem zurück, welches in einer QListWidget verwendet werden kann.
	 * Der Text des QListWidgetItems entspricht dem Namen des Objektes.
	 * Falls das QListWidgetItem noch nicht erzeugt wurde, wird es hier erzeugt und zurückgegeben.
	 * @author Alex Letkemann
	 * @date 23.10.2005
	 */
	virtual QListWidgetItem* getListWidgetItem();
	
	/**
	 * Überladene Funktion des BB_Object.
	 * Ruft die Funktion des BB_Object auf und ersetzt den Text im QListWidgetItem 
	 * (falls dieses Initialisiert ist) durch den neuen Namen.
	 * @param name Neuer Objektname
	 * @author Alex Letkemann
	 * @date 23.10.2005
	 */
    virtual void setName(const QString& name);
	
	/**
	 * Liest das Device <i>dev</i> aus und Parst es mit dem übergebenen XML-Handler.
	 * @param handler Handler, mit dem die Datei geparst werden soll.
	 * @param dev Device, welches ausgelesen werden soll.
	 * @return false im Fehlerfall sonst true;
	 * @author Alex Letkemann
	 */
	virtual bool read(QXmlDefaultHandler &handler, QIODevice * dev);
	
	/**
	 * Gibt den Errorstring zurück.
	 * @return Errorstring
	 */
    virtual QString getErrorString() const;
	
	/**
	 * Markiert die Datei als Modifiziert oder als nicht Modifiziert.
	 * In der Anzeige wird ein Sternchen an den Objektnamen angehängt.
	 * @param value True: Modifiziert, False: Nicht Modifiziert
	 */
    virtual void setModified( bool value );
	
	

protected:
	/** Gibt an, ob das Objekt modifiziert wurde */
    bool m_Modified;
	
	/** Dateiname */
    QString m_FileName;
	
	/** Pfad zur Datei im Dateisystem */
    QDir m_FilePath;
	
	/** ListwidgetItem für Die Anzeige in Listen */
	QListWidgetItem* m_ListWidgetItem;
	
	/** XML-Handler */
    QXmlDefaultHandler* m_Handler;
	
	/** Errorstring */
    QString m_ErrorString;
protected:
	/** 
	 * Schreibt die Datei in den angegeben Stream
	 * @param out Stream in den gweschrieben werden soll
	 * @author Alex Letkemann
	 */ 
	virtual bool write(QTextStream &out)  = 0;


};

#endif
