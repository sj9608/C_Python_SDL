#include <stdio.h>

int main()
{
    int score = 90;
    char grade = ' ';

    // else if 문 중첩은 최대 약 250개 정도까지 쓸 수 있다.
    // 컴파일시에 else if 가 stack에 저장됨. stack의 저장공간이 무제한이 아님
    if (score >= 90)
    {
        grade = 'A';
    }
    else if (score >= 80)
    {

    }

    printf("grade : %c", grade);

    return 0;
}