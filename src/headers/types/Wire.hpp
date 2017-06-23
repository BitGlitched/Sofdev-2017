#ifndef LINE_HPP
#define LINE_HPP

#include "GUIElement.h"

enum Direction
{
   LEFT,
   RIGHT,
   UP,
   DOWN
};

class Wire : public GUIElement
{
public:
   float thickness;
   Vector2 transform;
   Vector2 endTransform;
   Direction direction;

   Wire(Vector2 startPosition = Vector2(), Vector2 endPosition = Vector2(), float thick = 4, Color clr = Color(1.0f, 1.0f, 1.0f, 1.0f), Direction dir = LEFT)
   {
      transform = startPosition;
      endTransform = endPosition;
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
      DrawLine(transform, endTransform, thickness, color);
   }
};

#endif
