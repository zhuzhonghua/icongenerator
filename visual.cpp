#include "stdafx.h"

#include "visual.h"

void Visual::setBound(int x, int y, int w, int h)
{
	_bound = Utils::rect(x,y,w,h);
}
