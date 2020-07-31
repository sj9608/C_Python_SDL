#include <stdio.h>

int main()
{
    printf("%d %d %d %d \n",
    1 > 2,
    1 <= 2,
    1 == 1,
    1 != 2); // in %d T = 1 , F = 0

    printf("%d \n", ((1==1) && (2>1))); 
    printf("%d \n", ((1!=1) || (2>1)));

    printf("%d \n", ((1!=1) || (2>1) && (1 && 1))); 

    return 0;
}