#include "stdafx.h"

#include "image.h"

Image::Image(const std::string& path)
{
	_tex = ImageUtil::createTex(path);
	_bound = Utils::rect(0, 0, 48, 48);
}

Image::Image(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	_tex = ImageUtil::createSolid(width, height, r, g, b, a);
	_bound = Utils::rect(0, 0, 48, 48);
}

Image::~Image()
{
	if(_tex != NULL)
	{
		ImageUtil::destroyTex(_tex);
	}
	_tex = NULL;
}

void Image::setBound(int x, int y, int w, int h)
{
	_bound = Utils::rect(x,y,w,h);
}

void Image::draw()
{	
	ImageUtil::renderTex(_tex, NULL, &_bound);
}
