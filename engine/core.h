#ifndef __CORE_H__
#define __CORE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

typedef struct __core
{
    SDL_Window *m_pWin;
    SDL_Renderer *m_pRender;
    TTF_Font *m_pDefaultFont;
    Uint16 m_ScreenWidth;
    Uint16 m_ScreenHeight;

} tDE_S_Core;

typedef struct _tde_s_base_
{
    Uint16 m_nType;      // 엔티티 타입 정의
    SDL_bool m_bvisible; // 화면에 보일지 말지
    Uint32 m_nId;

    void (*m_fpDestroy)(void *pObj);
    void (*m_fpRender)(void *pObj, SDL_Renderer *pRender);
    void (*m_fpDoEvent)(void *pObj, SDL_Event *pEvt);
    void (*m_fpApply)(void *pObj, Uint32 tick);
} tDE_S_ObjectBase;


typedef struct __s_sheet_data
{
    char szName[32];
    SDL_Rect m_area;
} tDE_S_SheetData;

tDE_S_Core *tDE_setup_1(const char *szTitle,
                        int window_width,
                        int window_height,
                        Uint32 flags);
void tDE_closeCore(tDE_S_Core *pCore);
SDL_Texture *tDE_util_loadTexture(tDE_S_Core *pCore, const char *filename);
SDL_bool tDE_util_parseSheet(char *szStr, tDE_S_SheetData *pData);
#endif