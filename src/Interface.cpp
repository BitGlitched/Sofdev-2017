#include "headers/Main.h"

GUIElement wireToolButton;
GUIElement propertiesPanel;
GUIElement pickerPanel;
GUIElement arrow;
GUIElement dropbownBox;
GUIElement grayBackground;
GUIElement checkBoxChecked;

void InitGUI()
{
	//wireToolButton = GUIElement(
	propertiesPanel = GUIElement(-522.0f, 0.0f, 1.0f, 1.0f, TEX_PPANEL);
   pickerPanel = GUIElement (0.0f, 319.0f, 1.0f, 1.0f, TEX_PICKER_PANEL);
   dropbownBox = GUIElement (18.0f, 18.0f, 0.1f, 0.1f, TEX_DROPDOWN_BOX); //OPTION = GUIElement (200.0f, 200.0f, 50.0f, 50.0f, Options_Menu);
   checkBoxChecked = GUIElement (100.0f, 100.0f, 0.1f, 0.1f, TEX_CHECKBOX_CHECKED);
   arrow = GUIElement (167.0f, 18.0f, 0.1f, 0.1f, TEX_ARROW);
}

void UpdateGUI()
{
	propertiesPanel.CheckHover();
	pickerPanel.CheckHover();
}

void DrawGUI()
{
	propertiesPanel.Draw();
	pickerPanel.Draw();
	//checkBoxChecked.Draw();
}
