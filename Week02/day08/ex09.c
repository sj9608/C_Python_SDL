// 랜덤함수 관련설명
#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *gWindow;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    gWindow = SDL_CreateWindow("GAME", //create Window
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                bLoop = SDL_FALSE;
        }
        printf("%8d \r",rand()%100); // if you want to earn number 0~99 -> then rand()%100 
        SDL_Delay(500);
    }

    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    return 0;
}