#include <stdio.h>
#include <SDL2/SDL.h>

const float _PI = 3.14;

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  printf("%d \n", _PI);
  // _PI = 3.4; 문법적으로도 오류, 컴파일시 에도 오류 
  // _PI는 read-only variable 만약에 const 설정을 하지 않으면 정상작동.
  // 물론 함수 내에서만


  SDL_Quit();
  return 0;
}