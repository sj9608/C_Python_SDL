#include <stdio.h>
#include "ex04.h"

int main()
{
    int result1, result2 = 0;
    result1 = _sum(2, 3);
    result2 = _mul(5, 3);
    printf("sum : %d\nmul : %d", result1, result2);

    return 0;
}