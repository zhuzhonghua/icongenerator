#pragma once

class ImageButton;

class HeadItems{
public:
	HeadItems();
	~HeadItems();

	void draw();

	void setPos(int x, int y);
	void setVisible(bool vis) { _visible=vis; }
	void setOnClick(OnTouchClick click);
protected:
	std::vector<ImageButton*> _items;

	bool _visible;
};