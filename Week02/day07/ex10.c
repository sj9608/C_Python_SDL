#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  Sint16 data[5] = {0, }; //{0, } 으로 하면 자동으로 모든 인덱스 값 0으로 초기화
                          // [0, ] init array in python(list)
  for (int i=0; i<5; i++)
  {
    printf("[%2d : %2d]\n", i, data[i]);
  }

  Sint16 data2[] = {1, 2, 3, 4, 5, 6, 7, 8};

  printf("size : %d \n", sizeof(data2));

  Sint16 _size = sizeof(data2) / sizeof(data);

  for(int i=0; i<5 ; i++)
  {
    printf("[%2d:%2d]\n", i, data2[i]);
  }



  SDL_Quit();
  return 0;
}