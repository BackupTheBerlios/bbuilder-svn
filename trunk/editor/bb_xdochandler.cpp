//
// C++ Implementation: bb_xdochandler
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xdochandler.h"
#include "bb_doc.h" 
// #include <bb_object.h>

#include <iostream>

using namespace std;


/**
 * Konstruktor
 * @param doc Dokument, in dem die Daten gespeichert werden.
 */
BB_XDocHandler::BB_XDocHandler( BB_Doc* doc )
        : BB_XHandler( NULL )
{
    if ( doc != NULL )
    {
        m_Doc = doc;
    }

    m_XDocTag = false;
    m_ObjectId = 0;
}


/**
 * Destruktor
 */
BB_XDocHandler::~BB_XDocHandler()
{}


/**
 * @fn BB_XDocHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
 */
bool BB_XDocHandler::startElement( const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts )
{

    QString value;
    bool ok;
    int intValue;

    if ( !m_XDocTag && qName != "bb_doc" )
    {
        m_ErrorStr = QObject::tr( "Dies ist keine glbb Datei" );
        return false;
    }

    if ( qName == "bb_doc" )
    {
        QString version = atts.value( "version" );
        if ( !version.isEmpty() && version != "1.0" )
        {
            m_ErrorStr = QObject::tr( "Die ist keine glbb Datei der Version 1.0." );
            return false;
        }
        m_XDocTag = true;
    }
    else if ( qName == "properties" )
    {
        QString sMaxId = atts.value( "max_id" );
        int maxId;
        bool ok;

        maxId = sMaxId.toInt( &ok );

        if ( ok )
        {
            m_Doc->m_MaxId = maxId;
        }
        else
        {
            return false;
        }


    }
    else if ( qName == "bb_terrain" )
    {
        m_Path = m_Doc->getFilePath();
        m_Path.cd( "terrain" );

        value = atts.value( "id" );

        intValue = value.toInt( &ok );

        if ( ok )
        {
            m_ObjectId = intValue;
        }
        else
        {
            return false;
        }

    }
    else if ( qName == "buildings" )
    {
        m_Path = m_Doc->getFilePath();
        m_Path.cd( "buildings" );
    }
    else if ( qName == "bb_building" )
    {

        value = atts.value( "id" );

        intValue = value.toInt( &ok );

        if ( ok )
        {
            m_ObjectId = intValue;
        }
        else
        {
            return false;
        }
    }
    else if ( qName == "levels" )
    {
        // Verzeichnis ändern
        m_Path = m_Doc->getFilePath();
        m_Path.cd( "levels" );

    }
    else if ( qName == "bb_level" )
    {

        value = atts.value( "id" );

        intValue = value.toInt( &ok );

        if ( ok )
        {
            m_ObjectId = intValue;
        }
        else
        {
            return false;
        }

        value = atts.value( "building" );
        intValue = value.toInt( &ok );

        if ( ok )
        {
            m_BuidingNr = intValue;
        }
        else
        {
            return false;
        }
    }

    m_CurrentText.clear();

    return true;
}


/**
 * @fn BB_XDocHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
 */
bool BB_XDocHandler::endElement( const QString& namespaceURI, const QString& localName, const QString& qName )
{
    BB_Terrain * terrain;
    BB_Building* building;
    BB_Level* level;

    if ( qName == "name" )
    {
        m_Doc->setName( m_CurrentText );

    }
    else if ( qName == "description" )
    {
        m_Doc->setDescription( m_CurrentText );

    }
    else if ( qName == "bb_terrain" )
    {
        if ( m_Doc->getTerrain() == NULL )
        {
            terrain = m_Doc->newTerrain( m_Path, m_CurrentText );
            terrain->m_ObjectNr = m_ObjectId;
        }
        else
        {
            m_Doc->getTerrain() ->setFileName( m_CurrentText );
            m_Doc->getTerrain() ->setFilePath( m_Path );
        }
    }
    else if ( qName == "bb_building" )
    {
        building = m_Doc->newBuilding( m_Path, m_CurrentText );
        building->m_ObjectNr = m_ObjectId;
    }
    else if ( qName == "bb_level" )
    {
        building = m_Doc->getBuildingById( m_BuidingNr );

        if ( building == NULL )
        {
            qDebug( "BB_XDocHandler: Level konnte nicht erstellt werden.\n Gebäude (%d) nicht gefunden.", m_ObjectId );
        }

        level = m_Doc->newLevel( building, m_Path, m_CurrentText );
        level->m_ObjectNr = m_ObjectId;
    }

    return true;

}
