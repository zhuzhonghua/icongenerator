#include "stdafx.h"

#include "toucharea.h"
#include "inputmanager.h"

TouchArea::TouchArea(Rect rect)
	:_rect(rect),
	 _touchDown(false),
	 _onClick(NULL)
{
	InputManager::inst()->addEventListener(this);
}

TouchArea::TouchArea(int x, int y, int w, int h)
	:_rect(Utils::rect(x,y,w,h)),
	 _touchDown(false),
	 _onClick(NULL)
{
	InputManager::inst()->addEventListener(this);
}

void TouchArea::changeRect(Rect rect)
{
	_rect = rect;
}

void TouchArea::changeRect(int x, int y, int w, int h)
{
	_rect = Utils::rect(x,y,w,h);
}

TouchArea::~TouchArea()
{
	InputManager::inst()->removeEventListener(this);
}

bool TouchArea::overlapPoint(float x, float y)
{
	return x >= _rect.x && x < _rect.x + _rect.w && y >= _rect.y && y < _rect.y + _rect.h;
}

bool TouchArea::onEvent(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN &&
			e->button.button == SDL_BUTTON_LEFT)
	{
		int x = e->button.x;
		int y = e->button.y;

		if (this->overlapPoint(x, y))
		{
			_touchDown = true;
			this->onTouchDown();
			
			return true;
		}
	}

	if (e->type == SDL_MOUSEBUTTONUP &&
			e->button.button == SDL_BUTTON_LEFT)
	{
		int x = e->button.x;
		int y = e->button.y;

		if (this->overlapPoint(x, y))
		{
			_touchDown = false;
			this->onTouchUp();
			if(this->_onClick)
			{
				_onClick(this);
			}
			//this->onClick();

			return true;
		}
		else
		{
			if (_touchDown)
			{
				_touchDown = false;
				this->onTouchUp();

				return true;
			}
		}
	}

	return false;
}
