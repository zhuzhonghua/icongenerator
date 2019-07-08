#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "tab.h"
#include "headitems.h"
#include "hairitems.h"

void FrameItems::onHeadTabClick(void* ta)
{
	//printf("onclickheadtab");
	FrameItems* fi = (FrameItems*)(((TouchArea*)ta)->getData());
	fi->setAllItemsInvisible();
	fi->getHeadItems()->setVisible(true);
}

void FrameItems::onHairTabClick(void* ta)
{
	//printf("onclickhairtab");
	FrameItems* fi = (FrameItems*)(((TouchArea*)ta)->getData());
	fi->setAllItemsInvisible();
	fi->getHairItems()->setVisible(true);
}

FrameItems::FrameItems()
{
	int tabY = 100;
	_headTab = new Tab("Head");
	_headTab->setPos(100, tabY);
	_headTab->setOnClick(&(FrameItems::onHeadTabClick));
	_headTab->setData(this);
	
	_headItems = new HeadItems();
	_headItems->setPos(100+100+10, 100);
	_headItems->setVisible(true);

	_hairTab = new Tab("Hair");
	_hairTab->setPos(100, tabY+=50);
	_hairTab->setOnClick(&(FrameItems::onHairTabClick));
	_hairTab->setData(this);
		
	_hairItems = new HairItems();
	_hairItems->setPos(100+100+10, 100);
	_hairItems->setVisible(false);
}

FrameItems::~FrameItems()
{
	delete _headTab;
	delete _headItems;

	delete _hairTab;
	delete _hairItems;
}

void FrameItems::draw()
{	
	_headTab->draw();
	_headItems->draw();

	_hairTab->draw();
	_hairItems->draw();
}

void FrameItems::setAllItemsInvisible()
{
	_headItems->setVisible(false);
	_hairItems->setVisible(false);
}
