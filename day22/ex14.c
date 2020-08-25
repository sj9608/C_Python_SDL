#include <stdio.h>

typedef struct ex14
{
    float height;
    int age;
    short class;
    unsigned char p1;
    unsigned char p2;
} S_Test;

int main()
{
    S_Test test;
    test.height = 53.5;
    test.age = 20;
    test.class = 01;
    test.p1 = 0x40;
    test.p2 = 0x88;

    FILE *fp = fopen("t3.bin", "wb");

    fwrite(&test, sizeof(S_Test), 1, fp);

    fclose(fp);
    return 0;
}