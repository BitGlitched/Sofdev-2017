#ifndef GUIELEMENT_H
#define GUIELEMENT_H

#include "../Main.h"

class GUIElement
{
public:
	Vector2 imageSize;
	Texture texture;
	Vector2 transform;
	Vector2 scale;

	GUIElement(float x = 0.0f, float y = 0.0f, float w = 1.0f, float h = 1.0f, std::string ImagePath = "")
	{
		transform.x = x;
		transform.y = y;
		scale.x = w;
		scale.y = h;

		if (ImagePath != "")
		{
			printf("Creating texture\n");
			texture = Texture(ImagePath);
			texture.Load();
			imageSize = Vector2(texture.width, texture.height);
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
		imageSize = Vector2(texture.width, texture.height);
	}

	void Draw(int mode = 0, Vector2 offset = Vector2(0.0f, 0.0f))
	{
		//printf("Transform: %f, %f   Scale: %f, %f\n\n", transform.x, transform.y, scale.x, scale.y);
		Draw2D(GUIShader, Vector2(transform.x, transform.y), Vector2(scale.x, scale.y), texture.ID, texture.mode, Vector2(1.0f, 1.0f), offset);
	}

	bool CheckHover()
	{
		//Checks to see if the mouse is within the element
		if (Mouse.x > transform.x - (0.5f * scale.x * imageSize.x) && Mouse.x < transform.x + (0.5f * scale.x * imageSize.x) && Mouse.y > transform.y - (0.5f * scale.y * imageSize.y) && Mouse.y < transform.y + (0.5f * scale.y * imageSize.y))
		{
			return true;
		}

		return false;
	}
};

#endif
