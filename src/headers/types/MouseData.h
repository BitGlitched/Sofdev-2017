#ifndef MOUSEDATA_H
#define MOUSEDATA_H

enum ClickType
{
	LEFT_CLICK,
	RIGHT_CLICK,
	MIDDLE_CLICK
};

struct MouseData
{
	int x, y;
	bool LeftClick;
	bool RightClick;
	bool MiddleClick;

	void UpdateMouse()
	{
		LeftClick = false;
		RightClick = false;
		MiddleClick = false;

		//Updates mouse position
		SDL_GetMouseState(&x, &y);

		//Checks to see if the left mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			LeftClick = true;
		}

		//Checks to see if the right mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			RightClick = true;
		}

		//Checks to see if the middle mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		{
			MiddleClick = true;
		}
	}
};

#endif
