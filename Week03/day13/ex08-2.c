#include <stdio.h>
#include <SDL2/SDL.h>
#include "util.h"
#include "button.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDWO_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;

static SDL_bool bLoop = SDL_TRUE;

// 콜백함수 작성 01. 종료
void callback_Btn1_Push(S_BUTTON *pBtn)
{
    bLoop = SDL_FALSE;
}

// 콜백함수 작성 02. 버튼 색상 바꾸기
void callback_Btn2_Push(S_BUTTON *pBtn)
{
    pBtn->m_fillColor.r = 0;
    pBtn->m_fillColor.g = 0;
    pBtn->m_fillColor.b = 255;
}

// 버튼개수 정하기
S_BUTTON g_Button[5]; // 5개

int main(int argc, char *argv[])
{
    // 버튼 설정하기
    Button_Init(&g_Button[0], 160, 100, 120, 120, 1, callback_Btn1_Push);
    Button_Init(&g_Button[1], 320, 100, 120, 120, 2, callback_Btn2_Push);
    Button_Init(&g_Button[2], 80, 300, 120, 120, 3, NULL);
    Button_Init(&g_Button[3], 240, 300, 120, 120, 5, NULL);
    Button_Init(&g_Button[4], 400, 300, 120, 120, 4, NULL);

    // 초기화 에러검출
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL :%s\n", SDL_GetError());
        return 1;
    }

    g_pWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDWO_HEIGHT, 0);

    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

    // 윈도우창 에러검출
    if (!g_pWindow)
    {
        printf("error initializing SDL window : %s\n", SDL_GetError);
        return 1;
    }

    while (bLoop)
    {
        // 렌더러에 그릴 색상 설정 및 초기화
        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(g_pRenderer);

        // 버튼 렌더링하기
        for (int i = 0; i < 5; i++)
        {
            Button_Render(&g_Button[i], g_pRenderer);
        }

        SDL_RenderPresent(g_pRenderer);

        // event 받을 변수 선언
        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            for (int i = 0; i < 5; i++)
            {
                Button_DoEvent(&g_Button[i], &_event);
            }

            switch(_event.type)
            {
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