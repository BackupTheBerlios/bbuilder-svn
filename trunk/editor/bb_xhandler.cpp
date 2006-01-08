//
// C++ Implementation: bb_xhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xhandler.h"
#include "QMessageBox"

#include <iostream>

#include <bb_point.h>
#include <bb_terrainpoint.h>
#include <bb_drawobject.h>
#include <bb_triangle.h>
#include <bb_terraintriangle.h>
#include <bb_leveltriangle.h>
#include <bb_buildingtriangle.h>
#include "bb_wall.h"
#include "bb_window.h"
#include "bb_stair.h"

using namespace std;


BB_XHandler::BB_XHandler(BB_DocComponent*  docComponent)
 : QXmlDefaultHandler()
{
	if( docComponent == NULL )
	{
		qDebug( "BB_XHandler(BB_DocComponent*  docComponent): NULL-Pointer erhalten" );
	}
	
	m_DocComponent = docComponent;
	m_Object = NULL;
	m_ConstructionElement = NULL;
	m_XScale = false;
	m_ScalePointIndex = 0;
	
	
}


BB_XHandler::~BB_XHandler()
{
}


bool BB_XHandler::characters(const QString& ch)
{
	m_CurrentText += ch;
	return true;
}

/**
 * Wird aufgeruffen, wenn während des Parsens ein Fehler auftritt.
 * Dier Fehler wird im std::cout ausgegeben
 */
bool BB_XHandler::fatalError(const QXmlParseException& exception)
{
	
	QString errorString = QObject::tr("Parse error at line %1, column %2:\n%3")
									.arg(exception.lineNumber())
									.arg(exception.columnNumber())
									.arg(exception.message());
	cout << "XML-Fehler: " << errorString.toStdString() << endl;
	return false;
}


/*!
    \fn BB_XHandler::parseTexture( QXmlAttributes& atts )
 */
bool BB_XHandler::parseTexture( const QXmlAttributes& atts )
{
	if ( m_Object == NULL )
	{
		qDebug( "Texture nicht im <BB_DrawObject>" );
		return false;
	}
	if ( m_ConstructionElement != NULL )
	{
		m_ConstructionElement->setTextureFileName( atts.value( "file" ) );
	}
	else
	{
		qDebug() << atts.value( "file" );
		m_Object->setTextureFileName( atts.value( "file" ) );
	}
	
	return true;
}


/*!
    \fn BB_XHandler::parseTriangle( const QXmlAttributes& atts )
 */
bool BB_XHandler::parseTriangle( const QXmlAttributes& atts )
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

	for ( int i = 0; i < m_DocComponent->getDrawObjects() ->count(); i++ )
	{
		object = m_DocComponent->getDrawObjects() ->at( i );
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
		m_DocComponent->getDrawObjects() ->append( triangle );

	}
	else
	{
		cout << "Fehler: BB_Triangle konnte nicht erstellt werden!" << endl;
		return false;
	}
	
	return true;
}


/*!
    \fn BB_XHandler::parseTerrainTriangle( QXmlAttributes& atts )
 */
bool BB_XHandler::parseTerrainTriangle( const QXmlAttributes& atts )
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

	for ( int i = 0; i < m_DocComponent->getDrawObjects() ->count(); i++ )
	{
		object = m_DocComponent->getDrawObjects() ->at( i );
		if ( typeid( *object ) == typeid( BB_TerrainPoint ) )
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
		m_Object = ( BB_DrawObject* ) new BB_TerrainTriangle( point1, point2, point3 );
		m_DocComponent->getDrawObjects() ->append( m_Object );

	}
	else
	{
		cout << "Fehler: BB_TerrainTriangle konnte nicht erstellt werden!" << endl;
		return false;
	}
	
	return true;
}



bool BB_XHandler::parsePoint( const QXmlAttributes& atts )
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

	m_Object = new BB_Point();
	( ( BB_Point* ) m_Object ) ->setX( x );
	( ( BB_Point* ) m_Object ) ->setY( y );
