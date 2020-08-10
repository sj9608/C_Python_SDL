#include <stdio.h>

int main()
{
    char data1, data2, data3;
    char *p[3] = {&data1, &data2, &data3};

    for(int i=0; i<3; i++)
    {
        *p[i] = i + 1;
    }

    printf("%d, %d, %d",data1, data2, data3);
    printf("%d, %d, %d", *p[0], *p[1], *p[2]);
    printf("%d, %d, %d", p[0], p[1], p[2]);

    return 0;
}