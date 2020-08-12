#include <stdio.h>
#include <SDL2/SDL.h>
#include "button.h"
#include "util.h"

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID,
  void (*pCallbackBtnPush)(struct _S_BUTTON *))
{
    pBtn->m_nFSM;
    pBtn->m_Rect.x = x;
    pBtn->m_Rect.y = y;
    pBtn->m_Rect.w = w;
    pBtn->m_Rect.h = h;

    pBtn->m_bVisible = SDL_TRUE;

    pBtn->m_fillColor.r = 0;
    pBtn->m_fillColor.g = 0;
    pBtn->m_fillColor.b = 0;
    pBtn->m_fillColor.a = 255;

    pBtn->m_pCallbackBtnPush = pCallbackBtnPush;

    pBtn->m_nID = btnID;
}

void Button_Render(S_BUTTON *pBtn, SDL_Renderer *pRenderer)
{
    if (pBtn->m_bVisible)
    {
        //반투명 모드 활성화
        SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);

        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(pRenderer, &pBtn->m_Rect);

        SDL_SetRenderDrawColor(pRenderer, pBtn->m_fillColor.r, pBtn->m_fillColor.g, pBtn->m_fillColor.b,
                               pBtn->m_fillColor.a);
        SDL_RenderFillRect(pRenderer, &pBtn->m_Rect);

        //반투명 모드 비 활성화
        SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_NONE);
    }
}

void Button_DoEvent(S_BUTTON *pBtn, SDL_Event *pEvt)
{
    if (pBtn->m_nFSM == 0)
    {
        switch (pEvt->type)
        {
            case SDL_MOUSEMOTION:
            if(checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y))
            {
                pBtn->m_fillColor.a = 0x80;
                pBtn->m_nFSM = 1;
            }
            break;
        }
    }
    else if(pBtn->m_nFSM == 1)
    {
        switch (pEvt->type)
        {
            case SDL_MOUSEMOTION:
            if(!checkPointInRect(&pBtn->m_Rect,pEvt->motion.x, pEvt->motion.y))
            {
                pBtn->m_fillColor.a = 0;
                pBtn->m_nFSM = 0;
            }
            break;

            case SDL_MOUSEBUTTONDOWN:
            if(checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y))
            {
                if(pBtn->m_pCallbackBtnPush != NULL)
                {
                    pBtn->m_pCallbackBtnPush(pBtn);
                }
            }
        }
    }
}