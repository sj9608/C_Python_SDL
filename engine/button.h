#ifndef __BUTTON_H__
#define __BUTTON_H__
typedef struct _S_BUTTON
{
    SDL_bool m_bVisible;
    Uint16 m_nID;
    SDL_Rect m_Rect;
    Uint16 m_nFSM;// 유한상태기계
    SDL_Color m_fillColor;  
    void (*m_pCallbackBtnPush)(struct _S_BUTTON *);
} S_BUTTON;

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID, void (*m_pCallbackBtnPush)(struct _S_BUTTON *));
void Button_Render(S_BUTTON *pBtn, SDL_Renderer *pRenderer);
void Button_DoEvent(S_BUTTON *pBtn, SDL_Event *pEvt);
#endif