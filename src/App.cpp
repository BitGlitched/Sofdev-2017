#include "headers/Main.h"
#include "headers/GUI.h"

bool WireSelected = false;

//std::vector<int> v;

//Function called once on startup
//Actually make everything here
void Startup()
{
 	//Gray = GUIElement (40.0f, 200.0f, 150.0f, 400.0f, Panel_Gray);
	//arrow = GUIElement (26.0f, 12.0f, 30.0f, 30.0f, Arrow);
	//Making GUIElements example:
	//element = GUIElement(200.0f, 200.0f, 30.0f, 30.0f, TEX_EXAMPLE);
	//First argument provided is the x position, second is the y position, third is the x scale/size, fourth is the y scale/size, and fifth is the texture path
	// Y = 575 is roughly the bottom of the Interface
   InitGUI();
}

//Function updated every frame
void Update()
{
   ScaleGUI();
   DrawGUI();

	//Checking for clicking a GUIElement example:
	//if (testElement.CheckHover(Mouse) && Mouse.LeftClickDown)
	//{
		//printf("Clicked!\n");
	//}
}
