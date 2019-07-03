#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "tab.h"
#include "items.h"

void OnClick(TouchArea* ta)
{
	printf("onclick\n");
}

void OnClick2(TouchArea* ta)
{
	printf("onclick2\n");
}

FrameItems::FrameItems()
{
	int tabY = 100;
	_headTab = new Tab("Head");
	_headTab->setPos(100, tabY);
	_headTab->setOnClick(OnClick);
	
	_headItems = new Items();
	_headItems->setPos(100+100+10, 100);

	_hairTab = new Tab("Hair");
	_hairTab->setPos(100, tabY+=50);
	_hairTab->setOnClick(OnClick2);
}

FrameItems::~FrameItems()
{
	delete _headTab;
	delete _headItems;

	delete _hairTab;
}

void FrameItems::draw()
{	
	_headTab->draw();
	_headItems->draw();

	_hairTab->draw();
}
