#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_bool g_bLoop = SDL_TRUE;

enum EM_INPUT_STATUS
{ //사용자 정의 심볼 사용
    INPUT_ENABLE = 0,
    INPUT_STOP
};

Uint16 g_nInputFSM = INPUT_STOP; // 유한 상태기계(상태처리)

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    g_pWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    while (g_bLoop)
    {
        static char strInputBuf[64] = {
            0,
        }; // input buffer;

        // 이벤트처리
        SDL_Event _event;
        while (SDL_PollEvent(&_event)) // 이벤트 큐에 스택이 차곡차곡 쌓임 ( 스트럭쳐(?) ) case 안에 중괄호 처리 (지역변수 사용 할 때 이름 겹치는 경우 생겨서)
        {
            switch (_event.type)
            {
            case SDL_TEXTINPUT:
            {
                strcat(strInputBuf, _event.text.text);
                printf("%s \r", strInputBuf);
            }
            break;
            case SDL_QUIT: // 윈도우 창 x 버튼 눌렀을 때
            {
                g_bLoop = SDL_FALSE;
            }
            case SDL_KEYDOWN:
            {
                if (g_nInputFSM == INPUT_STOP) // 입력상태 시작
                {
                    if (_event.key.keysym.sym == SDLK_RETURN)
                    {
                        SDL_StartTextInput();
                        printf("input msg : \n");
                        g_nInputFSM = INPUT_ENABLE;
                    }
                }
                else if (g_nInputFSM == INPUT_ENABLE) // 입력상태 끝
                {
                    if (_event.key.keysym.sym == SDLK_RETURN)
                    {
                        SDL_StopTextInput();
                        g_nInputFSM = INPUT_STOP;
                        printf("input result : %s\n", strInputBuf);
                        strInputBuf[0] = 0x00;
                    }
                    else if(_event.key.keysym.sym == SDLK_BACKSPACE)
                    {
                        strInputBuf[strlen(strInputBuf)-1] = 0x00;
                        printf("%s  \r",strInputBuf);
                    }
                }scanf("%d",&g_nInputFSM);
            }
            break;
            default:
                break;
            }
        }
    }

    SDL_DestroyWindow(g_pWindow);
    return 0;
}