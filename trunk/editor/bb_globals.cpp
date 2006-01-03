//
// C++ Implementation: bb_globals
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//


/**
 * Datei enthält alle globalen Variablen und Funktionen.
 * BIN_DIR(): Pfad zum Verzeichnis wo die  ausführbare Datei liegt.
 * MAIN_DIR(): Pfad zu Hauptverzeichnis des Programms.
 * IMG_DIR(): Pfad, in welchem alle Grafiken des Programms untergebracht sind.
 * CONF_DIR(): Pfad zum Konfiguraionsordner des Programms.
 * SEPARATOR(): Separator des Dateisystems des Aktuellen Betriebssystems.
 * Die Pfade werden mit der Funktion setDirs(..) gesetzt und sind danach global erreichbar.
 * @author Alex Letkemann
 * @date 27.10.2005
 */

#include <QtCore>
#include <iostream>

#include "bb_globals.h"

using namespace std;


QString bin_dir;
QString main_dir;
QString img_dir;
QString conf_dir;
QString separator;
QString pro_dir;

QString PRO_DIR()
{
	return pro_dir;
}
 QString PRO_BUILDINGS_DIR(){
	 return pro_dir+SEPARATOR() + "buildings";
 }
 QString PRO_LEVELS_DIR(){
	 return pro_dir +SEPARATOR()+ "levels";
 }
 QString PRO_TERRAINS_DIR(){
	 return pro_dir +SEPARATOR()+ "terrain";
 }
 QString PRO_TEXTURES_DIR(){
	 return pro_dir +SEPARATOR()+ "textures";
 }

void setPRO_DIR(QString s)
{
	pro_dir = s;
}

QString BIN_DIR()
{
	return bin_dir;
}

QString MAIN_DIR()
{
	return main_dir;
}

QString IMG_DIR()
{
	return img_dir;
}

QString CONF_DIR()
{
	return conf_dir;
}

QString SEPARATOR()
{
	return separator;
}

/**
 * Setzt die Pfade des Programms.
 * @param argv0 Parameter-Array des Programms
 */
void setDirs(char * argv0)
{
	QFileInfo binaryFile(argv0);
	QDir dir( binaryFile.dir());
	
	
	separator = QDir::separator();
	
	dir.makeAbsolute();
	bin_dir = dir.path();
	
	dir.cdUp();
	main_dir = dir.path();
	
	if(!dir.cd("img"))
	{
		dir.mkdir("img");
		dir.cd("img");
	}
	img_dir = dir.path();
	
	dir.cdUp();
	if(!dir.cd("conf"))
	{
		dir.mkdir("conf");
		dir.cd("conf");
	}
	
	conf_dir = dir.path();
	
	
	cout << "MAIN_DIR: " <<  main_dir.toStdString()<< endl;
	cout << "BIN_DIR: " <<  bin_dir.toStdString()<< endl;
	cout << "CONF_DIR: " <<  conf_dir.toStdString()<< endl;
	cout << "IMG_DIR: " <<  img_dir.toStdString()<< endl;
	

}
