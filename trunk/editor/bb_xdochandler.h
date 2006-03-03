//
// C++ Interface: bb_xdochandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XDOCHANDLER_H
#define BB_XDOCHANDLER_H

#include "bb_xhandler.h"
#include <QDir>

class BB_Doc;

/**
 * XML-Handler füd das Interpretieren der Projektdatei.
 * @author Alex Letkemann
 */
class BB_XDocHandler : public BB_XHandler
{
public:
	
	/**
	 * Konstruktor
	 * @param doc Dokument, in dem die Daten gespeichert werden.
	 */
    BB_XDocHandler(BB_Doc* doc);

	/**
	 * Destruktor
	 */
    ~BB_XDocHandler();

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
	
	/** Dokument, in dem die Daten gespeichert werden. */
    BB_Doc* m_Doc;
	
	/** Merker für das Doctype */
    bool m_XDocTag;
	
	/** Hilfsvariable zur Pfad auflösung */
    QDir m_Path;
    
	/** Merker für Objektnummern */
	int m_ObjectId;
	
	/** Merker, für Gebäudenummern */
	int m_BuidingNr;

};

#endif
