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

/**
 * Konstruktor
 */
BR_KeyHandler::BR_KeyHandler()
{
	
	/* Alle Tasten auf NICHT gedrückt setzten */
	for( int i = 0 ; i < 256 ; i++ )
	{
		m_Keys[i] = false;
	}
}

/**
 * Destruktor
 */
BR_KeyHandler::~BR_KeyHandler()
{
}


/**
 * Rechnet die Qt-Keys in den Internen ArrayIndex um.
 * Diese Funktion ist notwendig, da Qt eine 32Bit Key-Maske liefert.
 * Die Klasse kann aber nur 256 Tasten behandeln.
 * @param key Qt-Key
 * @return Internet ArrayIndex
 */
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

/**
 * Gibt den Status einer Taste zurück
 * @param key Qt-Taste
 * @return Status der Qt-Taste
 */
bool BR_KeyHandler::isPressed( int key )
{
	return m_Keys[ keyToArray( key ) ];
}

/**
 * Setzt den Status einer Taste auf gedrückt
 * @param Qt-Taste 
 */
void BR_KeyHandler::pressed( int key )
{
	m_Keys [ keyToArray( key ) ] = true;
}

/**
 * Setzt den Status einer Taste auf NICHT gedrückt
 * @param key Qt-Taste
 */
void BR_KeyHandler::released( int key )
{
	m_Keys [ keyToArray( key ) ] = false;
}
