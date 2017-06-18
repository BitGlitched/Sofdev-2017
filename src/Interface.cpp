#include "headers/Main.h"

GUIElement wireToolButton;
GUIElement propertiesPanel;
GUIElement Black_Box;
GUIElement arrow;
GUIElement OPTION;
GUIElement Gray;
GUIElement Check;
GUIElement Drop;

void InitGUI()
{
	//wireToolButton = GUIElement(
	propertiesPanel = GUIElement(0.0f, 60.0f, 100.0f, 600.0f, TEX_ARROW);
   Black_Box = GUIElement (0.0f, 0.0f, 500.0f, 50.0f, Black_Panel);
   OPTION = GUIElement (18.0f, 18.0f, 25.0f, 25.0f, Options_Menu); //OPTION = GUIElement (200.0f, 200.0f, 50.0f, 50.0f, Options_Menu);
   Check = GUIElement (0.0f, 0.0f, 0.0f, 30.0f, Black_Check);
   arrow = GUIElement (167.0f, 18.0f, 40.0f, 30.0f, Arrow);
   Drop = GUIElement (73.0f, 70.0f, 80.0f, 17.0f, DropB);
}

void ScaleGUI()
{
	propertiesPanel.transform.w = WindowSize.x / 5.0f; // / 5.0f;
	propertiesPanel.transform.h = WindowSize.y;

   Black_Box.transform.w = WindowSize.x;
   Black_Box.transform.h = WindowSize.y / 9.7f;

   OPTION.transform.w = WindowSize.x / 35;
   OPTION.transform.h = WindowSize.y / 21;

   arrow.transform.w = WindowSize.x / 34;
   arrow.transform.h = WindowSize.y / 24;
   arrow.transform.x = WindowSize.x / 4.5;
   arrow.transform.y = (WindowSize.y / 50) + 5;

   Drop.transform.x = WindowSize.x / 11.5f;
   Drop.transform.y = WindowSize.y / 7.0f;
}

void DrawGUI()
{
	propertiesPanel.Draw();
   Black_Box.Draw();

   Check.Draw();
   OPTION.Draw();
   arrow.Draw();
   Drop.Draw();
}
