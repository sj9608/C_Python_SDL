#include <stdio.h>
#include <SDL2/SDL.h>
extern int result;
extern int result2;

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  printf("%d \n", result);
  printf("%d \n", result2);


  SDL_Quit();
  return 0;
}