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


#include "bb_point.h"

#include <iostream>

using namespace std;
BB_XTerrainHandler::BB_XTerrainHandler( BB_Terrain * terrain )
        : BB_XHandler()
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
    else if ( qName == "bb_point" )
    {
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
            static int scalePoint = 0;
            if ( scalePoint == 0 )
            {
                m_Terrain->getScalePoint_1() ->setX( x );
                m_Terrain->getScalePoint_1() ->setY( y );
            }
            else if ( scalePoint == 1 )
            {
                m_Terrain->getScalePoint_2() ->setX( x );
                m_Terrain->getScalePoint_2() ->setY( y );
            }

            scalePoint++;
        }
        else
        {
            m_Terrain->getDrawObjects() ->append( m_Object );
        }


    }
    else if ( qName == "bb_triangle" )
    {
        bool ok;
        QString tmp;
        BB_Point *point1 = NULL;
        BB_Point *point2 = NULL;
        BB_Point *point3 = NULL;
        int id;
        int p1, p2, p3;

        tmp = atts.value( "id" );
        id = tmp.toInt( &ok );

        tmp = atts.value( "p1" );
        p1 = tmp.toInt( &ok );

        tmp = atts.value( "p2" );
        p2 = tmp.toInt( &ok );

        tmp = atts.value( "p3" );
        p3 = tmp.toInt( &ok );


        BB_Object *object;

        for ( int i = 0; i < m_Terrain->getDrawObjects() ->count(); i++ )
        {
            object = m_Terrain->getDrawObjects() ->at( i );
            if ( typeid( *object ) == typeid( BB_Point ) )
            {
                if ( object->getObjectNr() == p1 )
                {
                    point1 = ( BB_Point* ) object;
                }
                else if ( object->getObjectNr() == p2 )
                {
                    point2 = ( BB_Point* ) object;
                }
                else if ( object->getObjectNr() == p3 )
                {
                    point3 = ( BB_Point* ) object;
                }
            }
        }

        if ( point1 != NULL && point2 != NULL && point3 != NULL )
        {
            BB_DrawObject * triangle = ( BB_DrawObject* ) new BB_Triangle( point1, point2, point3 );
            m_Terrain->getDrawObjects() ->append( triangle );

        }
        else
        {
            cout << "Fehler: BB_Triangle konnte nicht erstellt werden!" << endl;
            return false;
        }
    }

    m_CurrentText.clear();

    return true;
}


/*!
    \fn BB_XTerrainHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
 */
bool BB_XTerrainHandler::endElement( const QString& namespaceURI, const QString& localName, const QString& qName )
{
    // 	cout << "</" << qName.toStdString() << ">" << endl;
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
    else if ( qName == "bb_point" )
    {
        m_Object = NULL;
    }
    else if ( qName == "bb_triangle" )
    {
        m_Object = NULL;
    }


    return true;
}
