#include "stdafx.h"
#include "imageutil.h"
#include "util.h"

#include "image.h"

Image::Image(const std::string& path)
{
	_tex = ImageUtil::createTex(path);
	int w,h;
	ImageUtil::queryTex(_tex, &w, &h);	
	_bound = Utils::rect(0, 0, w, h);
}

Image::Image(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	_tex = ImageUtil::createSolid(width, height, r, g, b, a);
	_bound = Utils::rect(0, 0, width, height);
}

Image::~Image()
{
	ImageUtil::destroyTex(_tex);
}

void Image::draw()
{	
	ImageUtil::renderTex(_tex, NULL, &_bound);
}
