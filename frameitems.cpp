#include "stdafx.h"

#include "frameitems.h"
#include "imageutil.h"
#include "toucharea.h"

FrameItems::FrameItems()
{
	tex = ImageUtil::createTex("data/head/1.png");
	
	ta = new TouchArea(Utils::rect(100, 100, 48, 48));
}

FrameItems::~FrameItems()
{
}

void FrameItems::draw()
{
	SDL_Rect dst;
	dst.x = 100;
	dst.y = 100;
	dst.w = 48;
	dst.h = 48;
	SDL_RenderCopy(ImageUtil::getRenderer(), tex, NULL, &dst);
}
