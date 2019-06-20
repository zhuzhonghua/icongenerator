#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "tab.h"

FrameItems::FrameItems()
{
	_tab = new Tab("Head");
}

FrameItems::~FrameItems()
{
}

void FrameItems::draw()
{	
	_tab->draw();
}
