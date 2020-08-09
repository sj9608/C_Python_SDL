// Day06 ex11.c clone coding
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// WINDOW SIZE CONST
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char *argv[])
{
    //SDL INIT
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing : %s \n", SDL_GetError);
        return 1;
    }
    else
    {
        printf("Sucess INIT \n");
    }

    // Create a Window
    SDL_Window *gWindow = SDL_CreateWindow("GAME",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    // trigger the program that controls Graphic hardware and set flags
    Uint32 render_flgas = SDL_RENDERER_ACCELERATED;

    // create a renderer to render img
    SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow, -1, render_flgas);

    // create a surface to load an image into the main memory
    SDL_Surface *surface = IMG_Load("../res/tiny16/basictiles.png");
    // surface = IMG_Load("../res/tiny16/basictile.png");

    // Print Msg if loading IMG files Fail
    if (!surface)
    {
        printf("Error MSG : %s \n", IMG_GetError());
        return 1;
    }

    // load Img to Graphic hardware memory.
    SDL_Texture *tex = SDL_CreateTextureFromSurface(gRenderer, surface);
    ;
    // tex = SDL_CreateTextureFromSurface(gRenderer, surface);

    // clear main-memory
    SDL_FreeSurface(surface);

    SDL_bool bLoop = SDL_FALSE;
    while (bLoop)
    {
        //cears the screen
        SDL_RenderClear(gRenderer);

        for (int iy = 0; iy < 8; iy++)
        {
            for (int ix = 0; ix < 10; ix++)
            {
                SDL_Rect src = {16 * 6, 16 * 1, 16, 16};
                SDL_Rect dst = {ix * 64, iy * 64, 64, 64};
                SDL_RenderCopy(gRenderer, tex, &src, &dst);
            }
        }

        {
            int ix = 0;
            int iy = 0;
            int _tile_index = 31;

            int _src_index_x = _tile_index % 8;
            int _src_index_y = _tile_index / 8;
            SDL_Rect src = {16 * _src_index_x, 16 * _src_index_y, 16, 16};
            SDL_Rect dst = {ix * 64, iy * 64, 64, 64};
            SDL_RenderCopy(gRenderer, tex, &src, &dst);
        }
        SDL_RenderPresent(gRenderer);
    }
    SDL_DestroyWindow(gWindow);

    return 1;
}