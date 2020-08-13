#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
TTF_Font *g_pFont;

SDL_Texture *g_pLableTexture;
SDL_Rect g_labelRect_1;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    g_pWindow = SDL_CreateWindow("GAME", // creates a window
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!g_pWindow)
    {
        printf("error initializing SDL window: %s\n", SDL_GetError());
        return 1;\
        
    }

    // Renderer Create
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }
    else
    {
        printf("SDL_ttf Initialize OK \n");
    }

    // Load Font file
    g_pFont = TTF_OpenFont("../../res/nmf.ttf", 28);

    if (!g_pFont)
    {
        printf("font file load error");
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }
    else
    {
        printf("Font Load OK\n");
    }

    // 문자열 라벨 생성
    {
        SDL_Color _whiteColor = {0xff,0xff,0xff,0xff};
        SDL_Color _blackColor = {0,0,0,0xff};
        Uint16 text[]={'H','e','l','l','o',' ','W','o','r','l','d','!',L'한' ,L'글'};
        // SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(g_pFont, text, textColor); 유니코드 지원
        // SDL_Surface *textSurface = TTF_RenderText(g_pFont, "안녕하세요", _whiteColor,_blackColor); 유니코드 비 지원
        // SDL_Surface *textSurface = TTF_RenderUNICODE(g_pFont,text, _whiteColor,_blackColor); // 유니코드 지원
        SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(g_pFont,text, _whiteColor); // 유니코드 지원
        g_pLableTexture = SDL_CreateTextureFromSurface(g_pRenderer, textSurface);
        printf("%4d%4d\n", textSurface->w, textSurface->h);
        g_labelRect_1.w = textSurface->w;
        g_labelRect_1.h = textSurface->h;
        SDL_FreeSurface(textSurface);
    }

    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 0xff);
        SDL_RenderClear(g_pRenderer);

        g_labelRect_1.x = 120;
        g_labelRect_1.y = 240;
        SDL_RenderCopy(g_pRenderer,g_pLableTexture, NULL,&g_labelRect_1);

        SDL_RenderPresent(g_pRenderer);

        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            switch (_event.type)
            {
            case SDL_KEYDOWN:

                break;
            case SDL_QUIT:
                bLoop = SDL_FALSE;
                break;
            default:
                break;
            }
        }
    }

    TTF_CloseFont(g_pFont);
    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
    return 0;
}