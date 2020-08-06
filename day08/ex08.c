#include <stdio.h>

void testGet(int *num)
{
    *num = 3;
}

void _sum(int a, int b, int * c)
{
    *c = a + b;
}


void main()
{
    int a = 0;
    testGet(&a);
    printf("%d \n",a);
    int b;
    _sum(3, 5, &b);
    printf("%d \n", b);
}