#include "stdafx.h"

#include "hairitems.h"
#include "imagebutton.h"

HairItems::HairItems()
{
	_visible = false;
	for(int i=0;i<1;i++)
	{
		ImageButton* item = new ImageButton("data/hair/1.png");
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

void HairItems::setVisible(bool vis)
{
	_visible = vis;
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->setVisible(vis);
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

void HairItems::setOnClick(OnTouchClick click)
{
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->setOnClick(click);
	}
}


void HairItems::setData(void* data)
{
	for(int i=0; i<_items.size(); i++)
	{
		_items[i]->setData2(data);
	}
}
