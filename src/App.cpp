#include "headers/Main.h"
#include "headers/types/GUIElement.h"

//Defining texture paths example:
//#define TEX_EXAMPLE "data/imagename.png"
#define TEX_ARROW "data/PropertiesPanel.png"

//Creating GUIElements example:
//GUIElement element;
GUIElement propertiesPanel;

//Function called once on startup
//Actually make everything here
void Startup()
{
	//Making GUIElements example:
	//element = GUIElement(200.0f, 200.0f, 30.0f, 30.0f, TEX_EXAMPLE);
	//First argument provided is the x position, second is the y position, third is the x scale/size, fourth is the y scale/size, and fifth is the texture path

	propertiesPanel = GUIElement(0.0f, 100.0f, 100.0f, 500.0f, TEX_ARROW);
}

//Function updated every frame
void Update()
{
	propertiesPanel.transform.w = WindowSize.x / 5.0f;
	propertiesPanel.transform.h = WindowSize.y - propertiesPanel.transform.x;

	//Drawing GUIElements example:
	//element.Draw();
	propertiesPanel.Draw();

	//Checking for clicking a GUIElement example:
	//if (testElement.CheckHover(Mouse) && Mouse.LeftClickDown)
	//{
		//printf("Clicked!\n");
	//}
}
