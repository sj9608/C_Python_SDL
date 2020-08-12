#include <stdio.h>

int _sum(int a, int b)
{
    return a+b;
}

int _sub(int a, int b)
{
    return a-b;
}

int main()
{
    int (*p[2])(int, int); // 함수 이름 자체가 주소
    p[0] = _sum;     // 따라서 & 쓰지 않아도 됌
    p[1] = _sub;

    for(int i =0 ;i<2;i++)
    {
        printf("%4d\n",p[i](5,3));
    }
    return 0;
}