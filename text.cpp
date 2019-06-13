#include "stdafx.h"

#include "text.h"

Text::Text(const std::string& str)
	:_str(str)
{
	_strTex = TextUtil::renderText(str);
	_bound = Utils::rect(50, 50, 30, 30);
}

Text::~Text()
{
	ImageUtil::destroyTex(_strTex);
}

void Text::draw()
{
	ImageUtil::renderTex(_strTex, NULL, &_bound);
}
