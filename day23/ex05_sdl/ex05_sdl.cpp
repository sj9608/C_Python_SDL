// ex05_sdl.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

SDL_Window* g_pWindow;
SDL_Renderer* g_pRenderer;
SDL_Texture* g_pTexture;

int main(int argc, char * argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Init fail : %s \n", SDL_GetError());
		return 1;
	}

	g_pWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

	g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);


	SDL_bool bLoop = SDL_TRUE;
	while (bLoop)
	{
		SDL_Event _event;

		while (SDL_PollEvent(&_event))
		{
			switch (_event.type)
			{
			case SDL_KEYDOWN:
			{
				printf("%d \r",_event.key.keysym.scancode);
			}
			break;
			case SDL_QUIT:
			{
				bLoop = SDL_FALSE;
			}
				break;

			default:
				break;

			}
		}

	}

	SDL_DestroyTexture(g_pTexture);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);



	return 0;
}