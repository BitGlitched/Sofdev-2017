#include "../Main.h"

using namespace std;

//Constructor function with no arguments
Shader::Shader()
{
   printf("Empty shader object created!\n");
}

//Valid constructor fucntion
Shader::Shader(char* VertexShaderPathIn, char* FragmentShaderPathIn)
{
   if (VertexShaderPathIn == "" || FragmentShaderPathIn == "")
   {
      printf("There is a missing path one or both of the GLSL Shader files!\n");
   }
   string vertexShaderString = ReadFile(VertexShaderPathIn);
   string fragmentShaderString = ReadFile(FragmentShaderPathIn);

   //Prints out the string to show the shader's code
   //printf("\n%s\n", vertexShaderString.c_str());
   //printf("\n%s\n", fragmentShaderString.c_str());

   //Creates the GLchars needed to input the shader code
   //Using direct input right now bc reading input is broken
   const GLchar* vertex_shader = vertexShaderString.c_str();

   const GLchar* fragment_shader = fragmentShaderString.c_str();

   //Creates a vertex shader and compiles it
   GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
   printf("Blank vertex shader created...");
   glShaderSource(vertexShader, 1, &vertex_shader, NULL);
   printf("Vertex shader given source...");
   glCompileShader(vertexShader);

   //Compilation error checking begions here
   GLint isVertexCompiled = 0;
   glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isVertexCompiled);
   if (isVertexCompiled == GL_FALSE)
   {
      //Gets the length of the log
      GLint maxLength = 0;
      glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

      //Creates and writes the log to the errorLog
      GLchar* errorLog = (GLchar*)malloc(maxLength);
      glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &errorLog[0]);

      //Writes to the engine log with the shader error
      printf("Vertex shader failed to compile!\n");
      printf("%s\n", (char*)errorLog);

      //Frees the errorLog allocation
      free(errorLog);

      //Deletes the shader so it doesn't leak
      glDeleteShader(vertexShader);

      printf("Aborting shader creation.");
      return;
   }
   //Writes in the engine log to report successful compilation
   printf("Vertex shader successfully compiled!");

   //Creates a fragment shader
   GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   printf("Blank fragment shader created...");
   glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
   printf("Fragment shader given source...");
   glCompileShader(fragmentShader);

   //Compilation error checking begions here
   GLint isFragmentCompiled = 0;
   glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isFragmentCompiled);
   if (isFragmentCompiled == GL_FALSE)
   {
      //Gets the length of the log
      GLint maxLength = 0;
      glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

      //Creates and writes the log to the errorLog
      GLchar* errorLog = (GLchar*)malloc(maxLength);
      glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &errorLog[0]);

      printf("Fragment shader failed to compile!\n");
      printf((char*)errorLog);

      //Frees the errorLog allocation
      free(errorLog);

      //Deletes the shader so it doesn't leak
      glDeleteShader(vertexShader);
      glDeleteShader(fragmentShader);

      printf("Aborting shader creation.\n");
      return;
   }
   //Writes in the engine log to report successful compilation
   printf("Fragment shader successfully compiled!");

   //Creates the final shader product
   this->Program = glCreateProgram();
   printf("Blank shader created!");
   glAttachShader(this->Program, vertexShader);
   printf("Attatched Vertex shader to the shader!");
   glAttachShader(this->Program, fragmentShader);
   printf("Attatched Fragment shader to the shader!");
   glLinkProgram(this->Program);

   printf("Linking the shader program...");
   GLint isLinked = 0;
   glGetProgramiv(this->Program, GL_LINK_STATUS, (int*)&isLinked);
   if (isLinked == GL_FALSE)
   {
      printf("Shader program linking failed, error info:");
      //Gets the lngth of the shader info log
      GLint maxLength = 0;
      glGetProgramiv(this->Program, GL_INFO_LOG_LENGTH, &maxLength);

      //Gets and puts the actual log into a GLchar
      GLchar* errorLog = (GLchar*)malloc(maxLength);
      glGetProgramInfoLog(this->Program, maxLength, &maxLength, &errorLog[0]);

      //Deletes programs and shaders so they don't leak
      glDeleteShader(vertexShader);
      glDeleteShader(fragmentShader);

      printf(errorLog);
      printf("Aborting shader creation.\n");
      return;
   }

   printf("Shader linked!");

   printf("Shader created!\n");

   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);
}

//Regular functions
void Shader::Use()
{
   glUseProgram(this->Program);
}
