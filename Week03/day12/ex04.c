#include <stdio.h>

int main()
{
    char szBuf[32];
    gets(szBuf); //size + 1 ( including enter )
    FILE *fp = fopen("test.txt", "wt");


    if (!fp)
    {
        printf("Failed Open\n");
    }
    else
    {
        printf("oepn success\n");
        int _count = fprintf(fp, "%s \n", szBuf);
        printf("%d byte write\n",_count);

    }

    fclose(fp);


    puts(szBuf);

    return 0;
}