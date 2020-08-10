#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Rect rect = {10, 20, 300, 400};

    SDL_Rect *pRect = &rect;
    //pRect = &rect;

    printf("%d %d %d %d\n", pRect->x, pRect->y, pRect->w, pRect->h);
    return 0;
}