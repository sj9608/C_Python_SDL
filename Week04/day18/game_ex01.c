#include "../engine/core.h"
#include "../engine/tile.h"
#include "cmd_parser.h"

tDE_S_Core *g_pEngineCore;
Sint16 g_WorldMap[64];
SDL_Texture *g_pTileSet;

int main(int argc, char *argv[])
{
    g_pEngineCore = tDE_setup_1("Game", 640, 480, 0);
    g_pTileSet = tDE_util_loadTexture(g_pEngineCore, "../../res/dungeon.png");

    SDL_Renderer *pRender = g_pEngineCore->m_pRender;
    loadMap("./l1.map", g_WorldMap);

    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_SetRenderDrawColor(pRender, 0x00, 0x00, 0xff, 0xff);
        SDL_RenderClear(pRender);

        drawWorld(g_pEngineCore->m_pRender,
                  g_pTileSet, 16, 5, 2, //타일셋 정보
                  0, 0,                 //그려질 위치
                  8, g_WorldMap         //월드멥 정보
        );

        SDL_RenderPresent(pRender);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                bLoop = SDL_FALSE;
                break;

            default:
                break;
            }
        }
    }

    SDL_DestroyTexture(g_pTileSet);
    SDL_DestroyWindow(g_pEngineCore->m_pWin);

    return 0;
}