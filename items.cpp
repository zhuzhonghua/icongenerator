#include "stdafx.h"

#include "items.h"
#include "image.h"

Items::Items()
{
	Image* item = new Image("data/head/1.png");
	item->setSize(100, 100);
	_items.push_back(item);
}

Items::~Items()
{
}

void Items::draw()
{
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->draw();
	}	
}

void Items::setPos(int x, int y)
{
	//_item->setPos(x,y);
}
