#ifndef __TEXT_LABLE_H__
#define __TEXT_LABLE_H__

typedef struct text_lable
{
    // 베이스 구조체
    S_UIBASE m_base;

    TTF_Font *m_pFont;
    SDL_Texture *m_pLableTxture;

    SDL_Rect m_Rect;
    Uint16 m_nFSM;

    SDL_Color m_fgColor;
    SDL_Color m_bgColor;

} S_TextLable;

S_TextLable *myui_createLable(SDL_Renderer *pRenderer,
                         int x, int y, Uint16 nID,
                         const Uint16 *text,
                         TTF_Font *pFont);
// void TextLable_destory(S_TextLable *pObj);
// void TextLable_render(S_TextLable *pObj, SDL_Renderer *pRender);

#endif