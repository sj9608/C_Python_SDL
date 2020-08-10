#include <stdio.h>

void _test(char *strMsg); //함수의 호출자 위에 함수의 원형 선언 해줘야 컴파일 에러가 나지않는다.

int main()
{
    _test("hi~");

    return 0;
}

void _test(char *strMsg)
{
    printf("test call %s", strMsg); //char data pointer는 & 연산 받지않는다.
}