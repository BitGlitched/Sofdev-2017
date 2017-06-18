#include "headers/Main.h"

const std::string windowTitle = "Open Circuit Sim";

SDL_Window* window = NULL;
SDL_GLContext glcontext = NULL;

bool CloseWindow = false;
Vector2 WindowSize = Vector2();

MouseData Mouse;

//Function to read a file provided
std::string ReadFile(char* path)
{
   std::ifstream file;
   file.open(path, std::ifstream::in);
   std::string output;

   if (file.is_open())
   {
      printf("Opened file located at: \"%s\"\n", path);

      getline(file, output, '\0');

      printf("Successfully read file located at: \"%s\"\n", path);
   }
   else
   {
      printf("Could not read file!\n");
   }

   file.close();
   return output;
}

int main(int argc, char** argv)
{
 	//Initializes SDL
	printf("Initializing SDL...\n");
	SDL_Init(SDL_INIT_VIDEO);
	printf("SDL initialized successfully!\n\n");

   //Creates an SDL window
	printf("Creating window...\n");
   window = SDL_CreateWindow(
      windowTitle.c_str(),	   						//window's displayed title
      SDL_WINDOWPOS_CENTERED,							//x position
      SDL_WINDOWPOS_CENTERED, 						//y position
      1280,                   						//width, in pixels
      720,                    						//height of the window
      SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE		//Window flags
	);

   //Check to make sure the window was created
   if (window == NULL)
	{
      // In the case that the window could not be made, we print the error
      printf("Window could not be created: %s\n", SDL_GetError());
      return 1;
   }
	else
	{
		printf("Window created successfully!\n\n");
	}

	//Creates the program's renderer
	printf("Creating render context...\n");
	glcontext = SDL_GL_CreateContext(window);
	//renderer = SDL_CreateRenderer(window, -1, 0);

	//Check to make sure the renderer context was created
   if (glcontext == NULL)
	{
      // In the case that the window could not be made, we print the error
      printf("Renderer context could not be created: %s\n", SDL_GetError());
      return 1;
   }
	else
	{
		printf("Renderer context created successfully!\n");
	}

	InitOpenGL();
	Startup();

	printf("Starting to run main loop.\n");
	while(!CloseWindow)
	{
		// event handling
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				CloseWindow = true;
			}
		}

		//Sets the background color
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		glClearColor(255, 255, 255, 1);

		//Clears the renderer's buffer
		//SDL_RenderClear(renderer);
		glClear(GL_COLOR_BUFFER_BIT);

		//Updates everything such as mouse size, window size, etc etc
		//Updates the mouse
		Mouse.UpdateMouse();
		//Gets the window size and stores it in a Vector2
		SDL_GetWindowSize(window, (int*)&WindowSize.x, (int*)&WindowSize.y);

		//Calls the function for the application frontend
		Update();

		//SDL_RenderPresent(renderer);
		//SDL_GL_SwapBuffers();
		SDL_GL_SwapWindow(window);
	}

   //Close and destroy the renderer and window
	SDL_GL_DeleteContext(glcontext);
   SDL_DestroyWindow(window);

   //Clean up SDL
   SDL_Quit();
   return 0;
}
