#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>
#define MAX_TOKEN_SIZE 32

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *gWindow;
SDL_Renderer *g_pRenderer;

int doTokenize(char *szBuf, char szBufToken[8][MAX_TOKEN_SIZE]);

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    gWindow = SDL_CreateWindow("GAME", // creates a window
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!gWindow)
    {
        printf("error initializing SDL window: %s\n", SDL_GetError());
        return 1;
    }

    g_pRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    SDL_bool bLoop = SDL_TRUE;
    SDL_Rect _rects[32];
    SDL_Color _rect_colors[32];

    Uint16 rect_count = 0;
    Uint16 nInputFSM = 0;

    while (bLoop)
    {
        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 1);
        SDL_RenderClear(g_pRenderer);

        for (int i = 0; i < rect_count; i++)
        {
            SDL_SetRenderDrawColor(g_pRenderer, _rect_colors[i].r, _rect_colors[i].g, _rect_colors[i].b, _rect_colors[i].a);
            //SDL_Rect _rt = {100, 100, 64, 64};
            SDL_RenderFillRect(g_pRenderer, &_rects[i]);
        }

        SDL_RenderPresent(g_pRenderer);
        static char strBuf[32] = {
            0,
        };
        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            switch (_event.type)
            {
            case SDL_KEYDOWN:
                printf("%d \n", _event.key.keysym.scancode);
                if (_event.key.keysym.sym == SDLK_RETURN) // input key 'r' --> add rect
                {
                    if(nInputFSM == 0)
                    {
                        printf("input msg :");
                        SDL_StartTextInput();
                        nInputFSM = 1;
                    }
                    else if(nInputFSM == 1)
                    {
                        static char szTokens[8][32];
                        int _nunToken = doTokenize(strBuf, szTokens);
                        
                        if ( !strcmp(szTokens[0], "quit"))
                        {
                            bLoop = SDL_FALSE;
                        }
                        else if( !strcmp(szTokens[0], "dr"))
                        {
                            //dr x y w h r g b a
                            SDL_Rect _rt = { atoi(szTokens[1]), atoi(szTokens[2]),
                            atoi(szTokens[3]), atoi(szTokens[4])};
                            Uint8 r = atoi(szTokens[5]);
                            Uint8 g = atoi(szTokens[6]);
                            Uint8 b = atoi(szTokens[7]);
                            Uint8 a = atoi(szTokens[8]);

                            SDL_Rect *pRect = &_rects[rect_count];
                            *pRect = _rt;
                            SDL_Color *pColor = &_rect_colors[rect_count];
                            pColor->r = r;
                            pColor->g = g;
                            pColor->b = b;
                            pColor->a = a;
                            rect_count++;
                            
                            nInputFSM = 0;  
                            SDL_StopTextInput();
                        }
                        
                        
                    }
                    // SDL_Rect *pRect = &_rects[rect_count];
                    // pRect->x = rand() % WINDOW_WIDTH;
                    // pRect->y = rand() % WINDOW_HEIGHT;
                    // pRect->w = rand() % 200;
                    // pRect->h = rand() % 200;

                    // SDL_Color *pColor = &_rect_colors[rect_count];
                    // pColor->r = rand() % 255;
                    // pColor->g = rand() % 255;
                    // pColor->b = rand() % 255;
                    // pColor->a = 128;

                    // rect_count++;

                    if (rect_count >= 32)
                    {
                        SDL_RenderClear(g_pRenderer);
                        bLoop = SDL_FALSE;
                    }
                }
                break;
            case SDL_QUIT:
                bLoop = SDL_FALSE;
                break;
            default:
                break;
            }
        }
    }

    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    return 0;
}