#include <stdio.h>

int main()
{
    int data = 7;

    if(data > 3) {
        printf(" bigger than 3 : data = %d\n", data);
        data = data % 3;

    }

    printf("--- finish --- data : %d\n",data);

    return 0;
}