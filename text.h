#pragma once

#include "visual.h"

class Texture;

class Text : public Visual{
public:
	Text(const std::string& str);
	~Text();

	virtual void draw();
protected:
	std::string _str;
	Texture* _strTex;
	Rect _bound;
};
