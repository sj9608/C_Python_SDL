#include <stdio.h>

int main()
{
    int a = 0x12345678; 
    int *pA = &a;
    int *pB = pA;
    char *pC = (char *)pA;

    printf("%x \n", *pA);
    printf("%x \n", *pB);
    printf("%x \n", *pC);
    printf("%x \n", *(pC+1));
    printf("%x \n", *(pC+2));
}