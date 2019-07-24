#pragma once

class Image;

class Avatar{
public:
	Avatar();
	void draw();
protected:
	Image* _bg;
	Texture* _finalTex;

	Texture* _hairTex;
	Texture* _headTex;
};
