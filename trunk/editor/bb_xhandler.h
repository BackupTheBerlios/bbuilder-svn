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
 * @author Alex Letkemann
 */
class BB_XHandler : public QXmlDefaultHandler
{
public:
	
    /**
     * Konstruktor
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
	 * @param namespaceURI nicht verwendet
	 * @param localName nicht verwendet
	 * @param qName Name des Tags, welcher endet
	 * @return false im Fehlerfall sonst true
	 */
	virtual bool endElement(const QString& namespaceURI, const QString& localName, const QString& qName) = 0;
	
	
	/**
	 * Wird aufgeruffen, wenn der Parser den Anfang eines Elementes erreicht (einen Öffnenden Tag).
	 * @param namespaceURI 
	 * @param localName 
	 * @param qName 
	 * @param atts 
	 * @return 
	 */
	virtual bool startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts) = 0;
	
	
    /**
	 * Wird aufgeruffen, wenn während des Parsens ein Fehler auftritt.
	 * Dier Fehler wird im std::cout ausgegeben
	 */
	virtual bool fatalError(const QXmlParseException& exception);
    bool parseTerrainTriangle( QXmlAttributes& atts );

protected:
	/**  */
	QString m_CurrentText;
	QString m_ErrorStr;
    BB_DrawObject* m_Object;
    BB_ConstructionElement* m_ConstructionElement;
    bool m_XScale;
    BB_DocComponent* m_DocComponent;
	int m_ScalePointIndex;
protected:
    virtual bool parseTexture( const QXmlAttributes& atts );
    virtual bool parseTriangle( const QXmlAttributes& atts );
	virtual bool parseTerrainTriangle( const QXmlAttributes& atts );
	virtual bool parsePoint( const QXmlAttributes& atts );
	virtual bool parseTerrainPoint( const QXmlAttributes& atts );
    
protected:
    virtual bool parseLevelTriangle( const QXmlAttributes& atts );
    virtual bool parseBuildingTriangle( const QXmlAttributes& atts );
};

#endif
