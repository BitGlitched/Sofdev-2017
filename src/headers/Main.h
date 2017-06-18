#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>

#include "types/Vector2.h"
#include "types/MouseData.h"
#include "types/Texture.hpp"
#include "types/Shader.hpp"
#include "Font.h"

extern SDL_Window* window;
extern SDL_GLContext glcontext;
//extern SDL_Renderer* renderer;

extern bool CloseWindow;
extern Vector2 WindowSize;
extern MouseData Mouse;

std::string ReadFile(char*);
void Startup();
void Update();

extern GLuint QuadVertexArray;
extern Shader DefaultShader;

void InitOpenGL();
void Draw2D(Vector2, Vector2,/* Color,*/ int = 0, int = 0, Vector2 = Vector2(1.0f, 1.0f), Vector2 = Vector2(0.0f, 0.0f));

#include "GUI.h"
#include "types/IC.h"

#endif
