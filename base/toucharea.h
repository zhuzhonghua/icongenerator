#pragma once

#include "eventlistener.h"

class TouchArea;
typedef void (*OnTouchClick)(void*);

class TouchArea : public EventListener{
public:
	TouchArea(Rect rect);
	TouchArea(int x, int y, int w, int h);

	void changeRect(Rect rect);
	void changeRect(int x, int y, int w, int h);
	
	~TouchArea();
	virtual bool onEvent(Event* event);

	virtual void onTouchDown(){}
	virtual void onTouchUp(){}
	//virtual void onClick(){}

	void setOnClick(OnTouchClick click) { _onClick = click; }
	void setData(void* d) { _data = d; }
	void* getData() { return _data; }
protected:
	bool overlapPoint(float x, float y);
	
protected:
	bool _touchDown;
	Rect _rect;

	OnTouchClick _onClick;

	void* _data;
};
