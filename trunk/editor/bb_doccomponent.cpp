//
// C++ Implementation: bb_doccomponent
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_doccomponent.h"

/**
 * Konstruktor
 * @param path Verzeichnis, in dem gespeichert wird 
 * @param fileName  Dateiname, unter welchem gepeichert wird
 * @param name Objektname
 */
BB_DocComponent::BB_DocComponent( const QDir& path, const QString &fileName, const QString &name )
        : BB_FileObject( path, fileName, name ), BB_Map(), BB_DrawDevice()
{
	m_ScalePoint_1 = new BB_Point();
	m_ScalePoint_2 = new BB_Point();
	
	m_ScalePoint_1->setX( 0.0 );
    m_ScalePoint_1->setY( 0.0 );

    m_ScalePoint_2->setX( 50.0 );
    m_ScalePoint_2->setY( -50.0 );

    m_ScaleValue = 5.0;
}


/**
 * Destruktor
 */
BB_DocComponent::~BB_DocComponent()
{}


/**
 * Führt die open() Funktion von BB_FileObject aus und
 * läd zusätztlich die Map Datei des Gebäudes.
 * @author Alex Letkemann
 * @date 13.12.2005
 */
bool BB_DocComponent::open()
{
    bool exit = ( BB_FileObject::open() && loadMap( m_FilePath ) );

    return exit;
}


/**
 * Gibt den Pointer auf den ersten Maßstab-Punkt zurück
 */
BB_Point* BB_DocComponent::getScalePoint_1()
{
    return m_ScalePoint_1;
}


/**
 * Gibt den Pointer auf den zweiten Maßstab-Punkt zurück
 */
BB_Point* BB_DocComponent::getScalePoint_2()
{
    return m_ScalePoint_2;
}

/**
 * Setzt den reelen Abstand zwischen den Maßstab-Punkten
 * @param value der reele Abstand zwischen den Maßstab-Punkten
 */
double BB_DocComponent::getScaleReal() const
{
    return m_ScaleValue;
}


/**
 * Gibt den Pointer auf den reelen Maßstab.
 * @return Pointer auf den reelen Maßstab.
 */
double* BB_DocComponent::getScaleRealPointer()
{
    return & m_ScaleValue;
}


/**
 * Setzt den reelen Abstand zwischen den Maßstab-Punkten
 * @param value der reele Abstand zwischen den Maßstab-Punkten
 */
void BB_DocComponent::setScaleReal( double value )
{
    m_ScaleValue = value;
}



/**
 * Gibt die Länge der Pixel in Metern zurück
 * @param pixel Pixel
 * @return Meter
 */
double BB_DocComponent::getMeterPerPixel( double pixel )
{
    C2dVector tmp( ( m_ScalePoint_2->getX() - m_ScalePoint_1->getX() ), ( m_ScalePoint_2->getY() - m_ScalePoint_1->getY() ) );
    double lenght_pixel = tmp.getLength();

    double meter = pixel * ( m_ScaleValue / lenght_pixel );

    return meter;;
}


/**
 * Gibt die Länge der Meter in Pixeln zurück
 * @param meter Meter
 * @return Pixel
 */
double BB_DocComponent::getPixelPerMeter( double meter )
{
    C2dVector tmp( ( m_ScalePoint_2->getX() - m_ScalePoint_1->getX() ), ( m_ScalePoint_2->getY() - m_ScalePoint_1->getY() ) );
    double lenght_pixel = tmp.getLength();

    double pixel = ( meter * lenght_pixel ) / m_ScaleValue;

    return pixel;
}


/**
 * Startet einen Dialog zum Bearbeiten.
 * @param parent Fenster, welches blockert werden soll, solange der Dialog aktiv ist.
 * @return Rückgabewert des Dialoges
 * @author Alex Letkemann
 */
int BB_DocComponent::keyBoardEdit( QWidget* parent )
{
	parent = NULL;
	
	return 0;
}


/**
 * Wird aufgerufen, wenn die Map sich ändert und setzt den Offset neu.
 * @author Alex Letkemann
 */
void BB_DocComponent::mapChanged()
{

	C2dVector offset;
	offset.setX( m_Map.width() / 2.0 );
	offset.setY( m_Map.height() / 2.0 );

	setOffset( offset );
}



/**
 * Schreibt das XML-Element des DocComponentes in den angegeben Stream.
 * @param out Stream, in welchen geschrieben werden soll.
 * @param depth Einrückung.
 * @author Alex Letkemann
 */
void BB_DocComponent::generateXElement( QTextStream &out, int depth )
{
	out << BB::indent( depth ) 
			<< "<" << getClassName().toLower() 
			<< " id=\"" << getObjectNr() << "\">" 
			<< BB::escapedText( getFileName() ) 
			<< "</" << getClassName().toLower() << ">\n";
}

/**
 * Erzeugt das 3D-Model des Objektes.
 * @param triangles Vektor, an den die 3D-Dreiecke angehängt werden.
 * @param scale Maßstab
 * @author Alex Letkemann
 */
void BB_DocComponent::createGl(  QVector<C3dTriangle>& triangles, double scale )
{
	double docScale = 1 / getPixelPerMeter( 1.0 );
	scale =  scale * docScale;
	
	// qDebug() << getName() << " Scale: " << scale <<  " DocScale: " << docScale;
	
	C3dVector  v(0.0, 0.0, 0.0);
	
	for( int i = 0; i < m_DrawObjects.count(); i++ )
	{
		m_DrawObjects.at( i )->createGl( triangles,v, 0.0, scale ,0.0 );
	}
}


/**
 * Gibt die Höhe zurück.
 * @return Die Höhe
 * @author Alex Letkemann
 */
double BB_DocComponent::getHeight() const{
	// DocComponent hat noch keine Höhe.
	
	return 0.0;	
	
}

