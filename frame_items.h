#pragma once

class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();
protected:
	SDL_Texture* tex;
};
