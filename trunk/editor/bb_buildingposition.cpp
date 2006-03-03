//
// C++ Implementation: bb_buildingposition
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_buildingposition.h"
#include <bb_line.h>
#include <math.h>


/**
 * Konstrucktor. Erzeugt einene neuen Gebäudeposition.
 * Falls nur die ID des Gebäudes übergebene wird, kann die ID mit Hilfe von resolveBuildingId() aufgelöst werden.
 * @param building Das Gebäude
 * @param buildingId Id des Gebäudes
 * @param component Terrain
 * @param pos Positin des gebäudes.
 * @param height Höhe, in welcher das Gebäude dargestellt wird. Es is NICHT die Höhe des Gebäudes.
 * @param angle Rotation des Gebäudes auf der Y-Achse in Grad
 * @author Alex Letkemann
 */
BB_BuildingPosition::BB_BuildingPosition( BB_Building* building, int  buildingId, BB_DocComponent* component, C2dVector& pos, double height, double angle ) : BB_TerrainPoint()
{
    if ( component == NULL )
    {
        qDebug( "BB_BuildingPosition::BB_BuildingPosition( BB_DocComponent* component == NULL ): NULL-Pointer erhalten" );
    }
    m_Building = building;
	m_BuildingId = buildingId;
	
	if( m_Building != NULL )
	{
		m_BuildingId = m_Building->getObjectNr();
	}
    m_ParentDocComponent = component;

    if ( &pos == NULL )
    {
        setPos( C2dVector( 0.0, 0.0 ) );
    }
    else
    {
        setPos( pos );
    }
    setHeight( height );
    setRotation( angle );
}

/**
 * Destruktor
 * @author Alex Letkemann
 */
BB_BuildingPosition::~BB_BuildingPosition()
{}

/**
 * Zeichnet (2D) das Gebäude auf dem Gelände
 * @param transformer Transformer, welcher verwendet werden soll.
 * @param painter Painter, welcher verwendet werden soll.
 * @author Alex Letkemann
 */
void BB_BuildingPosition::show( BB_Transformer& transformer, QPainter& painter ) const
{

    BB_Point::show( transformer, painter );

    if ( m_Building != NULL )
    {
        painter.save();
        QPoint p;
        transformer.logicalToScreen( p, m_Pos );
        painter.translate( p );
        painter.rotate( m_Rotation );

        C2dVector oldOffset = transformer.getOffset();
        double oldScale = transformer.getScale();

        transformer.setOffset( C2dVector( 0.0, 0.0 ) );
        double scale = m_Building->getMeterPerPixel( 100 ) / m_ParentDocComponent->getMeterPerPixel( 100 );
        transformer.setScale( scale * oldScale );
        // 	painter.scale( scale, scale);

        if ( m_Building != NULL )
        {
            BB_DrawObject * object;
            BB_Line *line;
            for ( int i = 0; i < m_Building->getDrawObjects() ->count(); i++ )
            {
                object = m_Building->getDrawObjects() ->at( i );

                line = dynamic_cast<BB_Line*>( object );
                if ( line != NULL )
                {
                    line->show( transformer, painter );
                }
            }
        }

        transformer.setOffset( oldOffset );
        transformer.setScale( oldScale );
        painter.restore();
    }


}

/**
 * \fn BB_Object::getClassName() 
 */
const QString BB_BuildingPosition::getClassName()
{
    return QString( "BB_BuildingPosition" );
}

/**
 * Erzeugt das 'bb_buildingposition' XML-Element
 * @param out Stream, in den geschrieben werden soll.
 * @param depth Einrückung
 * @author Alex Letkemann
 */
void BB_BuildingPosition::generateXElement( QTextStream& out, int depth )
{
    if ( m_Building != NULL )
    {
        out << BB::indent( depth ) << "<bb_buildingposition id=\"" << getObjectNr()
        << "\" x=\"" << getPos().x()
        << "\" y=\"" << getPos().y()
        << "\" height=\"" << getHeight()
        << "\" building=\"" << m_Building->getObjectNr()
        << "\" angle=\"" << getRotation()
        << "\" >" << endl;
        BB_Object::generateXElement( out, depth + 1 );
        out << BB::indent( depth ) << "</bb_buildingposition>" << endl;
    }
}


/**
 * Gibt die Rotation des Gebäudes zurück.
 * @return Rotation des Gebäudes in Grad.
 * @author Alex Letkemann
 */
double BB_BuildingPosition::getRotation() const
{
    return m_Rotation;
}

/**
 * Setzt die Rotation des Gebäudes an der Y-Achse in Grad
 * @param value Winkel zur Y-Achse
 * @author Alex Letkemann
 */
void BB_BuildingPosition::setRotation( double value )
{
    m_Rotation = value;
}


/**
 * Löst die ID des Gebäudes auf und übernimmt das Gebäude mit der bekannten ID.
 * @param doc Dokument, welches die Gebäude enthält.
 * @author Alex Letkemann
 */
void BB_BuildingPosition::resolveBuildingId( BB_Doc * doc )
{
	BB_Building* building = NULL;
	if( m_Building == NULL && doc != NULL )
	{
		building = doc->getBuildingById( m_BuildingId );
		if( building != NULL )
		{
			m_Building = building;
		}
	}
}


/**
 * Gibt das Gebäude zurück.
 * @return Gebäude. Falls die ID noch nicht aufgelöst wurde, wird NULL zurückggeben.
 * @author Alex Letkemann
 */
BB_Building* BB_BuildingPosition::getBuilding() const
{
    return m_Building;
}


/**
 * Erzeugt die 3D Ansicht des Gebäudes.<br>
 * Die 3D Ansicht wird komplett aus Dreiecken erzeugt. Die Erzeugten Dreiecke werden an den üergeben Vektor 'triangles' angehängt.
 * @param triangles Vektor, an den die Dreiecke angehängt werden.
 * @param vector Hier keine Funktion
 * @param rotation Hier keine Funktion
 * @param scale Skalierung des Gebäudes
 * @param height Hier keine Funktion
 * @author Alex Letkemann
 */
void BB_BuildingPosition::createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height )
{
	double docScale = scale;
	scale = scale * 1/m_ParentDocComponent->getMeterPerPixel( 1 );
	C3dVector v( m_Pos.x() * docScale , m_Height * docScale , m_Pos.y() * docScale );
	if( m_Building != NULL )
	{
		m_Building->createGl( triangles,v, m_Rotation, scale, 0.0 );
	}
	
}
