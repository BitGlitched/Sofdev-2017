#include "headers/Main.h"
#define FONT "data/arial.ttf"

GUIElement wireToolButton;
GUIElement propertiesPanel;
GUIElement pickerPanel;
GUIElement arrow;
GUIElement forwardArrow;
GUIElement dropbownBox;
GUIElement grayBackground;
GUIElement checkBoxChecked;
GUIElement grid;
GUIElement battery;
GUIElement wire;
GUIElement resistor;
GUIElement capacitor;
GUIElement integratedCircuit;
GUIElement currentComponent;
GUIElement temp;

ToolType toolSelected = NONE;
int gridLockX;
int gridLockY;

int tempText;
TTF_Font* font;

Vector2 shiftViewStart;
Vector2 shiftViewOffset;

int componentOffsetX;
int componentOffsetY;

void InitGUI()
{
	arrow = GUIElement(-388.0f, 319.0f, 1.0f, 1.0f, TEX_ARROWLEFT);
	forwardArrow = GUIElement(-356.0f, 319.0f, 1.0f, 1.0f, TEX_ARROWRIGHT);
	//wireToolButton = GUIElement(
	propertiesPanel = GUIElement(-522.0f, 0.0f, 1.0f, 1.0f, TEX_PPANEL); //right edge at -404
   pickerPanel = GUIElement (0.0f, 319.0f, 1.0f, 1.0f, TEX_PICKER_PANEL);
   //dropbownBox = GUIElement (18.0f, 18.0f, 0.1f, 0.1f, TEX_DROPDOWN_BOX); //OPTION = GUIElement (200.0f, 200.0f, 50.0f, 50.0f, Options_Menu);
   //checkBoxChecked = GUIElement (100.0f, 100.0f, 0.1f, 0.1f, TEX_CHECKBOX_CHECKED);
   battery = GUIElement (-292.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   resistor = GUIElement (-228.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   capacitor = GUIElement (-164.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   integratedCircuit = GUIElement(-100.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   wire = GUIElement(-36.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   currentComponent = GUIElement();
   temp = GUIElement (0, 0, 0.10f, 0.10f, TEX_IC);
	grid = GUIElement (0, 0, 160.0f, 90.0f, TEX_GRID);
	grid.texture.mode = REPEAT;

	font = LoadFont((char*)FONT);
	tempText = RenderText((char*)"Test", {0, 0, 0, 0}, font);
}

void MoveView()
{
	grid.offset.x += (float)Mouse.velX * 0.001f;
	grid.offset.y += (float)Mouse.velY * 0.001f;

	shiftViewOffset.x += (float)Mouse.velX * 0.001f;
	shiftViewOffset.y += (float)Mouse.velY * 0.001f;

	//componentOffsetX = grid.offset.x - (int)grid.offset.x;
	//componentOffsetY = grid.offset.y - (int)grid.offset.y;
}

void UpdateGUI()
{
	/*if (Mouse.MiddleClickPressed)
	{
		if (Mouse.MiddleClickDown)
		{
			shiftViewStart = Vector2(Mouse.x, Mouse.y);
		}

		MoveView();
	}*/

	Draw2D(GUIShader, Vector2(), Vector2(1, 1), tempText);
	bool propertiesHover = propertiesPanel.CheckHover();
	bool pickerHover = pickerPanel.CheckHover();


	if (Mouse.LeftClickDown)
	{
		if (battery.CheckHover())
		{
			toolSelected = BATTERY;
		}
		if (wire.CheckHover())
		{
			toolSelected = WIRE;
		}
		if (resistor.CheckHover())
		{
			toolSelected = RESISTOR;
		}
		if (capacitor.CheckHover())
		{
			toolSelected = CAPACITOR;
		}
		if (integratedCircuit.CheckHover())
		{
			toolSelected = IC;
		}
	}

	if (toolSelected != NONE)
	{
		if(!pickerHover && !propertiesHover)
		{
			currentComponent.ChangeImage(TEX_IC);
			currentComponent.Draw();
			gridLockX = Mouse.x - (Mouse.x % 16);//(shiftViewOffset.x - componentOffsetX);
			gridLockY = Mouse.y - (Mouse.y % 16);//(shiftViewOffset.y - componentOffsetY);
			currentComponent.transform.x = gridLockX;
			currentComponent.transform.y = gridLockY;
		}
	}
}

void DrawGUI()
{
	grid.Draw();
	propertiesPanel.Draw();
	pickerPanel.Draw();
	arrow.Draw();
	battery.Draw();
	resistor.Draw();
	capacitor.Draw();
	forwardArrow.Draw();
	wire.Draw();
	integratedCircuit.Draw();
	temp.Draw();
}
