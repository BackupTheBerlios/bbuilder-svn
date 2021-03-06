/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
***************************************************************************/
#include "bb_building.h"
#include "bb_dlgbuildingedit.h"

#include "bb_xbuildinghandler.h"


#include "bb_line.h"
#include "bb_wall.h"
#include <bb_buildingtriangle.h>
#include "bb_stair.h"

#include <iostream>

using namespace std;

/**
 * Konstruktor
 * @param path Verzeichnis, in dem gespeichert wird 
 * @param fileName  Dateiname, unter welchem gepeichert wird
 * @param name Gebäudename
 * @author Alex Letkemann
 */
BB_Building::BB_Building( const QDir& path, const QString &fileName, const QString &name )
        : BB_DocComponent( path, fileName, name )
{
    m_Handler = new BB_XBuildingHandler( this );
    m_ListWidgetItem = NULL;
}


/**
 * Destruktor 
 * @author Alex Letkemann
 */
BB_Building::~BB_Building()
{
}




/**
 * Rüft ein Dialog auf, mit welchem einige Eigenschaften des Gebäudes geändert werden können. 
 * @param parent Fenster, welches Blockiert wird, solange der Dialog offen ist.
 * @return Ergebnis des Dialoges
 * @author Alex Letkemann
 */
int BB_Building::keyBoardEdit( QWidget* parent )
{
    QImage image;

    int result;
    bool exit = false;

    BB_DlgBuildingEdit dlg( parent );

    dlg.setName( getName() );
    dlg.setDescription( getDescription() );

    QString planFile( m_FilePath.path() + QDir::separator() + m_MapFileName );
    dlg.setPlanFile( planFile );

    do
    {

        result = dlg.exec();
        /* Falls Abbrechen gedrückt wurde: raus. */
        if ( result == QDialog::Rejected )
        {
            return false;
        }

        if ( dlg.getName().isEmpty() )
        {
            QMessageBox::critical( NULL, "Fehler", QString::fromUtf8( "Sie müssen einen Namen für das Gebäudes angeben." ) );
        }
        else if ( !image.load( dlg.getPlanFile() ) )
        {
            QMessageBox::critical( NULL, "Fehler", QString::fromUtf8( "Sie müssen eine gültige Bilddatei als Plan angeben." ) );
        }
        else
        {
            /* Falls alles gut ist */
            exit = 1;
        }

    }
    while ( result != QDialog::Rejected && !exit );

    setName( dlg.getName() );
    setDescription( dlg.getDescription() );

    m_MapFileName.sprintf( "%08d.png", getObjectNr() );

    image.save( m_FilePath.path() + QDir::separator() + m_MapFileName, "PNG" );

    setMap( QPixmap::fromImage( image ) );

    parent->update();
    
	setModified( true );
	
    return result;
}


/**
 * Schreibt das Gebäude in Form von XML in den übergebenen Stream 'out'.
 * @param out Stream, in welchen geschrieben wird.
 * @return Erfolg des Schreibens
 * @author Alex Letkemann
 */
bool BB_Building::write( QTextStream &out )
{
    int depth = 1;

	QVector<BB_DrawObject*> points;
	QVector<BB_DrawObject*> walls;
	QVector<BB_DrawObject*> triangles;
	QVector<BB_DrawObject*> stairs;

	BB_DrawObject* object;

	// Objekte auf mehrere Vektoren aufteilen
    for ( int i = 0; i < m_DrawObjects.count(); i++ )
    {
        object = m_DrawObjects.at( i );

        if ( typeid( *object ) == typeid( BB_Point ) )
        {
            points.append( ( BB_Point* ) object );
        }
        else if ( typeid( *object ) == typeid( BB_Wall ) )
        {
            walls.append( ( BB_Wall* ) object );
        }
		else if( typeid(*object) == typeid( BB_BuildingTriangle ) )
		{
			triangles.append( object );
		}
		else if ( typeid( *object ) == typeid( BB_Stair ) )
		{
			stairs.append( ( BB_Stair* ) object );
		}
        else
        {
            cout << "Unbekanntes Objekt gefunden: " << typeid( *object ).name() << endl;
        }
    }


	
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    << "<!DOCTYPE bb_building>\n"
    << "<bb_building version=\"1.0\">\n";
    BB_Object::generateXElement( out, depth );
    out << BB::indent( depth ) << "<mapfile>" << m_MapFileName << "</mapfile>\n";
    out << BB::indent( depth ) << "<scale value=\"" << m_ScaleValue << "\">\n";
    m_ScalePoint_1->generateXElement( out, depth + 1 );
    m_ScalePoint_2->generateXElement( out, depth + 1 );
    out << BB::indent( depth ) << "</scale>\n";

	
	// Knoten speichern
    if ( points.count() )
    {
        out << BB::indent( depth ) << "<points>\n";

        for ( int i = 0; i < points.count(); i++ )
        {
            points.at( i ) ->generateXElement( out, depth + 1 );
        }

        out << BB::indent( depth ) << "</points>\n";
    }
    else
    {
        out << "<points />";
    }

	// Wände speichern
    if ( walls.count() )
    {
        out << BB::indent( depth ) << "<walls>\n";

        for ( int i = 0; i < walls.count(); i++ )
        {
            walls.at( i ) ->generateXElement( out, depth + 1 );
        }

        out << BB::indent( depth ) << "</walls>\n";
    }
    else
    {
        out << BB::indent( depth ) << "<walls />\n";
    }

	// Flächen speichern
	if( triangles.count() )
	{
		out << BB::indent( depth ) << "<triangles>\n";

		for ( int i = 0; i < triangles.count(); i++ )
		{
			triangles.at( i ) ->generateXElement( out, depth + 1 );
		}

		out << BB::indent( depth ) << "</triangles>\n";
	}
	else
	{
		out << BB::indent( depth ) << "<triangles />\n";
	}
	
	// Treppen speichern
	if ( stairs.count() )
	{
		out << BB::indent( depth ) << "<stairs>\n";

		for ( int i = 0; i < stairs.count(); i++ )
		{
			stairs.at( i ) ->generateXElement( out, depth + 1 );
		}

		out << BB::indent( depth ) << "</stairs>\n";
	}
	else
	{
		out << BB::indent( depth ) << "<stairs />\n";
	}

    out << "</bb_building>\n";
    return true;
}

