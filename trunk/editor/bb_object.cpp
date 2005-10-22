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
#include "bb_object.h"

#include <iostream>

using namespace std;

int BB_Object::m_Counter = 0;

/**
 * Konstrucktor
 * Erzeugt ein neues Objekt. Name des Objektes wird aus der Objektnummer erzeugt.
 */
// BB_Object::BB_Object()
// {
// 	m_ObjectNr = m_Counter++;
// 	
// 	createName();
// 	
// 	
// }

/**
 * Konstrucktor
 * Erzeugt ein neues Objekt mit dem namen <i>name</i>
 * @param name Name des Objektes
 */
BB_Object::BB_Object(QString name)
{
	m_ObjectNr = m_Counter++;
	if(name != NULL && name != "")
	{
		setName(name);
	}
	else
	{
		createName();
	}
	
	
}

/**
 * Destrucktor
 */
BB_Object::~BB_Object()
{
}

/**
 * Gibt die Objektnummer zurück
 * @return Onjektnummer
 */
int BB_Object::getObjectNr() const
{
    return m_ObjectNr;
}

/**
 * Gibt den Namen des Objektes zurück
 * @return Name des Onjektes
 */
QString BB_Object::getName() const
{
    return m_Name;
}


/**
 * Setzt den Namen des Objektes
 * @param name Name des Objektes 
 */
void BB_Object::setName(const QString& name)
{
	if(name != NULL)
		m_Name = name;
	else
	{
		cout << "Object_" << m_ObjectNr << ": " << "Ungültiger Name" << endl;
		createName();
	}
		
}

/**
 * Gibt die Beschreibung des Objektes zurück
 * @return Beschreibung des Objektes
 */
QString BB_Object::getDescription() const
{
    return m_Description;
}


/**
 * Setzt die Beschreibung des Objektes
 * @param desc Beschreibung des Objektes 
 */
void BB_Object::setDescription(const QString& desc)
{
	if(desc != NULL)
	{
		m_Description = desc;
	}
}


/**
 * Erzeugt den Objektnamen aus der Objektnummer
 */
void BB_Object::createName()
{
	m_Name = QString("Object_") + QString::number(m_ObjectNr,10);
}


/*!
    \fn BB_Object::generateXElement(QTextStream &stream, int depth)
				@author Alex Letkemann
				@date 22.10.2005
 */
void BB_Object::generateXElement(QTextStream &out, int depth)
{
	out << BB::indent(depth) << "<name>" << BB::escapedText(getName()) << "</name>\n";
	
	if(!getDescription().isEmpty())
	{
		out << BB::indent(depth) << "<description>" << BB::escapedText(getDescription()) << "</description>\n";
	}
}


/*!
    \fn BB_Object::getClassName() const;
 */
const QString BB_Object::getClassName()
{
	return QString("BB_Object");
}
