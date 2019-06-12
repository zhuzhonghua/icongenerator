#pragma once

class TouchArea{
public:
	TouchArea(Rect rect);
	TouchArea(int x, int y, int w, int h);
protected:
	Rect _rect;
};
