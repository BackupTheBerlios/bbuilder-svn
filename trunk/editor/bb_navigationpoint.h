//
// C++ Interface: bb_navigationpoint
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_NAVIGATIONPOINT_H
#define BB_NAVIGATIONPOINT_H

#include <bb_point.h>

/**
Navigationspunkt

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_NavigationPoint : public BB_Point
{
public:
    BB_NavigationPoint(C2dVector p);

    ~BB_NavigationPoint();

	void setIndexed( bool value );
	

	bool getIndexed() const;
	

protected:
    bool m_Indexed;
};

#endif
