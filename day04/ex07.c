#include <stdio.h>

int main()
{
    char _a = 'A';
    printf("%c %d\n",_a, _a);

    float value1 = 3.1;
    printf("%d, %f\n",value1, value1); //%d 뒤에 %f 사용하면 값이 정확하지 않음.
    printf("%f \n",value1);

    return 0;
}