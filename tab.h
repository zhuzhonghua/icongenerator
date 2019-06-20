#pragma once

#include "toucharea.h"
#include "visual.h"

class Text;
class Image;

class Tab{
public:
	Tab(const std::string& str);
	~Tab();

	void draw();
protected:
	Text* _txt;
	Image* _bg;
};
