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

}

void tDE_closeCore(tDE_S_Core *pCore)
{
    TTF_CloseFont(pCore->m_pDefaultFont);
    SDL_DestroyRenderer(pCore->m_pRender);
    SDL_DestroyWindow(pCore->m_pWin);
}

SDL_Texture *tDE_util_loadTexture(tDE_S_Core *pCore, const char *filename)
{
    SDL_Surface *pSurface;
    pSurface = IMG_Load(filename);

    if(pSurface == NULL)
    {
        printf("file load error : %s\n",SDL_GetError());
        return NULL;
    }
    else
    {
        printf("IMG file Load Success\n");
    }
    SDL_Texture *pTex = SDL_CreateTextureFromSurface(pCore->m_pRender, pSurface);
    SDL_FreeSurface(pSurface);

    return pTex;
    
}