#ifndef BUTTON_H
#define BUTTON_H

#include "../headers/Main.h"

class Button
{
public:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;

	Button(float xPos, float yPos, float sizX, float sizY)
	{
		positionX = xPos;
		positionY = yPos;
		sizeX = sizX;
		sizeY = sizY;
	}

	bool CheckClick()
	{
		if (MousePositionX < positionX + sizeX && MousePositionX > positionX - sizeX && MousePositionY < positionY + sizeY && MousePositionY > positionY - sizeY)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

#endif
