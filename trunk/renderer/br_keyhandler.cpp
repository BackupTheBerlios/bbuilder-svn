//
// C++ Implementation: br_keyhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "br_keyhandler.h"


#include <iostream>

using namespace std;

BR_KeyHandler::BR_KeyHandler()
{
	
	/* Alle Tasten auf NICHT gedrückt setzten */
	for( int i = 0 ; i < 256 ; i++ )
	{
		m_Keys[i] = false;
	}
}


BR_KeyHandler::~BR_KeyHandler()
{
}



int BR_KeyHandler::keyToArray( int key )
{
	int index;
	
	/* Prüfen, ob key eine Steurungstaste ist */
	if( key & 0x01000000 )
	{
		index = key & 0x0000FFFF;
		index = index + 128;
	}
	else
	{
		index = key;
	}
	
	return index;
}


bool BR_KeyHandler::isPressed( int key )
{
	return m_Keys[ keyToArray( key ) ];
}


void BR_KeyHandler::pressed( int key )
{
	m_Keys [ keyToArray( key ) ] = true;
}


void BR_KeyHandler::released( int key )
{
	m_Keys [ keyToArray( key ) ] = false;
}
