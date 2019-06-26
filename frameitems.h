#pragma once

class Tab;
class Items;

class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();
protected:
	Tab* _tab;
	Items* _items;
};
