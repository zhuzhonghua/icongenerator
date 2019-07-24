#include "stdafx.h"

#include "avatar.h"
#include "image.h"

Avatar::Avatar()
{
	_bg = new Image(100, 100, 255, 255, 255, 255);
	_bg->setPos(250, 50);
}

void Avatar::draw()
{
	_bg->draw();
}
