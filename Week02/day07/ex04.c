// example for extern keyword
#include <stdio.h>
#include <SDL2/SDL.h>
// 함수원형 호출
void _sum(int data1, int data2);
// int result; 여기서 result를 선언 해준다고 해도 sum.c에 있는 result와
// 다르기 때문에 오류가 난다. 따라서 extern 사용해줘야함
extern int result;
// 이렇게만 해준다고해도 오류가 해결 되지 않음 (링킹 오류) 
//sum.c 에 해당 변수가 있기 때문에 컴파일을 할 때 같이 해줘야함 (makefile 참조)

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  //base
  _sum(5, 3);
  printf("%d \n",result);

  SDL_Quit();
  return 0;
}