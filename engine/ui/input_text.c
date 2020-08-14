#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ui_base.h"
#include "input_text.h"

static void _destory(void *_pObj)
{
    S_INPUT_TEXT *pObj = _pObj;
    if (pObj->m_pTextTexture)
    {
        SDL_DestroyTexture(pObj->m_pTextTexture);
    }
    SDL_free(pObj);
}

static void _render(void *_pObj, SDL_Renderer *pRender)
{

}

static void _doEvent(void *_pObj, SDL_Event *pEvt)
{
}

S_INPUT_TEXT *myui_createInputText(SDL_Renderer *pRenderer,
                                   int x, int y, int w, int h,
                                   Uint16 nID,
                                   TTF_Font *pFont,
                                   SDL_Color m_fgColor,
                                   SDL_Color m_bgColor)
{
    S_INPUT_TEXT *_pObj = SDL_malloc(sizeof(S_INPUT_TEXT));

    _pObj->m_base.m_nType = MYUI_TEXTINPUT;
    _pObj->m_base.m_nID = nID;

    _pObj->m_Rect.x = x;
    _pObj->m_Rect.y = y;
    w , h

    //font
    //texture
    
    _pObj->m_bgColor

    //라벨생성
    {
        SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};
        SDL_Color _blackColor = {0, 0, 0, 0x00};
        SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(pFont, text, _whiteColor);
        _pObj->m_pLableTxture = SDL_CreateTextureFromSurface(pRenderer, textSurface);

        _pObj->m_Rect.w = textSurface->w;
        _pObj->m_Rect.h = textSurface->h;

        SDL_FreeSurface(textSurface);
    }

    _pObj->m_base.m_fpRender = _render;
    _pObj->m_base.m_fpDestory = _destory;

    return _pObj;
}