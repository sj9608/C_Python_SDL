#include <stdio.h>

int main()
{
    int num1, num2;
    float real_1;

    printf("input num1, num2 : ");
    scanf("%d %d", &num1, &num2);
    printf("input real_1 : ");
    scanf("%f", &real_1);
    printf("integer values : %d %d\n", num1, num2);
    printf("float value : %f\n", real_1);

    return 0;
}