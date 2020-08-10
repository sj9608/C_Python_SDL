#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *getName()
{
    char buf[32];
    gets(buf);

    char *pName = (char *)malloc(sizeof(strlen(buf) + 1));

    strcpy(pName, buf);

    return pName;
}

void getName2(char **ppName)
{
    char buf[32];
    gets(buf);

    // char *ppName = (char *)malloc(sizeof(strlen(buf) + 1));
    *ppName = (char *)malloc(strlen(buf) + 1);

    strcpy(*ppName, buf);    
}
int main()
{
    char *pMyName = getName();

    printf("%s \n", pMyName);
    free(pMyName);

    getName2(&pMyName);
    printf("%s \n", pMyName);
    free(pMyName);
    return 0;
}