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

#include <QIODevice>
#include <QString>

/**
@author Alex Letkemann
*/
class BB_XGenerator{
public:
    BB_XGenerator();

    virtual ~BB_XGenerator();
    virtual bool write(QIODevice *device);

protected:
    virtual QString escapedAttribute(const QString &str);
    virtual QString escapedText(const QString &str);
    virtual QString indent(int depth);
};

#endif
