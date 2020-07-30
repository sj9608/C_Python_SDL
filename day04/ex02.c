#include <stdio.h>

int _sum(int a, int b)
{
    int result = a + b;

    return result;
}

void _test()
{
    printf("test call \n");
    return; //return 문을 만나면 함수가 강제로 종료됌.
    print("tes call 2 \n");
}

int main()
{
    int a, b, result = 0;
    

    printf("Hello world\n");

    printf("input a, b :");
    scanf("%d %d", &a, &b);
    result = _sum(a, b);

    printf("result is %d.\n", result);

    _test();

    return 0;
}

/*

10 LET A=1
15 A = A+1
20 PRINT A
25 IF A > 10 THEN GOTO 40
30 GOTO 15
40 PRINT "END"

RUTN 10

*/ // Q(MS) BASIC LANGUAGE 