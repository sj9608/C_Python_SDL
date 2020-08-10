#include <stdio.h>

int main()
{
    int data = 3;
    int **pp;
    int my_ptr = (int)&data;

    pp = (int **)&my_ptr;

    // int portnum = 1000;
    // *((int *) portnum) = 1;
    // *((char *) 0x7000) = 1;

    printf("%d \n", **pp);
    (**pp)++;                   // 연산자 우선순위 조심
    printf("%d \n", data);

    return 0;
}