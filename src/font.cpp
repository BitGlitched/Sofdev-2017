#include <SDL.h>
#include <SDL_ttf.h>

#define FontResolution 64
TTF_Font* slLoadFont (char* path)
{
	TTF_Font* font = TTF_OpenFont(path,FontResolution);
	if (!font) return NULL;
	return font;
};

extern SDL_Renderer* renderer;
SDL_Texture* RenderText (char* str, SDL_Color color, TTF_Font* font)
{
	if (!str) return NULL;
	if (!*str) return NULL;
	if (!font) return NULL;
	
	SDL_Surface* surf = TTF_RenderText_Blended(font,str,color);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2");
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer,out->surf);
	SDL_SetTextureBlendMode(tex,SDL_BLENDMODE_BLEND);
	
	return tex;
};
