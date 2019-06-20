#pragma once

class Visual{
public:
	virtual void draw() = 0;
	
	void setBound(int x, int y, int w, int h);

protected:
	Rect _bound;
};
