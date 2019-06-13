#pragma once

#include "visual.h"

class Image : public Visual{
public:
	Image(const std::string& path);
	Image(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	~Image();

	void setBound(int x, int y, int w, int h);
	
	virtual void draw();
protected:
	Texture* _tex;
	Rect _bound;
};
