#include <stdio.h>
#include <malloc.h>

void main()
{
    char *ptr;
    int *ptr2;

    ptr = (char *)malloc(1);     // 1byte 할당
    ptr2 = (int *)malloc(4 * 2); //4 byte * 2 할당;

    // ptr[0] = 1;

    printf("%d \n", ptr[0]);

    ptr2[0] = 12;
    ptr2[1] = 24;
    printf("%4d %4d\n", ptr2[0], ptr2[1]);

    free(ptr2);
    free(ptr);
}