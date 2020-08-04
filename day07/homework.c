#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

void _copystr(int nStartIndex, int nEndIndex, char src[], char dst[])
{
    int count = 0;
    for(count = 0; nStartIndex < nEndIndex; count++, nStartIndex++)
    {
        dst[count] = src[nStartIndex];
    }
    dst[count] = 0;
    printf("%s\n", dst);
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    char data[] = "kor, mat, eng, bio, pyh, earth";

    char buf1[16];
    char buf2[16];
    char buf3[16];
    char buf4[16];
    char buf5[16];
    char buf6[16];

    _copystr(0, 3, data, buf1);
    _copystr(5, 8, data, buf2);
    _copystr(10, 13, data, buf3);
    _copystr(15, 18, data, buf4);
    _copystr(20, 23, data, buf5);
    _copystr(25, 30, data, buf6);


    SDL_Quit();
    return 0;
}