#ifndef __INPUT_TExT_H__
#define __INPUT_TExT_H__
typedef struct _input_text
{
    S_UIBASE m_base;

    TTF_Font *m_pFont;
    SDL_Texture *m_pTextTexture;

    SDL_Rect m_Rect;
    Uint16 m_nFSM;

    SDL_Poin

    SDL_Color m_fgColor;
    SDL_Color m_bgColor;
} S_INPUT_TEXT;
S_INPUT_TEXT *myui_createInputText(SDL_Renderer *pRenderer,
                                   int x, int y, int w, int h,
                                   Uint16 nID,
                                   TTF_Font *pFont,
                                   SDL_Color m_fgColor,
                                   SDL_Color m_bgColor);

static void _doEvent(void *_pObj, SDL_Event *pEvt);
static void _render(void *_pObj, SDL_Renderer *pRender);
static void _destory(void *_pObj);

#endif