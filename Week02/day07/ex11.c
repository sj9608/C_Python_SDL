#include <stdio.h>
#include <SDL2/SDL.h>

int getStrLength(char data[]) //배열을 매개변수로 전달할 때(크기 정하지않고)
{
  int _count = 0;
  while (data[_count] != 0)
  {
    data[_count] = '*';
    _count++;
  }
  return _count;
}

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  char data[6] = {'h', 'a', 'p', 'p', 'y', 0};
  char data2[] = "birthday";

  printf("%s %s\n", data, data2);

  printf("data2 length is : %d\n", getStrLength(data2));

  printf("%s %s\n", data, data2);

  SDL_Quit();
  return 0;
}