#include <stdio.h>

#include "headers/Main.h"
#include "headers/Functions.h"
#include "types/Button.h"

int main()
{
	Button newButton;
	Button Button2;

	newButton.positionX = 3;
	newButton.positionY = 6.5f;
	newButton.sizeX = 1;
	newButton.sizeY = 1;

	while(1)
	{
		if (newButton.CheckClick())
		{
			DoThing();
		}
	}
}
