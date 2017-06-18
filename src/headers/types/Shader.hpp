#ifndef SHADER_HPP
#define SHADER_HPP

//Class for custom shaders
class Shader
{
public:
   GLuint Program;

   //Constructor functions
   Shader();
   Shader(char*, char*);

   //Regular functions
   void Use();
};

#endif
