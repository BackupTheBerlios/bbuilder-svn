//
// C++ Implementation: bb_xbuildinghandler
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xbuildinghandler.h"
#include "bb_building.h"
#include "bb_door.h"
#include "bb_window.h"
#include "bb_stair.h"

#include <iostream>

using namespace std;


/**
 * Konstrukto.
 * @param building Gebäude, in dem die Daten gespeichert werden sollen.
 * @author Alex Letkemann
 */
BB_XBuildingHandler::BB_XBuildingHandler( BB_Building* building )
        : BB_XHandler( building )
{
    if ( building != NULL )
    {
        m_Building = building;
        m_DrawObjects = m_Building->getDrawObjects();

        m_XBuildingTag = false;
        m_XScale = false;
        m_ScalePointIndex = 0;

        m_ConstructionElement = NULL;
        m_Object = NULL;
    }
}


/** Destruktor */
BB_XBuildingHandler::~BB_XBuildingHandler()
{}


/**
 * @fn BB_XBuildingHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
 */
bool BB_XBuildingHandler::startElement( const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts )
{

    if ( !m_XBuildingTag && qName != "bb_building" )
    {
        m_ErrorStr = QObject::tr( "Dies ist keine gültige bb_building Datei" );
        // 		cout << m_ErrorStr.toStdString() << endl;
        return false;
    }

    if ( qName == "bb_building" )
    {
        QString version = atts.value( "version" );
        if ( !version.isEmpty() && version != "1.0" )
        {
            m_ErrorStr = QObject::tr( "Die ist keine bb_building Datei der Version 1.0." );
            return false;
        }
        m_XBuildingTag = true;
    }
    else if ( qName == "scale" )
    {
		parseScale(atts);
    }
    else if ( qName == "bb_point" )
    {
		
		parsePoint( atts );
    
	}
    else if ( qName == "bb_wall" )
    {

		parseWall(atts);
    }
    else if ( qName == "bb_stair" )
    {
		parseStair(atts);
    }
    else if ( qName == "bb_door" )
    {
		parseDoor(atts);
    }
    else if ( qName == "bb_window" )
    {
		parseWindow(atts);
    }
	else if( qName == "bb_buildingtriangle" )
	{
		parseBuildingTriangle( atts );
	}
    else if ( qName == "texture" )
    {
		parseTexture( atts );
    }
    m_CurrentText.clear();

    return true;
}


/**
 * @fn BB_XBuildingHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
 */
bool BB_XBuildingHandler::endElement( const QString& namespaceURI, const QString& localName, const QString& qName )
{
    if ( m_Object == NULL )
    {
        if ( qName == "name" )
        {
            m_Building->setName( m_CurrentText );

        }
        else if ( qName == "description" )
        {
            m_Building->setDescription( m_CurrentText );

        }
        else if ( qName == "mapfile" )
        {
            m_Building->setMapFileName( m_CurrentText );
        }
    }
    else
    {
        if ( qName == "name" )
        {
            m_Object->setName( m_CurrentText );

        }
        else if ( qName == "description" )
        {
            m_Object->setDescription( m_CurrentText );

        }
    }

    if ( qName == "scale" )
    {
        m_XScale = false;
    }
    else if ( qName == "bb_point" )
    {
        m_Object = NULL;
    }
    else if ( qName == "bb_wall" )
    {
        m_Object = NULL;
    }
	else if( qName == "bb_buildingtriangle" )
	{
		m_Object = NULL;
	}
    else if ( qName == "bb_stair" )
    {
        m_Object = NULL;
    }
    else if ( qName == "bb_door" )
    {
        ( ( BB_Wall * ) m_Object ) ->getObjects() ->append( m_ConstructionElement );
        m_ConstructionElement = NULL;
    }
    else if ( qName == "bb_window" )
    {
        ( ( BB_Wall * ) m_Object ) ->getObjects() ->append( m_ConstructionElement );
        m_ConstructionElement = NULL;
    }

    return true;

}
