#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../../engine/text_lable.h"
#include "../../engine/button.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
TTF_Font *g_pFont;

S_TextLable *g_pLableMainMenu;
S_BUTTON *g_pBtnExit;

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

    // 윈도우 생성 에러검출
    if (!g_pWindow)
    {
        printf("error initializing SDL window: %s\n", SDL_GetError());
        return 1;
    }

    // 렌더러 생성
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

    // 렌더러 생성 에러검출
    if (!g_pRenderer)
    {
        printf("fail setup Renderer : %s\n", SDL_GetError());
        return 1;
    }

    // 폰트 생성
    TTF_Init();
    g_pFont = TTF_OpenFont("../../res/nmf.ttf", 28); // font size 28 은 대각선 크기를 뜻함.

    // 라벨 생성
    g_pLableMainMenu = createLable(g_pRenderer, 0, 0, 1,
                                    L"메인메뉴",
                                     g_pFont);
    
    // 버튼0 생성
    g_pBtnExit = createButton(g_pRenderer, 10, 100, 120, 60, 0, L"나가기",g_pFont, NULL);

    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_SetRenderDrawColor(g_pRenderer, 0x00, 0xab, 0x00, 0xff);
        SDL_RenderClear(g_pRenderer);

        // 라벨 렌더링
        g_pLableMainMenu->m_fpRender(g_pLableMainMenu, g_pRenderer);

        // 버튼0 렌더링
        g_pBtnExit->m_fpRender(g_pBtnExit, g_pRenderer);

        SDL_RenderPresent(g_pRenderer);
        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            g_pBtnExit->m_fpDoEvent(g_pBtnExit,&_event);
            
            switch (_event.type)
            {
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

    // 메모리 해제 해주고 프로그램 마침 (크리에이트의 역순으로 해제해주면서)

    g_pBtnExit->m_fpDestory(g_pBtnExit);
    g_pLableMainMenu->m_fpDestory(g_pLableMainMenu);
    TTF_CloseFont(g_pFont);
    SDL_DestroyRenderer(g_pRenderer); // 렌더러 메모리 해제
    SDL_DestroyWindow(g_pWindow);     // 윈도우 메모리 해제
    SDL_Quit();

    return 0;
}