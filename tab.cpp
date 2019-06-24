#include "stdafx.h"

#include "tab.h"
#include "image.h"
#include "text.h"

Tab::Tab(const std::string& str)
{
	_bg = new Image(60, 25, 255, 255, 255, 255);
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
}
