#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <boost/random.hpp>

#ifndef NULL
#define NULL 0
#endif

#define ASSERT(expr) if(!(expr)) *(int*)0 = 0;

static inline void fatalError(std::string info)
{
  std::cout << info << std::endl;
  std::cout << "Enter Any Key To Exit" << std::endl;
  int tmp;
  std::cin >> tmp;
  SDL_Quit();
  exit(1);
}

typedef SDL_Rect Rect;
typedef SDL_Point Point;

#include "util.h"
#include "imageutil.h"
