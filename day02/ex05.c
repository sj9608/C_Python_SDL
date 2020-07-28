#include <stdio.h>

int main()
{
    char opr;
    int a = 0, b = 0, Result = 0;

    printf("input a op b : ");
    scanf("%d %c %d",&a, &opr, &b);

    if (opr == '+')
    {
        printf("Result : %d + %d = %d", a, b, a + b);
    }
    else if (opr == '-')
    {
        printf("Result : %d - %d = %d", a, b, a - b);
    }
    else if (opr == '*')
    {
        printf("Result : %d * %d = %d", a, b, a * b);
    }
    else if (opr == '/')
    {
        printf("Result : %d / %d = %d", a, b, a / b);
    }
        else if (opr == '%')
    {
        printf("Result : %d %% %d = %d.", a, b, a / b);
    }

    return 0;
}