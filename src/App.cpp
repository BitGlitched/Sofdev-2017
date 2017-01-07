#include "headers/Main.h"
#include "headers/types/Vector2.h"
#include "headers/types/GUIElement.h"

#define TEX_PROTOTYPING "data/Prototyping.png"

Vector2 WindowSize;
GUIElement testElement;

struct MouseData
{
	int x, y;
	bool leftMouse;
	bool rightMouse;
	bool middleMouse;

	void UpdateMouse()
	{
		leftMouse = false;
		rightMouse = false;
		middleMouse = false;

		//Updates mouse position
		SDL_GetMouseState(&x, &y);

		//Checks to see if the left mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			leftMouse = true;
		}

		//Checks to see if the right mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			rightMouse = true;
		}

		//Checks to see if the middle mouse button is pressed
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		{
			middleMouse = true;
		}
	}
} Mouse;

void Startup()
{
	testElement = GUIElement(200.0f, 200.0f, 30.0f, 30.0f, TEX_PROTOTYPING);
}

void UpdateVars()
{
	//Updates the mouse
	Mouse.UpdateMouse();
	//Gets the window size and stores it in a Vector2
	int winSizeX, winSizeY;
	SDL_GetWindowSize(window, &winSizeX, &winSizeY);
	WindowSize = Vector2(winSizeX, winSizeY);
}

void Update()
{
	//Software code goes here
	testElement.Draw();
}
