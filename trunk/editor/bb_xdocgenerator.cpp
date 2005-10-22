//
// C++ Implementation: bb_xdocgenerator
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xdocgenerator.h"
#include <iostream>


using namespace std;

BB_XDocGenerator::BB_XDocGenerator(BB_Doc * doc)
	: BB_XGenerator() 
{
	if(doc != NULL)
	{
		m_Doc = doc;
	}
	else
	{
		qDebug("BB_XDocGenerator::BB_XDocGenerator(): NULL-Pointer erhalten");
	}
}


BB_XDocGenerator::~BB_XDocGenerator()
{
}




/**
 *
 */
bool BB_XDocGenerator::write(QIODevice *device)
{
	m_Stream.setDevice(device);
	m_Stream.setCodec("UTF-8");
	
	m_Stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
			<< "<!DOCTYPE bb_doc>\n"
			<< "<bb_doc version=\"1.0\">\n";
	
	m_Doc->getTerrain()->generateXElement(m_Stream, 1);
	
	m_Stream << "</bb_doc>\n";
	
	return true;
}
