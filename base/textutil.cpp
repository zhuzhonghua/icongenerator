#include "stdafx.h"

#include "textutil.h"

TTF_Font* TextUtil::_font;
SDL_Renderer*TextUtil:: _render;

void TextUtil::initFont(SDL_Renderer* render, const std::string& path)
{
	ASSERT(_font == NULL);

	_font = TTF_OpenFont(path.c_str(), 20);
	_render = render;
}

Texture* TextUtil::renderText(const std::string& str)
{
	SDL_Color color={0,0,0};
	SDL_Surface* img = TTF_RenderUTF8_Solid(_font, str.c_str(), color);

	Texture* tex = SDL_CreateTextureFromSurface(_render, img);
  
  SDL_FreeSurface(img);

	return tex;
}
