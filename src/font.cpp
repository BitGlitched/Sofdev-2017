#include "headers/Main.h"

#define FontResolution 64
TTF_Font* LoadFont (char* path)
{
	TTF_Font* font = TTF_OpenFont(path, FontResolution);
	if (!font) return NULL;
	return font;
};

int RenderText (char* str, SDL_Color color, TTF_Font* font)
{
	if (!str) return -1;
	if (!*str) return -1;
	if (!font) return -1;

	SDL_Surface* surface = TTF_RenderUTF8_Blended(font, str, color);
	/*SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);*/
	GLuint texture;
	GLenum texture_format;
	Uint8 colors = surface->format->BytesPerPixel;

	if (colors == 4)
	{   // alpha
    	if (surface->format->Rmask == 0x000000ff)
		{
        	texture_format = GL_RGBA;
	  	}
    	else
		{
      	texture_format = GL_BGRA_EXT;
		}
	}
	else
	{             // no alpha
	   if (surface->format->Rmask == 0x000000ff)
		{
	      texture_format = GL_RGB;
		}
	   else
		{
	   	texture_format = GL_BGR_EXT;
		}
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, colors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);

	return texture;
};