/**
 * \fn BB_Object::getClassName()
 */
const QString BB_Building::getClassName()
{
    return QString( "BB_Building" );
}




/**
 * Löscht alle Dateien des Gebäudes
 * @author Alex Letkemann
 */
void BB_Building::remove()
{
    QString xmlFile, pngFile, name;
    name.sprintf( "%08d.png", getObjectNr() );

    xmlFile = m_FilePath.path() + QDir::separator() + m_FileName;
    pngFile = m_FilePath.path() + QDir::separator() + name;

    cout << xmlFile.toStdString() << endl;
    cout << pngFile.toStdString() << endl;

    QFile::remove( xmlFile );
    QFile::remove( pngFile );
}



/**
 * Fügt die übergebene Etage dem Gebäude hinzu.
 * @param level Etage, die dem Gebäude hinzugefügt werden soll.
 * @author Alex Letkemann
 */
void BB_Building::addLevel( BB_Level* level )
{
	if( level != NULL && level->getBuilding() == this )
	{
		m_Levels.append( level );
	}
}


/**
 * Gibt den Vektor mit allen Etagen zurück.
 * @return Vektor mit allen Etagen.
 * @author Alex Letkemann
 */
QVector<BB_Level*>* BB_Building::getLevels()
{
	return &m_Levels;
}


/**
 * Entfernt die übergebene Etage aus dem Gebäude.
 * @param level Etage, die aus dem gebäude entfernt werden soll.
 * @author Alex Letkemann
 */
void BB_Building::removeLevel( BB_Level* level )
{
	for( int i = m_Levels.count() -1 ; i >= 0; i--)
	{
		if( m_Levels.at(i) == level )
		{
			m_Levels.remove( i );
		}
	}
}


/**
 * Gibt die Etage nach ihrem Index zurück.
 * @param index Index der Etage.
 * @return Pointer auf die Etage, falls diese Existiert sonst NULL.
 * @author Alex Letkemann
 */
BB_Level* BB_Building::getLevel( int index )
{

	int count =  m_Levels.count();
	
	if( index < count && index >= 0 )
	{
		return m_Levels.at( index );
	}
	
	return NULL;
}


/**
 * Gibt die Anzahl der Etagen im Gebäude zurück.
 * @return Anzahl der Etagen im Gebäude.
 * @author Alex Letkemann
 */
int BB_Building::getLevelCount()
{
	int count = m_Levels.count();
	return count;
}


/**
 * Gibt die Höhe des Gebäudes zurück.
 * @return Höhe des Gebäudes.
 * @author Alex Letkemann
 */
double BB_Building::getHeight() const 
{
	double height = 0;
	
	for(int i = 0; i < m_Levels.count(); i++)
	{
		height += m_Levels.at( i )->getHeight();
	}
	
	return height;
}


/**
 * Erzeugt die 3D Ansicht des Gebäudes.<br>
 * Die 3D Ansicht wird komplett aus Dreiecken erzeugt. Die Erzeugten Dreiecke werden an den üergeben Vektor 'triangles' angehängt.
 * @param triangles Vektor, an den die Dreiecke angehängt werden.
 * @param vector Vektor zur Positionierung des Gebäudes.
 * @param rotation Rotation des Gebäudes in der Y-Achse
 * @param scale Skalierung des Gebäudes
 * @param height Hier keine Funktion
 * @author Alex Letkemann
 */
void BB_Building::createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height )
{
	double docScale = 1 / getPixelPerMeter( 1.0 );
	scale =  scale * docScale;
	height = 1.0;
	
	// Ausßenwände erzeugen
	qDebug( "getPixelPerMeter( getBuildingHeight() ): %f ", getPixelPerMeter( getHeight() ) );
	
	for( int i = 0; i < m_DrawObjects.count(); i++ )
	{
		m_DrawObjects.at( i )->createGl( triangles, vector, rotation, scale, getPixelPerMeter( getHeight() ) );
	}
	
	// Innenwände der Etagen erzeugen
	for( int i = 0; i < m_Levels.count(); i++ )
	{
		
		m_Levels.at( i )->createGl( triangles, vector, rotation, scale, getPixelPerMeter( 1.0 ) );
		vector.setY( vector.y() +  getPixelPerMeter( m_Levels.at(i)->getHeight() ) * scale );
	}
}


