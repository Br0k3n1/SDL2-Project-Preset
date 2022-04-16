#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* pTitle, int pWidth, int pHeight)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pWidth, pHeight, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "ERROR: WINDOW HAS FAILED TO INIT. SDL_ERROR: " << SDL_GetError() << std::endl;
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}