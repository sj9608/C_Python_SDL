#include <stdio.h>

int main()
{
    int data1 = -1;

    printf("%u \n", data1); //unsigned decimal 의 MAX 값 4294967295 표시 됌
    
    char data2 = -1; //8비트 정수형 

    printf("%d %u\n", data2, data2); //출력시에는 32비트 정수형으로 계산됌. 4294967295

    float pi = 3.14;

    print("%f, %e \n", pi, pi); //지수형 표현 %e

    return 0;
}