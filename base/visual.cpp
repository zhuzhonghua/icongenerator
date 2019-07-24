#include "stdafx.h"
#include "util.h"

#include "visual.h"

void Visual::setPos(int x, int y)
{
	_bound.x = x;
	_bound.y = y;
}

void Visual::setSize(int w, int h)
{
	_bound.w = w;
	_bound.h = h;
}

void Visual::setBound(int x, int y, int w, int h)
{
	_bound = Utils::rect(x,y,w,h);
}

void Visual::setBound(const Rect& bound)
{
	_bound = bound;
}
