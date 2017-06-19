#ifndef MOUSEDATA_H
#define MOUSEDATA_H

#include "Vector2.h"

extern Vector2 WindowSize;
struct MouseData
{
private:
	int X, Y;
public:
	int x, y;
	int velX, velY;
	bool LeftClickPressed;
	bool LeftClickDown;
	bool RightClickPressed;
	bool RightClickDown;
	bool MiddleClickPressed;
	bool MiddleClickDown;

	void UpdateMouse()
	{
		LeftClickDown = false;
		RightClickDown = false;
		MiddleClickDown = false;

		//Updates mouse position
		SDL_GetMouseState(&x, &y);
		velX = X - x;
		velY = Y - y;

		X = x;
		Y = y;
		
		x -= WindowSize.x * 0.5f;
		y -= WindowSize.y * 0.5f;
		y = -y;

		//Checks to see if the left mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			if (!LeftClickPressed)
			{
				LeftClickDown = true;
			}
			else
			{
				LeftClickDown = false;
			}

			LeftClickPressed = true;
		}
		else
		{
			LeftClickPressed = false;
		}

		//Checks to see if the right mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			if (!RightClickPressed)
			{
				RightClickDown = true;
			}
			else
			{
				RightClickDown = false;
			}

			RightClickPressed = true;
		}
		else
		{
			RightClickPressed = false;
		}

		//Checks to see if the middle mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		{
			if (!MiddleClickPressed)
			{
				MiddleClickDown = true;
			}
			else
			{
				MiddleClickDown = false;
			}

			MiddleClickPressed = true;
		}
		else
		{
			MiddleClickPressed = false;
		}
	}
};

#endif
