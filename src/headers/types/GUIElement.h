#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Vector2.h"
#include "MouseData.h"

class GUIElement
{
private:
	Vector2 imageSize;
public:
	SDL_Texture* image = NULL;
	SDL_Rect transform;

	GUIElement(float x = 0.0f, float y = 0.0f, float w = 1.0f, float h = 1.0f, std::string ImagePath = "")
	{
		transform.x = x;
		transform.y = y;
		transform.w = w;
		transform.h = h;

		if (ImagePath != "")
		{
			//Loads the image
			image = IMG_LoadTexture(renderer, ImagePath.c_str());
			int w, h;
			SDL_QueryTexture(image, NULL, NULL, &w, &h);
			imageSize = Vector2(w, h);
		}
		else
		{
			printf("...\n");
		}
	}

	void ChangeImage(std::string ImagePath)
	{
		//gets rid of the previous image
		SDL_DestroyTexture(image);

		//Loads the new image
		image = IMG_LoadTexture(renderer, ImagePath.c_str());
		int w, h;
		SDL_QueryTexture(image, NULL, NULL, &w, &h);
		imageSize = Vector2(w, h);
	}

	void Draw()
	{
		SDL_RenderCopy(renderer, image, NULL, &transform);
	}

	bool CheckHover(MouseData mouse)
	{
		//Checks to see if mouse x is within the size of the element
		if (mouse.x > transform.x - ((float)transform.w / 2.0f) && mouse.x < transform.x + ((float)transform.w / 2.0f))
		{
			//Checks to see if mouse y is within the size of the element
			if (mouse.y > transform.y - ((float)transform.h / 2.0f) && mouse.y < transform.y + ((float)transform.h / 2.0f))
			{
				return true;
			}
		}

		return false;
	}
};

#endif
