#include "stdafx.h"

#include "imageutil.h"

Texture* ImageUtil::createSolid(SDL_Renderer* render, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif

  SDL_Surface* img = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = width;
  rect.h = height;  
  SDL_FillRect(img, &rect, SDL_MapRGBA(img->format, r, g, b, a));  
  SDL_Texture* tex = SDL_CreateTextureFromSurface(render, img);
  
  SDL_FreeSurface(img);

  return tex;
}

Texture* ImageUtil::createSolid(int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	return createSolid(gRender, width, height, r, g, b, a);
}

// TODO: texture cache
Texture* ImageUtil::createTexture(SDL_Renderer* render, const std::string& path)
{
	Texture* tex = IMG_LoadTexture(render, path.c_str());
	ASSERT(tex != NULL);
	return tex;
}

Texture* ImageUtil::createTex(const std::string& path)
{
	return ImageUtil::createTexture(gRender, path);
}

Texture* ImageUtil::createEmptyTex(int w, int h)
{
	Texture* tex = SDL_CreateTexture(gRender, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
	SDL_SetRenderTarget(gRender, tex);
	SDL_SetRenderDrawBlendMode(gRender, SDL_BLENDMODE_NONE);
	SDL_SetRenderDrawColor(gRender, 255, 255, 255, 0);
	SDL_RenderFillRect(gRender, NULL);
	SDL_SetRenderTarget(gRender, NULL);

	return tex;
}

void ImageUtil::composeTex(Texture* tex, ...)
{
	SDL_SetRenderTarget(gRender, tex);
	
	va_list ap;
	va_start(ap, tex);
	Texture* temp = NULL;
	while ((temp = va_arg(ap, Texture*)) != NULL)
	{
		SDL_RenderCopy(gRender, temp, NULL, NULL);
	}
	
	va_end(ap);

	SDL_SetRenderTarget(gRender, NULL);
}

// TODO: tex cache
void ImageUtil::destroyTex(Texture* tex)
{
	SDL_DestroyTexture(tex);
}

void ImageUtil::renderTex(Texture* tex, Rect* src, Rect* dst)
{
	SDL_RenderCopy(gRender, tex, src, dst);
}

void ImageUtil::queryTex(Texture* tex, int* w, int* h)
{
	SDL_QueryTexture(tex, NULL, NULL, w, h);
}

SDL_Renderer* ImageUtil::gRender;

SDL_Renderer* ImageUtil::getRenderer()
{
	return gRender;
}

void ImageUtil::setRenderer(SDL_Renderer* render)
{
	gRender = render;
}
