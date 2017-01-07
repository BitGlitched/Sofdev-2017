#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

void Startup();
void UpdateVars();
void Update();

#endif
