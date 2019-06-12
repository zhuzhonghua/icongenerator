#pragma once

#include "timing.h"
#include "inputmanager.h"

class FrameItems;

class Game{
public:
  Game();
  void init();
  void run();
	
protected:
  void update();
  void draw();
  void processInput();
  
protected:
  bool _gameExit;
  FPSLimiter _fpsLimiter;

  float _fps;
protected:
  int _width;
  int _height;
  
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  InputManager _inputMgr;

protected:
	FrameItems* _frame;
};
