#include "headers/Main.h"
#define FONT "data/arial.ttf"

GUIElement wireToolButton;
GUIElement propertiesPanel;
GUIElement pickerPanel;
GUIElement arrow;
GUIElement dropbownBox;
GUIElement grayBackground;
GUIElement checkBoxChecked;
GUIElement grid;

int tempText;
TTF_Font* font;

Vector2 shiftViewStart;

void InitGUI()
{
	//wireToolButton = GUIElement(
	propertiesPanel = GUIElement(-522.0f, 0.0f, 1.0f, 1.0f, TEX_PPANEL);
   pickerPanel = GUIElement (0.0f, 319.0f, 1.0f, 1.0f, TEX_PICKER_PANEL);
   dropbownBox = GUIElement (18.0f, 18.0f, 0.1f, 0.1f, TEX_DROPDOWN_BOX); //OPTION = GUIElement (200.0f, 200.0f, 50.0f, 50.0f, Options_Menu);
   checkBoxChecked = GUIElement (100.0f, 100.0f, 0.1f, 0.1f, TEX_CHECKBOX_CHECKED);
   arrow = GUIElement (167.0f, 18.0f, 0.1f, 0.1f, TEX_ARROW);
	grid = GUIElement (0, 0, 160.0f, 90.0f, TEX_GRID);
	grid.texture.mode = REPEAT;

	font = LoadFont((char*)FONT);
	tempText = RenderText((char*)"Test", {0, 0, 0, 0}, font);
}

void UpdateGUI()
{
	if (Mouse.MiddleClickPressed)
	{
		if (Mouse.MiddleClickDown)
		{
			shiftViewStart = Vector2(Mouse.x, Mouse.y);
		}

		grid.offset.x += (float)Mouse.velX * 0.00075f;
		grid.offset.y += (float)Mouse.velY * 0.00075f;
		printf("Offset: %f, %f\n", grid.offset.x, grid.offset.y);
	}

	Draw2D(GUIShader, Vector2(), Vector2(1, 1), tempText);
	propertiesPanel.CheckHover();
	pickerPanel.CheckHover();
}

void DrawGUI()
{
	grid.Draw();
	propertiesPanel.Draw();
	pickerPanel.Draw();
	//checkBoxChecked.Draw();
}
