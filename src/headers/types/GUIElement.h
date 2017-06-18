#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include "../Main.h"

class GUIElement
{
public:
	Vector2 imageSize;
	Texture texture;
	SDL_Rect transform;

	GUIElement(float x = 0.0f, float y = 0.0f, float w = 1.0f, float h = 1.0f, std::string ImagePath = "")
	{
		transform.x = x;
		transform.y = y;
		transform.w = w;
		transform.h = h;

		if (ImagePath != "")
		{
			printf("Creating texture\n");
			texture = Texture(ImagePath);
			texture.Load();
			printf("Created texture\n");
		}
	}

	void ChangeImage(std::string ImagePath)
	{
		//gets rid of the previous image
		//SDL_DestroyTexture(image);

		//Loads the new image
		/*image = IMG_LoadTexture(renderer, ImagePath.c_str());
		int w, h;
		SDL_QueryTexture(image, NULL, NULL, &w, &h);
		imageSize = Vector2(w, h);*/

		texture = Texture(ImagePath);
		texture.Load();
	}

	void Draw(int mode = 0, Vector2 offset = Vector2(0.0f, 0.0f))
	{
		Draw2D(Vector2(transform.x, transform.y), Vector2(transform.w, transform.h), texture.ID, texture.mode, Vector2(1.0f, 1.0f), offset);
	}

	bool CheckHover(MouseData mouse)
	{
		//Checks to see if the mouse is within the element
		if (mouse.x > transform.x && mouse.x < transform.x + transform.w && mouse.y > transform.y && mouse.y < transform.y + transform.h)
		{
			return true;
		}

		return false;
	}
};

#endif
