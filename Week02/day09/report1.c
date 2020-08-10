// 333p Q6 포인터를 사용하여 데이터 구성하기
#include <stdio.h>

int main()
{
    char a = 0x12, b = 0x34;
    short c = 0x5678;
    int t = 0;

    char *p = (char *)&t;
    short *q = (short *)&t;

    *(p + 3) = a;
    *(p + 2) = b;
    *(q) = c;

    printf("%8x", t);

    return 0;
}