#include <stdio.h>
#include <SDL2/SDL.h>

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

  SDL_bool bLoop = SDL_TRUE;
  while(bLoop)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      case SDL_MOUSEBUTTONDOWN:
        printf("%2d [%4d%4d] \n", event.button.button,event.motion.x, event.motion.y);
        break;
      case SDL_MOUSEMOTION:
        printf("[%4d%4d] \r", event.motion.x, event.motion.y);
        break;
      
      default:
        break;
      }
    }
  }


  SDL_DestroyWindow(gWindow);

  return 0;
}