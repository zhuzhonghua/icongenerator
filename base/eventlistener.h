#pragma once

class EventListener{
public:
	EventListener(){}
	~EventListener(){}

	virtual bool onEvent(SDL_Event* event) = 0;
};
