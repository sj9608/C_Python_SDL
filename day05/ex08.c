#include <stdio.h>

int main()
{
    int data = 1;

    if(data = 3) // 조건에 대입연산 하는 실수.
    //이 실수를 줄이기 위한 대안
    //if ( 3 = data ) 라고 작성시 오류(컴파일오류 문법오류 --> 에러 찾기 쉬워짐)
    {
        printf("data equal to 3 \n");
    }

    printf("complete %d\n", data);

    return 0;
}