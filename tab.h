#pragma once

#include "toucharea.h"
#include "visual.h"

class Text;
class Image;

class Tab : public TouchArea{
public:
	Tab(const std::string& str);
	~Tab();

	void draw();

	void setPos(int x, int y);
protected:
	Text* _txt;
	Image* _bg;
};
