#include "stdafx.h"

#include "hairitems.h"
#include "image.h"

HairItems::HairItems()
{
	_visible = false;
	for(int i=0;i<21;i++)
	{
		Image* item = new Image("data/hair/1.png");
		item->setSize(100, 100);
		_items.push_back(item);
	}
}

HairItems::~HairItems()
{
	for(int i=0; i<_items.size(); i++)
	{
		delete _items[i];
	}
	
	_items.clear();
}

void HairItems::draw()
{
	if(!_visible) return;
	
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->draw();
	}	
}

void HairItems::setPos(int x, int y)
{
	int tempX=x, tempY=y;
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->setPos(tempX, tempY);
		tempX += 100;
		if((i+1)%5==0){
			tempX = x;
			tempY += 100;
		}
	}
}
