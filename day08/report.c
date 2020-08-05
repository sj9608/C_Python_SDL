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

    for(int i = 0; i < 4; i++)
    {
        printf("%s\n", '*' * 4);
    }

    SDL_Quit();
    return 0;
}