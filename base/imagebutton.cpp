#include "stdafx.h"

#include "imagebutton.h"

ImageButton::ImageButton(const std::string& path)
	:Image(path),TouchArea(0,0,0,0)
{
	setData(this);
}

void ImageButton::setPos(int x, int y)
{
	Image::setPos(x, y);
	TouchArea::changeRect(_bound);
}
