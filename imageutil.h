#pragma once
#include "util.h"

class ImageUtil{
public:
  static SDL_Texture* createSolid(SDL_Renderer* render, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static SDL_Texture* createTexture(SDL_Renderer* render, const std::string& path);

	static SDL_Texture* createTex(const std::string& path);

public:
	static SDL_Renderer* getRenderer();
	static void setRenderer(SDL_Renderer* render);
private:
	static SDL_Renderer* gRender;
};
