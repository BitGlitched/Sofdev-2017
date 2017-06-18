#include "headers/Main.h"

#define DEFAULT_VERTEX_SHADER "data/shaders/330Vertex.glsl"
#define DEFAULT_FRAGMENT_SHADER "data/shaders/330Fragment.glsl"

std::string GLRendererString;
std::string GLVersionString;
std::string GLSLVersionString;

GLuint QuadVertexArray;
Shader DefaultShader = Shader();

//Creates a vertex array for a quad
GLuint CreateVertexArray()
{
	const GLfloat Vertices[] =
	{
		//VERTICES      //TEXCOORDS
		1.0f,  1.0f,    1.0f, 0.0f, // Top Right
		1.0f, -1.0f,    1.0f, 1.0f, // Bottom Right
		-1.0f, -1.0f,    0.0f, 1.0f, // Bottom Left
		-1.0f,  1.0f,    0.0f, 0.0f  // Top Left
	};

	GLuint Indices[] =
	{
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	GLuint vbo, vao, ebo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	//Copy vertices into the buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	//Copy the Indices into the buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

	//Attribute Pointers
	//Position attribute // 2 instead of 4 for the stride length, or the size of each section
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Texture coordinate attribute pointer
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//Unbinds the VAO
	glBindVertexArray(0);

	return vao;
}

void InitOpenGL()
{
	//Initiate GLEW
	glewExperimental = GL_TRUE;
	GLenum glewStatus = glewInit();

	//If GLEW is not initiated properly, we throw an error
	if (glewStatus != GLEW_OK)
	{
		printf("ERROR: GLEW failed to start\n");
		return;
	}
	else
	{
		printf("INFO: GLEW initiated!\n");
	}

	////////////////////////////////////////////////////////////////
	//                      OpenGL Options                        //
	////////////////////////////////////////////////////////////////
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	////////////////////////////////////////////////////////////////
	// Section to set up rendering and info on the hardware used  //
	////////////////////////////////////////////////////////////////
	//Writes the OpenGL version and the graphics hardware the user has to the startup log
	std::string renderer = "Graphics Hardware: ";
	std::string version = "OpenGL version: ";
	std::string glslVersion = "GLSL version: ";

	GLRendererString = (char*)glGetString(GL_RENDERER);
	GLVersionString = (char*)glGetString(GL_VERSION);
	GLSLVersionString = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

	renderer += GLRendererString;
	version += GLVersionString;
	glslVersion += GLSLVersionString;

	printf(renderer.c_str());
	printf(version.c_str());
	printf(glslVersion.c_str());

	//Creates the default shader for the game engine
	printf("\nINFO: Creating default shader:");
	DefaultShader = Shader((char*)DEFAULT_VERTEX_SHADER, (char*)DEFAULT_FRAGMENT_SHADER);

	//Creates the default vertex array for a quad
	printf("INFO: Creating quad vertex array...");
	QuadVertexArray = CreateVertexArray();
	printf("INFO: Successfully created quad vertex array!\n");
}

//Conversion function between engine coordinates and OpenGL coordinates
/*float UnitToGLCoords(float coord)
{
	float size = 1 / (Camera.size / 2);
	coord *= size;

	return coord;
}*/

//Universal drawing function to draw using a provided textureID
void Draw2D(Vector2 position, Vector2 scale,/* Color tint,*/ int textureID, int texMode, Vector2 uvScale, Vector2 uvOffset)
{
   //Use the default shader
   DefaultShader.Use();

   //Get's the shader's uniform variable for aspect ratio
   GLfloat Aspect = glGetUniformLocation(DefaultShader.Program, "aspect");
   glUniform1f(Aspect, WindowSize.x / WindowSize.y);

   //Get's the shader's uniform variable for position
   GLfloat drawPosition = glGetUniformLocation(DefaultShader.Program, "position");
   glUniform2f(drawPosition, position.x, position.y);

   GLfloat drawScale = glGetUniformLocation(DefaultShader.Program, "scale");
   glUniform2f(drawScale, scale.x, scale.y);

   GLfloat drawPixelSize = glGetUniformLocation(DefaultShader.Program, "pixelSize");
   GLint hasTexture = glGetUniformLocation(DefaultShader.Program, "hasTexture");

   //If we have a texture provided
   if (textureID != 0)
   {
      //Binds the texture we give it
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, textureID);
      glUniform1i(glGetUniformLocation(DefaultShader.Program, "Texture"), 0);
      //Get's the shader's uniform variable for the dimension of the texture in pixels
      int width, height;
      glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
      glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
      //GLfloat pixelSize = (GLfloat)Camera.size / (1 / (float)Camera.PixelsPerUnit);
      glUniform2f(drawPixelSize, width / scale.x, height / scale.y);
      glUniform1i(hasTexture, 1);
   }
   else
   {
      //GLfloat pixelSize = (GLfloat)Camera.size / (1 / (float)Camera.PixelsPerUnit);
      glUniform2f(drawPixelSize, scale.x, scale.y);
      glUniform1i(hasTexture, 0);
   }

   GLfloat drawUVScale = glGetUniformLocation(DefaultShader.Program, "uvScale");
   glUniform2f(drawUVScale, uvScale.x, uvScale.y);

   GLfloat drawUVOffset = glGetUniformLocation(DefaultShader.Program, "uvOffset");
   glUniform2f(drawUVOffset, uvOffset.x, uvOffset.y);

   GLint drawTexMode = glGetUniformLocation(DefaultShader.Program, "texMode");
   glUniform1i(drawTexMode, texMode);

   //Get's the shader's uniform variable for drawing tint
   /*GLint drawTint = glGetUniformLocation(DefaultShader.Program, "tint");
   glUniform4f(drawTint, tint.r, tint.g, tint.b, tint.a);*/

   //Binds the Vertex Array Object
   glBindVertexArray(QuadVertexArray);

   // draw points 0-3 from the currently bound VAO with current in-use shader
   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

   glBindVertexArray(0);
   glBindTexture(GL_TEXTURE_2D, 0);
}
