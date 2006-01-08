//
// C++ Implementation: bb_xterrainhandler
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xterrainhandler.h"
#include "bb_terrain.h" 
// #include "bb_drawobject.h"
#include "bb_triangle.h"
#include <bb_buildingposition.h>

#include "bb_terrainpoint.h"

#include <iostream>

using namespace std;
BB_XTerrainHandler::BB_XTerrainHandler( BB_Terrain * terrain )
        : BB_XHandler( terrain )
{
    if ( terrain != NULL )
    {
        m_Terrain = terrain;
        m_XTerrainTag = false;
        m_XScale = false;
    }

    m_Object = NULL;

}


BB_XTerrainHandler::~BB_XTerrainHandler()
{}




/*!
    \fn BB_XTerrainHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
 */
bool BB_XTerrainHandler::startElement( const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts )
{
    // 	return QXmlDefaultHandler::startElement(namespaceURI, localName, qName, atts);

    // 	cout << "event: " << namespaceURI.toStdString() << " | " << localName.toStdString() << " | " << qName.toStdString() << endl;

    // 	cout << "<" << qName.toStdString() << ">" << endl;

    if ( !m_XTerrainTag && qName != "bb_terrain" )
    {
        m_ErrorStr = QObject::tr( "Dies ist keine gültige bb_terrain Datei" );
        // 		cout << m_ErrorStr.toStdString() << endl;
        return false;
    }

    if ( qName == "bb_terrain" )
    {
        QString version = atts.value( "version" );
        if ( !version.isEmpty() && version != "1.0" )
        {
            m_ErrorStr = QObject::tr( "Die ist keine bb_terrain Datei der Version 1.0." );
            return false;
        }
        m_XTerrainTag = true;
    }
    else if ( qName == "scale" )
    {
        bool ok;
        QString tmp;
        double value;

        tmp = atts.value( "value" );
        value = tmp.toDouble( &ok );

        m_Terrain->setScaleReal( value );

        m_XScale = true;
    }
    else if ( qName == "bb_terrainpoint" )
    {
		parseTerrainPoint( atts );
    }
    else if ( qName == "bb_point" )
    {
        bool ok;
        QString tmp;

        double x, y, h;
        int id;

        tmp = atts.value( "id" );
        id = tmp.toInt( &ok );

        tmp = atts.value( "x" );
        x = tmp.toDouble( &ok );

        tmp = atts.value( "y" );
        y = tmp.toDouble( &ok );

        tmp = atts.value( "h" );
        h = tmp.toDouble( &ok );

        m_Object = new BB_TerrainPoint();
        ( ( BB_Point* ) m_Object ) ->setX( x );
        ( ( BB_Point* ) m_Object ) ->setY( y );
        ( ( BB_TerrainPoint* ) m_Object ) ->setHeight( h );
        m_Object->m_ObjectNr = id;
        m_Object->setSelected( false );

        if ( m_XScale )
        {
           
            if ( m_ScalePointIndex == 0 )
            {
                m_Terrain->getScalePoint_1() ->setX( x );
                m_Terrain->getScalePoint_1() ->setY( y );
				
				m_ScalePointIndex = 1;
            }
			else if ( m_ScalePointIndex == 1 )
            {
                m_Terrain->getScalePoint_2() ->setX( x );
                m_Terrain->getScalePoint_2() ->setY( y );
				
				m_ScalePointIndex = 0;
            }

        }
        else
        {
            m_Terrain->getDrawObjects() ->append( m_Object );
        }


    }
    else if ( qName == "bb_terraintriangle" )
    {
		parseTerrainTriangle( atts );
    }
    else if ( qName == "bb_buildingposition" )
    {
        bool ok;
        QString tmp;

        double x, y, h, angle;
        int id, building;

        tmp = atts.value( "id" );
        id = tmp.toInt( &ok );

        tmp = atts.value( "x" );
        x = tmp.toDouble( &ok );

        tmp = atts.value( "y" );
        y = tmp.toDouble( &ok );

        tmp = atts.value( "height" );
        h = tmp.toDouble( &ok );

        tmp = atts.value( "angle" );
        angle = tmp.toDouble( &ok );

        tmp = atts.value( "building" );
        building = tmp.toInt( &ok );

        C2dVector pos;
        pos = C2dVector( x, y );
        m_Object = new BB_BuildingPosition(NULL, building , m_Terrain, pos, h, angle );
        ( ( BB_BuildingPosition* ) m_Object ) ->setX( x );
        ( ( BB_BuildingPosition* ) m_Object ) ->setY( y );
        ( ( BB_BuildingPosition* ) m_Object ) ->setHeight( h );
        m_Object->m_ObjectNr = id;
        m_Object->setSelected( false );


        m_Terrain->getDrawObjects() ->append( m_Object );
	} else if( qName == "texture")
	{
		parseTexture( atts );
	}

    m_CurrentText.clear();

    return true;
}


/*!
    \fn BB_XTerrainHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
 */
bool BB_XTerrainHandler::endElement( const QString& namespaceURI, const QString& localName, const QString& qName )
{
//     	cout << "</" << qName.toStdString() << ">" << endl;
    if ( m_Object == NULL )
    {
        if ( qName == "name" )
        {
            m_Terrain->setName( m_CurrentText );

        }
        else if ( qName == "description" )
        {
            m_Terrain->setDescription( m_CurrentText );

        }
        else if ( qName == "mapfile" )
        {
            m_Terrain->setMapFileName( m_CurrentText );
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
    else if ( qName == "bb_terrainpoint" )
    {
        m_Object = NULL;
    }
    else if ( qName == "bb_terraintriangle" )
    {
        m_Object = NULL;
    }
    else if ( qName == "bb_buildingposition" )
    {
        m_Object = NULL;
    }


    return true;
}
