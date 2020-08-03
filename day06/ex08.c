#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  int num, j = 0 ;
  int rst[8];

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("SDL Initializing : %s ", SDL_GetError);
    return 1;
  }

  else
  {
     printf("success INIT\n");
  }

  //input numer
  printf("input number : ");
  scanf("%d", &num);

  printf("the number is : %d \n",num);
  // change decimal to binary
  
  for (int i=0; i<8; i++)
  {
    int _status = num & (0x80 >> i);

    if(_status)
    {
      printf("1");
    }
    else
    {
      printf("0");
    }
    
    
  }
/*  for (int i = 0; num = 0; i++)
  {
    if (num > 2)
    {
      num /= 2;
      rst[i] = num%2;
      printf("%d\n", num);
    }

    if (num == 0)
    {
      for (int k = 0 ; k <= j ; k ++)
      {
        printf("%d",rst[k]);
      }
    }
  }
*/

  return 0;
}