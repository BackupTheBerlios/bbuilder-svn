//
// C++ Interface: bb_doccomponent
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DOCCOMPONENT_H
#define BB_DOCCOMPONENT_H

#include <bb_fileobject.h>
#include <bb_map.h>
#include <bb_drawdevice.h>

/**
 * Die Klasse vereinit mehrere Klassen und stellt die Basisklasse für die Komponenten des Projektes (Gelände, Gebäude, Etage).<br />
 * Klasse besteht aus drei Klassen:<br />
 * BB_FileObject:	Für das Speichern/Laden<br />
 * BB_Map: 			Hintergrundbild laden/speichern<br />
 * BB_DrawDevice:	Enthält die Geometriedaten<br />
 * @author Alex Letkemann
 */
class BB_DocComponent : public BB_FileObject, public BB_Map, public BB_DrawDevice
{
public:
	/**
	 * Konstruktor
	 * @param path Verzeichnis, in dem gespeichert wird 
	 * @param fileName  Dateiname, unter welchem gepeichert wird
	 * @param name Objektname
	 */
	BB_DocComponent( const QDir& path, const QString &fileName, const QString &name );
	
	/**
	 * Destruktor
	 */
	~BB_DocComponent();
	
	/**
	 * Führt die open() Funktion von BB_FileObject aus und
	 * läd zusätztlich die Map Datei des Gebäudes.
	 * @author Alex Letkemann
	 * @date 13.12.2005
	 */
	virtual bool open();
};

#endif
