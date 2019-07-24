#include "stdafx.h"

#include "avatar.h"
#include "image.h"
#include "util.h"
#include "imageutil.h"

Avatar::Avatar()
{
	_bound = Utils::rect(250, 50, 100, 100);
	
	//_bg = new Image(_bound.w, _bound.h, 255, 255, 255, 255);
	//_bg->setBound(_bound);

	_finalTex = ImageUtil::createSolid(_bound.w,_bound.h,255,255,255,255);	
}

void Avatar::draw()
{
	//_bg->draw();
	
	ImageUtil::renderTex(_finalTex, NULL, &_bound);
}

void Avatar::setHairTex(Texture* tex)
{
	_hairTex = tex;
	compose();
}

void Avatar::setHeadTex(Texture* tex)
{
	_headTex = tex;
	compose();
}

void Avatar::compose()
{
	ImageUtil::composeTex(_finalTex, _hairTex, _headTex, NULL);
}
