#include "headers/Main.h"
#include "headers/types/GUIElement.h"


#define Options_Menu "data/3 BAR THING.png"
#define Arrow "data/ARROW.png"
#define Dropdown "data/DropdownBackground.png"
#define Panel_Gray "data/GrayBackground.png"



//Defining texture paths example:
//#define TEX_EXAMPLE "data/imagename.png"
#define TEX_ARROW "data/PropertiesPanel.png"

//Creating GUIElements example:
//GUIElement element;
GUIElement propertiesPanel;

GUIElement arrow;
GUIElement OPTION;
GUIElement Gray;


//Function called once on startup
//Actually make everything here
void Startup()
{
 	Gray = GUIElement (40.0f, 200.0f, 150.0f, 400.0f, Panel_Gray);
	arrow = GUIElement (26.0f, 12.0f, 30.0f, 30.0f, Arrow);
 	OPTION = GUIElement (16.0f, 12.0f, 30.0f, 30.0f, Options_Menu);
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

<<<<<<< HEAD
=======
  Gray.Draw();
  OPTION.Draw();
  arrow.Draw();
Gray.transform.x += 0.01f;
>>>>>>> origin/master
=======
  	Gray.Draw();
  	OPTION.Draw();
  	arrow.Draw();
	Gray.transform.x += 0.000000000001f;
>>>>>>> origin/master
	//Drawing GUIElements example:

	//element.Draw();
	propertiesPanel.Draw();

	//Checking for clicking a GUIElement example:
	//if (testElement.CheckHover(Mouse) && Mouse.LeftClickDown)
	//{
		//printf("Clicked!\n");
	//}
}
