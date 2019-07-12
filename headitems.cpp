#include "stdafx.h"

#include "headitems.h"
#include "imagebutton.h"

HeadItems::HeadItems()
{
	_visible = false;
	for(int i=0;i<21;i++)
	{
		ImageButton* item = new ImageButton("data/head/1.png");
		item->setSize(100, 100);
		_items.push_back(item);
	}
}

HeadItems::~HeadItems()
{
	for(int i=0; i<_items.size(); i++)
	{
		delete _items[i];
	}
	
	_items.clear();
}

void HeadItems::draw()
{
	if(!_visible) return;
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->draw();
	}	
}

void HeadItems::setPos(int x, int y)
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

void HeadItems::setOnClick(OnTouchClick click)
{
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->setOnClick(click);
	}
}
