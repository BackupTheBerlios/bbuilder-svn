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


BB_XBuildingHandler::~BB_XBuildingHandler()
{}


bool BB_XBuildingHandler::startElement( const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts )
{
    // 	return QXmlDefaultHandler::startElement(namespaceURI, localName, qName, atts);

    //     cout << "event: " << namespaceURI.toStdString() << " | " << localName.toStdString() << " | " << qName.toStdString() << endl;

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
//         bool ok;
//         QString tmp;
// 
//         double x, y;
//         int id;
// 
//         tmp = atts.value( "id" );
//         id = tmp.toInt( &ok );
// 
//         tmp = atts.value( "x" );
//         x = tmp.toDouble( &ok );
// 
//         tmp = atts.value( "y" );
//         y = tmp.toDouble( &ok );
// 
// 
//         m_Object = new BB_Point();
//         ( ( BB_Point* ) m_Object ) ->setX( x );
//         ( ( BB_Point* ) m_Object ) ->setY( y );
// 
//         m_Object->m_ObjectNr = id;
//         m_Object->setSelected( false );
// 
//         if ( m_XScale )
//         {
// 
//             if ( m_ScalePointIndex == 0 )
//             {
//                 m_Building->getScalePoint_1() ->setX( x );
//                 m_Building->getScalePoint_1() ->setY( y );
//             }
//             else if ( m_ScalePointIndex == 1 )
//             {
//                 m_Building->getScalePoint_2() ->setX( x );
//                 m_Building->getScalePoint_2() ->setY( y );
//             }
// 
//             m_ScalePointIndex++;
//         }
//         else
//         {
//             m_DrawObjects->append( m_Object );
//         }

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
    // 	else if(qName == "levels")
    // 	{
    // 		m_Path = m_Doc->getFilePath();
    // 		m_Path.cd("levels");
    // 	}

    m_CurrentText.clear();

    return true;
}



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
    // 	else if(qName == "bb_terrain")
    // 	{
    // 		if(m_Doc->getTerrain() == NULL)
    // 		{
    // 			m_Doc->newTerrain(m_Path, m_CurrentText);
    // 		}
    // 		else
    // 		{
    // 			m_Doc->getTerrain()->setFileName(m_CurrentText);
    // 			m_Doc->getTerrain()->setFilePath(m_Path);
    // 		}
    // 	}
    // 	else if(qName == "bb_building")
    // 	{
    // 		m_Doc->newBuilding(m_Path, m_CurrentText);
    // 	}
    // 	else if(qName == "bb_level")
    // 	{
    // 		m_Doc->newLevel(m_Path, m_CurrentText);
    // 	}

    return true;

}
