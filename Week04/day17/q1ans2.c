#include <stdio.h>
#include <malloc.h>

int main()
{
    unsigned char *pdata = malloc(13);
    FILE *fp = fopen("q1.dat", "rb");
    fread(pdata,13, 1,fp);

    printf("%4x, %4x, %4x",*(short *)pdata, *((short *)pdata+1), *((int *)pdata+1));

    fclose(fp);
    return 0;
}