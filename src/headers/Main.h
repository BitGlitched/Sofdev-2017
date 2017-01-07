#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "types/Vector2.h"
#include "types/MouseData.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern Vector2 WindowSize;
extern bool CloseWindow;

extern MouseData Mouse;

void Startup();
void Update();

#endif
