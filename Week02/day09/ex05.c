#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

//8, 16, 32 선택해서 값을 받아오는 함수
int GetData(void *p, Uint8 type)
{
    Uint32 _rt = 0;
    switch (type)
    {
    case 'c':
        _rt = *(Uint8 *)p; // void 형 이기 때문에 type casting 해줘야함
        break;

    case 's':
        _rt = *(Uint16 *)p;
        break;

    case 'i':
        _rt = *(Uint32 *)p;
        break;

    default:
        break;
    }
}
int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    int data = 0x12345678;
    // in Window OS has been using memory stack 'Little Endian'
    printf("%x \n",GetData(&data,'c')); // char 8bit -> 1byte
    printf("%x \n",GetData(&data,'s')); // short 16bit -> 2byte
    printf("%x \n",GetData(&data,'i')); // int 32bit -> 4byte

    SDL_Quit();
    return 0;
}