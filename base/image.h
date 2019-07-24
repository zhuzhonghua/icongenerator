#pragma once

#include "visual.h"

class Image : public Visual{
public:
	Image(const std::string& path);
	Image(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	~Image();
	
	virtual void draw();

	Texture* getTex() { return _tex; }
protected:
	Texture* _tex;
};
