#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  char data[256] = "Happy bithday"; // 배열을 정적으로 선언하면 sizeof 함수는 전체크기를 구하지만 strlen함수는 문자열 갯수만 카운트해줌.
  printf("%d \n",strlen(data));
  printf("%d \n",sizeof(data)-1);

  char _buffer[256];

  //copy
  strcpy(_buffer,data); // (넘겨받을값, 원본값)
/*
  for(int i=0; i<strlen(data); i++)
  {
    _buffer[i] = data[i];
  }
  _buffer[strlen(data)] = 0;
*/
  printf("%s \n",_buffer);

  strcat(_buffer," to you\n"); // 문자열 덧 붙이기

  printf("%s \n",_buffer);

  _buffer[5] = 0; // 특정 인덱스 뒤 초기화 하는 방법
  printf("%s \n",_buffer);

  SDL_Quit();
  return 0;
}