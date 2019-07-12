#pragma once

class Tab;
class HeadItems;
class HairItems;

class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();

	static void onHeadTabClick(void* ta);
	static void onHairTabClick(void* ta);

	static void onHeadImgClick(void* ta);
	static void onHairImgClick(void* ta);
	
	HeadItems* getHeadItems() { return _headItems; }
	HairItems* getHairItems() { return _hairItems; }

	void setAllItemsInvisible();
protected:
	Tab* _headTab;
	HeadItems* _headItems;

	Tab* _hairTab;
	HairItems* _hairItems;
};
