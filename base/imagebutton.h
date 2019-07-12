#pragma once

#include "image.h"
#include "toucharea.h"

class ImageButton: public Image, public TouchArea{
public:
	ImageButton(const std::string& path);

	virtual void setPos(int x, int y);
};
