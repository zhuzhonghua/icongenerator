#pragma once

class EventListener{
public:
	EventListener(){}
	~EventListener(){}

	virtual bool onEvent(Event* event) = 0;
};
