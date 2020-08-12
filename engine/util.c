#include <SDL2/SDL.h>

SDL_bool checkPointInRect(SDL_Rect *pRect, Sint32 point_x, Sint32 point_y)
{
    SDL_Point _pt = {point_x, point_y};

    return SDL_PointInRect(&_pt, pRect); // 포인터가 함수내에 있는지 확인하는 함수 매개변수는 이와 같이 받는다. 

    //return SDL_FALSE;
}