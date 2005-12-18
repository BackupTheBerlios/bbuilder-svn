//
// C++ Interface: bb_globals
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef BB_GLOBALS_H
#define BB_GLOBALS_H

#include <QString> 
 
 QString BIN_DIR();
 QString MAIN_DIR();
 QString IMG_DIR();
 QString CONF_DIR();
 QString SEPARATOR();

 void setDirs(char *argv0);
 
#endif 
