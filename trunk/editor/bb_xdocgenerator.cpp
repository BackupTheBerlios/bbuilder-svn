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


