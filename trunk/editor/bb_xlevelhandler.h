//
// C++ Interface: bb_xlevelhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XLEVELHANDLER_H
#define BB_XLEVELHANDLER_H

#include <bb_xhandler.h>
#include <bb_level.h>
#include <bb_drawobject.h>
#include <bb_wall.h>
#include <bb_navigationpoint.h>

/**
 * XML-Handler für das Einlesen von BB_Level-XML-Dateien
 *
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_XLevelHandler : public BB_XHandler
{
public:
	
    /**
     * Konstruktor. Erstellt ein XML-Handler, der die Daten in der angegebenen Etage speichert,
     * @param level Etage, in der die interpretierten Daten gespeichert weden sollen.
     * @author Alex Letkemann
     */
    BB_XLevelHandler( BB_Level* level );

	/**
	 * Destruktor
	 */
    ~BB_XLevelHandler();

	/**
	 * Wird aufgeruffen, wenn der Parser das Ende eines Elementes erreicht (eine schliessenden Tag).
	 * Beendet die Interpretation eines Objektes.
	 * @param qName Name des Tags, welcher endet.
	 * @return false im Fehlerfall sonst true
	 */
    virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);
	
	/**
	 * Wird aufgeruffen, wenn der Parser den Anfang eines Elementes erreicht (einen Öffnenden Tag).
	 * Ruft zu jedem Tag die entsprechende 'parse'-Funktion auf.
	 * @param qName Element-Name (Tag)
	 * @param atts Attribute des Elementes
	 * @return false im Fehlerfall sonst true
	 */
    virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);

protected:
    
	/** Etage, in der die Daten gespeichert werden */
	BB_Level* m_Level;
	
	/** Merker für Doctype */
    bool m_XLevelTag;
	
	/** Objektvektor */
	QVector<BB_DrawObject*>* m_DrawObjects;
};

#endif
