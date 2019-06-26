#pragma once

class Image;

class Items{
public:
	Items();
	~Items();

	void draw();

	void setPos(int x, int y);
protected:
	std::vector<Image*> _items;
};
