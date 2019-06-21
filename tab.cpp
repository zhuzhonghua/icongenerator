#include "stdafx.h"

#include "tab.h"
#include "image.h"
#include "text.h"

Tab::Tab(const std::string& str)
{
	_bg = new Image(30, 30, 255, 255, 255, 255);
	_txt = new Text(str);
}

Tab::~Tab()
{
	delete _bg;
	delete _txt;
}

void Tab::draw()
{
	//_bg->draw();
	_txt->draw();
}

