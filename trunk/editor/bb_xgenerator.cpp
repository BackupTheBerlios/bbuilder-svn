//
// C++ Implementation: bb_xgenerator
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_xgenerator.h"

/** Konstrucktor */
BB_XGenerator::BB_XGenerator()
{
}


/** Destrucktor */
BB_XGenerator::~BB_XGenerator()
{
}








QString BB_XGenerator::indent(int depth)
{
	const int IndentSize = 4;
	return QString(IndentSize * depth, ' ');
}



// bool BB_XGenerator::write(QIODevice *device)
// {
// 	return true;
// }
