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

#include <iostream>

using namespace std;

BB_Building::BB_Building( const QDir& path, const QString &fileName, const QString &name )
        : BB_DocComponent( path, fileName, name )
{
    m_Handler = new BB_XBuildingHandler( this );
    m_ListWidgetItem = NULL;
}


/**
 * Destruktor 
 */
BB_Building::~BB_Building()
{
}




/*!
    \fn BB_Building::keyBoardEdit(QWidget* parent)
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


/*!
    \fn BB_Building::write(QIODevice *device)
 */
bool BB_Building::write( QTextStream &out )
{
    int depth = 1;

    QVector<BB_Point*> points;
    QVector<BB_Wall*> walls;

    BB_Object* object;

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
    m_ScalePoint_1.generateXElement( out, depth + 1 );
    m_ScalePoint_2.generateXElement( out, depth + 1 );
    out << BB::indent( depth ) << "</scale>\n";

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

    out << "</bb_building>\n";
    return true;
}


/*!
    \fn BB_Building::generateXElement(QTextStream &out, int depth)
 */
void BB_Building::generateXElement( QTextStream &out, int depth )
{
    out << BB::indent( depth ) << "<bb_building>" << BB::escapedText( getFileName() ) << "</bb_building>\n";
}


/*!
    \fn BB_Building::getClassName()
 */
const QString BB_Building::getClassName()
{
    return QString( "BB_Building" );
}







/*!
    \fn BB_Building::remove()
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



/*!
    \fn BB_Building::addLevel( BB_Level* level )
 */
void BB_Building::addLevel( BB_Level* level )
{
	if( level != NULL && level->getBuilding() == this )
	{
		m_Levels.append( level );
	}
}


/*!
    \fn BB_Building::getLevels()
 */
QVector<BB_Level*>* BB_Building::getLevels()
{
	return &m_Levels;
}


/*!
    \fn BB_Building::removeLevel( BB_Level* level )
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


/*!
    \fn BB_Building::getLevel( int index )
 */
BB_Level* BB_Building::getLevel( int index )
{
	if( index < m_Levels.count() && index >= 0 )
	{
		return m_Levels.at( index );
	}
	
	return NULL;
}
