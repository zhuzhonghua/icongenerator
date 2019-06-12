#include "stdafx.h"

#include "touch_area.h"

TouchArea::TouchArea(Rect rect)
	:_rect(rect)
{
}

TouchArea::TouchArea(int x, int y, int w, int h)
	:_rect(Utils::rect(x,y,w,h))
{	
}
