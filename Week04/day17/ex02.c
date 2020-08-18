#include "../../engine/core.h"

tDE_S_SheetData g_sheetDataAssets[1024];

int main(int argc, char *argv[])
{
    tDE_S_Core *pEngineCore = tDE_setup_1("example2", 640, 480, 0);

    SDL_bool bLoop = SDL_TRUE;

    {
        int nCount = 0;
        static char szBuf[256];
        FILE *fp = fopen("../../res/tanks/sheet_tanks.xml", "rt");
        while (fgets(szBuf, sizeof(szBuf), fp))
        {
            tDE_S_SheetData _tmp;
            if (tDE_util_parseSheet(szBuf, &g_sheetDataAssets[nCount++]))
            {
                g_sheetDataAssets[nCount++] = _tmp;
                // printf("%32s%4d%4d%4d%4d\n", data.szName, data.x, data.y, data.w, data.h);
            }
        }
    }

    SDL_Texture *pTanksTex = tDE_util_loadTexture(pEngineCore, "../../res/tanks/sheet_tanks.png");
    while (bLoop)
    {
        SDL_SetRenderDrawColor(pEngineCore->m_pRender, 0, 0, 0, 0xff);
        SDL_RenderClear(pEngineCore->m_pRender);
        {
            Uint16 sheet_index = 44;
            SDL_Rect dstRt = {128, 0,
                              g_sheetDataAssets[sheet_index].m_area.w,
                              g_sheetDataAssets[sheet_index].m_area.h};
            SDL_RenderCopy(pEngineCore->m_pRender, pTanksTex,
                           &g_sheetDataAssets[sheet_index].m_area, &dstRt);
        }

        SDL_RenderPresent(pEngineCore->m_pRender);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
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

    SDL_DestroyTexture(pTanksTex);

    return 0;
}