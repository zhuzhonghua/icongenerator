#pragma once

class Tab;
class HeadItems;
class HairItems;

class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();
protected:
	Tab* _headTab;
	HeadItems* _headItems;

	Tab* _hairTab;
	HairItems* _hairItems;
};
