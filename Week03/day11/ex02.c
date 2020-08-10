#include <stdio.h>

int main()
{
    int **p2;
    int *p;
    int data = 3;
    p = &data;
    p2 = &p;
    **p2 = 30;

    printf("%d \n", **p2);

    return 0;
}
// 쓰레기