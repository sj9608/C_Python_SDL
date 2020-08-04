#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  int arr_num = 20;

  Sint16 student[arr_num];

  //Sint16 student[20];

  student[0] = 10;

  printf("%d \n",student[0]);
  printf("%d \n", student[1]);

  for(int i=0; i < arr_num ; i++)
  {
    student[i] = 0;
  }
  for(int i=0; i<arr_num; i++)
  {
    printf("[%2d:%2d]\n", i, student[i]);

  }

  SDL_Quit();
  return 0;
}