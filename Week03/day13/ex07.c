#include <stdio.h>
#include <SDL2/SDL.h>
#include "../../engine/util.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
SDL_Surface *g_pSurface;

typedef struct _S_BUTTON
{
    SDL_Rect m_Rect;
    // Uint16 m_nFSM;  // 유한상태기계
    SDL_bool bCheckHitRect;

} S_BUTTON;

S_BUTTON g_Buttons[2]; // 버튼 개수

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

    //사각형 1
    {
        S_BUTTON *pbtn = &g_Buttons[0];
        pbtn->m_Rect.x = 100;
        pbtn->m_Rect.y = 100;
        pbtn->m_Rect.w = 120;
        pbtn->m_Rect.h = 120;
        pbtn->bCheckHitRect = SDL_FALSE;
    }

    {
        S_BUTTON *pbtn = &g_Buttons[1];
        pbtn->m_Rect.x = 300;
        pbtn->m_Rect.y = 100;
        pbtn->m_Rect.w = 120;
        pbtn->m_Rect.h = 120;
        pbtn->bCheckHitRect = SDL_FALSE;
    }
    while (bLoop)
    {
        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(g_pRenderer);

        //버튼 랜더
        for (int i = 0; i < sizeof(g_Buttons) / sizeof(S_BUTTON); i++) // 전체바이트 수/ 구조체 크기  => 배열의 길이
        {
            S_BUTTON *pBtn = &g_Buttons[i];
            if (!pBtn->bCheckHitRect)
            {
                SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(g_pRenderer, &(pBtn->m_Rect));
            }
            else
            {
                SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
                SDL_RenderFillRect(g_pRenderer, &(pBtn->m_Rect));
            }
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
                for (int i = 0; i < 2; i++)
                {
                    if (g_Buttons[i].bCheckHitRect == checkPointInRect(&(g_Buttons[i].m_Rect), _mx, _my) == SDL_TRUE)
                    {
                        printf("button index %d down \r", i);
                    }
                }
            }
            break;

            case SDL_MOUSEMOTION: // 마우스 포인터 움직일 때
            {
                for (int i = 0; i < 2; i++)
                {
                g_Buttons[i].bCheckHitRect = checkPointInRect(&(g_Buttons[i].m_Rect), _mx, _my);
                }
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
