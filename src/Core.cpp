#include "headers/Main.h"
#include "headers/Functions.h"
#include "types/Button.h"

float MousePositionX = 10;
float MousePositionY = 20;

int main()
{
	Button newButton(3, 6.5f, 1, 1);
	Button button2 = Button(1, 7, 1, 1);

	while(1)
	{
		if (newButton.CheckClick())
		{
			DoThing();
		}
	}
}
