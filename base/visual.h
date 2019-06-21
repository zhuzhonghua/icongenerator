#pragma once

#include "gizmo.h"

class Visual:public Gizmo{
public:
	void setPos(int x, int y);
	void setSize(int w, int h);
	void setBound(int x, int y, int w, int h);
	void setBound(const Rect& bound);
protected:
	Rect _bound;
};
