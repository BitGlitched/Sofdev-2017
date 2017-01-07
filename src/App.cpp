#include "headers/Main.h"
#include "headers/types/GUIElement.h"

#define TEX_PROTOTYPING "data/Prototyping.png"

GUIElement testElement;

//Function called once on startup
void Startup()
{
	testElement = GUIElement(200.0f, 200.0f, 30.0f, 30.0f, TEX_PROTOTYPING);
}

//Function updated every frame
void Update()
{
	//Software code goes here
	testElement.Draw();

	if (testElement.CheckHover(Mouse) && Mouse.LeftClick)
	{
		printf("Clicked!\n");
	}
}
