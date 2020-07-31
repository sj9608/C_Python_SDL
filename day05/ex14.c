#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

            { // 0행
                {// 0, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 0;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 1, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 1;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 2, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 2;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 3, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 3;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }
                {// 4, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 4;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 5, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 5;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 6, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 6;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 7, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 7;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 8, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 8;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 9, 0
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 9;
                    _dstRt.y = 16 * 4 * 0;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }
            }
            //0행 끝

            { // 1행
                {// 0, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 0;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 1, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 1;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 2, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 2;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 3, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 3;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 4, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 4;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 5, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 5;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 6, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 6;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 7, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 7;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 8, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 8;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }

                {// 9, 1
                    SDL_Rect _srcRt;
                    _srcRt.x = 0;
                    _srcRt.y = 16 * 8;
                    _srcRt.w = 16;
                    _srcRt.h = 16;

                    SDL_Rect _dstRt;
                    _dstRt.x = 16 * 4 * 9;
                    _dstRt.y = 16 * 4 * 1;
                    _dstRt.w = 16*4;
                    _dstRt.h = 16*4;

                    SDL_RenderCopy(renderer, tex, &_srcRt, &_dstRt);
                }
            }

            
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