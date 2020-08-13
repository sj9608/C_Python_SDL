// 먼저 버튼에 대한 구조체 선언
#ifndef __BUTTON_H__
#define __BUTTON_H__
typedef struct _S_BUTTON
{
    SDL_bool m_bVisible;
    Uint16 m_nID;
    Uint16 m_nFSM;
    SDL_Rect m_Rect;
    SDL_Color m_fillColor;
    void (*m_pCallbackBtnPush)(struct _S_BUTTON *);
} S_BUTTON;

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID, void (*m_pCallbackBtnPush)(struct _S_BUTTON *));
void Button_Render(S_BUTTON *pBtn, SDL_Renderer *pRenderer);
void Button_DoEvent(S_BUTTON *pBtn, SDL_Event *pEvt);
S_BUTTON *createButton(int x, int y, int w, int h, Uint16 btnID, void (*pCallbackBtnPush)(struct _S_BUTTON *));
void destroyButton(S_BUTTON *pBtn);
#endif