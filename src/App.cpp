#include "headers/Main.h"
#include "headers/types/GUIElement.h"


#define Options_Menu "data/DropdownMenu.png"
#define Arrow "data/ARROW.png"
#define Dropdown "data/DropdownBackground.png"
#define Panel_Gray "data/GrayBackground.png"
#define Black_Panel "data/CircuitPickerPanel.png"
#define Black_Check "data/CheckboxChecked.png"

//Defining texture paths example:
//#define TEX_EXAMPLE "data/imagename.png"
#define TEX_ARROW "data/PropertiesPanel.png"

//Creating GUIElements example:
//GUIElement element;
GUIElement propertiesPanel;
GUIElement Black_Box;
GUIElement arrow;
GUIElement OPTION;
GUIElement Gray;
GUIElement Check;

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
	propertiesPanel = GUIElement(0.0f, 60.0f, 100.0f, 600.0f, TEX_ARROW);
  Black_Box = GUIElement (0.0f, 0.0f, 500.0f, 50.0f, Black_Panel);
              //OPTION = GUIElement (200.0f, 200.0f, 50.0f, 50.0f, Options_Menu);
  OPTION = GUIElement (18.0f, 18.0f, 25.0f, 25.0f, Options_Menu);
  Check = GUIElement ( 0.0f, 0.0f, 30.0f, 30.0f, Black_Check);
  arrow = GUIElement (167.0f, 18.0f, 40.0f, 30.0f, Arrow);
}

//Function updated every frame
void Update()
{
	propertiesPanel.transform.w = WindowSize.x / 5.0f; // / 5.0f;
	propertiesPanel.transform.h = WindowSize.y;  //propertiesPanel.transform.y; //- propertiesPanel.transform.x; wth andrew. You're litterally subtracting Zero...

  Black_Box.transform.w = WindowSize.x;    //  / 5.0f;
  Black_Box.transform.h = WindowSize.y / 9.7f;

  OPTION.transform.w = WindowSize.x / 35 ;
  OPTION.transform.h = WindowSize.y / 21 ;

  arrow.transform.w = WindowSize.x / 17;
  arrow.transform.h = WindowSize.y / 25;
  //arrow.transform.x = WindowSize.x + 30;

//  Black_Box.transform.h = WindowSize.y - Black_Box.transform.x;

  //Gray.Draw();
  //OPTION.Draw();

//Gray.transform.x += 0.01f;

	//Drawing GUIElements example:

	//element.Draw();
	propertiesPanel.Draw();
  Black_Box.Draw();

  Check.Draw();
  OPTION.Draw();
  arrow.Draw();
	//Checking for clicking a GUIElement example:
	//if (testElement.CheckHover(Mouse) && Mouse.LeftClickDown)
	//{
		//printf("Clicked!\n");
	//}
}
