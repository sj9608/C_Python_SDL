#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{

    SDL_bool bLoop = SDL_TRUE;

    while (bLoop)
    {
        printf("exit now? (1.exit \n2.none \n3.print app version \n4.start game) : ");
        Sint8 sel = getchar();
        rewind(stdin);
        if (sel == '1')
        {
            bLoop = SDL_FALSE;
        }
        else if(sel == '3')
        {
            printf("app version 1.0\n");
        }
    }

    return 0;
}