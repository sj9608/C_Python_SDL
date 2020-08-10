#include <stdio.h>
#include <malloc.h>

typedef unsigned int UInt;
typedef unsigned char Uchar;
typedef Uchar * PTRchar;

typedef int MyData[5];

int main()
{
    unsigned int a = 1;
    UInt b = 2;
    Uchar c = 128;
    PTRchar ptr;
    MyData q = {2, 4, 6, 8, 10};

    ptr = &c;

    MyData *p;
    p = (MyData *)malloc(sizeof(MyData));
    (*p)[0] = 3;

    printf("%d %d %d %d %d\n", a, b, c, *ptr, (*p)[0]);

    return 0;
}