#include <stdio.h>

int main()
{
    float a = 1.52e-5;
    int b = 0xFA; //16진수
    int c = 012; //8진수 표현은 앞에 '0' 만 붙이면 된다.
    int d = 0b1111; //2진수 표현 (c99 문법)
    char *strMsg = "Hello World!"; //문자열 상수 저장
    

    printf("%f %d %d %d %s \n", a, b, c, d,strMsg);

    return 0;
}