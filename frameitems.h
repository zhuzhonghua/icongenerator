#pragma once

class TouchArea;
class FrameItems{
public:
	FrameItems();
	~FrameItems();

	void draw();
protected:
	SDL_Texture* tex;
	TouchArea* ta;
};
