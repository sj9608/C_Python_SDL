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
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }

    /* stair star */
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
    printf("\n");

    /* diamond */
    int _stair = 3;
    for (int i = 0; i < _stair; i++)
    {
        for (int j = _stair - 1; j > i; j--)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 1; i < _stair; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        for (int j = 2 * _stair - 1; j > 2 * i; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    SDL_Quit();
    return 0;
}