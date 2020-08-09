#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Select tile (x, y)
SDL_Rect _select_source_tile(int x, int y)
{
    SDL_Rect _src = {16 * x, 16 * y, 16, 16};
    return _src;
}

SDL_Rect _put_tile_destination(int x, int y)
{
    SDL_Rect _dst = {(16 * x) * 4, (16 * y) * 4, 16 * 4, 16 * 4};
    return _dst;
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0)
        {

            // creates a surface to load an image into the main memory
            SDL_Surface *surface;

            // please provide a path for your image
            surface = IMG_Load("./basictiles.png");

            // loads image to our graphics hardware memory.
            SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);

            // clears main-memory
            SDL_FreeSurface(surface);

            SDL_bool done = SDL_FALSE;

            while (!done)
            {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                { // Base Tiles
                    // 8, 0 tiles select
                    SDL_Rect _srcRt = _select_source_tile(0, 8);

                    for (int _Width = 0; _Width < 10; _Width++)
                    {
                        for (int _Height = 0; _Height < 8; _Height++)
                        {
                            SDL_Rect _dstRt = _put_tile_destination(_Width, _Height);

                            SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                        }
                    }
                }

                // 5, 1 tiles select

                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                }
            }

            // destroy texture
            SDL_DestroyTexture(tex);
        }

        if (renderer)
        {

            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}