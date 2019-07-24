#include "stdafx.h"

#include "text.h"
#include "util.h"
#include "imageutil.h"
#include "textutil.h"

Text::Text(const std::string& str)
	:_str(str)
{
	_strTex = TextUtil::renderText(str);
	int w,h;
	ImageUtil::queryTex(_strTex, &w, &h);
	_bound = Utils::rect(0, 0, w, h);
}

Text::~Text()
{
	ImageUtil::destroyTex(_strTex);
}

void Text::draw()
{
	ImageUtil::renderTex(_strTex, NULL, &_bound);
}
