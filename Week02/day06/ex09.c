//10진수 --> 2진수 변환
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
  int num = 1; // 0001
  while (SDL_TRUE)
  {
    num ^= 1; // ^001 --> xor 연산 (toggle) 0 -> 1 , 1 -> 0
    // if (num == 1) num = 0;
    // else num = 1;
    printf("[%2d] \r", num);
    SDL_Delay(500); 
  }

  return 0;
}