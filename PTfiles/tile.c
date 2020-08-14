#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// 던전 타일용으로 소스가 8x8 만큼 긁어오는거..  --> fix basic tile 용 16 16 긁어오기
// pRenderer, texture ,
void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex, Uint16 _x, Uint16 _y, Uint16 _index)
{
  SDL_Rect _tmpSrcRt;
  _tmpSrcRt.x = (_index % 8) * 16; // 맵 소스를 받아올 x 의 위치 (인덱스 값으로 계산할거)
  _tmpSrcRt.y = (_index / 8) * 16;  // 맵 소스를 받아올y 의 위치   3번 타일 이다 할 경우 48,0의 소스 좌표  만약 9번타일 일 경우 y 값이 1 증가해야함
  _tmpSrcRt.w = 16;
  _tmpSrcRt.h = 16;

  SDL_Rect _tmpDstRt;
  _tmpDstRt.x = _x * 16 * 2;
  _tmpDstRt.y = _y * 16 * 2;
  _tmpDstRt.w = 16 * 2;
  _tmpDstRt.h = 16 * 2;

  SDL_RenderCopy(pRenderer, pTex, &_tmpSrcRt, &_tmpDstRt);
}