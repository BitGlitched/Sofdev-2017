#ifndef LINE_HPP
#define LINE_HPP

#include "GUIElement.h"

enum Direction
{
   HORIZONTAL,
   VERTICAL
};

class Wire : public GUIElement
{
public:
   float thickness;
   float distance;
   Vector2 transform;
   Direction direction;

   Wire(Vector2 startPosition = Vector2(), float dist = 1.0f, float thick = 4, Color clr = Color(1.0f, 1.0f, 1.0f, 1.0f), Direction dir = VERTICAL)
   {
      transform = startPosition;
      distance = dist;
      thickness = thick;
      color = clr;
      direction = dir;
   }

   //MODIFY TO FACTOR IN WIRE LENGTH AND THICKNESS, ALSO DIRECTION
   bool CheckHover()
   {
      //Checks to see if the mouse is within the element
		if (Mouse.x > transform.x - (0.5f * scale.x * imageSize.x) && Mouse.x < transform.x + (0.5f * scale.x * imageSize.x) && Mouse.y > transform.y - (0.5f * scale.y * imageSize.y) && Mouse.y < transform.y + (0.5f * scale.y * imageSize.y))
		{
			return true;
		}

		return false;
   }

   void Draw()
   {
      Vector2 actualEnd;

      if (direction == HORIZONTAL)
      {
         actualEnd.x = transform.x + distance;
         actualEnd.y = transform.y;
      }
      else
      {
         actualEnd.x = transform.x;
         actualEnd.y = transform.y + distance;
      }

      DrawLine(transform, actualEnd, thickness, color);
   }
};

#endif