// 	( ( BB_TerrainPoint* ) m_Object ) ->setHeight( h );
	m_Object->m_ObjectNr = id;
	m_Object->setSelected( false );

	if ( m_XScale )
	{
		
		if ( m_ScalePointIndex == 0 )
		{
			m_DocComponent->getScalePoint_1() ->setX( x );
			m_DocComponent->getScalePoint_1() ->setY( y );
			
			m_ScalePointIndex = 1;
		}
		else if ( m_ScalePointIndex == 1 )
		{
			m_DocComponent->getScalePoint_2() ->setX( x );
			m_DocComponent->getScalePoint_2() ->setY( y );
			
			m_ScalePointIndex = 0;
		}
	}
	else
	{
		m_DocComponent->getDrawObjects() ->append( m_Object );
	}
	return true;	
}


bool BB_XHandler::parseTerrainPoint( const QXmlAttributes& atts )
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


		m_DocComponent->getDrawObjects() ->append( m_Object );
		
		
		return true;
}



/*!
    \fn BB_XHandler::parseLevelTriangle( const QXmlAttributes& atts )
 */
bool BB_XHandler::parseLevelTriangle( const QXmlAttributes& atts )
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

	for ( int i = 0; i < m_DocComponent->getDrawObjects() ->count(); i++ )
	{
		object = m_DocComponent->getDrawObjects() ->at( i );
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
		BB_DrawObject * triangle = ( BB_DrawObject* ) new BB_LevelTriangle( point1, point2, point3 );
		m_DocComponent->getDrawObjects() ->append( triangle );

	}
	else
	{
		cout << "Fehler: BB_Triangle konnte nicht erstellt werden!" << endl;
		return false;
	}
	
	return true;
}


/*!
    \fn BB_XHandler::parseBuildingTriangle( const QXmlAttributes& atts )
 */
bool BB_XHandler::parseBuildingTriangle( const QXmlAttributes& atts )
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

	for ( int i = 0; i < m_DocComponent->getDrawObjects() ->count(); i++ )
	{
		object = m_DocComponent->getDrawObjects() ->at( i );
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
		BB_DrawObject * triangle = ( BB_DrawObject* ) new BB_BuildingTriangle( point1, point2, point3 );
		m_DocComponent->getDrawObjects() ->append( triangle );

	}
	else
	{
		cout << "Fehler: BB_Triangle konnte nicht erstellt werden!" << endl;
		return false;
	}
	
	return true;
}

bool BB_XHandler::parseWindow(const QXmlAttributes& atts){
	if ( typeid( *m_Object ) != typeid( BB_Wall ) )
	{
		qDebug( "BB_Window kann nicht erstellt werden, es ligt kein BB_Wall vor" );
		return false;
	}

	QString tmp;
	int id;
	bool ok;

	C2dVector v1;
	C2dVector v2;

	C2dVector pv1;
	C2dVector pv2;
		
	C2dVector cv1;
	C2dVector cv2;

	tmp = atts.value( "id" );
	id = tmp.toInt( &ok );

	tmp = atts.value( "x1" );
	v1.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "y1" );
	v1.setY( tmp.toDouble( &ok ) );

	tmp = atts.value( "px1" );
	pv1.setX( tmp.toInt( &ok ) );
	tmp = atts.value( "py1" );
	pv1.setY( tmp.toInt( &ok ) );
		
	tmp = atts.value( "cx1" );
	cv1.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "cy1" );
	cv1.setY( tmp.toDouble( &ok ) );

	tmp = atts.value( "x2" );
	v2.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "y2" );
	v2.setY( tmp.toDouble( &ok ) );

	tmp = atts.value( "px2" );
	pv2.setX( tmp.toInt( &ok ) );
	tmp = atts.value( "py2" );
	pv2.setY( tmp.toInt( &ok ) );
		
	tmp = atts.value( "cx2" );
	cv2.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "cy2" );
	cv2.setY( tmp.toDouble( &ok ) );

	m_ConstructionElement = new BB_Window( v1, v2 );
	m_ConstructionElement->setWallPosition1( pv1 );
	m_ConstructionElement->setWallPosition2( pv2 );
	m_ConstructionElement->setCoefficientPos1(cv1);
	m_ConstructionElement->setCoefficientPos2(cv2);
	m_ConstructionElement->m_ObjectNr = id;

}

