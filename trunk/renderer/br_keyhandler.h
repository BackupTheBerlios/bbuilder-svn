//
// C++ Interface: br_keyhandler
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BR_KEYHANDLER_H
#define BR_KEYHANDLER_H

/**
 * Speichert die Zustände der Tasten der Tastatur.
 * Der Klasse werden mit einem KeyPressEvent oder einem KeyReleaseEvent die Zustandänderungen der Tasten mitgeteilt.
 * Die Klasse speichert die Zustände und erlaubt es somit jederzeit den Status einer Taste abzufragen.
 * Die Klasse kann 256 Tasten behandeln.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BR_KeyHandler{
public:
	
	/**
	 * Konstruktor
	 */
    BR_KeyHandler();
	
	/**
	 * Destruktor
	 */
    virtual ~BR_KeyHandler();
	
	/**
	 * Gibt den Status einer Taste zurück
	 * @param key Qt-Taste
	 * @return Status der Qt-Taste
	 */
    virtual bool isPressed( int key );
	
	/**
	 * Setzt den Status einer Taste auf gedrückt
	 * @param Qt-Taste 
	 */
    virtual void pressed( int key );
	
	/**
	 * Setzt den Status einer Taste auf NICHT gedrückt
	 * @param key Qt-Taste
	 */
    virtual void released( int key );

private:
	/**
	 * Rechnet die Qt-Keys in den Internen ArrayIndex um.
	 * Diese Funktion ist notwendig, da Qt eine 32Bit Key-Maske liefert.
	 * Die Klasse kann aber nur 256 Tasten behandeln.
	 * @param key Qt-Key
	 * @return Internet ArrayIndex
	 */
    int keyToArray( int key );
	
private:
	
	/** Array für die Tastenzustände */
	bool m_Keys[256];
};

#endif
