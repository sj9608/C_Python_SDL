#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  unsigned int b = 0x12345678; // 1byte 뒤 내용은 다 잘려서 120만 출력됌.
  // unsigned char d = 0x00; // 'd' data type is char -> 1byte  
  // unsigned short e = 0x0000;
  Uint8 d = 0x00; // unsigned int 8bit 
  Uint16 e = 0x0000; // SDL 내부에 정의되어있는 자료형 조금 더 직관적임 (unsigned int 16 bit )

  d = b;
  printf("%d \n", d);

  SDL_Quit();
  return 0;
}