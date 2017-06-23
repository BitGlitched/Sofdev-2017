#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>

#include "types/Vector2.h"
#include "types/InputData.h"
#include "types/Texture.hpp"
#include "types/Shader.hpp"
#include "types/Color.hpp"
#include "Font.h"

extern SDL_Window* window;
extern SDL_GLContext glcontext;
//extern SDL_Renderer* renderer;

extern bool CloseWindow;
extern Vector2 WindowSize;
extern Vector2 Canvas;
extern MouseData Mouse;

std::string ReadFile(char*);
void Startup();
void Update();

extern GLuint QuadVertexArray;
extern Shader GUIShader;
extern Shader ObjShader;

void InitOpenGL();
void Draw2D(Shader, Vector2, Vector2, Color = Color(), int = 0, int = 0, Vector2 = Vector2(1.0f, 1.0f), Vector2 = Vector2(0.0f, 0.0f));
void DrawLine(Vector2, Vector2, float, Color);


#include "GUI.h"
#include "types/IC.h"
#include "types/Wire.hpp"

#endif
