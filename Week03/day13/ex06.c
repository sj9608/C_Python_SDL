#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../engine/util.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
SDL_Surface *g_pSurface;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    g_pWindow = SDL_CreateWindow("GAME", // creates a window
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

    if (!g_pWindow)
    {
        printf("error initializing SDL window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_bool bLoop = SDL_TRUE;
    SDL_bool bCheckHitRect = SDL_FALSE;
    SDL_bool bCheckHitRect2 = SDL_FALSE;

    while (bLoop)
    {
        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(g_pRenderer);
        // 사각형 그리기
        SDL_Rect _Rect1 = {100, 100, 120, 120};
        SDL_Rect _Rect2 = {300, 100, 120, 120};

        //1번째 사각형 처리
        if (!bCheckHitRect)
        {
            SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(g_pRenderer, &_Rect1);
        }
        else
        {
            SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
            SDL_RenderFillRect(g_pRenderer, &_Rect1);
        }

        // 2번째 사각형 처리
        if (!bCheckHitRect2)
        {
            SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(g_pRenderer, &_Rect2);
        }
        else
        {
            SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 255);
            SDL_RenderFillRect(g_pRenderer, &_Rect2);
        }

        SDL_RenderPresent(g_pRenderer);

        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            int _mx = _event.motion.x; // mouse x point
            int _my = _event.motion.y; // mouse y point
            switch (_event.type)
            {
            case SDL_MOUSEBUTTONDOWN: // 마우스 왼쪽 버튼 클릭
            {
                if (checkPointInRect(&_Rect1, _mx, _my) == SDL_TRUE)
                {
                    printf("push button\n");
                }

                if (checkPointInRect(&_Rect2, _mx, _my) == SDL_TRUE)
                {
                    printf("push button2\n");
                }
            }
            break;

            case SDL_MOUSEMOTION: // 마우스 포인터 움직일 때
            {
                bCheckHitRect = checkPointInRect(&_Rect1, _mx, _my);
                bCheckHitRect2 = checkPointInRect(&_Rect2, _mx, _my);
                printf("%4d%4d\r", _mx, _my);
                // if ((_Rect1.x < _mx && _Rect1.y < _my) &&
                //     ((_Rect1.x + _Rect1.w) > _mx && (_Rect1.y + _Rect1.h) > _my)) // 사각형 안에 마우스 포인터가 있는지 검사
                // {
                //     printf("%4d%4d%2d\r", _mx, _my, 1);
                //     bCheckHitRect = SDL_TRUE;
                // }
                // else
                // {
                //     printf("%4d%4d%2d\r", _mx, _my, 0);
                //     bCheckHitRect = SDL_FALSE;
                // }

                // printf("%4d%4d\r", _event.motion.x, _event.motion.y);
            }
            break;

            case SDL_KEYDOWN:

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
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();

    return 0;
}
