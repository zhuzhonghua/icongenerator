#pragma once

class Image;

class HeadItems{
public:
	HeadItems();
	~HeadItems();

	void draw();

	void setPos(int x, int y);
	void setVisible(bool vis) { _visible=vis; }
protected:
	std::vector<Image*> _items;

	bool _visible;
};
