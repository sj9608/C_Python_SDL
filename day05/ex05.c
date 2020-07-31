#include <stdio.h>

int main()
{
    int data = 0;

    data > 3 && data++; //앞의 data > 3 조건이 F이기 때문에 뒤 조건은 안봄.

    printf("%d \n", data); // data = 0 

    return 0;
}