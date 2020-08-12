// 366p. Q1)사용자에게 세개의 정수값을 입력 받아서 평균값을 출력하는 프로그램 작성하세요.
/*
#include <stdio.h>

int _Sum(int _a, int _b, int _c)
{
    return _a + _b + _c;
}

int main()
{
    int a, b, c;

    printf("정수를 입력해주세요\n");
    scanf("%d %d %d", &a, &b, &c);
    rewind(stdin);
    printf("입력된 값들의 합은 : %d \n",_Sum(a, b, c));

    return 0;
}
*/

// 366p Q2) 문자열 2개 합치기
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[32];
    char b[32];
    char c[64];
    gets(a);
    rewind(stdin);
    gets(b);
    rewind(stdin);

    strcat(a, b);
    printf("%s \n",a);
    return 0;
}
*/

// 366p Q3)/ 사용자가 kim 80.1 186.5 A 105 라고 입력하면 이름 : kim 몸무게 :80.1kg. 키 : 186.5cm, 혈액형 A형 심박수 : 105회
/*
#include <stdio.h>

typedef struct
{
    char _Name[32];
    char _B_type;
    int _beat;
    float _Weight;
    float _Height;
}info;

int main()
{
    info human;

    scanf("%s %f %f %c %d",&human._Name, &human._Weight,&human._Height, &human._B_type, &human._beat);
    printf("이름 : %8s\n",human._Name );
    printf("몸무게 : %4f\n", human._Weight);
    printf("키 : %4f\n", human._Height);
    printf("혈액형 : %c\n",human._B_type );
    printf("심박수 : %4d\n",human._beat );
}
*/