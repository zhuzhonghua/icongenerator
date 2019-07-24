#pragma once

class Image;

class Avatar{
public:
	Avatar();
	void draw();
	
	void setHairTex(Texture* tex);
	void setHeadTex(Texture* tex);
protected:
	void compose();
protected:
	Rect _bound;
	//Image* _bg;
	Texture* _finalTex;

	Texture* _hairTex;
	Texture* _headTex;
};
