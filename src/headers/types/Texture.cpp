#include "../Main.h"
#include <GL/SOIL.h>
#include <fstream>

Texture::Texture(std::string Path)
{
   if (Path == "")
   {
      printf("Empty texture object created!\n");
   }
   else
   {
      if (std::ifstream(Path.c_str()).good())
      {
         fileName = Path;
         GLuint id;
         glGenTextures(1, &id);
         ID = id;
         std::string info = "Texture created!\n Path: ";
         info += Path + "\n";
         printf(info.c_str());
      }
      else
      {
         std::string err = "File does not exist!\n Path: ";
         err += Path + "\n";
         printf(err.c_str());
      }
   }
}

void Texture::Load()
{
   if (ID != -1)
   {
      glEnable(GL_TEXTURE_2D);
      //Load the texture from the path given using the SOIL library, and also gets the width and hieght of the texture in pixels
      unsigned char* baseImage = SOIL_load_image(fileName.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);

      //Generates the texture
      glBindTexture(GL_TEXTURE_2D, ID);

      //Area for texture options
      // Set the texture wrapping parameters
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      // Set texture filtering parameters
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

      //Attatches the image onto our currently bound texture
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, baseImage);

      //Frees the image data from memory and makes sure there is no bound texture for GL_TEXTURE_2D
      SOIL_free_image_data(baseImage);
      glBindTexture(GL_TEXTURE_2D, 0);
   }
}
