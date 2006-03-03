//
// C++ Interface: bb_xterrainhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XTERRAINHANDLER_H
#define BB_XTERRAINHANDLER_H

#include <bb_xhandler.h>

#include "bb_drawobject.h"


class BB_Terrain;

/**
 * XML-Handler für die Gelände-XML-Dateinen
 * @author Alex Letkemann
 */
class BB_XTerrainHandler : public BB_XHandler
{
public:
	
	/**
	 * Konstruktor.
	 * @param terrain Gelände, in dem die Daten gespeichert werden.
	 * @author Alex Letkemann
	 */
	BB_XTerrainHandler( BB_Terrain * terrain );

    /**
     * Destruktor
     */
    ~BB_XTerrainHandler();
	
	/**
	 * Wird aufgeruffen, wenn der Parser den Anfang eines Elementes erreicht (einen Öffnenden Tag).
	 * Ruft zu jedem Tag die entsprechende 'parse'-Funktion auf.
	 * @param qName Element-Name (Tag)
	 * @param atts Attribute des Elementes
	 * @return false im Fehlerfall sonst true
	 */
    virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);
	
	/**
	 * Wird aufgeruffen, wenn der Parser das Ende eines Elementes erreicht (eine schliessenden Tag).
	 * Beendet die Interpretation eines Objektes.
	 * @param qName Name des Tags, welcher endet.
	 * @return false im Fehlerfall sonst true
	 */
    virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName);

protected:

	/** Gelände, in dem die Daten gespeichert werden. */
    BB_Terrain* m_Terrain;
    
	/** Merker für Doctype */
	bool m_XTerrainTag;

};

#endif
