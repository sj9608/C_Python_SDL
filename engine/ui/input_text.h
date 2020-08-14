#ifndef __INPUT_TExT_H__
#define __INPUT_TExT_H__

typedef struct _input_text
{
    S_UIBASE m_base;

    TTF_Font *m_pFont;
    SDL_Texture *m_pTextTexture;

    SDL_Rect m_Rect;
    Uint16 m_nFSM;

    SDL_Point m_textSzie;

    SDL_Color m_fgColor;
    SDL_Color m_bgColor;

    char m_szBuf[256];

} S_INPUT_TEXT;

S_INPUT_TEXT *myui_createInputText(SDL_Renderer *pRenderer,
                                   int x, int y, int w, int h,
                                   Uint16 nID,
                                   TTF_Font *pFont,
                                   SDL_Color m_fgColor,
                                   SDL_Color m_bgColor);

#endif