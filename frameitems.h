#pragma once

class Tab;
class Items;

class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();
protected:
	Tab* _headTab;
	Items* _headItems;

	Tab* _hairTab;
	Items* _hairItems;
};
