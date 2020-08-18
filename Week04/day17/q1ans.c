#include <stdio.h>
#include <malloc.h>

typedef struct _S_DATA
{
    short a;
    short b;
    int c;
    char d[5];
} S_DATA;


int main()
{
    S_DATA *pdata = malloc(sizeof(S_DATA));
    FILE *fp = fopen("q1.dat", "rb");
    fread(pdata, sizeof(S_DATA), 1, fp);

    printf("%4x%4x%4x\n", pdata->a, pdata->b, pdata->c);

    for (int i = 0; i < 5; i++)
    {
        printf("%4d",pdata->d[i]);
    }

    fclose(fp);
    printf("done!\n");   


    return 0;
}