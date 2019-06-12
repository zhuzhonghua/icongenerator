#include "stdafx.h"

#include "frame_items.h"
#include "imageutil.h"

FrameItems::FrameItems()
{
	tex = ImageUtil::createTex("data/head/1.png");
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
