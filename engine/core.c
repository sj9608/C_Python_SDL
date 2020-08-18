#include "core.h"
#include <time.h>

tDE_S_Core *tDE_setup_1(const char *szTitle,
                        int window_width,
                        int window_height,
                        Uint32 flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL INIT error : %s\n", SDL_GetError());
        return NULL;
    }

    tDE_S_Core *pCore = SDL_malloc(sizeof(tDE_S_Core));

    pCore->m_pWin = SDL_CreateWindow(szTitle,
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     window_width,
                                     window_height, flags);

    pCore->m_pRender = SDL_CreateRenderer(pCore->m_pWin, -1, SDL_RENDERER_ACCELERATED);
    
    if(!IMG_Init(IMG_INIT_PNG) &IMG_INIT_PNG)
    {
        printf("SDL image dll init Error : %s \n",SDL_GetError());
        return NULL;
    }

    if(TTF_Init() == -1)
    {
        printf("sdl TTF dll init Error : %s\n",SDL_GetError());
        return NULL;
    }
    
    pCore->m_pDefaultFont = TTF_OpenFont("../../res/nmf.ttf",14);
    if(!pCore->m_pDefaultFont)
    {
        printf("load default font Error : %s\n",SDL_GetError());
    }
    printf("init Module ok\n");
    printf("engine start at %8d\n",time(NULL));
    srand(time(NULL));

    return pCore;
}

void tDE_closeCore(tDE_S_Core *pCore)
{
    TTF_CloseFont(pCore->m_pDefaultFont);
    SDL_DestroyRenderer(pCore->m_pRender);
    SDL_DestroyWindow(pCore->m_pWin);
}

SDL_Texture *tDE_util_loadTexture(tDE_S_Core *pCore, const char *filename)
{
    SDL_Surface *surface;
    surface = IMG_Load(filename);

    if(surface == NULL)
    {
        printf("file load error : %s\n",SDL_GetError());
        return NULL;
    }
    else
    {
        printf("IMG file Load Success\n");
    }
    SDL_Texture *pTex = SDL_CreateTextureFromSurface(pCore->m_pRender, surface);
    SDL_FreeSurface(surface);

    return pTex;
    
}

SDL_bool tDE_util_parseSheet(char *szStr, tDE_S_SheetData *pData)
{
      char *szToken = strtok(szStr, " ");
  if (!strcmp(szToken, "\t<SubTexture"))
  {
    static char _szBuf[5][256];
    //name
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[0], szToken);
    //x
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[1], szToken);
    //y
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[2], szToken);
    //w
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[3], szToken);
    //h
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[4], szToken);

    //name 파싱
    szToken = strtok(_szBuf[0], "=");
    szToken = strtok(NULL, ".");
    strcpy(_szBuf[0], szToken + 1);
    //printf("%s\n", _szBuf[0]);
    strcpy(pData->szName,_szBuf[0]);

    //x 파싱
    szToken = strtok(_szBuf[1], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("x:%d\n", atoi(szToken));
    pData->m_area.x = atoi(szToken);

    //y 파싱
    szToken = strtok(_szBuf[2], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("y:%d\n", atoi(szToken));
    pData->m_area.y = atoi(szToken);

    //w
    szToken = strtok(_szBuf[3], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("w:%d\n", atoi(szToken));
    pData->m_area.w = atoi(szToken);

    //h
    szToken = strtok(_szBuf[4], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("h:%d\n", atoi(szToken));
    pData->m_area.h = atoi(szToken);
    return 1;
  }
  return 0;
}