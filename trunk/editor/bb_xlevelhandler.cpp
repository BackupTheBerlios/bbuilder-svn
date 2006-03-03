//
// C++ Implementation: bb_xlevelhandler
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xlevelhandler.h"

#include <iostream>

using namespace std;

BB_XLevelHandler::BB_XLevelHandler( BB_Level* level ) : BB_XHandler( level )
{
    if ( level == NULL )
    {
        qDebug( "BB_XLevelHandler benötigt ein Level  " );
        exit( 1 );
    }

    m_Level = level;

    m_DrawObjects = m_Level->getDrawObjects();

    m_Object = NULL;
    m_ScalePointIndex = 0;
    m_XLevelTag = false;
    m_XScale = false;
}


BB_XLevelHandler::~BB_XLevelHandler()
{}


bool BB_XLevelHandler::endElement( const QString& namespaceURI, const QString& localName, const QString& qName )
{

    if ( m_Object == NULL )
    {
        if ( qName == "name" )
        {
            m_Level->setName( m_CurrentText );

        }
        else if ( qName == "description" )
        {
            m_Level->setDescription( m_CurrentText );

        }
        else if ( qName == "mapfile" )
        {
            m_Level->setMapFileName( m_CurrentText );
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
    else if ( qName == "bb_leveltriangle" )
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

bool BB_XLevelHandler::startElement( const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts )
{

    if ( !m_XLevelTag && qName != "bb_level" )
    {
        m_ErrorStr = QObject::tr( "Dies ist keine gültige bb_level Datei" );

        return false;
    }

    if ( qName == "bb_level" )
    {
        QString version = atts.value( "version" );
        if ( !version.isEmpty() && version != "1.0" )
        {
            m_ErrorStr = QObject::tr( "Die ist keine bb_level Datei der Version 1.0." );
            return false;
        }
        m_XLevelTag = true;
    }
    else if ( qName == "scale" )
    {
        parseScale( atts );
        // 		bool ok;
        // 		QString tmp;
        // 		double value;
        //
        // 		tmp = atts.value( "value" );
        // 		value = tmp.toDouble( &ok );
        //
        // 		m_Level->setScaleReal( value );
        //
        // 		m_XScale = true;
    }
    else if ( qName == "bb_point" )
    {
        parsePoint( atts );
        /*
        bool ok;
        QString tmp;

        double x, y;
        int id;

        tmp = atts.value( "id" );
        id = tmp.toInt( &ok );

        tmp = atts.value( "x" );
        x = tmp.toDouble( &ok );

        tmp = atts.value( "y" );
        y = tmp.toDouble( &ok );


        m_Object = new BB_Point();
        ( ( BB_Point* ) m_Object ) ->setX( x );
        ( ( BB_Point* ) m_Object ) ->setY( y );

        m_Object->m_ObjectNr = id;
        m_Object->setSelected( false );

        if ( m_XScale )
        {
        	
        	if ( m_ScalePointIndex == 0 )
        	{
        		m_Level->getScalePoint_1() ->setX( x );
        		m_Level->getScalePoint_1() ->setY( y );
        	}
        	else if ( m_ScalePointIndex == 1 )
        	{
        		m_Level->getScalePoint_2() ->setX( x );
        		m_Level->getScalePoint_2() ->setY( y );
        	}

        }
        else
        {
        	m_DrawObjects->append( m_Object );
        }                 */

    }
    else if ( qName == "bb_wall" )
    {

        parseWall( atts );

    }
    else if ( qName == "bb_leveltriangle" )
    {
        parseLevelTriangle( atts );
    }
    else if ( qName == "bb_door" )
    {
        parseDoor( atts );
    }
    else if ( qName == "bb_window" )
    {
        parseWindow( atts );
    }
    else if ( qName == "texture" )
    {
        parseTexture( atts );
    }


    m_CurrentText.clear();

    return true;
}

