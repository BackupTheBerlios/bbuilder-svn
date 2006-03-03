//
// C++ Interface: bb_xbuildinghandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XBUILDINGHANDLER_H
#define BB_XBUILDINGHANDLER_H

#include "bb_xhandler.h"
#include "bb_drawobject.h"

#include "bb_point.h"
#include "bb_wall.h"
#include "bb_constructionelement.h"

class BB_Building;

/**
 * XML-Handler zur interpetierung der Gebäude-XML-Dateien
 * @author Alex Letkemann
 */
class BB_XBuildingHandler : public BB_XHandler
{
public:
	
    /**
     * Konstrukto.
     * @param building Gebäude, in dem die Daten gespeichert werden sollen.
     * @author Alex Letkemann
     */
    BB_XBuildingHandler(BB_Building* building);

	/** Destruktor */
    ~BB_XBuildingHandler();
	
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
	
	/** Gebäude, in dem die Daten gespeichert werden sollen. */
    BB_Building* m_Building;
	
	/** Merker für den Doctype */
	bool m_XBuildingTag;
	
	/** Objektvektor, an den die Objekte angehängt werden. */
    QVector<BB_DrawObject*>* m_DrawObjects;
};

#endif
