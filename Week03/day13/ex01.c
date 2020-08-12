#include <stdio.h>

void foo()
{
    printf("Hello function foo1\n");
}

void foo2()
{
    printf("Hello function foo2\n");
}

void foo3(char *msg)
{
    printf("%s \n", msg);
}

void foo4(int a, int b)
{
    return (a + b);
}
int main()
{
    void (*p)();
    void (*p2)(char *); //foo3 함수에 매개변수를 받기위한 방법

    p = foo;
    p();

    p = foo2;
    p();

    p = foo3; // 기능 작동 안돼야 정상
    p("hello1");

    p2 = foo3; // 인자 값과 함수 원형을 맞춰줘야함
    p2("hello2");

    // p = foo4;                    기능작동안함 정상
    // printf("%d \n", p(2, 3)); 

    int (*p3)(int, int);
    p3 = foo4;
    printf("%d \n",p3(3,4));

    return 0;
}