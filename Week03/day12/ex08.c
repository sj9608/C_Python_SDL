#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char strBuf[32];

    FILE *fp = fopen("test4.txt", "rt");

    // while (EOF != fscanf(fp, "%s", &strBuf)) -> 한단어(스페이스 만나면 끊김)씩 출력됌
    while (NULL != fgets(strBuf, sizeof(strBuf), fp)) // 한줄씩 반환됌
    {
        // printf("%s", strBuf);
        char *pszTemp1; // 1줄 읽고 strtok으로 구분자로 나눈 문자열을 반환받을 변수
        char szName[32];
        int kor, eng, math;

        static char *pszDelimiter = ",";
        pszTemp1 = strtok(strBuf,pszDelimiter);
        //printf("%s \n", pszTemp1);

    // name
        strcpy(szName, pszTemp1);
    // korea
        pszTemp1 = strtok(NULL,pszDelimiter); // 이미 strBuf 에서 처음 반환한 문자가 나가고 다음문자를 넣어줌
        kor = atoi(pszTemp1);
    // english
        pszTemp1 = strtok(NULL,pszDelimiter);
        eng = atoi(pszTemp1);
    // math
        pszTemp1 = strtok(NULL, pszDelimiter);
        math = atoi(pszTemp1);

        printf("%s %d %d %d \n", szName, kor, eng, math);

        // puts(strBuf);
    }

    fclose(fp);
}