#include "headers/Main.h"
#include "headers/Functions.h"

bool CloseWindow = false;

const std::string windowTitle = "Open Circuit Sim";

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char** argv)
{
 	//Initializes SDL
	printf("Initializing SDL...\n");
	SDL_Init(SDL_INIT_VIDEO);
	printf("SDL initialized successfully!\n\n");

   //Creates an SDL window
	printf("Creating window...\n");
   window = SDL_CreateWindow(
      windowTitle.c_str(),     //window's displayed title
      SDL_WINDOWPOS_UNDEFINED, //x position
      SDL_WINDOWPOS_UNDEFINED, //y position
      800,                     //width, in pixels
      600,                     //height of the window
      SDL_WINDOW_RESIZABLE     //Window flags
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
	printf("Creating renderer...\n");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Check to make sure the window was created
   if (renderer == NULL)
	{
      // In the case that the window could not be made, we print the error
      printf("Renderer could not be created: %s\n", SDL_GetError());
      return 1;
   }
	else
	{
		printf("Renderer created successfully!\n");
	}


	printf("Starting to run main loop.\n");
	while(!CloseWindow)
	{
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

   //Close and destroy the renderer and window
	SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);

   //Clean up SDL
   SDL_Quit();
   return 0;
}
