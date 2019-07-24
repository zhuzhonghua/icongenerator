#pragma once

class ImageButton;

class HairItems{
public:
	HairItems();
	~HairItems();

	void draw();

	void setPos(int x, int y);
	void setVisible(bool vis);
	void setOnClick(OnTouchClick click);
	void setData(void* data);
protected:
	std::vector<ImageButton*> _items;

	bool _visible;
};
