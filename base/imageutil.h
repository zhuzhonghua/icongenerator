#pragma once

class ImageUtil{
public:
  static Texture* createSolid(SDL_Renderer* render, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static Texture* createSolid(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	
	static Texture* createTexture(SDL_Renderer* render, const std::string& path);

	static Texture* createTex(const std::string& path);

	static void destroyTex(Texture* tex);

	static void renderTex(Texture* tex, Rect* src, Rect* dst);
	static void queryTex(Texture* tex, int* w, int* h);
	static void composeTex(Texture* tex, ...);
public:
	static SDL_Renderer* getRenderer();
	static void setRenderer(SDL_Renderer* render);
private:
	static SDL_Renderer* gRender;
};
