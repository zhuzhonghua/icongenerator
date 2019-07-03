#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
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
typedef SDL_Texture Texture;
typedef SDL_Event Event;

#include "util.h"
#include "imageutil.h"
#include "textutil.h"

static inline void trace(const char* cmd, ...)
{
  va_list args;
  va_start(args, cmd);
  vprintf(cmd, args);
  va_end(args);
}

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//__VA_ARGS
#define INFO(cmd, args...)  trace(cmd "\n", ##args)

#define ERROR(cmd, args...)  trace(ANSI_COLOR_RED cmd ANSI_COLOR_RESET "\n", ##args)
