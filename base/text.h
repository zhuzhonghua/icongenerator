#pragma once

#include "visual.h"

class Text : public Visual{
public:
	Text(const std::string& str);
	~Text();

	virtual void draw();
protected:
	std::string _str;
	Texture* _strTex;
};
