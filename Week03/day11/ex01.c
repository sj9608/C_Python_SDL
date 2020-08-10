#include <stdio.h>

int main()
{
    int data = 0;
    int *p = &data;
    int **p2 = &p;  // 2차원 Pointer (좀 쓰임)(2차원 배열을 다루기 위해)
    int ***p3 = &p2; // 3차원 Pointer (별로 안쓰임)

    printf("%d \n", data);

    *p = 32;
    printf("%d \n", data);

    **p2 = 42;
    printf("%d \n", data);

    ***p3 = 52;
    printf("%d \n", data);
    

    return 0;
}