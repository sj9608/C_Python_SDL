#include <stdio.h>

int main()
{
    char strBuf[32];
    FILE *fp = fopen("test3.txt", "rt");

    // while (EOF != fscanf(fp, "%s", &strBuf)) -> 한단어(스페이스 만나면 끊김)씩 출력됌
    while (NULL != fgets(strBuf,sizeof(strBuf),fp))
    {
        // puts(strBuf);
        printf("%s", strBuf);
    }
    
    fclose(fp);
}