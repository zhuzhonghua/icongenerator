#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "tab.h"
#include "items.h"

FrameItems::FrameItems()
{
	_tab = new Tab("Head");
	_tab->setPos(100, 100);

	_items = new Items();
	_items->setPos(100+100+10, 100);
}

FrameItems::~FrameItems()
{
	delete _tab;
	delete _items;
}

void FrameItems::draw()
{	
	_tab->draw();
	_items->draw();
}
