#pragma once

class TextUtil{
public:
	// TODO: font manager, multi ptsize
	static void initFont(SDL_Renderer* render, const std::tring& path);

	static Texture* renderText(const std::string& str);
private:
	static TTF_Font* _font;
	static SDL_Renderer* _render;
};
