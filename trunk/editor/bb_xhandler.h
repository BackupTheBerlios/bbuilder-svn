//
// C++ Interface: bb_xhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XHANDLER_H
#define BB_XHANDLER_H

#include <QXmlDefaultHandler>
#include <bb_doccomponent.h>
#include <bb_drawobject.h>
#include <bb_constructionelement.h>
/**
 * Abstrackte Klasse BB_XHandler. Wird benötigt um die XML-Dateien auszulesen.
 * Eine abgeleitete Klasse muss die Funktionen startElement() und endElement() implementieren.
 * Die Klasse bietet bereits eine Vielzahl von methoden, mit denen alle XML-Elemente des Projektes Interpretiert werden können.
 * @author Alex Letkemann
 */
class BB_XHandler : public QXmlDefaultHandler
{
public:
	
	/**
	 * Erzeugt einen neuen XML-Handler
	 * @param docComponent Dokument-Komponent welches gelesen und Interpretiert werden soll.
	 */
	BB_XHandler(BB_DocComponent*  docComponent);

    /**
     * Destruktor
     */
    ~BB_XHandler();

	/**
	 * Hängt den Strting ch an den Member-String 'm_CurrentText' an.
	 * @param ch String, welcher angehängt werden soll
	 * @return false im Fehlerfall sonst true
	 */
	virtual bool characters(const QString& ch);
	
	/**
	 * Wird aufgeruffen, wenn der Parser das Ende eines Elementes erreicht (eine schliessenden Tag).
	 * Beendet die Interpretation eines Objektes.
	 * @param qName Name des Tags, welcher endet.
	 * @return false im Fehlerfall sonst true
	 */
	virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName) = 0;
	
	
	/**
	 * Wird aufgeruffen, wenn der Parser den Anfang eines Elementes erreicht (einen Öffnenden Tag).
	 * Ruft zu jedem Tag die entsprechende 'parse'-Funktion auf.
	 * @param qName Element-Name (Tag)
	 * @param atts Attribute des Elementes
	 * @return false im Fehlerfall sonst true
	 */
	virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts) = 0;
	
	
    /**
	 * Wird aufgeruffen, wenn während des Parsens ein Fehler auftritt.
	 * Dier Fehler wird im std::cout ausgegeben
	 * @param exception QXmlParseException
	 */
	virtual bool fatalError(const QXmlParseException& exception);
protected:
	
	/** Zuletzt gelesener Text */
	QString m_CurrentText;
	
	/** Errorstring */
	QString m_ErrorStr;
	
	/** Zur Zeit gelesenes Objekt */
	BB_DrawObject* m_Object;
	
	/** Zur Zeit gelesenes Konstruktions-Objekt */
    BB_ConstructionElement* m_ConstructionElement;
	
	/** Merker, ob der gelesene Punkt ein Maßstab-Punkt ist */
    bool m_XScale;
	
	/** Dokument-Komponent des gerade gelesen wird. */
    BB_DocComponent* m_DocComponent;
	
	/** Index der Maßstab-Punkte */
	int m_ScalePointIndex;
	
	
protected:
	
    /**
     * Interpretiert die das 'texture'-Element aus den angegebenen XML-Attributen.
     * @param atts XML-Attribute
     * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
     */
    virtual bool parseTexture( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_triangle'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
    virtual bool parseTriangle( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_terraintriangle'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseTerrainTriangle( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_point'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parsePoint( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_terrainpoint'-Punkt-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseTerrainPoint( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_window'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseWindow(const QXmlAttributes& atts);
	
	/**
	 * Interpretiert die das 'bb_leveltriangle'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
    virtual bool parseLevelTriangle( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_buildingtriangle'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
    virtual bool parseBuildingTriangle( const QXmlAttributes& atts );
	
	/**
	 * Interpretiert die das 'bb_door'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseDoor(const QXmlAttributes& atts);
	
	/**
	 * Interpretiert die das 'bb_stair'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseStair(const QXmlAttributes& atts);
	
	/**
	 * Interpretiert die das 'bb_wall'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseWall(const QXmlAttributes& atts);
	
	/**
	 * Interpretiert die das 'scale'-Element aus den angegebenen XML-Attributen.
	 * @param atts XML-Attribute
	 * @return Erfolg der Interpretation. True, wenn das Element erfolgreich interpretiert werden konnte, sonst false.
	 * @author Alex Letkemann
	 */
	virtual bool parseScale(const QXmlAttributes& atts);
};

#endif
