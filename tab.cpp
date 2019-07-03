#include "stdafx.h"

#include "tab.h"
#include "image.h"
#include "text.h"

const int TABWIDTH = 60;
const int TABHEIGHT = 25;

Tab::Tab(const std::string& str)
	:TouchArea(0,0,0,0)
{
	_bg = new Image(TABWIDTH, TABHEIGHT, 255, 255, 255, 255);
	_txt = new Text(str);
}

Tab::~Tab()
{
	delete _bg;
	delete _txt;
}

void Tab::draw()
{
	_bg->draw();
	_txt->draw();
}

void Tab::setPos(int x, int y)
{
	_bg->setPos(x, y);
	_txt->setPos(x, y);
	changeRect(x, y, TABWIDTH, TABHEIGHT);
}
