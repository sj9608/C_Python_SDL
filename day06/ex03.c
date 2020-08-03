#include <stdio.h>

int main()
{
  int sum = 0;
  int num = 1;

  do
  {
    printf("%d \n", num);
    sum += num;
    if (num >= 5) break;

    num ++;
  } while (1);
  

  return 0;
}