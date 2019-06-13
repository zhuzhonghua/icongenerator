#pragma once

#include "toucharea.h"
#include "visual.h"

class Text;
class Image;

class Tab : public TouchArea, public Visual{
public:
	Tab(const std::string& str);
	~Tab();

	virtual void draw();
protected:
	Text* _txt;
	Image* _bg;
};