bool BB_XHandler::parseDoor(const QXmlAttributes& atts){
	if ( typeid( *m_Object ) != typeid( BB_Wall ) )
	{
		qDebug( "BB_Door kann nicht erstellt werden, es ligt kein BB_Wall vor" );
		return false;
	}

	QString tmp;
	int id;
	bool ok;

	C2dVector v1;
	C2dVector v2;

	C2dVector pv1;
	C2dVector pv2;
		
	C2dVector cv1;
	C2dVector cv2;

	tmp = atts.value( "id" );
	id = tmp.toInt( &ok );

	tmp = atts.value( "x1" );
	v1.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "y1" );
	v1.setY( tmp.toDouble( &ok ) );

	tmp = atts.value( "px1" );
	pv1.setX( tmp.toInt( &ok ) );
	tmp = atts.value( "py1" );
	pv1.setY( tmp.toInt( &ok ) );
		
	tmp = atts.value( "cx1" );
	cv1.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "cy1" );
	cv1.setY( tmp.toDouble( &ok ) );

	tmp = atts.value( "x2" );
	v2.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "y2" );
	v2.setY( tmp.toDouble( &ok ) );

	tmp = atts.value( "px2" );
	pv2.setX( tmp.toInt( &ok ) );
	tmp = atts.value( "py2" );
	pv2.setY( tmp.toInt( &ok ) );
		
	tmp = atts.value( "cx2" );
	cv2.setX( tmp.toDouble( &ok ) );
	tmp = atts.value( "cy2" );
	cv2.setY( tmp.toDouble( &ok ) );

	m_ConstructionElement = new BB_Door( v1, v2 );
	m_ConstructionElement->setWallPosition1( pv1 );
	m_ConstructionElement->setWallPosition2( pv2 );
	m_ConstructionElement->setCoefficientPos1(cv1);
	m_ConstructionElement->setCoefficientPos2(cv2);
	m_ConstructionElement->m_ObjectNr = id;

}

bool BB_XHandler::parseStair(const QXmlAttributes& atts){
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

	for ( int i = 0; i < m_DocComponent->getDrawObjects()->count(); i++ )
	{
		object = m_DocComponent->getDrawObjects()->at( i );
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
		m_Object =  new BB_Stair();
		( ( BB_Stair* ) m_Object ) ->setPos1( point1 );
		( ( BB_Stair* ) m_Object ) ->setPos2( point2 );
		m_DocComponent->getDrawObjects()->append( m_Object );

	}
	else
	{
		qDebug() << "Fehler: BB_Stair konnte nicht erstellt werden!" << endl;
		return false;
	}
}

bool BB_XHandler::parseWall(const QXmlAttributes& atts){
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

	for ( int i = 0; i < m_DocComponent->getDrawObjects()->count(); i++ )
	{
		object = m_DocComponent->getDrawObjects()->at( i );
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
		m_DocComponent->getDrawObjects()->append( m_Object );
		( ( BB_Wall* ) m_Object ) ->setPos2( point2 );

	}
	else
	{
		qDebug() << "Fehler: BB_Wall konnte nicht erstellt werden!" << endl;
		return false;
	}
}

bool BB_XHandler::parseScale(const QXmlAttributes& atts){
	bool ok;
	QString tmp;
	double value;

	tmp = atts.value( "value" );
	value = tmp.toDouble( &ok );

	m_DocComponent->setScaleReal( value );

	m_XScale = true;
}
