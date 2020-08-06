#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    /* 4 x 4 size star*/
    for(int i = 0; i < 4; i++)
    {
        for(int j =0; j < 4; j++)
        {
            printf("%c",'*');
        }
        printf("\n");
    }

    /* stair star */
    for(int i =0; i < 5; i++)
    {
        for(int j = 0; j < i; j++)
        {
                printf("%c",'*');
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = i+1 ; j < i ; j++)
        {
            printf("%c",'*');
        }
        printf("\n");
    }
    SDL_Quit();
    return 0;
}