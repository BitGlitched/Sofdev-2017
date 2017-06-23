#ifndef COLOR_HPP
#define COLOR_HPP

//Color class for storing a color's numerical value
class Color
{
public:
   float r, g, b, a;

   //Constructor function
   Color(float red = 1.0f, float green = 1.0f, float blue = 1.0f, float alpha = 1.0f);
};

#endif
