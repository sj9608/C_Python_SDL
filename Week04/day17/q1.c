#include <stdio.h>
#include <malloc.h>

int main()
{
    short *a;
    short *b;
    int *c;
    int _sum1;

    unsigned char t[5] = {0,};
    unsigned char _sum2;

    FILE *fp = fopen("q1.dat", "rb");

    fseek(fp, 0, SEEK_SET);
    fread(a, sizeof(short), 1, fp);

    printf("%04x\n", *a);
    


    // for (int i = 0; i < sizeof(t)/sizeof(t[0]); i++)
    // {
        
    // }
    


    fclose(fp);
    return 0;
}