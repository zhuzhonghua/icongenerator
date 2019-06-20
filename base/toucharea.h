#pragma once

#include "eventlistener.h"
class TouchArea : public EventListener{
public:
	TouchArea(Rect rect);
	TouchArea(int x, int y, int w, int h);

	~TouchArea();
	virtual bool onEvent(SDL_Event* event);

	virtual void onTouchDown(){}
	virtual void onTouchUp(){}
	virtual void onClick(){}
	
protected:
	bool overlapPoint(float x, float y);
	
protected:
	bool _touchDown;
	Rect _rect;
};
