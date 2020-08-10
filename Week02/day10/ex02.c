#include <stdio.h>

int main()
{
    char data[4] = {'a', 'b', 'c', 'd'};
    // char *p = &data[0];
    char *p = data;
    // printf("%d, %d",data, p);

    printf("%c %c %c %c %c\n", *p, *(p+1), data[2], *(data+2), p[3]);

    p = p + 1; //주소 값을 + 1 해줌

    printf("%c", *p);

    return 0;
}