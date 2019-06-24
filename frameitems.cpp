#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "tab.h"

FrameItems::FrameItems()
{
	_tab = new Tab("Head");

	_tab->setPos(100, 100);
}

FrameItems::~FrameItems()
{
	delete _tab;
}

void FrameItems::draw()
{	
	_tab->draw();
}
