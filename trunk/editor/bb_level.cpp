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
#include "bb_level.h"
#include "bb_building.h"

#include <bb_dlgleveledit.h>
#include <bb_xlevelhandler.h>
#include <bb_leveltriangle.h>

#include <iostream>

using namespace std;


/**
 * Konstrucktor<br />
 * Erstellt eine neue Etage
 * @param building Gebäude, welchem die Etage zugeteilt wird.
 * @param path Pfad zur Datei
 * @param fileName Dateiname
 * @param name Etagen-Name
 * @author Alex Letkemann
 */
BB_Level::BB_Level( BB_Building* building, const QDir& path, const QString &fileName, const QString &name )
        : BB_DocComponent( path, fileName, name )
{
	if( building == NULL )
	{
		qDebug( "BB_Level kann nicht ohne building initialisiert werden." );
		exit(1);
	}
	
	m_Building = building;
	m_Building->addLevel(this);
	
	m_Handler = new BB_XLevelHandler(this );
	
    //Standart Hoehe
	m_Height = 3.0;
	m_ScaleValue = building->getScaleReal();
	m_ScalePoint_1 = building->getScalePoint_1();
	m_ScalePoint_2 = building->getScalePoint_2();
}

/**
 * Destruktor
 */
BB_Level::~BB_Level()
{
	m_Building->removeLevel(this);
}


/**
 * \fn BB_Object::getClassName()
 */
const QString BB_Level::getClassName()
{
    return QString( "BB_Level" );
}

/**
 * Gibt die Höhe zurück
 * @return Höhe der Etage
 * @author Alex Letkemann
 */
double BB_Level::getHeight() const
{
    return m_Height;
}

/**
 * Setzt die Höhe der Etage
 * @param Value Höhe der Etage
 * @author Alex Letkemann
 */
void BB_Level::setHeight( double Value )
{
    m_Height = Value;
}


/**
 * Gibt das Gebäude zurück, welchem die Etage zugehört.
 * @return Gebäude
 * @author Alex Letkemann
 */
BB_Building* BB_Level::getBuilding()
{
	return m_Building;
}

/**
 * \fn BB_DocComponent::keyBoardEdit( QWidget* parent )
 */
int BB_Level::keyBoardEdit( QWidget* parent )
{
	QImage image;
	
	int result;
	bool exit = false;

	BB_DlgLevelEdit dlg(parent);
	
	dlg.setName(getName());
	dlg.setDescription(getDescription());
	
	QString planFile(m_FilePath.path() + QDir::separator() + m_MapFileName);
	dlg.setPlanFile( planFile );
	
	do
	{
	
		result = dlg.exec();
		/* Falls Abbrechen gedrückt wurde: raus. */
		if(result == QDialog::Rejected)
		{
			return false;
		}
		
		if(dlg.getName().isEmpty())
		{
			QMessageBox::critical(NULL,"Fehler",QString::fromUtf8("Sie müssen einen Namen für das Gelände angeben."));
		}
		else if(!image.load(dlg.getPlanFile()))
		{
			QMessageBox::critical(NULL,"Fehler",QString::fromUtf8("Sie müssen eine gültige Bilddatei als Plan angeben."));
		}
		else
		{
			/* Falls alles gut ist */
			exit = 1;
		}
			
	} while(result != QDialog::Rejected && !exit);
	
	setName(dlg.getName());
	setDescription(dlg.getDescription());
	
	m_MapFileName.sprintf("%08d.png",getObjectNr());
	
	image.save(m_FilePath.path() + QDir::separator() + m_MapFileName,"PNG");
	
	setMap(QPixmap::fromImage(image));
	
	parent->update();
	getListWidgetItem()->setText(getName());
	return result;
}


/**
 * Erstellt den 'bb_level' XML-Element
 * @param out Stream, in den geschrieben werden soll-.
 * @param depth Eirückung
 * @author Alex Letkemann
 */
void BB_Level::generateXElement( QTextStream &out, int depth )
{
	out << BB::indent( depth ) 
			<< "<" << getClassName().toLower() << " id=\"" << getObjectNr() 
			<< "\" building=\"" << m_Building->getObjectNr() << "\" >" 
			<< BB::escapedText( getFileName() ) 
			<< "</" << getClassName().toLower() << ">\n";
}


/**
 * \fn BB_FileObject::write( QTextStream &out )
 */
bool BB_Level::write( QTextStream &out )
{
	int depth = 1;

	QVector<BB_DrawObject*> points;
	QVector<BB_DrawObject*> walls;
	QVector<BB_DrawObject*> triangles;

	BB_DrawObject* object;

	for ( int i = 0; i < m_DrawObjects.count(); i++ )
	{
		object = m_DrawObjects.at( i );

		if ( typeid( *object ) == typeid( BB_Point ) )
		{
			points.append( object );
		}
		else if ( typeid( *object ) == typeid( BB_Wall ) )
		{
			walls.append( object );
		}
		else if( typeid( *object ) == typeid( BB_LevelTriangle ) )
		{
			triangles.append( object );
		}
		else
		{
			cout << "Unbekanntes Objekt gefunden: " << typeid( *object ).name() << endl;
		}
	}



	out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
			<< "<!DOCTYPE bb_level>\n"
			<< "<bb_level version=\"1.0\">\n";
	BB_Object::generateXElement( out, depth );
	out << BB::indent( depth ) << "<mapfile>" << m_MapFileName << "</mapfile>\n";
// 	out << BB::indent( depth ) << "<scale value=\"" << m_ScaleValue << "\">\n";
// 	m_ScalePoint_1.generateXElement( out, depth + 1 );
// 	m_ScalePoint_2.generateXElement( out, depth + 1 );
// 	out << BB::indent( depth ) << "</scale>\n";

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
	
	if( triangles.count() )
	{
		out << BB::indent( depth) << "<triangles>\n";
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

	out << "</bb_level>\n";
	return true;
}


/**
 * Erzeugt das 3D-Model der Etage.
 * Das Model wird komplett aus Dreiecken erstellt, welche an den übergebene Vektor 'triangles' angehängt wird.
 * @param triangles Vektor, an den die Dreiecke angehängt werden.
 * @param vector Positionvektor
 * @param rotation Rotation der Etage in Grad
 * @param scale Maßstab
 * @param height Höhe eines Meters in Pixel
 */
void BB_Level::createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height )
{
	for( int i = 0; i < m_DrawObjects.count(); i++ )
	{
		m_DrawObjects.at( i )->createGl( triangles, vector ,rotation , scale, m_Height * height  );
	}
}
