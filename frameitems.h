#pragma once

class Tab;
class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();
protected:
	Tab* _tab;
};
