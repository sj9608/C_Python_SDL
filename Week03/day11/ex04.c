// 2차원 포인터가 가리키는 대상을 동적으로 할당하기
#include <stdio.h>
#include <malloc.h>

void main()
{
    short **pp;
    pp = (short **)malloc(sizeof(short *)); // 주소의 주소
    *pp = (short *)malloc(sizeof(short)); // 주소
    **pp = 10;

    printf("**pp : %d\n", **pp);
    free(*pp);
    free(pp);
}