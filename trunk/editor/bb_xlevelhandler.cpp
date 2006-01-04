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

BB_XLevelHandler::BB_XLevelHandler( BB_Level* level ): BB_XHandler()
{
	if( level == NULL )
	{
		qDebug("BB_XLevelHandler benötigt ein Level  ");
		exit(1);
	}
	
	m_Level = level;
	
	m_DrawObjects = m_Level->getDrawObjects();
	
	m_Object = NULL;
	m_ScalePointIndex = 0;
	m_XLevelTag = false;
	m_XScale = false;
}


BB_XLevelHandler::~BB_XLevelHandler()
{
}


bool BB_XLevelHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
{
	cout << "BB_XLevelHandler::endElement(" << qName.toStdString() << ") - Start" << endl;
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
	cout << "BB_XLevelHandler::endElement(" << qName.toStdString() << ") - Ende" << endl;
	return true;

}

bool BB_XLevelHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
{
	cout << "BB_XLevelHandler::startElement(" << qName.toStdString() << ") - Start" << endl;
    // 	return QXmlDefaultHandler::startElement(namespaceURI, localName, qName, atts);

    // 	cout << "event: " << namespaceURI.toStdString() << " | " << localName.toStdString() << " | " << qName.toStdString() << endl;

	if ( !m_XLevelTag && qName != "bb_level" )
	{
		m_ErrorStr = QObject::tr( "Dies ist keine gültige bb_level Datei" );
        // 		cout << m_ErrorStr.toStdString() << endl;
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
		bool ok;
		QString tmp;
		double value;
		
		tmp = atts.value( "value" );
		value = tmp.toDouble( &ok );
		
		m_Level->setScaleReal( value );
		
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

			m_ScalePointIndex++;
		}
		else
		{
			m_DrawObjects->append( m_Object );
		}

	}
	else if ( qName == "bb_wall" )
	{

		bool ok;
		QString tmp;
		BB_Point *point1 = NULL;
		BB_Point *point2 = NULL;
		double p1, p2;
		int id;

		tmp = atts.value( "id" );
		id = tmp.toInt( &ok );

		tmp = atts.value( "p1" );
		p1 = tmp.toDouble( &ok );

		tmp = atts.value( "p2" );
		p2 = tmp.toDouble( &ok );

		BB_Object *object;

		for ( int i = 0; i < m_DrawObjects->count(); i++ )
		{
			object = m_DrawObjects->at( i );
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
			}
		}

		if ( point1 != NULL && point2 != NULL )
		{
			m_Object = ( BB_DrawObject* ) new BB_Wall( point1, point2 );
			m_DrawObjects->append( m_Object );
			( ( BB_Wall* ) m_Object ) ->setPos2( point2 );

		}
		else
		{
			qDebug("Fehler: BB_Wall konnte nicht erstellt werden!");
			return false;
		}


	}
    // 	else if(qName == "levels")
    // 	{
    // 		m_Path = m_Doc->getFilePath();
    // 		m_Path.cd("levels");
    // 	}

	m_CurrentText.clear();
	cout << "BB_XLevelHandler::startElement(" << qName.toStdString() << ") - Ende" << endl;
	return true;
}

