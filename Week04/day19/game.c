#include "../engine/core.h"
#include "../engine/tile.h"
#include "cmd_parser.h"

tDE_S_Core *g_pEngineCore;
Sint16 g_WorldMap[4][64];

SDL_Texture *g_pTileSet;
SDL_Texture *g_pTileSet2;

SDL_Point g_PlayerPos;

int g_nGameLogicFsm = 0; // 게임로직 제어를 위한 FSM(유한상태기계) 0 이면 레디

int main(int argc, char *argv[])
{
    g_pEngineCore = tDE_setup_1("Game", 640, 480, 0);
    g_pTileSet = tDE_util_loadTexture(g_pEngineCore, "../../res/dungeon.png");
    g_pTileSet2 = tDE_util_loadTexture(g_pEngineCore, "../../res/gb_ft_rpg_tile_set.png");

    SDL_Renderer *pRender = g_pEngineCore->m_pRender;
    loadMap("./l1.map", g_WorldMap);

    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_SetRenderDrawColor(pRender, 0x00, 0x00, 0xff, 0xff);
        SDL_RenderClear(pRender);

        switch (g_nGameLogicFsm)
        {
        case 0:
        {
            printf("start game? (press key) \n");
            g_nGameLogicFsm = 1;
        }
        break;

        case 1:
            break;

        case 10:
        {
            // 월드맵 그리기
            drawWorld(g_pEngineCore->m_pRender,
                      g_pTileSet, 16, 5, 2, //타일셋 정보
                      0, 0,                 //그려질 위치
                      8, g_WorldMap[0]         //월드멥 정보
            );
        }
        default:
            break;
        }

        // object layer 재설정
        // {
        //     memset(g_WorldMap_obj_layer, 0, 64*sizeof(Uint16));

        //     g_WorldMap_obj_layer[g_PlayerPos.y * 8 + g_PlayerPos.x] = 1;
        // }

        // {
        //     Sint16 *map = g_WorldMap_obj_layer;
        //     for (int i = 0; i < 64; i++)
        //     {
        //         Sint16 _index = map[i];
        //         if (_index != 1)
        //         {
        //             if (_index == 1)
        //             { //캐릭터 그리기
        //                 int x = i % 8;
        //                 int y = i / 8;
        //                  putTile(pRender, g_pTileSet2, x, y, 190, 16, 10, 2);
        //             }
        //         }
        //     }
        // }

        SDL_RenderPresent(pRender);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYUP:
            {
            }
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