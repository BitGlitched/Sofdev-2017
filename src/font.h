#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

TTF_Font* slLoadFont (char* path);
SDL_Texture* RenderText (char* str, SDL_Color color, TTF_Font* font);