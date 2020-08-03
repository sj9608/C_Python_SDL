//새로 타일 찍기.
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  // SDL INIT
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("SDL Initializing : %s ", SDL_GetError);
    return 1;
  }

  else
  {
     printf("success INIT\n");
  }

  // main
  SDL_Window *gWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;

  // creates a renderer to render our images
  SDL_Renderer *rend = SDL_CreateRenderer(gWindow, -1, render_flags);

  SDL_bool bLoop = SDL_TRUE;


  return 0;
}