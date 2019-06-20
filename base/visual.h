#pragma once

#include "gizmo.h"

class Visual:public Gizmo{
public:	
	void setBound(int x, int y, int w, int h);

protected:
	Rect _bound;
};
