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
GUIElement switchB;
GUIElement resistor;
GUIElement capacitor;
GUIElement integratedCircuit;
GUIElement currentComponent;
GUIElement lightBulb;

std::vector<GUIElement*> components;
int elementNumber;

GUIElement* selected = NULL;

ToolType toolSelected = NONE;
int gridLockX;
int gridLockY;

int tempText;
TTF_Font* font;

Vector2 shiftViewStart;
Vector2 shiftViewOffset;

int componentOffsetX;
int componentOffsetY;

Texture texArrowLeft;
Texture texArrowRight;
Texture texIC;
Texture texResistor;
Texture texCapacitor;
Texture texSwitch;
Texture texLight;

void TryAddComponent()
{
	for (int i = 0; i < components.size(); i++)
	{
		GUIElement* comp = components.at(i);

		if (currentComponent.transform.x + 32.0f > comp->transform.x - 32.0f && currentComponent.transform.x - 32.0f < comp->transform.x + 32.0f &&
			currentComponent.transform.y + 32.0f > comp->transform.y - 32.0f && currentComponent.transform.y - 32.0f < comp->transform.y + 32.0f)
		{
			printf("Failed to place\n");
			return;
		}
	}

	//if (toolSelected == )
	components.push_back(new GUIElement(currentComponent));
}

void InitGUI()
{
	texArrowLeft = Texture(TEX_ARROWLEFT);
	texArrowLeft.Load();
	texArrowRight = Texture(TEX_ARROWRIGHT);
	texArrowRight.Load();
	texIC = Texture(TEX_IC);
	texIC.Load();
	texResistor = Texture();
	texResistor.Load();
	texCapacitor = Texture();
	texCapacitor.Load();
	texSwitch = Texture();
	texSwitch.Load();
	texLight = Texture();
	texLight.Load();

	arrow = GUIElement(-388.0f, 319.0f, 1.0f, 1.0f, TEX_ARROWLEFT);
	forwardArrow = GUIElement(-356.0f, 319.0f, 1.0f, 1.0f, TEX_ARROWRIGHT);
	propertiesPanel = GUIElement(-522.0f, 0.0f, 1.0f, 1.0f, TEX_PPANEL); //right edge at -404
   pickerPanel = GUIElement (0.0f, 319.0f, 1.0f, 1.0f, TEX_PICKER_PANEL);
   battery = GUIElement (-292.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   resistor = GUIElement (-228.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   capacitor = GUIElement (-164.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   integratedCircuit = GUIElement(-100.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   switchB = GUIElement(-36.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   lightBulb = GUIElement(28.0f, 319.0f, 1.0f, 1.0f, TEX_IC);
   currentComponent = GUIElement();
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
		else if (switchB.CheckHover())
		{
			toolSelected = SWITCHB;
		}
		else if (resistor.CheckHover())
		{
			toolSelected = RESISTOR;
		}
		else if (capacitor.CheckHover())
		{
			toolSelected = CAPACITOR;
		}
		else if (integratedCircuit.CheckHover())
		{
			toolSelected = IC;
		}
		else if (lightBulb.CheckHover())
		{
			toolSelected = LIGHTBULB;
		}
		else if (toolSelected == NONE)
		{
			for (int i = 0; i < components.size(); i++)
			{
				if (components.at(i)->CheckHover())
				{
					selected = components.at(i);
					toolSelected = SELECTED;
					elementNumber = i;
					printf("Set selected\n");
				}
			}
		}
	}

	if (ButtonEscPressed)
	{
		toolSelected = NONE;
		printf("Removed tool\n");
	}

	if (toolSelected == SELECTED && toolSelected != NONE && ButtonDelPressed && selected != NULL)
	{
		components.erase (components.begin() + elementNumber);
		toolSelected = NONE;
	}

	if (toolSelected != NONE && toolSelected != SELECTED)
	{
		if(!pickerHover && !propertiesHover)
		{
			currentComponent.Draw();
			gridLockX = Mouse.x - (Mouse.x % 16);//(shiftViewOffset.x - componentOffsetX);
			gridLockY = Mouse.y - (Mouse.y % 16);//(shiftViewOffset.y - componentOffsetY);
			currentComponent.transform.x = gridLockX;
			currentComponent.transform.y = gridLockY;

			/*if (toolSelected == IC)
			{*/
				currentComponent.ChangeImage(texIC);
			//}

			if (Mouse.LeftClickDown)
			{
				TryAddComponent();
			}
		}
	}
}

void DrawGUI()
{
	grid.Draw();

	for (GUIElement* i : components)
	{
		i->Draw();
	}

	propertiesPanel.Draw();
	pickerPanel.Draw();
	arrow.Draw();
	battery.Draw();
	resistor.Draw();
	capacitor.Draw();
	forwardArrow.Draw();
	switchB.Draw();
	lightBulb.Draw();
	integratedCircuit.Draw();
}
