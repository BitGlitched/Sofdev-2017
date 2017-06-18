#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

enum TextureMode
{
   STRETCH,
   REPEAT
};

//Texture class
class Texture
{
public:
   int ID = -1;
   std::string fileName = "";
   int width, height;
   TextureMode mode = STRETCH;

   //Constructor function
   Texture(std::string = "");

   //Loading function
   void Load();

   //Function to load multiple textures
   static void LoadTextures();
};

#endif
