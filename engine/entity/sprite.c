// 2d 캐릭터를 만들 수 있는 툴??
#include "sprite.h"

static void _destory(void *pObj)
{
    SDL_free(pObj);
}

static void _render(void *pObj, SDL_Renderer *pRender)
{
    tDE_Entity_S_sprite *pEnty = pObj; // 보이드형으로 받고 형변환해서 사용하기
    SDL_Rect _rt = {pEnty->m_ptPos.x, pEnty->m_ptPos.y,
                    pEnty->m_srcRect.w, pEnty->m_srcRect.h};
    SDL_RenderCopy(pRender, pEnty->m_pTexture, &pEnty->m_srcRect, &_rt);
}

static void _doEvent(void *pObj, SDL_Event *pEvt)
{
    tDE_Entity_S_sprite *pEnty = pObj;
    switch (pEvt->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        if (pEnty->m_callbackMouseDown)
        {
            SDL_Point mspt = {pEnty->m_ptPos.x, pEnty->m_ptPos.y};
            SDL_Rect bodyRect = {
                pEnty->m_srcRect.x,
                pEnty->m_srcRect.y,
                pEnty->m_srcRect.w,
                pEnty->m_srcRect.h,
            };
            
            if (SDL_PointInRect(&mspt, &bodyRect))
            {
                pEnty->m_callbackMouseDown(pEnty);
            }
        }
        break;

    default:
        break;
    }
}
tDE_S_ObjectBase *tDE_Entity_createSprite(int x, int y, Uint16 nID,
                                          SDL_Rect srcRect,
                                          SDL_Texture *pTexture,
                                          void (*m_callbackMouseDown)(void *),
                                          void (*m_callbackKeyDown)(void *),
                                          void (*m_callbackJoystic)(void *))
{
    tDE_Entity_S_sprite *pObj = SDL_malloc(sizeof(tDE_Entity_S_sprite));

    pObj->m_pTexture = pTexture;
    pObj->m_srcRect = srcRect;

    pObj->m_ptPos.x = x;
    pObj->m_ptPos.y = y;

    pObj->m_base.m_bvisible = SDL_FALSE;
    pObj->m_base.m_fpDestroy = _destory;
    pObj->m_base.m_fpDoEvent = _doEvent;
    pObj->m_base.m_fpRender = _render;

    pObj->m_callbackMouseDown = m_callbackMouseDown;

    return (void *)pObj;
}