#include <stdio.h>
#include "headers/Button.h"
#include "headers/Functions.h"

int main()
{
	Button newButton;
	Button Button2;

	newButton.positionX = 3f;
	newButton.positionY = 6.5f;

	if (newButton.CheckClicked())
	{
		DoThing();
	}
}
