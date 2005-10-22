//
// C++ Interface: bb_xgenerator
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_XGENERATOR_H
#define BB_XGENERATOR_H

#include <QTextStream>
#include <QIODevice>
#include <QString>

/**
@author Alex Letkemann
*/
class BB_XGenerator{
public:
    BB_XGenerator();

    virtual ~BB_XGenerator();
    virtual bool write(QIODevice *device) = 0;
	
	static QString indent(int depth);
   
protected:
    QTextStream m_Stream;
};

#endif
