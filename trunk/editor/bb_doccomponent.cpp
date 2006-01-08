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


double BB_DocComponent::getScaleReal() const
{
    return m_ScaleValue;
}

double* BB_DocComponent::getScaleRealPointer()
{
    return & m_ScaleValue;
}


void BB_DocComponent::setScaleReal( double value )
{
    m_ScaleValue = value;
}



/*!
    \fn BB_DocComponent::getMeterPerPixel(int pixel)
 */
double BB_DocComponent::getMeterPerPixel( double pixel )
{
    C2dVector tmp( ( m_ScalePoint_2->getX() - m_ScalePoint_1->getX() ), ( m_ScalePoint_2->getY() - m_ScalePoint_1->getY() ) );
    double lenght_pixel = tmp.getLength();

    double meter = pixel * ( m_ScaleValue / lenght_pixel );

    return meter;;
}


/*!
    \fn BB_DocComponent::getPixelPerMeter(double meter)
 */
double BB_DocComponent::getPixelPerMeter( double meter )
{
    C2dVector tmp( ( m_ScalePoint_2->getX() - m_ScalePoint_1->getX() ), ( m_ScalePoint_2->getY() - m_ScalePoint_1->getY() ) );
    double lenght_pixel = tmp.getLength();

    double pixel = ( meter * lenght_pixel ) / m_ScaleValue;

    return pixel;
}


/*!
    \fn BB_DocComponent::keyBoardEdit( QWidget* parent )
 */
int BB_DocComponent::keyBoardEdit( QWidget* parent )
{
	parent = NULL;
	
	return 0;
}


/*!
    \fn BB_DocComponent::mapChanged()
 */
void BB_DocComponent::mapChanged()
{

	C2dVector offset;
	offset.setX( m_Map.width() / 2.0 );
	offset.setY( m_Map.height() / 2.0 );

	setOffset( offset );
}


/*!
    \fn BB_DocComponent::generateXElement( QTextStream &out, int depth )
 */
void BB_DocComponent::generateXElement( QTextStream &out, int depth )
{
	out << BB::indent( depth ) 
			<< "<" << getClassName().toLower() 
			<< " id=\"" << getObjectNr() << "\">" 
			<< BB::escapedText( getFileName() ) 
			<< "</" << getClassName().toLower() << ">\n";
}

void BB_DocComponent::createGl(  QVector<C3dTriangle>& triangles, double scale )
{
	double docScale = 1 / getPixelPerMeter( 1.0 );
	scale =  scale * docScale;
	
	qDebug() << getName() << " Scale: " << scale <<  " DocScale: " << docScale;
	
	C3dVector  v(0.0, 0.0, 0.0);
	
	for( int i = 0; i < m_DrawObjects.count(); i++ )
	{
		m_DrawObjects.at( i )->createGl( triangles,v, 0.0, scale ,0.0 );
	}
}

double BB_DocComponent::getHeight() const{
	return 0.0;
}

