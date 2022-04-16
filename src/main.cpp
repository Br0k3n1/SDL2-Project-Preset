#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argv, char** args)
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "ERROR: SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "ERROR: IMG_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Event event;

	bool gameRunning = true;
	while (gameRunning){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				gameRunning = false;
			}
		}
	}
	
	window.cleanUp();
	SDL_Quit();

	return 0;
}