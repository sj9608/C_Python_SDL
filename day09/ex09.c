#include <stdio.h>
#include <string.h>

// 문자열 -> 정수형 변환
int main()
{
    char strBuf[32];
    printf("input number : ");
    gets(strBuf);

    int num  = 0;

    printf("str length %d \n", strlen(strBuf));
    // 문자열 길이 구하는 함수는 반복문으로 카운트 증가시키며 0찾으면됌


    int count = strlen(strBuf);
    int pos_num = 1;
    for(int i = 0; i < count-1 ; i++)
    {
        pos_num *= 10;
    }
    
    printf("max pos_num : %d \n", pos_num);

    for(int i = 0 ; i<count ; i++)
    {
        num = num + (strBuf[i] - '0') * pos_num;
        pos_num /= 10;
    }
    printf("%s = > %d \n", strBuf, num);
    

    return 0;
}