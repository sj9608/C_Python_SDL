#include <stdio.h>

typedef struct Test
{
    unsigned short a;
    unsigned short b;
} _Test;

int main()
{
    int a = 0x00030002;

    _Test *t = (_Test *)&a;

    printf("%04x\n", t->a + t->b); // 1번 방법 구조체로

    short *p = (short *)&a;

    short q = *p + *(p+1);

    printf("%04x\n", q); //2번 방법

    return 0;
}