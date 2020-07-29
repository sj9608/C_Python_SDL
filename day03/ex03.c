#include <stdio.h>

int  main()
{
    int num;
    printf("input number : ");
    scanf("%d", &num);
    printf("10 : %d,  8 : %o, 16 : %x \n", num, num, num);

    return 0;
}