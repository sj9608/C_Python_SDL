#include <stdio.h>

int main()
{
    int data = 7;

    printf("[%d] [%5d] \n" , data, data);
    printf("[%5d] \n", data * 11);
    printf("[%5d] \n", data);   //오른쪽 정렬
    printf("[%-5d] \n", data);  //왼쪽 정렬
    printf("[%05d] \n", data);  //0채우기

    float pi = 3.14159265358979;

    printf("\\%f \n", pi);
    printf("[%20.15f] \n", pi);
    printf("[%-20.15f] \n", pi);
    printf("[%020.15f] \n", pi);

    return 0;
}