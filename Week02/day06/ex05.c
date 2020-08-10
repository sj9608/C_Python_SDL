#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL : %s \n", SDL_GetError());
    return 1;
  }
  else
  {
    printf("success SDL INIT \n");
  }

  for (int i = 2; i < 10 ; i++)
  {
    printf("[%4d] \r", i);
    SDL_Delay(200);
  }

  return 0;
}