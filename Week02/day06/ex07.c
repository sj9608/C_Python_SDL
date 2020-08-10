#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("SDL Initializing : %s ", SDL_GetError);
    return 1;
  }

  else
  {
     printf("success INIT\n");
  }
  // 0000 0001
  char num = 1;

  // 0000 0001 < shift 연산 --> x 2
  printf("%d \n", num << 1 );

  // 0000 0001 < shift 연산2 --> x 4
  printf("%d \n", num << 2 );

  num = 8;
  // 0000 1000 
  // 0001 0000
  printf("%d \n", num << 1);
  
  return 0;
}