#include <stdio.h>

void test(int _a[]) // 함수의 매개변수에서 배열은 포인터값으로 들어간다.
{
    int _tmp = _a[2];
    _a[2] = _a[0];
    _a[0] = _tmp;
}

void main()
{
    int a[3] = {1,2,3};

    printf("%d %x \n", a[0], a); // 배열은 주소값이 표현된다.

    test(a);
    
    printf("%d %d %d \n", a[0], a[1], a[2]); 
}