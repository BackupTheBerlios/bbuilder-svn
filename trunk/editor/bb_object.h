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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_OBJECT_H
#define BB_OBJECT_H

#include <QTextStream>
#include <QString>
#include "bb.h"

/**
 * Basisklasse für alle weiteren Objekte.
 * Ein Objekt besitzt eine Eindeutige Nummer, einen Namen und eine Beschreibung.
 * Die Nummer wird beim Erstellen des Objektes erzeugt und kann später nur noch von den Friend-Klassen geändert werden.
 * @author Alex Letkemann
 */
class BB_Object{
public:
	
	/**
	 * Konstruktor
	 * @param name Objektname 
	 */
	BB_Object(QString name = "");

	
    /**
     * Destruktor
     */
    virtual ~BB_Object();

	/**
	 * Gibt die Objektnummer zurück
	 * @return Onjektnummer
	 */
	int getObjectNr() const;

	/**
	 * Setzt den Namen des Objektes. Falls der Name leer ist, wird ein Name aus der Objektnummer erzeugt.
	 * @param name Name des Objektes 
	 * @author Alex Letkemann
	 * @date 23.10.2005
	 */
	void BB_Object::setName(const QString& theValue);
	
	/**
	 * Gibt den Namen des Objektes zurück
	 * @return Name des Onjektes
	 */
	const QString& BB_Object::getName() const;
	
	/**
	 * Setzt die Beschreibung des Objektes.
	 * @param desc Beschreibung des Objektes. 
	 */
	void BB_Object::setDescription(const QString& theValue);
	
	/**
	 * Gibt die Beschreibung des Objektes zurück
	 * @return Beschreibung des Objektes
	 */
	const QString& BB_Object::getDescription() const;
	
	/**
	 * Erzeugt die XML-Elemente &ltname&gt und &ltdescription&gt des Objektes, falls diese gesetzt sind.
	 * @author Alex Letkemann
	 * @date 22.10.2005
	 */
	virtual void generateXElement(QTextStream &out, int depth);	
	
	/**
	 * Gibt den Klassennamen zurück
	 * @return Klassenname
	 */
    virtual const QString getClassName();


private:
    static int m_Counter;
	
	/** Ojektnummer */
    int m_ObjectNr;
	
	/** Beschreibung */
    QString m_Description;
	
	/** Name */
    QString m_Name;
	
	/** Markiert, ob Name gesetzt oder automatisch erstellt */
	bool m_AutoName;
	
	
	
private:
	/**
     * Erzeugt den Objektnamen aus der Objektnummer (<i>'Object_' + Onjektnummer</i>).
     * @author Alex Letkemann
     * @date 20.09.2005
	 */
    void createName();
	
	/* Fruendklassen zum Laden der Objekte */
	friend class BB_XBuildingHandler;
	friend class BB_XLevelHandler;
	friend class BB_XTerrainHandler;
	friend class BB_XDocHandler;
	friend class BB_Doc;
	friend class BB_XHandler;

};

#endif
