#include "stdafx.h"
#include "game.h"
#include "util.h"
#include "imageutil.h"
#include "frameitems.h"
#include "image.h"
#include "textutil.h"

Game::Game()
{
  _width = 640;
  _height = 960;

  _gameExit = false;
}

Game::~Game()
{
	TTF_Quit();
}

void Game::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  _window = SDL_CreateWindow( "IconGenerator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  _renderer = SDL_CreateRenderer(_window, -1, 0);
	ImageUtil::setRenderer(_renderer);

	TTF_Init();	
	TextUtil::initFont(_renderer, "data/font/font.ttf");
	
  _fpsLimiter.setMaxFPS(60.0f);

	_frame = new FrameItems();
	_bg = new Image("data/bg.png");
	_bg->setBound(0, 0, _width, _height);
}

void Game::run()
{
  SDL_StartTextInput();	
  while(_gameExit == false){
    _fpsLimiter.begin();

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
    
    _inputMgr.update();
    
    processInput();
    update();
    draw();
    
    SDL_RenderPresent(_renderer);
    
    _fps = _fpsLimiter.end();
  }
  SDL_StopTextInput();

  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void Game::draw()
{
	_bg->draw();
	_frame->draw();
}

void Game::update()
{
}

void Game::processInput()
{
  SDL_Event e;
  while(SDL_PollEvent(&e) != 0){
    switch(e.type){
    case SDL_QUIT:
      _gameExit = true;
      break;
    case SDL_MOUSEMOTION:
      _inputMgr.setMouseCoords(e.motion.x, e.motion.y);
      break;
    case SDL_KEYDOWN:
      _inputMgr.pressKey(e.key.keysym.sym);
      break;
    case SDL_KEYUP:
      _inputMgr.releaseKey(e.key.keysym.sym);
      break;
    case SDL_MOUSEBUTTONDOWN:
      _inputMgr.pressKey(e.button.button);
      break;
    case SDL_MOUSEBUTTONUP:
      _inputMgr.releaseKey(e.button.button);
      break;
    }

		_inputMgr.dispatch(&e);
  }
}
