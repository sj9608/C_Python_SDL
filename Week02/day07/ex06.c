#include <stdio.h>
#include <SDL2/SDL.h>
// 함수 호출 횟수 카운팅
int counter()
{
  //int counter = 0; 지역변수는 stack에 저장되는 휘발성 메모리.
  static int counter = 0; // static 변수는 메모리에 계속 저장이 되어있음.
  // static int counter = 0; 
  //초기화 명령(프로그램 시작시 한번만 초기화)일 뿐 오퍼레이션(연산 명령)이 아니다.
  return ++counter;
}

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  printf("%d \n", counter());
  printf("%d \n", counter());
  printf("%d \n", counter());

  SDL_Quit();
  return 0;
}