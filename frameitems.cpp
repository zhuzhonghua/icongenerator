#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "tab.h"
#include "headitems.h"
#include "hairitems.h"
#include "avatar.h"

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

void FrameItems::onHeadImgClick(void* ta)
{
	printf("onheadimgclick");
}

void FrameItems::onHairImgClick(void* ta)
{
	printf("onhairimgclick");
}

FrameItems::FrameItems()
{
	int tabX = 25;
	int tabY = 200;
	int interW = 80;

	int itemsX = tabX+interW;
	int itemsY = 200;
	
	_headTab = new Tab("Head");
	_headTab->setPos(tabX, tabY);
	_headTab->setOnClick(&(FrameItems::onHeadTabClick));
	_headTab->setData(this);
	
	_headItems = new HeadItems();
	_headItems->setPos(itemsX, itemsY);
	_headItems->setVisible(true);
	_headItems->setOnClick(FrameItems::onHeadImgClick);
	
	_hairTab = new Tab("Hair");
	_hairTab->setPos(tabX, tabY+=50);
	_hairTab->setOnClick(&(FrameItems::onHairTabClick));
	_hairTab->setData(this);
		
	_hairItems = new HairItems();
	_hairItems->setPos(itemsX, itemsY);
	_hairItems->setVisible(false);
	_hairItems->setOnClick(FrameItems::onHairImgClick);

	_avatar = new Avatar();
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
	_avatar->draw();
	
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
