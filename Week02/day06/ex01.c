#include <stdio.h>

void main()
{
  int sum , num;
  
  // sum, num 값을 동시에 초기화 하면서 반복문시작
  for(num = 1, sum =0; num <= 5; num++)
  {
    printf("%d \n",num);
    
    sum += num;
  }


  printf("result : %d \n", sum);

}
